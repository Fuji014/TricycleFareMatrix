/*
 * This code is to use in Arduino UNO for interfacing the Thermal Printer.
 * By:- Sourav Gupta 
 * Date:- 14.11.2018
 * Circuitdigest.com
 */

//Pin declaration
int led = 13;
int SW = 2;

// Programe flow related operations

int is_switch_press = 1; // For detecting the switch press status
int debounce_delay = 300; //Debounce delay

void setup() {
/*  
 *   This function is used to set the pin configuration
 */
 pinMode(led, OUTPUT);
 pinMode(SW, INPUT);
 Serial.begin(9600);
}

void loop() {
  is_switch_press = digitalRead(SW); // Reading the Switch press status

  if (is_switch_press == HIGH){
    delay(debounce_delay); // debounce delay for button press
    if(is_switch_press == HIGH){
    digitalWrite(led, HIGH);
    Serial.println("Hello");
    delay(100);
    Serial.println("This is a Thermal printer interface");
    Serial.println("with Arduino UNO.");
    delay(100);
    Serial.println("Circuitdigest.com");    
    Serial.println ("\n\r");
    Serial.println ("\n\r");
    Serial.println ("\n\r");
    Serial.println ("---------------------------- \n \r");
    Serial.println ("Thank You.");
    Serial.println ("\n\r");
    Serial.println ("\n\r");
    Serial.println ("\n\r");
    digitalWrite(led, LOW);    
    }    
  }
  else{
    digitalWrite(led, LOW);
  }    
}
