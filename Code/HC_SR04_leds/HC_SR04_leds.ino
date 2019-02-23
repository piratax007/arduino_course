const int echoPin = 2;
const int trigPin = 3;

float duration, distance;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  // LEDs
  for (int i = 9; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = 0.034 * duration / 2;

  int leds = detection(distance);

  switch (leds) {
    case 1:
      digitalWrite(9, HIGH);
      for (int i = 10; i < 14; i++) {
        digitalWrite(i, LOW);
      }
      break;
    case 2:
      for (int i = 9; i < 11; i++) {
        digitalWrite(i, HIGH);
      }
      for (int i = 11; i < 14; i++) {
        digitalWrite(i, LOW);
      }
      break;
    case 3:
      for (int i = 9; i < 12; i++) {
        digitalWrite(i, HIGH);
      }
      for (int i = 12; i < 14; i++) {
        digitalWrite(i, LOW);
      }
      break;
    case 4:
      for (int i = 9; i < 13; i++) {
        digitalWrite(i, HIGH);
      }
      digitalWrite(13, LOW);
      break;
    case 5:
      for (int i = 9; i < 14; i++) {
        digitalWrite(i, HIGH);
      }
      break;
    default:
      for (int i = 9; i < 14; i++) {
        digitalWrite(i, LOW);
      }
  }
}

int detection(float d) {
  int ledIndicator = 0;
  if (d < 5) {
    ledIndicator = 5;
  } else if (d > 5 && d < 10) {
    ledIndicator = 4;
  } else if (d > 10 && d < 15) {
    ledIndicator = 3;
  } else if (d > 15 && d < 20) {
    ledIndicator = 2;
  } else if (d > 20) {
    ledIndicator = 1;
  }

  return ledIndicator;
}
