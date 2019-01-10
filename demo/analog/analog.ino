/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/

// the setup routine runs once when you press reset:
  int STP = 4; 
    int DIR = 3; 

  bool s=true;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(STP,OUTPUT); 
  pinMode(DIR,OUTPUT); 
        digitalWrite(STP,HIGH); 
        digitalWrite(DIR,LOW); 

}
String tem="";
int count=10;
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  if(count<10){
    count++;
    tem+= String(voltage)+" ";
  }else{
    Serial.println(tem);
    count=0;
    tem="";
  }
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  delay(300);
  
  // print out the value you read:

  // waits for a second
}
