#include <Arduino.h>
#include <EEPROM.h>

int addr = 44;
int sec = 0;

void setup(){ 
  Serial.begin(9600);
}

void loop(){
  
  sec = EEPROM.read(addr);
  float minutes = (float)sec / 60;
  Serial.print("Seconds: ");
  Serial.print(sec);
  Serial.print(", Minutes: ");
  Serial.println(minutes);
  delay(1000);
  exit(0);
}