int switchState = LOW;

void setup() {
  pinMode(2, INPUT);  // switch
  pinMode(3, OUTPUT);  // green
  pinMode(4, OUTPUT);  // red
  pinMode(5, OUTPUT);  // red
}

void loop() {
  switchState = digitalRead(2);
  
  // Button is not pressed
  if (switchState == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else {  // Button is pressed
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    
    delay(500);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(750);
  }

}
