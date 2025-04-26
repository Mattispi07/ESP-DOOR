#include <ESP32Servo.h>
#include <BluetoothSerial.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 14, 27, 26, 25);
Servo motore;
BluetoothSerial SerialBT;

const int btnPin = 2;
const int buzzerPin = 4;
const int motorePin = 5;

const int rosso = 18;
const int verde = 19;
const int blu = 21;

bool messaggio = false;

void setup() {
  lcd.begin(16, 2);
  SerialBT.begin("ESP-Door");
  Serial.begin(115200);

  pinMode(btnPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(rosso, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(blu, OUTPUT);

  motore.attach(motorePin);
  motore.write(0);

  setLED(LOW, LOW, LOW);
  Serial.println("Sistema pronto.");
}

void loop() {
  int stato = digitalRead(btnPin);
  Serial.print("Stato bottone: ");
  Serial.println(stato);

  if (stato == HIGH) {
    digitalWrite(buzzerPin, HIGH);
    setLED(LOW, LOW, HIGH);
    delay(200);
    digitalWrite(buzzerPin, LOW);
    lcd.print("ATTESA");
    SerialBT.println("richiesta");
    Serial.println("Messaggio inviato: richiesta");
  }

  if (stato == LOW) {
    messaggio = false;
  }

  if (SerialBT.available()) {
    char risposta = SerialBT.read();
    Serial.print("Risposta ricevuta: ");
    Serial.println(risposta);

    switch (risposta) {
      case '0':
        nega();
        break;
      case '1':
        apri();
        break;
      case '2':
        connesso();
        break;
    }

    delay(3000);
    reset();
  }
}

void reset() {
  setLED(LOW, LOW, LOW);
  motore.write(0);
  lcd.clear();
}

void apri() {
  lcd.clear();
  motore.write(120);
  setLED(LOW, HIGH, LOW);
  lcd.print("APRI");
}

void connesso() {
  setLED(LOW, HIGH, HIGH);
  lcd.print("CONNESSO");
  delay(2000);
  reset();
}

void nega() {
  lcd.clear();
  motore.write(0);
  setLED(HIGH, LOW, LOW);
  lcd.print("NEGA");
}

void setLED(int r, int g, int b) {
  digitalWrite(rosso, r);
  digitalWrite(verde, g);
  digitalWrite(blu, b);
}
