    /*
      e-Gizmo Microstep Driver Sample code
      *""""Wiring connections:"""*
       Gizduino MCU  to  Microstep
         D3  -------------> DIR
         D4  -------------> STP/CLK
         GND -------------> GND
         +5V -------------> VIN
      by e-Gizmo Mechatronix Central
      http://www.e-gizmo.com
      February 18, 2016
     */
/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/

String tem="";
int count=10;
// the loop routine runs over and over again forever:
  //Pin assignments
  int STP = 4; 
  int DIR = 3; 
  int delay_ms = 250;
  int delay_time = 10;
    void setup() {
        Serial.begin(9600);

      //make the pins as an output
      pinMode(STP,OUTPUT); 
      pinMode(DIR,OUTPUT);
    }
    bool running=true;
    void loop() {
        
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  if(voltage<1.5){
      running=false;
  }
      Serial.println(voltage);

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  delay(100);

  // print out the value you read:

  // waits for a second
    if(running){
      digitalWrite(DIR,HIGH); // The motor moves in a particular direction
      // makes 100000 pulses
      for(int x = 0; x < 10000; x++) {
        digitalWrite(STP,HIGH); 
        delayMicroseconds(delay_ms); 
        digitalWrite(STP,LOW); 
        delayMicroseconds(delay_ms); 
      }
    }
      /*
      delay(delay_time); // One second delay
      
      digitalWrite(DIR,HIGH); //Changes the direction
      // makes 10000 pulses
      for(int x = 0; x < 10000; x++) {
        digitalWrite(STP,HIGH);
        delayMicroseconds(delay_ms);
        digitalWrite(STP,LOW);
        delayMicroseconds(delay_ms);
      }
      delay(delay_time);
      */
    }
