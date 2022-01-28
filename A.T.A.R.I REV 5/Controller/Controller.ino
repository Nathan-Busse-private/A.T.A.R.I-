int xAxis, yAxis;

void setup() {
  Serial.begin(38400);
}

void loop() {
  xAxis = analogRead(A0);
  yAxis = analogRead(A1);
  Serial.write('F'); 
  Serial.write('B');
  delay(20);
}
