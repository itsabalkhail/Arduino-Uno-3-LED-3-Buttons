
bool led1State = false;
bool led2State = false;
bool led3State = false;

bool lastButton1 = false;
bool lastButton2 = false;
bool lastButton3 = false;

void setup() {
  pinMode(7, INPUT);
  pinMode(4, INPUT);
  pinMode(2, INPUT);
  
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(8, LOW);
}

void loop() {
  bool currentButton1 = digitalRead(7);
  bool currentButton2 = digitalRead(4);
  bool currentButton3 = digitalRead(2);
  
  if (currentButton1 == HIGH && lastButton1 == LOW) {
    led1State = !led1State;
    digitalWrite(13, led1State);
    delay(50);
  }
  
  if (currentButton2 == HIGH && lastButton2 == LOW) {
    led2State = !led2State;
    digitalWrite(12, led2State);
    delay(50);
  }
  
  if (currentButton3 == HIGH && lastButton3 == LOW) {
    led3State = !led3State;
    digitalWrite(8, led3State);
    delay(50);
  }
  
  lastButton1 = currentButton1;
  lastButton2 = currentButton2;
  lastButton3 = currentButton3;
}