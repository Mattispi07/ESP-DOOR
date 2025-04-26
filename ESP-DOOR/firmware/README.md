# Firmware ESP-Door

Questo firmware è sviluppato per ESP32 e gestisce il controllo della porta tramite Bluetooth e feedback visivi/acustici.

## 📜 Descrizione

- **Bluetooth**: Comunicazione tra ESP32 e app mobile.
- **Servo Motor**: Apertura fisica della porta.
- **Buzzer**: Notifica sonora alla pressione del pulsante.
- **LED RGB**: Indicazione dello stato del sistema.
- **LCD**: Visualizzazione in tempo reale.

## 📚 Librerie necessarie

- `ESP32Servo`
- `BluetoothSerial`
- `LiquidCrystal`

## ⚙️ Istruzioni di caricamento

1. Apri `ESP-Door.ino` con Arduino IDE.
2. Installa le librerie mancanti tramite Library Manager.
3. Imposta la scheda: **ESP32 Dev Module**.
4. Carica il firmware sulla tua ESP32.

---
