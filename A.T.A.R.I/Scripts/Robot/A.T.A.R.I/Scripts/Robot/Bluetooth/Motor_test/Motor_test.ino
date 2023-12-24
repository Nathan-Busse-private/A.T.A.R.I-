int Enable1 = 5;
int Motor1_Pin1 = 6;
int Motor1_Pin2 = 7;

int Motor2_Pin1 = 8;
int Motor2_Pin2 = 9;
int Enable2 = 10;

int velocity = 0;  //Variable to control the speed of motor

#define wait 2000

void setup(){

//Setting the L298N, LED and RGB LED pins as output pins.
pinMode(Motor1_Pin1, OUTPUT);
pinMode(Motor1_Pin2, OUTPUT);
pinMode(Enable1, OUTPUT);
pinMode(Motor2_Pin1, OUTPUT);
pinMode(Motor2_Pin2, OUTPUT);
pinMode(Enable2, OUTPUT);

//Setting the enable and RGB LED pins as HIGH.
digitalWrite(Enable1, HIGH);
digitalWrite(Enable2, HIGH);
}

void loop() {

  velocity = 255;  //Full velocity
  analogWrite(Enable1, velocity);
  analogWrite(Enable2, velocity);

  // Forward
  digitalWrite(Motor2_Pin2, HIGH);
  digitalWrite(Motor2_Pin1, LOW);
  digitalWrite(Motor1_Pin1, LOW);
  digitalWrite(Motor1_Pin2, HIGH);
  delay(wait);

  // Back
  digitalWrite(Motor2_Pin2, LOW);
  digitalWrite(Motor2_Pin1, HIGH);
  digitalWrite(Motor1_Pin1, HIGH);
  digitalWrite(Motor1_Pin2, LOW);
  delay(wait);

  // Left
  digitalWrite(Motor1_Pin1, HIGH);
  digitalWrite(Motor1_Pin2, LOW);
  digitalWrite(Motor2_Pin1, LOW);
  digitalWrite(Motor2_Pin2, HIGH);
  delay(wait);

  // Right
  digitalWrite(Motor1_Pin1, LOW);
  digitalWrite(Motor1_Pin2, HIGH);
  digitalWrite(Motor2_Pin1, HIGH);
  digitalWrite(Motor2_Pin2, LOW);
  delay(wait);

  // Stop
  digitalWrite(Motor2_Pin2, LOW);
  digitalWrite(Motor2_Pin1, LOW);
  digitalWrite(Motor1_Pin2, LOW);
  digitalWrite(Motor1_Pin1, LOW);
  delay(wait);
}
