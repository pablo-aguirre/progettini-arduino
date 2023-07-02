#include <Servo.h>

Servo myServo;

int const potPin = A0;  // potenziometro
int potVal;
int angle;

void setup() {
  myServo.attach(3);    // PWM 3
  // Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);

  // Serial.print("potVal: ");
  // Serial.println(potVal);

  angle = map(potVal, 0, 1023, 0, 179); // trasforma i valori tra 0 e 1023 in valori tra 0 e 179
  // Serial.print("angle: ");
  // Serial.println(angle);

  myServo.write(angle);
  // delay(1000);
}
