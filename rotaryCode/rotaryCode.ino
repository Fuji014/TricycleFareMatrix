#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int outputA = 6; // clock of rotary
const int outputB = 7; // dt of rotary
int counter = 0;
int aState;
int aLastState;

//declaring var for computation
const float pi = 3.14;
const int R = 7;
const int N = 22;
int distance = 0;

void setup() {
  //lcd display
  lcd.begin();
  lcd.backlight();
  delay(1000);
  lcd.print("Running Test.");
  delay(1000);
  lcd.clear();
  lcd.print("Running Test..");
  delay(1000);
  lcd.clear();
  lcd.print("Running Test...");
  delay(1000);
  lcd.clear();
  lcd.print("Running Test....");
  delay(1000);
  lcd.clear();
  lcd.print("Running Test....");
  delay(2000);
  lcd.clear();
  lcd.print("Tricycle Meter");
  
  // put your setup code here, to run once:
  pinMode(outputA, INPUT);
  pinMode(outputB, INPUT);

//  Serial.begin(9600);
  aLastState = digitalRead(outputA);
}

void loop() {
  aState = digitalRead(outputA);
  if(aState != aLastState){
    if(digitalRead(outputB) != aState){
      counter++;
    }
    distance = (counter*pi*R)/N;
    lcd.setCursor(0,1);
    lcd.print(distance);
    lcd.setCursor(2,1);
    lcd.print("M ");
   
//    Serial.print("Position: ");
//    Serial.print(counter);
  }
  aLastState = aState;

}
