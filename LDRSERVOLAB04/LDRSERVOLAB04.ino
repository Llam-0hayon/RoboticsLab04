/*
  Servo LDR

  Program Goal:
  The Main Goal of this program is to control the angle of a servo motor with an LDR(light detecting resistor). 
  Esentialy making the motor move depending on the amount of light the sensor detectects.
  An LDR is a varriable resistor whos resistance changes based on the amount of light it detects.
  
  Main Theme:
  The main theme of this program is controlling a servo motor based on the readings from from the LDR. 
  This is done by converting the analog reading received by the analog input LDR is attached to from analog values to degrees using  the map funtion.
  Then using Servo.h libraries we move the servo to that angle.
  The brighter it is the less resistance and the greater the angle.
  Essentially controlling the voltage outputed byy controlling the amount inputed via the resistance we are able to control the angle.
  making it so that the analog input controls the didgital output.
 
  All Servo.h commands and functions:
  - #include <Servo.h>: Includes the Servo library, enabling the use of functions and commands within this library.
  - Servo Servo1;: Declares an object of the Servo class named Servo1.
  - Servo1.attach();: Attaches the Servo object to a specified pin on the Arduino.
  - Servo1.write();: Sets the angle of the servo motor based on the specified value.
*/

#include <Servo.h>//Includes the Servo library, allowing the use the functions and commands in this library.

Servo Servo1; //Declares an object of the Servo class named Servo1. 

int servoPin = 9;  // Define the pin for the servo signal.
int ldr = A0; // Define the analog input pin for the LDR.
float pullUpResistor = 1000.0;// Define the pull-up resistor value.


void setup() {
  // put your setup code here, to run once:
  
  Servo1.attach(servoPin);// Attach the servo to the specified pin.
  Serial.begin(9600);// Initialize serial communication at 9600 baud .

  pinMode(9, OUTPUT);// Set the servoPin as an OUTPUT.
  
}

void loop() {
  //put your main code here, to run repeatedly:
  int reading = analogRead(ldr );                 // Read the analog input from the LDR.
  float val = map(reading, 0, 1023, 0, 5000);     // Map the analog reading to a range in milivolts.
  float voltage = (val / 1000);                   // Calculating voltage in volts by dividng value in milivolts by 1000.
  int angle = map(reading, 0, 1023, 0, 180);      // Map the analog reading to the servo angle.

  float ldrResistance = (pullUpResistor * (5.0 - voltage)) / voltage;  // Calculating LDR resistance using Ohms law.
  
  Servo1.write(angle);// Set the servo angle based on the mapped value.
  
  Serial.print("Analog Read:");    // Prints exactly what's in "" on Serial Monitor.
  Serial.print(reading);           // Print value of reading to serila monitor.
  Serial.print("\t");              // Prints Space to Serial Monitor.
  Serial.print("Voltage:");        // Prints exactly what's in "" on Serial Monitor.
  Serial.print(voltage);           // Print value of voltage to Serial Monitor.
  Serial.print("Volts");           // Prints exactly what's in "" on Serial Monitor.
  Serial.print("\t");              // Prints Space to Serial Monitor.
  Serial.print("Angle:");          // Prints exactly what's in "" on Serial Monitor.
  Serial.print(angle);             // Print value of angle to Serial Monitor.
  Serial.print("\t");              // Prints Space to Serial Monitor.
  Serial.print("LDR Resistance :");// Prints exactly what sin "" to Serial Monitor.
  Serial.print(ldrResistance);     // Prints Value of ldrResistance to Serial Monitor.
  Serial.println("Ohms");          // Prints exactly whats in to Serial Monitor.ln makes it so that everything printed after this print, is printed on a new line every time code is looped.
  
         

}






















