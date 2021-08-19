#include <EEPROM.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 10; i++){
    byte val = EEPROM.read(i);
    Serial.print("Endereço ");
    Serial.print(i);
    Serial.print(" : ");
    Serial.println(val, DEC);
    delay(500);
  }
  
}
