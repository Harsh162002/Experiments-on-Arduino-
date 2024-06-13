#define TRIGGER_PIN  2 // Arduino pin connected to the trigger pin on the ultrasonic sensor.
#define ECHO_PIN     3 // Arduino pin connected to the echo pin on the ultrasonic sensor.

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 bps.
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Send a trigger pulse to the ultrasonic sensor.
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Measure the pulse duration on the echo pin.
  unsigned long pulseDuration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance based on the speed of sound (343 m/s or 0.0343 cm/us).
  float distance = pulseDuration * 0.0343 / 2; // Divide by 2 because the sound travels to the target and back.

  // Display the measured distance on the Serial Monitor.
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Add a short delay before the next measurement.
  delay(100);
}
