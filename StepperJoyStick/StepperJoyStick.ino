

/*
  Stepper motor controlled by joystick

  Main Goal:
  The main goal was to control a stepper motor by using the Stepper.h library. with a joystick.
  To allow a analog input to control of four digital outputs that control the stepper motor.
  
  Main Theme:
  The main theme was using the library to allow the analog read from the joystick to control the digital outputs that can output analog values usin PWM.
  The functions and commands used fro this have been listed below.

  Stepper.h Functions and Commands:
  Stepper(steps, motorPin1, motorPin2, motorPin3, motorPin4)
  setSpeed(): Sets the speed of the stepper motor.
  step(steps): Moves the stepper motor a specified number of steps.
  steps:The amount of steps requuired to move the motor. Positive for forward, negative for backward.

  
*/
#include <Stepper.h>// Initializing Stepper.h library.

const int stepsPerRevolution = 2048;       // Define the number of steps per revolution for the stepper motor.
const int revolutionsPerMinute = 15;       // Define the desired revolutions per minute for the stepper motor.
const int joy_X = A1;                      // Define the analog pin connected to the x axis output.

Stepper myStepper(stepsPerRevolution, 2, 4, 3, 5);   // Create a Stepper object named myStepper, specifying the pins for motor control

void setup() {
  // put your main code here, to run repeatedly:


  myStepper.setSpeed(revolutionsPerMinute);         // Set the speed of the stepper motor in revolutions per minute
  Serial.begin(9600);                              // Initialize serial communication with a baud rate of 9600

}
void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("X-axis: ");// Print the exactly whats in "" to serial monitor.
  Serial.println(analogRead(joy_X)); // Print the X-axis analog reading to the serial monitor.

  int a = analogRead(joy_X); // Read analog input from the x axis of the joystick.

  // Check the X-axis reading and take actions accordingly
  if (a > 400 && a < 520) {
    // If X-axis reading is within a certain range that range being when its not moving, stop the stepper motor.
    for (int i = 2; i < 6; i++) {
      digitalWrite(i, LOW);  // Turn off the digital pins associated with the stepper motor.
    }
  } else if (a < 400) {
    // If X-axis reading is below a threshold, move the stepper motor forward.
    myStepper.setSpeed(revolutionsPerMinute);
    myStepper.step(30);  // Positive value for forward motion.
  } else if (a > 530) {
    // If X-axis reading is above a threshold, move the stepper motor forward.
    myStepper.setSpeed(revolutionsPerMinute);
    myStepper.step(30);  // Positive value for forward motion.
  }
}
