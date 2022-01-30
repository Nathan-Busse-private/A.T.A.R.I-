#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display


int incomingByte = 2
;
int MA1 =  12;     // Motor A
int MA2 =  9;      // Motor A
int PWM_A =10;     // Speed PWM Motor A
int MB1 =  13;     // Motor B
int MB2 =  8;      // Motor B
int PWM_B =11;  // Speed PWM Motor B

//int horn_Buzz = 4;
//boolean horn = false;
boolean lightFront = false;

int command;   

//Int to store app command state.

int speedCar = 255;  
int speedCarM = 255;// 50 - 255.

// defines variables
long duration;
int distance;
int safetyDistance;

int period = 300; // Delay in milliseconds for screen
int safe = 300;
unsigned long time_now = 5000;

void setup() {

pinMode(MA1, OUTPUT);   //Motor A1
pinMode(MA2, OUTPUT);   //Motor A2
pinMode(PWM_A, OUTPUT); //Speed PWM Motor A
pinMode(MB1, OUTPUT);   //Motor B1
pinMode(MB2, OUTPUT);   //Motor B2
pinMode(PWM_B, OUTPUT); //Speed PWM Motor 

  lcd.clear();
  lcd.init();// initialize the lcd 
  lcd.backlight();// Backlight ON
  
  Serial.begin(9600);
  lcd.setCursor(5,19);// 2nd column,1st row
  lcd.print(" Powering On! ");

  delay(2000);
  lcd.clear();
  lcd.setCursor(5,19);// 1st column,3nd row
  lcd.print(" Booting Up ");
  
  delay(2000);
  lcd.clear();
  lcd.setCursor(5,19);
  lcd.println(" A.T.A.R.I ");

  delay(2000);
  lcd.clear();
  lcd.setCursor(5,19);
  lcd.println(" REV 11 ");

  delay(2000);
  lcd.clear();
  lcd.setCursor(19,2);//
  //lcd.setCursor(19,12);   
  lcd.print(" Made by Nathan Busse ");
  
  delay(2000);
  lcd.clear();
  lcd.setCursor(5,19);
  lcd.print(" I am ready ");
  delay(2000);

  lcd.clear();
  lcd.noBacklight();
}
  
void loop() {

// Failsafe when robot disconnects
// Time declaration for screen to prevent strobing

 lcd.clear();
 
 if(millis() > time_now + safe + period){
        time_now = millis();
        
        digitalWrite(MA1, LOW);
        digitalWrite(MA2, LOW);
        analogWrite(PWM_A, 0);
        digitalWrite(MB1, LOW);
        digitalWrite(MB2, LOW);
        analogWrite(PWM_B, 0); 
        lcd.noBacklight();
/*
 if(millis() > time_now + period){
        time_now = millis();        
        lcd.noBacklight();
    }
    
 /*
if(millis() > time_now + period){
        time_now = millis();
 
 lcd.noBacklight();
}
*/

}
if (Serial.available() > 0) {
  lcd.clear(); 
lcd.setCursor(5,12);
   lcd.backlight(); //Backlight is on
  lcd.println(" CONNECTED!!! ");
  
  
incomingByte = Serial.read();
}
switch (incomingByte)
{
case '0':speedCar = 100;break;
case '1':speedCar = 115;break;
case '2':speedCar = 130;break;
case '3':speedCar = 145;break;
case '4':speedCar = 160;break;
case '5':speedCar = 175;break;
case '6':speedCar = 190;break;
case '7':speedCar = 205;break;
case '8':speedCar = 220;break;
case '9':speedCar = 255;break; 
speedCar; 

{
case 'S':
      
Stop(1);
Serial.println("Stop");
}
break;

case 'F':
     
{
Forward(1);
//lightFront;

Serial.println("Forward");
}
break;
case 'B':
{
Backward(1);
Serial.println("Backward");
}
break;
case 'R':
{
turnRight(1);
Serial.println("turn Right");
}
break;
case 'L':
{
turnLeft(1);
Serial.println("turn Left");

}

break;
case 'I':
{
forwardRight(1);
Serial.println("turn Right");
}

break;
case 'J':
{
backRight(1);
Serial.println("turn Right");
}

break;
case 'G':
{
forwardLeft(1);
Serial.println("turn Left");
}

break;
case 'H':
{
backLeft(1);
Serial.println("turn Left");
}
}
}
void Forward(int time)
{
digitalWrite(MA1, HIGH);
digitalWrite(MA2, LOW);
analogWrite(PWM_A, speedCar);
digitalWrite(MB1, HIGH);
digitalWrite(MB2, LOW);
analogWrite(PWM_B, speedCar);
delay(time);
}

void Backward(int time)
{
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
analogWrite(PWM_A, speedCar);
digitalWrite(MB1, LOW);
digitalWrite(MB2, HIGH);
analogWrite(PWM_B, speedCar);
delay(time);
}

void turnLeft(int time)
{
digitalWrite(MA1, HIGH);
digitalWrite(MA2, LOW);
analogWrite(PWM_A, speedCar);
digitalWrite(MB1, LOW);
digitalWrite(MB2, HIGH);
analogWrite(PWM_B,speedCar);
delay(time);
}

void turnRight(int time)
{
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
analogWrite(PWM_A, speedCar);
digitalWrite(MB1, HIGH);
digitalWrite(MB2, LOW);
analogWrite(PWM_B, speedCar);
delay(time);
}

void forwardRight (int time)
{
digitalWrite (MB1, HIGH);
digitalWrite (MB2, LOW);
analogWrite(PWM_B, 255);
digitalWrite (MA1, LOW);
digitalWrite (MA2, LOW);
analogWrite(PWM_A, 0);
}

void backRight (int time)
{
digitalWrite (MB1, LOW);
digitalWrite (MB2, HIGH);
analogWrite(PWM_B, 255);
digitalWrite (MA1, LOW);
digitalWrite (MA2, LOW);
analogWrite(PWM_A, 0);
}

void forwardLeft (int time)
{
digitalWrite (MB1, LOW);
digitalWrite (MB2, LOW);
analogWrite(PWM_B, 0);
digitalWrite (MA1, HIGH);
digitalWrite (MA2, LOW);
analogWrite(PWM_A, 255);
}

void backLeft (int time)
{
digitalWrite (MB1, LOW);
digitalWrite (MB2, LOW);
analogWrite(PWM_B, 0);
digitalWrite (MA1, LOW);
digitalWrite (MA2, HIGH);
analogWrite(PWM_A, 255);
}

void Stop(int time)
{
digitalWrite(MA1, LOW);
digitalWrite(MA2, LOW);
analogWrite(PWM_A, 0);
digitalWrite(MB1, LOW);
digitalWrite(MB2, LOW);
analogWrite(PWM_B, 0);
delay(time);
}
