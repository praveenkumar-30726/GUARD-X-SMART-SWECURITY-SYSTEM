#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

// ---------------- LCD ----------------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------------- KEYPAD ----------------
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'D','C','B','A'},
  {'#','9','6','3'},
  {'0','8','5','2'},
  {'*','7','4','1'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// ---------------- PINS ----------------
const int buzzerPin = 12;
const int espTriggerPin = 11;
const int servo1Pin = 10;
const int servo2Pin = A0;   // ✅ FIXED (NOT 13)

// ---------------- OBJECTS ----------------
Servo servo1;
Servo servo2;

// ---------------- VARIABLES ----------------
String inputPassword = "";
const String GENERAL_PIN = "1234";
const String MASTER_PIN  = "5678";

int fails = 0;
bool masterMode = false;

// ---------------- SETUP ----------------
void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(buzzerPin, OUTPUT);
  pinMode(espTriggerPin, OUTPUT);

  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);

  // LOCK POSITION
  servo1.write(90);
  servo2.write(120);

  digitalWrite(espTriggerPin, LOW);

  showMsg("SYSTEM READY", "ENTER PIN:");
}

// ---------------- LOOP ----------------
void loop() {

  // Alarm beep in master mode
  if (masterMode) {
    tone(buzzerPin, 1000, 200);
    delay(150);
  } else {
    noTone(buzzerPin);
  }

  char key = keypad.getKey();

  if (key) {
    tone(buzzerPin, 2000, 50);
    delay(150);

    if (key == 'A') {
      if (inputPassword.length() > 0) checkPass();
    }

    else if (key == 'B') {
      inputPassword = "";
      showMsg(masterMode ? "MASTER MODE" : "ENTER PIN:", "");
    }

    else if ((key >= '0' && key <= '9') || key == '#') {
      if (inputPassword.length() < 16) {
        inputPassword += key;
        lcd.setCursor(inputPassword.length() - 1, 1);
        lcd.print("*");
      }
    }
  }
}

// ---------------- PASSWORD CHECK ----------------
void checkPass() {

  if (!masterMode) {

    if (inputPassword == GENERAL_PIN) {
      showMsg("ACCESS GRANTED", "OPENING DOOR");

      // OPEN
      servo1.write(180);
      servo2.write(0);

      delay(5000);

      // CLOSE
      servo1.write(90);
      servo2.write(120);

      fails = 0;
    }

    else {
      fails++;

      int triesLeft = max(0, 3 - fails);
      showMsg("WRONG PIN", "TRY: " + String(triesLeft));

      delay(1500);

      if (fails >= 3) {
        masterMode = true;

        // ESP Trigger
        digitalWrite(espTriggerPin, HIGH);
        delay(300);
        digitalWrite(espTriggerPin, LOW);

        showMsg("SYSTEM LOCKED", "ALARM ACTIVE");
      }
    }
  }

  else {
    if (inputPassword == MASTER_PIN) {
      masterMode = false;

      digitalWrite(espTriggerPin, LOW);

      showMsg("DISARMED", "SYSTEM RESET");

      fails = 0;
      delay(2000);
    }

    else {
      showMsg("WRONG MASTER", "TRY AGAIN");
      delay(2000);
    }
  }

  inputPassword = "";
  showMsg(masterMode ? "MASTER MODE" : "ENTER PIN:", "");
}

// ---------------- DISPLAY FUNCTION ----------------
void showMsg(String l1, String l2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(l1);
  lcd.setCursor(0, 1);
  lcd.print(l2);
}