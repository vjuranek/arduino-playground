const int greenLED = 9;
const int blueLED = 10;
const int redLED = 11;

const int greenSensor = A0;
const int blueSensor = A1;
const int redSensor = A2;

int redVal = 0;
int greenVal = 0;
int blueVal = 0;
int redSensorVal = 0;
int greenSensorVal = 0;
int blueSensorVal = 0;

void setup() {
  Serial.begin(9600);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  redSensorVal = analogRead(redSensor);
  delay(5);
  greenSensorVal = analogRead(greenSensor);
  delay(5);
  blueSensorVal = analogRead(blueSensor);

  redVal = redSensorVal/4;
  if (redVal < 200) {
    redVal = 0;
  }
  greenVal = greenSensorVal/4;
  if (greenVal < 200) {
    greenVal = 0;
  }
  blueVal = blueSensorVal/4;
  if (blueVal < 200) {
    blueVal = 0;
  }

  Serial.println("Sensor values\tLED PWM values:");
  
  Serial.print("\tred:\t");
  Serial.print(redSensorVal);
  Serial.print("\t");
  Serial.println(redVal);
  
  Serial.print("\tgreen:\t");
  Serial.print(greenSensorVal);
  Serial.print("\t");
  Serial.println(greenVal);
  
  Serial.print("\tblue:\t");
  Serial.print(blueSensorVal);
  Serial.print("\t");
  Serial.println(blueVal);
  
  analogWrite(redLED, redVal);
  analogWrite(greenLED, greenVal);
  analogWrite(blueLED, blueVal);

  delay(1000);
  
}
