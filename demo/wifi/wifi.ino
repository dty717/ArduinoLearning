#include <SoftwareSerial.h>
#define RX 10
#define TX 11
String AP = "@PHICOMM_FC";       // CHANGE ME
String PASS = "52180362"; // CHANGE ME
String API = "1VXGP9GVNAKAD0E7";   // CHANGE ME
String HOST = "192.168.2.101";
String PORT = "8080";
String field = "field1";
int countTrueCommand;
int countTimeCommand; 
boolean found = false; 
int valSensor = 1;
SoftwareSerial esp8266(RX,TX); 
 
  
void setup() {
  Serial.begin(9600);
  esp8266.begin(9600);
  delay(3000);
  
  sendCommand("AT",5,"OK");
  sendCommand("AT+CWMODE=1",5,"OK");
  //AT+CWJAP="@PHICOMM_FC","52180362"
  sendCommand("AT+CWJAP=\""+ AP +"\",\""+ PASS +"\"",20,"OK");
  sendCommand("AT+CIPMUX=1",5,"OK");
}
void loop() {
 //valSensor = getSensorData();
 //String getData = "GET /test?api_key="+ API +"&"+ field +"="+String(valSensor);
 if (esp8266.available()) {
    String readString=esp8266.readString();
    Serial.print(readString);
    int ipd=readString.indexOf("+IPD,");
    if(ipd!=-1){
        String str=readString.substring(ipd+5);
        ipd=str.indexOf(":");
        if(ipd!=-1){
          String target=str.substring(ipd+1,ipd+1+str.substring(str.indexOf(",")+1,ipd).toInt());
          Serial.println("\nreadString:"+target+"??");        
        }
    }
  }
  if (Serial.available()) {
    esp8266.write(Serial.read());
  }
 
/* sendCommand("AT+CIPMUX=1",5,"OK");
 sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
 sendCommand("AT+CIPSEND=0," +String(getData.length()+4),4,">");
 esp8266.println(getData);delay(1500);countTrueCommand++;
 sendCommand("AT+CIPCLOSE=0",5,"OK");*/
}
int getSensorData(){
  return random(1000); // Replace with 
}
void sendCommand(String command, int maxTime, char readReplay[]) {
  Serial.print(countTrueCommand);
  Serial.print(". at command => ");
  Serial.print(command);
  Serial.print(" ");
  while(countTimeCommand < (maxTime*1))
  {
    esp8266.println(command);//at+cipsend
    if(esp8266.find(readReplay))//ok
    {
      found = true;
      break;
    }
  
    countTimeCommand++;
  }
  
  if(found == true)
  {
    Serial.println("OYI");
    countTrueCommand++;
    countTimeCommand = 0;
  }
  
  if(found == false)
  {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }
  
  found = false;
 }
