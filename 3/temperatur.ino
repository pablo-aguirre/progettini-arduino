const int sensorPin = A0;
const float baselineTemp = 25.0; // temperatura della stanza 

void setup() {
  Serial.begin(9600);
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal/1024.0) * 5.0; // converti la lettura ADC in tensione
  float temperature = (voltage - .5) * 100;
  
  Serial.print("sensorVal: ");
  Serial.println(sensorVal);
  Serial.print("voltage: ");
  Serial.println(voltage);
  Serial.print("temperature: ");
  Serial.println(temperature);
  Serial.println();

  if(temperature < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp+2 && temperature < baselineTemp+4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp+4 && temperature < baselineTemp+6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(5000);
}
