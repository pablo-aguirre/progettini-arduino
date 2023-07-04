#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // piedini utilizzati per comunicare

const int switchPin = 6;  // pulsante
int switchState = 0;      // stato attuale del pulsante
int prevSwitchState = 0; // stato precedente del pulsante

int reply; // risposta sullo schermo

void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);

  // messaggio di benvenuto
  lcd.clear();
  lcd.print("Fai una domanda");
  lcd.setCursor(0, 1);  // prima colonna, seconda riga
  lcd.print("alla sfera...");
}

void loop() {
  switchState = digitalRead(switchPin);
  
  if (switchState != prevSwitchState)
    if (switchState == LOW) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("La sfera dice:");
      lcd.setCursor(0,1);
      lcd.print(random(2) == 0 ? "no :(" : "si! :D");
    }
    prevSwitchState = switchState;
}
