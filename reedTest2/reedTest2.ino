#include "Wire.h"
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // set lcd i2c address
int ledpin=13; // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer

float radius_of_wheel = 0.4699;  //Measure the radius of your wheel and enter it here
volatile byte rotation; // variale for interrupt fun must be volatile
float timetaken,rpm,dtime,kmRes,circumference,distanceTravel;
const float km = 0.0001885; 
int v,counter;
unsigned long pevtime;

 
void setup()
 {
  
   Serial.begin(9600); //start the Bluetooth communication at 9600 baudrate
   //pinMode(ledpin,OUTPUT); //LED pin aoutput for debugging
   
    // lcd start
    lcd.begin(20,4);
    lcd.setCursor(3,0);
    lcd.print("Welcome User!");
    lcd.setCursor(8,1);
    lcd.print("****");
    lcd.setCursor(0,2);
    lcd.print("Tricycle Meter");
    lcd.setCursor(8,3);
    lcd.print("****");
    delay(1000);
    lcd.clear();
    //lcd end
    

   attachInterrupt(0, falling, FALLING); //secound pin of arduino used as interrupt and magnet_detect will be called for each interrupt
   pinMode(2, INPUT);
   digitalWrite(2, HIGH); //Enable pullup
   rotation = rpm = pevtime = 0; //Initialize all variable to zero
 }
 
void loop()
{
  /*To drop to zero if vehicle stopped*/
  if(millis()-dtime>1500) //no magnet found for 1500ms
 {
  rpm= v = 0; // make rpm and velocity as zero
  Serial.println(v);
//  lcd.setCursor(3,0);
//  lcd.print(v);
  dtime=millis();
 }
   v = radius_of_wheel * rpm * 0.37699; //0.33 is the radius of the wheel in meter
}
 
void falling() //Called whenever a magnet is detected
{
  rotation++;
  dtime=millis();
  if(rotation>=2)
  {
    counter++;
    timetaken = millis()-pevtime; //time in millisec for two rotations
    rpm=(1000/timetaken)*60;    //formulae to calculate rpm
    pevtime = millis();
    rotation=0;
//    lcd.setCursor(3,2);
    Serial.println(v);
//    lcd.print(v);
    //Cycle_BT.println("Magnet detected...."); //enable while testing the hardware

    // calculate km/ph
    kmRes = radius_of_wheel * v * km;
    Serial.println(kmRes, 4);

    // distance formula calculate
    circumference =  2 * 3.14 * radius_of_wheel;
    distanceTravel = counter * circumference * 0.0001885;
    String name = "distance travel ";
    Serial.print(name);
    Serial.println(distanceTravel, 4);
    
    
  }
}
