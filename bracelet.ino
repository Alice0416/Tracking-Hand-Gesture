const int trigPin = 7; // Trigger pin of HC-SR04
const int echoPin = 6; // Echo pin of HC-SR04
const int ledPin = 13; // LED pin
int score = 1000; // Initial score

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in cm
  int distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");

  // Check if distance is within the specified range
  if (!(distance >= 2.72 && distance <= 4.72)) {
    score = max(0, score - 1); // Decrease score by 1, but keep it >= 0
  }

  Serial.print("\tScore: ");
  Serial.println(score);
  
  if (distance < 4.72) { // Adjust this value according to your requirement
    digitalWrite(ledPin, HIGH); // Turn on the LED if distance is less than 4.72 cm
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED if distance is equal to or greater than 4.72 cm
  }
  
  delay(100); // Delay before next measurement
}


