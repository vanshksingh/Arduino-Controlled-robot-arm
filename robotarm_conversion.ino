#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int ledPin = 13;
char command;
int pos1 = 90; // Initial position for servo1
int pos2 = 90; // Initial position for servo2
int pos3 = 90; // Initial position for servo3
int pos4 = 90; // Initial position for servo4
int pos5 = 90; // Initial position for servo5

void setup() {
  servo1.attach(9); // Attach servo1 to pin 9
  servo2.attach(10); // Attach servo2 to pin 10
  servo3.attach(11); // Attach servo3 to pin 11
  servo4.attach(12); // Attach servo4 to pin 12
  servo5.attach(6);  // Attach servo5 to pin 6
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication
  Serial.println("Arduino is ready.");
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read(); // Read the incoming command from the computer
    executeCommand(command);
  }
}

void executeCommand(char cmd) {
  switch (cmd) {
    case 'A':
      moveServo(servo1, pos1, 5); // Increase servo1 angle by 5 degrees
      break;
    case 'B':
      moveServo(servo1, pos1, -5); // Decrease servo1 angle by 5 degrees
      break;
    case 'C':
      // Implement similar control for other servos (servo2, servo3, servo4, servo5)
      break;
    case 'L':
      digitalWrite(ledPin, HIGH); // Turn on LED
      break;
    case 'l':
      digitalWrite(ledPin, LOW); // Turn off LED
      break;
    default:
      // Invalid command, do nothing
      break;
  }
}

void moveServo(Servo &servo, int &position, int increment) {
  position = constrain(position + increment, 0, 180);
  servo.write(position);
}
