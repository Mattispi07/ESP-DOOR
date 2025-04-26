# Manuale d'Uso - ESP-Door

Benvenuto nel sistema **ESP-Door**!  
Questo manuale ti guida passo passo per utilizzare il dispositivo e l'app mobile associata.

---

## 📦 Contenuto del sistema

- Scheda **ESP32** con firmware caricato.
- **Modulo Bluetooth** integrato nell'ESP32.
- **Display LCD 16x2** per notifiche utente.
- **LED RGB** per stato operativo.
- **Servo motore** per apertura porta.
- **App Android** dedicata.

---

## 🔌 Prima installazione

1. Collega la scheda ESP32 tramite USB al PC.
2. Carica il firmware `ESP-Door.ino` usando Arduino IDE.
3. Scarica e installa l'app **ESP-Door** sul tuo smartphone Android.
4. Alimenta il sistema ESP32.

---

## 📲 Utilizzo

- Quando qualcuno preme il pulsante esterno:
  - Il buzzer emette un segnale acustico.
  - Il LED blu si accende.
  - L'LCD mostra "ATTESA".
  - L'app riceve una **notifica Bluetooth** ("richiesta").

- Tramite app puoi:
  - **Accettare** la richiesta → il motore apre la porta, LED verde acceso, LCD "APRI".
  - **Negare** l'accesso → porta chiusa, LED rosso acceso, LCD "NEGA".

---

## 🎨 Codifica dei colori LED

| Stato           | Colore LED          | Descrizione |
|-----------------|----------------------|-------------|
| Attesa richiesta | Blu acceso           | In attesa di risposta |
| Accesso concesso | Verde acceso         | Porta aperta |
| Accesso negato   | Rosso acceso          | Accesso rifiutato |
| Dispositivo connesso | Verde + Blu (Ciano) | Connessione Bluetooth attiva |

---

## ⚠️ Note importanti

- Assicurati che il Bluetooth sia attivo sullo smartphone.
- Il raggio di azione dipende dal modulo ESP32, tipicamente 5-10 metri.

---

# 🤝 Assistenza

Per problemi o suggerimenti: **[https://github.com/Mattispi07]**

---
