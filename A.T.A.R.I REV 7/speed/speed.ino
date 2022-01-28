
/* 
 *  
 *I figured out how to slow down the servo when I thought of this scenario.
 *  
 * We all know that Servo motors are controlled by sending a PWM (pulse-width modulation) signal to the
signal line of the servo. The width of the pulses determines the position of the output
shaft right. When you send the servo a signal with a pulse width of 1.5 milliseconds (ms), the
servo will move to the neutral position (90 degrees). The min (0 degrees) and max (180
degrees) position typically correspond to a pulse width of 1 ms and 2 ms respectively and visa versa.

*/






#include <Servo.h>

unsigned long MOVING_TIME = 3000; // moving time is 3 seconds
unsigned long moveStartTime;

Servo motor1,motor2, motor3, motor4;
int degree1 = 100, degree2 = 100, degree3 = 15, degree4 = 180, degree5 = 1, degree6 = 50, degree7 = 100, degree8 = 90; ;

//const int speed = 2;

void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
motor1.attach (6); // Claw
motor2.attach (9); // Right
motor3.attach (10); // Left
motor4.attach (11);// Middle

 moveStartTime = millis(); // start moving

}

void loop() {
  // put your main code here, to run repeatedly: 

unsigned long progress = millis() - moveStartTime;

// How do I add all the servo movements to the parameter

  if (progress <= MOVING_TIME) {
    long angle = map(progress, 0, MOVING_TIME, degree1, degree5);// This is where I am stuck. 
    //When I try add degree1 to degree8 it throws an error saying to many arguments

    
  
motor1.write (angle); 
/* When I add "angle" to every object the arm freezes but when I only use "angle" once 
in this case "motor1.write" it works fine. This will slowly open and close the claw.
*/


motor2.write (degree2);       
                            
motor3.write (degree3);    
                           
motor4.write (degree4);

motor1.write (degree5);

motor2.write (degree6);

motor3.write (degree7);

motor4.write (degree8);


  }
}
