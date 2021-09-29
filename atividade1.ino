int led = 4;
int button = 3;
int led2 = 5;
unsigned long lastTime = 0;
bool lastState = false;

void ledBlink(int requestedTime) {
  while(true){
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
}

void setup(){
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  if(digitalRead(button)){

    delay(50);
    if(!digitalRead(button)){
      delay(50);

      if(!digitalRead(button)){
        ledBlink(500);
      }
    }
  }
}