const int trigPin = 2;
const int echoPin = 3;
const int buzzerPin = 4;
const long timeoutMicroseconds = 20000;
const int minimumDistance = 6;

bool buzzerOn = false;
unsigned long previousMillis = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, timeoutMicroseconds);
  float distance = duration * 0.0343 / 2.0;

  if (distance > minimumDistance) {
    if (!buzzerOn) {
      buzzerOn = true;
      previousMillis = millis();
      tone(buzzerPin, 5000); // Play a tone of 1000 Hz
    }
  } else {
    if (buzzerOn) {
      buzzerOn = false;
      noTone(buzzerPin); // Stop the tone
    }
  }

  if (buzzerOn && (millis() - previousMillis >= 30000)) {
    buzzerOn = false;
    noTone(buzzerPin); // Stop the tone
    delay(30000); // Wait for 30 seconds
  }

  delay(100);
}