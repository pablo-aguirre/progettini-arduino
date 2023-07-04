int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // calibrazione valori minimi e massimi del sensore
  while (millis() < 5000) {           // millis() => ms da quando Arduino è acceso/resettato
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh)
      sensorHigh = sensorValue;
    if (sensorValue < sensorLow)
      sensorLow = sensorLow;
  }
  digitalWrite(ledPin, LOW);
}

void loop() {
  sensorValue = analogRead(A0);

  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  tone(8, pitch, 20); // suona, sul piedino 8, per 20 ms
  delay(10);
}
