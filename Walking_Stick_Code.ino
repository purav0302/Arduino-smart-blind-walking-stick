int trigPin = 9;
int echoPin = 10;
int buzzer = 6;
int led = 5;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long time = pulseIn(echoPin, HIGH);
  int distance = time * 0.034 / 2;

  if (distance > 50 || distance == 0) {
    noTone(buzzer);
    digitalWrite(led, LOW);
  }
  else if (distance > 30) {
    beep(1);
  }
  else if (distance > 10) {
    beep(2);
  }
  else {
    beep(5);
  }
}

void beep(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(led, HIGH);
    tone(buzzer, 2000);
    delay(100);

    digitalWrite(led, LOW);
    noTone(buzzer);
    delay(150);
  }
}