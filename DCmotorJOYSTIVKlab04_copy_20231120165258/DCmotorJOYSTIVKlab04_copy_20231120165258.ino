/*
DC motor controled by Joystick (speed&direction)

The Main Purpose:              
The main purpose was learn motor control by using to control the speed and direction of a DC motor/

The Main Theme:
The main theme was using the analog input from the joystick to control the analog output to the IN2 pin and the digital output to the EN and IN1 pin on the L293D motor driver.
The motor driver is what controls the speed and direction  amung other things of the DC motor it is attched to.
The analog input controls those pins specificaly because the IN2 pin controls speed  and the IN1 and EN1 pin control direction.
The IN2 pin is attached to an  output because it must output a range of voltages so the motor can run differnt speeds.
The  IN1 and EN1 are digital out puts becuase the direction depnding on which one receives power.
The analog value is converted into a spped value with a direction is by converting the analog value (0,1023) To (-255,255).
The range of [-255, 255] was chosen because it allows for controlof the speed and direction of a motor using PWM.
Positive values make the motor go forward, zero stops it, and negative values make it reverse.
This range works with Arduino's analogWrite.


*/

//Ppin numbers for motor control and joystick input are deifined below.

int speedPin = 5;             // Motor speed control pin.
int dir1 = 4;                 // Motor direction control pin 1.
int dir2 = 3;                 // Motor direction control pin 2.
int speed;                    // Variable for motor speed.
int joy_Y = A1;               // Joystick Y_ axis input pin.
int joyVal;                   // Variable to store ananlog value joystick value.

void setup() {
   
  pinMode(speedPin, OUTPUT);  // Set speedPin as an output.
  pinMode(dir1, OUTPUT);      // Set dir1 as an output.
  pinMode(dir2, OUTPUT);      // Set dir2 as an output.
  pinMode(joy_Y, INPUT);      // Set jPin as an input.
  Serial.begin(9600);         // Initialize serial communication at 9600 baud.
}

void loop() {
  
  joyVal = analogRead(joy_Y);    // Read the analog value from the pin y axis of joystick is attached to.

  Serial.println(joyVal);      // Print the analog joystick value to the serial monitor.

  // Check if the joystick value is less than 512 if so do whats within {}
  if (joyVal < 512) {
    digitalWrite(dir1, LOW);  // Set dir1 to LOW.
    digitalWrite(dir2, HIGH); // Set dir2 to HIGH.
    float speed = -255. / 512. * joyVal + 255.;  // Calculate motor speed based on the joystick value.
    analogWrite(speedPin, speed);  // Set the motor speed using PWM.
  }

  // Check if the joystick value is greater than or equal to 512 if so do what within {}
  if (joyVal >= 512) {
    digitalWrite(dir1, HIGH);      // Set dir1 to HIGH.
    digitalWrite(dir2, LOW);       // Set dir2 to LOW.
    float speed = (255. / 512.) * joyVal - 255.;  // Calculate motor speed based on the joysticks anolog value read.
    analogWrite(speedPin, speed);  //  Send 
  }
}