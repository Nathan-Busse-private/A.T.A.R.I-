#include <Servo.h>
#include <SlowMotionServo.h>

SMSSmooth myServo, myServo2, myServo3, myServo4; /* Servo with linear trajectory */
float target = 0.0;

void setup() {
  myServo.setInitialPosition(target);
  myServo.setMinMax(700, 4000);
   myServo2.setInitialPosition(target);
  myServo2.setMinMax(700, 4000);
  myServo3.setInitialPosition(target);
  myServo3.setMinMax(700, 4000);
  myServo4.setInitialPosition(target);
  myServo4.setMinMax(700, 4000);
  myServo.setPin(11); /* the servo is connected to pin 3 */
   myServo2.setPin(6);
   myServo3.setPin(9);
   myServo4.setPin(10);
}

void loop() {
  if (myServo.isStopped()) {
    target = 1.0 - target;
    myServo.goTo(target);
  }

  if (myServo2.isStopped()) {
    target = 1.0 - target;
    myServo2.goTo(target);
  }

  if (myServo3.isStopped()) {
    target = 1.0 - target;
    myServo3.goTo(target);
  }

  if (myServo4.isStopped()) {
    target = 1.0 - target;
    myServo4.goTo(target);
  }

  SlowMotionServo::update();
}
