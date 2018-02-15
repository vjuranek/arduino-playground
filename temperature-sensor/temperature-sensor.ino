const int tempPin = A0;
const float tempBase = 22.0;

void setup() {
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}

void loop() {
  int tempVal = analogRead(tempPin);
  float voltage = (tempVal/1024.0) * 5.0;
  float temp = (voltage - 0.5) * 100;
  
  Serial.print("Temperature sensor value: ");
  Serial.print(tempVal);
  Serial.print(", volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  Serial.println(temp);

  if (temp < tempBase) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temp > tempBase && temp < (tempBase + 2)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temp > (tempBase + 2) && temp < (tempBase + 4)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temp > (tempBase + 6)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  delay(1000);
}
