#include <Servo.h>

const int ledPin = 13;
const int buttonPin = 2;
const int xPin = A0;
const int yPin = A1;

Servo xServo;
Servo yServo;

int buttonState = 0;
int lastButtonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  xServo.attach(9);
  yServo.attach(10);

  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    if (buttonState == LOW) { // Switch is active low
      int colorIndex = random(10); // choose a random color index
      Serial.println(colorIndex);
      digitalWrite(ledPin, HIGH); // light up the LED
    } else {
      digitalWrite(ledPin, LOW);
    }
    lastButtonState = buttonState;
  }

  int x = analogRead(xPin);
  int y = analogRead(yPin);

  int mappedX = map(x, 0, 1023, 0, 800);
  int mappedY = map(y, 0, 1023, 0, 800);

  Serial.print(mappedX);
  Serial.print(",");
  Serial.println(mappedY);

  delay(20);

}
