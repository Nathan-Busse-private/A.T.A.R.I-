/*     
  * This code was written for this project 
  * to work effectively with the
  * instructions provided and should
  * not be tampered with unless stated otherwise.
  
  * Follow the instructions in the README file included in the project's 
  * Github repository: https://github.com/Nathan-Busse/All-Terrain-Arduino-Robotic-Interface
  
  * Created by Nathan-Busse
  * 
  * Don't you love coding and Arduino?
  * Me too! ;)
  * 
  * All bugs will be repaired by me "Nathan-Busse" YOU can to.
  * Mention them in the Issues tab.
  * 
  */

//including the libraries
#include <SoftwareSerial.h> // TX RX software library for bluetooth



//Initializing pins for bluetooth Module
int bluetoothTx = 2; // bluetooth tx to 2 pin
int bluetoothRx = 3; // bluetooth rx to 3 pin
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

//Steering Motor Pins  In my case.
int Enable1 = 5;

/* Swap pin values with your robot
 *  My steering for the robot is at the back and 
 *  the drive motors are at the front.
 */

int Motor1_Pin1 = 6;  
int Motor1_Pin2 = 7; 

// Drive Motor Pins  In my case  

/*Swap pin values with your robot
 *  My steering for the robot is at the back and 
 *  the drive motors are at the front.
 *  
 *  Excluding the enable pin
 */ 
int Motor2_Pin1 = 8; 
int Motor2_Pin2 = 9; 
int Enable2 = 10; 


char command ; //variable to store the data
int velocity = 0; //Variable to control the speed of motor

void setup() 
{       
  //Set the baud rate of serial communication and bluetooth module at same rate.
  Serial.begin(9600);  
  bluetooth.begin(9600);

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

void loop(){
  if(bluetooth.available() > 0){  //Checking if there is some data available or not
    command = bluetooth.read();   //Storing the data in the 'command' variable
    Serial.println(command);      //Printing it on the serial monitor
    
    //Change pin mode only if new command is different from previous.   
    switch(command){
    case 'F':  //Moving the Car Forward
      digitalWrite(Motor2_Pin2, HIGH);
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, HIGH);
      break;
    case 'B':  //Moving the Car Backward
      digitalWrite(Motor2_Pin2, LOW);
      digitalWrite(Motor2_Pin1, HIGH);
      digitalWrite(Motor1_Pin1, HIGH);
      digitalWrite(Motor1_Pin2, LOW);
      break;
    case 'L':  //Moving the Car Left
      digitalWrite(Motor1_Pin1, HIGH);
      digitalWrite(Motor1_Pin2, LOW);
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, HIGH);
      break;
    case 'R':   //Moving the Car Right
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, HIGH);  
      digitalWrite(Motor2_Pin1, HIGH);
      digitalWrite(Motor2_Pin2, LOW);
      break;
    case 'S':   //Stop
      digitalWrite(Motor2_Pin2, LOW);
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor1_Pin2, LOW);
      digitalWrite(Motor1_Pin1, LOW);
      break; 

    case 'I':  //Moving the Car Forward right
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, HIGH);
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, LOW);
      break; 
    case 'J':  //Moving the Car backward right
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, LOW);
      digitalWrite(Motor2_Pin1, HIGH);
      digitalWrite(Motor2_Pin2, LOW);
      break;        
    case 'G':  //Moving the Car Forward left
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, LOW);
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, HIGH);
      break; 
    case 'H':  //Moving the Car backward left
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, LOW);
      digitalWrite(Motor1_Pin1, HIGH);
      digitalWrite(Motor1_Pin2, LOW);
      break;

      
    
    case 'x': //Turn ON Everything

    break;
    case 'X': //Turn OFF Everything
      
    break;




    //Controlling the Speed of Car  
    default:  //Get velocity
      if(command=='q'){
        velocity = 255;  //Full velocity
        analogWrite(Enable1, velocity);
        analogWrite(Enable2, velocity);

      }
      else{ 
        //Chars '0' - '9' have an integer equivalence of 48 - 57, accordingly.
        if((command >= 48) && (command <= 57)){ 
          //Subtracting 48 changes the range from 48-57 to 0-9.
          //Multiplying by 25 changes the range from 0-9 to 0-225.
          velocity = (command - 48)*25;       
          analogWrite(Enable1, velocity);
          analogWrite(Enable2, velocity);

        }
      }
    }
  }
}
     