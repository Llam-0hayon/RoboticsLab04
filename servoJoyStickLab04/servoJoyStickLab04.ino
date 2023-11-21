
/*
 Joystick controllling servo

  Program Goal:
  The main goal of this program is to control a servo motor using a joystick. 
  The servo's angle is determined by the voltage it receives.
  Voltage can be controlled by controlling current. 
  The joystick essentallly being funtionin as two potentiometers (one for the X-axis the for the Y-axis) controls the resistance. 
  In this program, the servo is mapped to the Y-axis of the joystick,because inly one axis is available since i only have one servo. 
  Note that when the joystick is plugged into the breadboard, the axis may appear inverted. 
  The program utilizes the Servo.h library for servo motor control.

  Main Theme:
  Analog input controlling digital output. 
  The analog input from the joystick is used to control the servo motor's position.
  This shows the relationship between joystick movement, analog readings, and servo angles.
  It does this by:
  Having program reading the joystick's analog input, maping the values from anaolg values to an angle in degrees  with float variable and map function. 
  Then using Servo.h to move the joystick based on the angle given from the joystick. 
  Finally it prints the relevant values to the serial monitor.

  All Servo.h commands and functions:
  #include <Servo.h>: Includes the Servo library, allowing the use the functions and commands in this library.
  Servo Servo1;: Declares an object of the Servo class named Servo1SS. 
  Servo1.attach();: Attaches the Servo object to a pin on the Arduino.
  Servo1.write();: Sets the angle of the servo motorbased on the specified value.
  

*/

#include <Servo.h>//Includes the Servo library, allowing the use the functions and commands in this library.

Servo Servo1; //Declares an object of the Servo class named Servo1. 

int servoPin = 9;  // Define the pin for the servo signal.
int joyPin_Y = A0; // Define the analog input pin for the Y-axis of the joystick.

void setup() {
  // put your setup code here, to run once:
  
  Servo1.attach(servoPin);// Attach the servo to the specified pin.
  Serial.begin(9600);// Initialize serial communication at 9600 baud .

  pinMode(9, OUTPUT);// Set the servoPin as an OUTPUT.
  pinMode(A0, INPUT); // Set the joyPin_Y as an INPUT (analog).
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(joyPin_Y);          // Read the analog input from the joystick.
  float val = map(reading, 0, 1023, 0, 5000);     // Map the analog reading to a range in milivolts.
  float voltage = (val / 1000);                 // Calculating voltage in volts by dividng value in milivolts by 1000.
  int angle = map(reading, 0, 1023, 0, 180);   // Map the analog reading to the servo angle.
  Servo1.write(angle);                         // Set the servo angle based on the mapped value.

  Serial.print("Analog Read:"); // Prints exactly what's in "" on Serial Monitor.
  Serial.print(reading); // Print value of voltage to Serial Monitor.
  Serial.print("\t");// Prints Space to Serial Monitor.
  Serial.print("Voltage:"); // Prints exactly what's in "" on Serial Monitor.
  Serial.print(voltage);  // Print value of voltage to Serial Monitor.
  Serial.print("\t"); // Prints Space to Serial Monitor.
  Serial.print("Angle:"); // Prints exactly what's in "" on Serial Monitor.
  Serial.println(angle); // Print value of angle to Serial Monitor.ln makes it so that everything printed after this print, is printed on a new line every time code is looped.
}
