#include <Arduino.h>
#include <EEPROM.h>

int addr = 44;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Segundo: ");
  Serial.println(val);
  EEPROM.write(addr, val);
  val++;
  delay(1000);
}