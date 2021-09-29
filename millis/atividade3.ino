int led = 4;
int button = 3;
int led2 = 5;
unsigned long lastTimeLed = 0;
unsigned long lastTimeLed2 = 0;
bool lastStateLed = false;
bool lastStateLed2 = false;

void ledBlink(int ledPin, int requestedTime, unsigned long *lastTime, bool *lastState) {

  if((millis() - *lastTime) > requestedTime && *lastState == false){
    
    *lastState = true;
    digitalWrite(ledPin, HIGH);
    *lastTime = millis();
  }

  if((millis() - *lastTime) > requestedTime && *lastState == true){
    
    *lastState = false;
    digitalWrite(ledPin, LOW);
    *lastTime = millis();
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
          ledBlink(led, 200, &lastTimeLed, &lastStateLed);
          ledBlink(led2, 500, &lastTimeLed2, &lastStateLed2);

          if(digitalRead(button)){

            delay(50);
            if(!digitalRead(button)){
              delay(50);

              if(!digitalRead(button)){
                digitalWrite(led, LOW);
                digitalWrite(led2, LOW);
                break;
              }
            }
          }
        }
      }
    }
  }
}