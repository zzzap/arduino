int ladderPin = A0;
int piezoPin = 13;

int notes[] = {262, 294, 330, 349};

void setup() {
  Serial.begin(9600);
}

void loop() {
  int keyValue = analogRead(ladderPin);
  
  if (keyValue == 1023) {
    tone(piezoPin, notes[0]);
  }
  else if (keyValue >= 990 && keyValue <= 1010) {
    tone(piezoPin, notes[1]);
  }
  else if (keyValue >= 505 && keyValue <= 515) {
    tone(piezoPin, notes[2]);
  }
  else if (keyValue >= 5 && keyValue <= 10) {
    tone(piezoPin, notes[4]);
  }
  else {
    noTone(piezoPin);
  }
  
}
