const int greenLEDPin = 9;
const int blueLEDPin = 10;
const int redLEDPin = 11;

const int greenSensorPin = A0;
const int blueSensorPin = A1;
const int redSensorPin = A2;

int greenValue = 0;
int blueValue = 0;
int redValue = 0;

int greenSensorValue = 0;
int blueSensorValue = 0;
int redSensorValue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
}

void loop() {
  greenSensorValue = analogRead(greenSensorPin);
  blueSensorValue = analogRead(blueSensorPin);
  redSensorValue = analogRead(redSensorPin);

  Serial.print("Raw Sensor Values \n\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\n\t Blue: ");
  Serial.print(blueSensorValue);
  Serial.print("\n\t Red: ");
  Serial.println(redSensorValue);

  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;
  redValue = redSensorValue/4;

  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueValue, blueValue);
  analogWrite(redLEDPin, redValue);
  delay(2000);
}
