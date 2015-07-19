#include <Servo.h>

Servo myServo;

const int tempSensorPin = A0;
const int servoPin = 3;

const int numReadings = 50;

float readings[numReadings];
int index = 0;
float total = 0;
float average;

int tempSensorValue;
float voltage;
float temperature;

int angle;

void setup() {
  myServo.attach(servoPin);
  
  Serial.begin(9600);
}

void loop() {
  // https://www.arduino.cc/en/Tutorial/Smoothing
  total = total - readings[index];
 
  tempSensorValue = analogRead(tempSensorPin);
  voltage = (tempSensorValue / 1024.0) * 5.0;
  temperature = (voltage - .5) * 100;
  
  readings[index] = temperature;
  
  total = total + readings[index];
  index = index + 1;
  
  if (index >= numReadings) {
    average = total / numReadings; 
    angle = map(average, 0, 50, 0, 175);  // works from 0 to 50 *C
    myServo.write(angle); 
    
    index = 0;
    delay(500);  //delay after a series of readings
  }
  
  delay(3);  // delay between each reading
}
