#include <ArduinoJson.h>

// Global variables for communication 
int com = 0;              // Represents the communication number for message dropping handling
int leftJoyx = 0;         // left analog joystick x value
int leftJoyy = 0;         // left analog joystick y value
int rightJoyx = 0;        // right analog joystick x value
int rightJoyy = 0;        // right analog joystick y value

// Communication Protocol functionality
//"{"com": 0,"leftJoyX": 0,"leftJoyY": 0,"rightJoyX": 0,"rightJoyY": 0}"

void sendResponse(){
  // Json incoding for the current string, use this url to determinefurute strings
  // https://arduinojson.org/v6/assistant/
  StaticJsonDocument<48> doc;
  doc["COM"] = 0;
  doc["leftJoyX"] = leftJoyx;
  doc["leftJoyY"] = leftJoyy;
  doc["rightJoyX"] = rightJoyx;
  doc["rightJoyY"] = rightJoyy;

  size_t jsonBytes = serializeJson(doc, Serial1);
  size_t jsonByte = serializeJson(doc, Serial);
}

int Com(int comCNT){
  if (com+1 == comCNT){
    com++;
  }
  else{
    // Implement some sort of error throw here
  }
  return com;
}

//---------------PINOUT-----------//
#define leftJoyX A0
#define leftJoyY A1 
#define rightJoyX A2
#define rightJoyY A3

void joyReadOut(){
  leftJoyx = analogRead(leftJoyX);
  leftJoyy = analogRead(leftJoyY);
  rightJoyx = analogRead(rightJoyX);
  rightJoyy = analogRead(rightJoyY);
}

void setup() {
  Serial.begin(9600);     //Debugging serial Monitor
  Serial1.begin(9600);    //Raspberry Pi connection
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    Serial.print("You sent me: ");
    Serial.println(data);
  }
  Serial1.println("connection established");
  joyReadOut();
  sendResponse();
  delay(100);
}