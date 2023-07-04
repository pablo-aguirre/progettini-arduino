const int switchPin = 8;         // interruttore di inclinazione

unsigned long previousTime = 0;  // memorizza il momento in cui è stato modificato l'ultimo led

int switchState = 0;
int prevSwitchState = 0;

int led = 2;  // prossimo led da accendersi

long interval = 2000; // intervallo di accensione di ogni LED

void setup() {
  Serial.begin(9600);
  for (int iLED = 2; iLED < 8; iLED++)
    pinMode(iLED, OUTPUT);

  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - previousTime > interval) {
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;

    if (led == 7) {
      // cosa fare allo scadere del tempo
    }
  }
  
  switchState = digitalRead(switchPin);
  Serial.println(switchState);
  
  if (switchState != prevSwitchState) {
    for (int iLED = 2; iLED < 8; iLED++)
      digitalWrite(iLED, LOW);
    
    led = 2;
    previousTime = currentTime;
  }

  prevSwitchState = switchState;
}
