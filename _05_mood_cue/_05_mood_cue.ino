#include <Servo.h>

Servo myServo;

const int potPin = A0;
const int servoPin = 3;

int potVal;
int angle;

void setup() {
  myServo.attach(servoPin);
  
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  angle = map(potVal, 0, 1023, 0, 175);
  
  myServo.write(angle);
  delay(15);
}
