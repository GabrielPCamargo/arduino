#include <EEPROM.h>

int dayAddr = 10;
int monthAddr = 11;
int yearAddr = 12;

void setup() {
  // put your setup code here, to run once:

   EEPROM.write(dayAddr, 9);
   EEPROM.write(monthAddr, 7);
   EEPROM.write(yearAddr, 3);
  
   int day = EEPROM.read(dayAddr);
   int month = EEPROM.read(monthAddr);
   int year = EEPROM.read(yearAddr);

   Serial.begin(9600);
   Serial.print("Data de nascimento: 0");
   Serial.print(day);
   Serial.print("/0");
   Serial.print(month);
   Serial.print("/0");
   Serial.print(year);
}

void loop() {
  // put your main code here, to run repeatedly:

}
