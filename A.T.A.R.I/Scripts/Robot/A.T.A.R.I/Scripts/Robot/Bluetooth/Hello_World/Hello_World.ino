#include <SoftwareSerial.h> // TX RX software library for bluetooth

//Initializing pins for bluetooth Module
int bluetoothTx = 2; // bluetooth tx to 2 pin
int bluetoothRx = 3; // bluetooth rx to 3 pin
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup() {
  Serial.begin(115200);  //initial the Serial
    bluetooth.begin(115200);

}

void loop() {
  if (bluetooth.available())  {
    bluetooth.write(bluetooth.read());//send what has been received
    Serial.println('hi');   //print line feed character
  }
}