#include <Servo.h>
#include <SlowMotionServo.h>

SMSLinear motor1,motor2, motor3, motor4; /* Servo with linear trajectory */
float target = 0.0;


void setup() {
  // put your setup code here, to run once:
  motor1.setInitialPosition(target);
  motor2.setInitialPosition(target);
  motor3.setInitialPosition(target);
  motor4.setInitialPosition(target);
  
  motor1.setMinMax(700, 2000);
  motor2.setMinMax(700, 2000);
  motor3.setMinMax(700, 2000);
  motor4.write(100);
  
  motor1.setPin(6); // claw
  motor2.setPin(9); // Right
  motor3.setPin(10); // Left
  motor4.setPin(11); // claw
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  if (motor1.isStopped()) {
    target = 1.0 - target;
    motor1.goTo(target);
  }
*/
  if (motor2.isStopped()) {
    target = 1.0 - target;
    motor2.goTo(target);
  }

  if (motor3.isStopped()) {
    target = 2.0 - target;
    motor3.goTo(target);
  }

  if (motor4.isStopped()) {
    target = 3.0 - target;
    motor4.goTo(target);
  }
  
  SlowMotionServo::update();
}
