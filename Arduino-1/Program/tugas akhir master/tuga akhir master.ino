#include <Wire.h>

const int trigPin = 26;  // Pin trigger sensor ultrasonik
const int echoPin = 25;  // Pin echo sensor ultrasonik

void setup() {
  Wire.begin();  // Inisialisasi I2C komunikasi
  Serial.begin(9600);  // Inisialisasi Serial Monitor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, cm;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  cm = duration / 29 / 2;  // Menghitung jarak dalam cm
  
  // Mengirim data jarak ke ESP32 melalui I2C
  Wire.beginTransmission(9);  // Alamat I2C ESP32 (Slave)
  Wire.write(cm);  // Mengirim data jarak
  Wire.endTransmission();
  Serial.println(cm);
  delay(100);  // Menunda pengukuran selama 100ms
}
