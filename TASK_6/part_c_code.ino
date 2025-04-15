//Include Servo and LiquidCrystal libraries for controlling servo motors and LCD display
#include <Servo.h>
#include <LiquidCrystal.h>

//Create servo objects to control servo motors
Servo servo1;
Servo servo2;

//Define current and last state of push buttons to use the push button as a toggle switch
int buttonState = 0;            //Store current state of push button
int lastButtonState = 0;        //Store last state of push button
bool servoControl = true;       //Flag to toggle between servo1 and servo2
int buttonPin = 8;              //Digital pin where push button is connected
//Define pins to connect to LCD display
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  servo1.attach(6);                    //Attach servo1 to pin 6 
  servo2.attach(10);                   //Attach servo2 to pin 10
  pinMode(buttonPin, INPUT_PULLUP);    // Set button pin as input with internal pull-up resistor
  lcd.begin(16, 2);                    // Initialize 16x2 LCD display
  lcd.clear();                         //Clear any previous data from the display
}

void loop() {
  buttonState = digitalRead(buttonPin);                   //Read the current state of the 
   // Check for button press (detect transition from HIGH to LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    delay(50);  
    servoControl = !servoControl;                         //Toggle the active servo
  } 
  lastButtonState=buttonState;                            // Update the last button state for next loop
  lcd.setCursor(0,0);                                     // Set LCD cursor to first row, first column
  int angle = map(analogRead(A0), 0, 1023, 0, 180);       // Read potentiometer value and map it to angle (0–180)
  // Control the active servo and display its status on LCD
  if (servoControl) {
    servo1.write(angle); 
    lcd.print("Servo-1 Active!");
  } else {
    servo2.write(angle);
    lcd.print("Servo-2 Active!");
  }
  lcd.setCursor(0,1);                     // Set LCD cursor to second row
  //Display Current Angle
  lcd.print("Angle: ");                    
   lcd.print(angle);
} 
