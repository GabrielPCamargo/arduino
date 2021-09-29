int led = 4;
int button = 3;
int led2 = 5;
unsigned long lastTime = 0;
bool lastState = false;

void ledBlink(int ledPin, int requestedTime) {
  if((millis() - lastTime) > requestedTime && lastState == false){
    
    lastState = true;
    digitalWrite(ledPin, HIGH);
    lastTime = millis();
  }

  if((millis() - lastTime) > requestedTime && lastState == true){
    
    lastState = false;
    digitalWrite(ledPin, LOW);
    lastTime = millis();
  }
}

void setup(){
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  if(digitalRead(button)){

    delay(50);
    if(!digitalRead(button)){
      delay(50);

      if(!digitalRead(button)){
        while(true) {
          ledBlink(led, 200);

          if(digitalRead(button)){

            delay(50);
            if(!digitalRead(button)){
              delay(50);

              if(!digitalRead(button)){
                digitalWrite(led, LOW);
                while(true) {
                  
                  ledBlink(led2, 300);

                  
                }
              }
            }
          }
        }
      }
    }
  }
}