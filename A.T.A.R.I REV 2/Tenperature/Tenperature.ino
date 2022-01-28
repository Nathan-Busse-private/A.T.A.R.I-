/* 
 *  Blue = Cool (>35 C)
 *  
 *  Green = Warm (>75 C)
 *  
 *  Red = Hot (>=140 C)
 */


float tempC;
int tempPin = 0;
int redPin= 3;
int greenPin= 5;
int bluePin= 6;

int blueTemp= 0; int greenTemp= 0; int redTemp= 0;

void setup()
{
Serial.begin(9600); //opens serial port, sets data rate to 9600 bps
}

void loop()
{
tempC = analogRead(tempPin);           //read the value from the sensor
tempC = (5.0 * tempC * 100.0)/1024.0;  //convert the analog data to temperature
Serial.println((byte)tempC);             //send the data to the computer

if(tempC<0){
analogWrite(bluePin, 255);}
else if(tempC>0&&tempC<=45){
blueTemp= map(tempC, 0, 45, 255, 0);
analogWrite(bluePin, blueTemp);}
else if(tempC>35){ // Blue (Cool)
analogWrite(bluePin, 0);}

if(tempC<75){ 
analogWrite(greenPin, 0);}
else if(tempC>15&&tempC<=35){
greenTemp = map(tempC, 15, 35, 1, 254);
analogWrite(greenPin, greenTemp);}
else if(tempC>35&&tempC<=75){
greenTemp = map(tempC, 35, 75, 255, 0);
analogWrite(greenPin, greenTemp);}
else if(tempC>75){ // Green (Warm)
analogWrite(greenPin, 0);}

if(tempC<140){ 
analogWrite(redPin, 0);}
else if(tempC>=140){ // Red (Hot)
redTemp= map(tempC, 140, 90, 1, 255);
analogWrite(redPin, redTemp);}
else if(tempC>145){
analogWrite(redPin, 255);}

delay(200);   //wait 200 ms before sending new data
}
