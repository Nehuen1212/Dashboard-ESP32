# Dashboard-ESP32

Plantilla mínima para un ESP32 con servidor web y dashboards.

Descripción rápida:
- Código en `src/main.cpp` (WiFi, servidor web).
- Archivos estáticos en `data/` (p. ej. `index.html`).
- Dashboards de ejemplo en `Recursos/`.

Requisitos:
- PlatformIO
- Placa ESP32

Uso básico (PowerShell):
```powershell
# Compilar y subir
pio run -t upload

# Monitor serie
pio device monitor -b 115200
```

Personaliza:
- Edita `src/main.cpp` para poner tu SSID/PASSWORD.
- Copia los HTML que quieras desde `Recursos/` a `data/` para servirlos.

Notas:
- No subas credenciales a repositorios públicos.
- Añade `LICENSE` si quieres compartir con una licencia clara.

Listo — si quieres, puedo acortar más o añadir ejemplos concretos desde `src/main.cpp`.
