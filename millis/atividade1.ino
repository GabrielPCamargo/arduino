int led = 4;
int button = 3;
int led2 = 5;
unsigned long lastTime = 0;
bool lastState = false;

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

//Blinks the LED
void ledBlink(int requestedTime) {
    if((millis() - lastTime) > requestedTime && lastState == false){
      
      lastState = true;
      digitalWrite(led, HIGH);
      lastTime = millis();
    }

    if((millis() - lastTime) > requestedTime && lastState == true){
      
      lastState = false;
      digitalWrite(led, LOW);
      lastTime = millis();
    }
}

void setup(){
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  if(onClickedButton(button)){ //If the button was pressed then enter a infinite loop to blink the LED.

    while(true){
      ledBlink(500);
      if(onClickedButton(button)){ //If the button was pressed again then turn the LED off and get out of the loop.
        pinMode(led, LOW);
        break;
      }
    }
  }
}