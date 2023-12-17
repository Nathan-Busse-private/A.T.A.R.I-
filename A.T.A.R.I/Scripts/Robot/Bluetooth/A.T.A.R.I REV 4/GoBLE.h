#include <GoBLE.h>

#include <Metro.h>

#include <GoBLE.h>

//include libraries
#include <GoBLE.h>
#include <QueueArray.h>
#include <Servo.h>
#include <Metro.h>

//assign motor pins and direction pins
int speedPin_M1 = 5;     //M1 Speed Control
int speedPin_M2 = 6;     //Speed Control
int directionPin_M1 = 4;     //Direction Control
int directionPin_M2 = 7;     //M1 Direction Control

int joystickX, joystickY; //create joystick variables for goble

void setup() {   //the setup function runs once

Goble.begin(); //begin GoBLE
Serial.begin(115200); //serial communication speed
}

void loop() {  //the main loop runs forever (or until you power off the microcontroller or a component fails)

if (Goble.available()) { //check for a bluetooth connection to goBLE

  joystickX = Goble.readJoystickX(); //read joystick x value
  joystickY = Goble.readJoystickY(); //read joystick y value

  //use the serial monitor to debug
  //(x and y joystick values are from 0 - 255)


  //    Serial.print("Joystick Value: ");
  //    Serial.print(joystickX);
  //    Serial.print("  ");
  //    Serial.println(joystickY);

  if (joystickY > 196) { //if joystick y > 196 then turn right at speed 250
    Serial.println("turn right");
    carTurnRight(250, 250);
  }
  else if (joystickY < 64) { // //if joystick y < 64 then turn left at speed 250
    Serial.println("turn left");
    carTurnLeft(250, 250);
  }
  else if (joystickX > 196) { //if joystick x > 196 then go forward at speed 500
    Serial.println("move forward");
    carAdvance(500, 500);
  }
  else if (joystickX < 64) { //if joystick x <64 then go backward at speed 500
    Serial.println("move backward");
    carBack(500, 500);
  }
  else {
    carStop(); //or else stop
  }
}
}

//tank movement functions

void carStop() {                //  Motor Stop
digitalWrite(speedPin_M2, 0);
digitalWrite(directionPin_M1, LOW);
digitalWrite(speedPin_M1, 0);
digitalWrite(directionPin_M2, LOW);
}

void carTurnLeft(int leftSpeed, int rightSpeed) {       //Turn Left
analogWrite (speedPin_M2, leftSpeed);             //PWM Speed Control
digitalWrite(directionPin_M1, HIGH);
analogWrite (speedPin_M1, rightSpeed);
digitalWrite(directionPin_M2, LOW);
}

void carTurnRight(int leftSpeed, int rightSpeed) {     //Turn Right
analogWrite (speedPin_M2, leftSpeed);
digitalWrite(directionPin_M1, LOW);
analogWrite (speedPin_M1, rightSpeed);
digitalWrite(directionPin_M2, HIGH);
}

void carBack(int leftSpeed, int rightSpeed) {           //Move backward
analogWrite (speedPin_M2, leftSpeed);
digitalWrite(directionPin_M1, LOW);
analogWrite (speedPin_M1, rightSpeed);
digitalWrite(directionPin_M2, LOW);
}
void carAdvance(int leftSpeed, int rightSpeed) {         //Move forward
analogWrite (speedPin_M2, leftSpeed);
digitalWrite(directionPin_M1, HIGH);
analogWrite (speedPin_M1, rightSpeed);
digitalWrite(directionPin_M2, HIGH);
}
