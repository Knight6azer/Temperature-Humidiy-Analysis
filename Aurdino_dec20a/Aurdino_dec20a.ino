const int trigPin = 9;       // Trigger pin for ultrasonic sensor
const int echoPin = 10;      // Echo pin for ultrasonic sensor
const int pirPin = 8;        // PIR motion sensor pin
const int redPin = 11;       // Red LED pin
const int greenPin = 12;     // Green LED pin
const int buzzerPin = A4;     // Buzzer pin

long duration;               // Variable to store pulse duration
float distance;              // Variable to store the calculated distance
int motionDetected = LOW;    // Variable to store PIR sensor status

void setup() {
  pinMode(trigPin, OUTPUT);    // Set the trigPin as output
  pinMode(echoPin, INPUT);     // Set the echoPin as input
  pinMode(pirPin, INPUT);      // Set the pirPin as input
  pinMode(redPin, OUTPUT);     // Set the redPin as output
  pinMode(greenPin, OUTPUT);   // Set the greenPin as output
  pinMode(buzzerPin, OUTPUT);  // Set the buzzerPin as output

  Serial.begin(9600);          // Start serial communication
}

void loop() {
  // Ultrasonic Sensor Measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);                 // Wait for 2 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);                // Wait for 10 microseconds to send pulse
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);    // Measure the duration of pulse
  distance = (duration * 0.0343) / 2;   // Calculate the distance in cm

  // Read the PIR motion sensor
  motionDetected = digitalRead(pirPin);

  // Show the distance on the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (motionDetected == HIGH) {
    // Motion detected
    digitalWrite(redPin, HIGH);    // Red light ON
    digitalWrite(greenPin, LOW);   // Green light OFF
    digitalWrite(buzzerPin, HIGH); // Buzzer ON
    Serial.println("Motion detected!");
  } 
  else if (distance > 10 && distance > 0) {
    // Object detected nearby (within 10 cm)
    digitalWrite(redPin, HIGH);     // Red light OFF
    digitalWrite(greenPin, LOW);  // Green light ON
    digitalWrite(buzzerPin, LOW); // Buzzer ON
    Serial.println("Object detected nearby!");
  }
  else {
    // No motion and no object nearby
    digitalWrite(redPin, LOW);     // Red light OFF
    digitalWrite(greenPin, HIGH);  // Green light ON
    digitalWrite(buzzerPin, LOW);  // Buzzer OFF
    Serial.println("No motion and no object nearby.");
  }

  delay(500); // Delay for stability
}
