int redpin = 11; // select the pin for the red LED
int bluepin =12; // select the pin for the  blue LED
int greenpin =4; // select the pin for the green LED

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  
    analogWrite(bluepin, 255);
    analogWrite(redpin, 255);
    analogWrite(greenpin, 255);
    delay(1000); 
  
  
    analogWrite(bluepin, 0);
    analogWrite(redpin, 0);
    analogWrite(greenpin, 0);
        delay(1000); 
  }
