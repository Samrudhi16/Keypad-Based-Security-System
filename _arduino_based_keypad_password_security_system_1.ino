#include <Keypad.h>
#include <LiquidCrystal.h>

// LCD pins: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 4, 5, 3, 2);

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {A0, A1, A2, A3};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Password
String password = "1234";
String input = "";

void setup() {

  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
}

void loop() {

  char key = keypad.getKey();

  if (key) {

    // Check password when # is pressed
    if (key == '#') {

      lcd.clear();

      if (input == password) {

        lcd.setCursor(0, 0);
        lcd.print("SYSTEM UNLOCK");
      }
      else {

        lcd.setCursor(0, 0);
        lcd.print("WRONG PASSWORD");
      }

      delay(3000);

      // Clear old password
      input = "";

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Password");
    }

    // Clear input using *
    else if (key == '*') {

      input = "";

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Password");
    }

    // Store keypad input
    else {

      input += key;

      lcd.setCursor(0, 1);
      lcd.print(input);
    }
  }
}