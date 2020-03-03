const int redIn = 2;
const int blueIn = 3;
const int greenIn = 4;

const int redPin = 9;
const int bluePin = 10;
const int greenPin = 11;

int pressedRed = 0;
int pressedBlue = 0;
int pressedGreen = 0;

void setup() {
  Serial.begin(9600);

  pinMode(redIn, INPUT);
  pinMode(blueIn, INPUT);
  pinMode(greenIn, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {

  if (digitalRead(redIn)) {
    pressedRed = pressedRed + 32;
    if (pressedRed > 255) {
      pressedRed = 0;
    }
  }

  if (digitalRead(blueIn)) {
    pressedBlue = pressedBlue + 32;
    if (pressedBlue > 255) {
      pressedBlue = 0;
    }
  }

  if (digitalRead(greenIn)) {
    pressedGreen = pressedGreen + 32;
    if (pressedGreen > 255) {
      pressedGreen = 0;
    }
  }

  delay(100);
  
  analogWrite(redPin, pressedRed);
  analogWrite(bluePin, pressedBlue);
  analogWrite(greenPin, pressedGreen);
}
