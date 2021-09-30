int led = 4;
int button = 3;
int led2 = 5;
unsigned long lastTime = 0;
bool lastState = false;
bool powerOff = false;

//Return true only if the button was pressed and it's not debounce effect.
bool onClickedButton(int button) {
  if(digitalRead(button)){
    delay(50);
    if(!digitalRead(button)){
      delay(50);
        if(!digitalRead(button)){
          return true;
        }
    }
  }

  return false;
}

//Blink a LED
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
  if(onClickedButton(button)){ //Check if the button was pressed

    while(true){               //Creates a infinite loop in order to blink the LED and check if the button was pressed.
      ledBlink(led, 200);       
      if(onClickedButton(button)){  //If button was pressed for the second time turn led off and blinks led2. Also check if the button was pressed again

        digitalWrite(led, LOW);
        while(true) {
          ledBlink(led2, 300);
          
          if(onClickedButton(button)){ //If the button was pressed again then it is supossed to power off, turning de led2 off and getting out of the loop.
            powerOff = true;
            digitalWrite(led2, LOW);
            break;
          }
        }
      }

      if(powerOff){ //if is in power off mode, it will get out of the first loop and reset power off mode to false.
        powerOff = false;
        break;
      }
    }
  }
}