
  
  //Hopper Robot Code Basic Code 2.0 with Serial Read
  
  const int buttonPin=2;
  int buttonState = 0;
  int incomingByte = 0;
  int pulsems=900; //pulse width for the motor 900stand by, 1400 top speed 
  int pulsestandby=900;
void setup()
{
  pinMode(buttonPin,INPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  buttonState=digitalRead (buttonPin);
  
  if (Serial.available() > 0) {
    incomingByte = Serial.parseInt(); // read serial input and change pulse width
    pulsems=incomingByte;
    Serial.println(pulsems);}
    
  if (buttonState== HIGH) {  
  digitalWrite(3, HIGH);
  delayMicroseconds(pulsems); 
  digitalWrite(3, LOW);
  delayMicroseconds(20000 - pulsems);
  }
  else{
  digitalWrite(3, HIGH);
  delayMicroseconds(pulsestandby); // Approximately 10% duty cycle @ 1KHz
  digitalWrite(3, LOW);
  delayMicroseconds(20000 - pulsestandby);} 
}
