// Constants for Ultrasonic Sensor Pins
const int trigPin = 2;
const int echoPin = 3;

// Constant for the Buzzer Pin
const int buzzerPin = 4;

// Constants for Ultrasonic Sensor Parameters
const long timeoutMicroseconds = 20000;  // Maximum time to wait for echo signal (in microseconds)
const int minimumDistance = 6;           // Minimum distance for the buzzer to sound (in centimeters)

// Buzzer control variables
bool buzzerOn = false;
unsigned long previousMillis = 0;
const long buzzerOnDuration = 60000;   // 1 minute (in milliseconds)
const long buzzerOffDuration = 60000;  // 1 minute (in milliseconds)

void setup() {
  // Initialize Serial Monitor for debugging (optional)
  Serial.begin(9600);

  // Setup pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Trigger the ultrasonic sensor to send the signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse from the ultrasonic sensor
  long duration = pulseIn(echoPin, HIGH, timeoutMicroseconds);

  // Calculate the distance based on the speed of sound
  float distance = duration * 0.0343 / 2.0;  // Sound travels ~343 meters per second at 20°C

  // Output the distance to Serial Monitor (optional)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if the distance is greater than 6 cm
  if (distance > minimumDistance) {
    // If the buzzer is not already on, turn it on and record the start time
    if (!buzzerOn) {
      buzzerOn = true;
      previousMillis = millis();
      digitalWrite(buzzerPin, HIGH);
    }
  } else {
    // If the buzzer is on and has been on for the specified duration, turn it off
    if (buzzerOn && (millis() - previousMillis >= buzzerOnDuration)) {
      buzzerOn = false;
      digitalWrite(buzzerPin, LOW);
    }
  }

  // Check if the buzzer has been on for the specified duration and turn it off
  if (buzzerOn && (millis() - previousMillis >= buzzerOnDuration)) {
    buzzerOn = false;
    digitalWrite(buzzerPin, LOW);
  }

  // Add some delay before next measurement
  delay(100);
}