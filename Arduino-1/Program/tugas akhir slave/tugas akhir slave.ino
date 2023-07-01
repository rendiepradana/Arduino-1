#include <Wire.h>

const int ledPin1 = 5;  // Pin LED 1
const int ledPin2 = 6;  // Pin LED 2
const int ledPin3 = 7;  // Pin LED 3

void setup() {
  Wire.begin(9);  // Inisialisasi I2C komunikasi dengan alamat 9
  Wire.onReceive(receiveEvent);  // Menetapkan fungsi receiveEvent sebagai callback saat data diterima
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
}

void loop() {
  // Tidak ada yang perlu dilakukan di loop()
}

void receiveEvent(int byteCount) {
  if (Wire.available()) {
    int cm = Wire.read();  // Menerima data jarak dari Arduino
    
    // Mengendalikan LED berdasarkan nilai jarak
    if (cm <= 5) {
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
    } else if (cm <= 10) {
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
    } else if (cm <= 15) {
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
    } else {
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
    }
  }
}
