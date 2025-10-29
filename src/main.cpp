#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

const char* ssid = "Extensor - Depto";
const char* password = "nehuen2008";

const int LED_GPIO = 2; 

AsyncWebServer server(80);

float leerValorSensor() {
  return 20.0 + (float)random(0, 100) / 10.0; 
}

void setup() {
  Serial.begin(115200); 
  if(!SPIFFS.begin(true)){
    Serial.println("Ha ocurrido un error al montar SPIFFS");
    return;
  }
  pinMode(LED_GPIO, OUTPUT);
  digitalWrite(LED_GPIO, LOW); 
  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado!");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");
  });
  server.on("/data", HTTP_GET, [](AsyncWebServerRequest *request){
    float sensorValue = leerValorSensor();
    request->send(200, "text/plain", String(sensorValue));
  });  
  server.on("/state", HTTP_GET, [](AsyncWebServerRequest *request){
    String estado = (digitalRead(LED_GPIO) == HIGH) ? "ON" : "OFF";
    request->send(200, "text/plain", estado);
  });
  
  server.on("/toggle", HTTP_GET, [](AsyncWebServerRequest *request){
    int estado = digitalRead(LED_GPIO);
    digitalWrite(LED_GPIO, !estado); 
    request->send(200, "text/plain", "OK");
  });
  server.begin();
}

void loop() {
  
}