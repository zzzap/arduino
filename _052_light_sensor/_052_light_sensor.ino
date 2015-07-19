#include <Servo.h>

Servo myServo;

const int sensorPin = A0;
const int servoPin = 3;

const int numReadings = 10;

int readings[numReadings];
int index = 0;
int total = 0;
int average;

int angle;

void setup() {
  myServo.attach(servoPin);
  
  Serial.begin(9600);
}

void loop() {
  // https://www.arduino.cc/en/Tutorial/Smoothing
  total = total - readings[index];
  
  readings[index] =  analogRead(sensorPin);
  total = total + readings[index];
  index = index + 1;
  
  if (index >= numReadings) {
    average = total / numReadings; 
    angle = map(average, 0, 1023, 0, 175);  // works from 0 to 50 *C
    myServo.write(angle); 

    index = 0;
    delay(100);  //delay after a series of readings
  }
  
  delay(1);  // delay between each reading
}
