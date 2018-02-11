
int switchState = LOW;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  if (switchState == LOW) {
    switchState = digitalRead(2);
    
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);

    delay(1000);

    digitalWrite(3, LOW);

    delay(1000);
  } else {
    digitalWrite(3, LOW);
    
    for (int i = 0; i < 5; i++) { 
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);

      delay(1000);

      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);

      delay(1000);
    }

    switchState = LOW;
  }

}
