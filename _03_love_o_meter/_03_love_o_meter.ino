const int sensorPin = A0;
const float baselineTemp = 23;

void setup() {
  Serial.begin(9600);
  
  for (int pinNumber = 3; pinNumber < 6; pinNumber ++ ) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
  
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal/1024.0) * 5.0;
  float temperature = (voltage - .5) * 100;
  
  if (temperature < baselineTemp + 2) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 3) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else if (temperature >= baselineTemp + 3 && temperature < baselineTemp + 4) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }
  else if (temperature >= baselineTemp + 4) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
  else {
    delay(10);
  }
  
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees: ");
  Serial.println(temperature);
}
