// C++ code
//
int us_sensor = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);

  pinMode(12, OUTPUT);
}

void loop()
{
  us_sensor = 0.01723 * readUltrasonicDistance(6, 5);
  if (us_sensor <= 70) {
    delay(3000); // Wait for 3000 millisecond(s)
    Serial.println(us_sensor);
    digitalWrite(12, HIGH);
  } else {
    Serial.println(us_sensor);
    digitalWrite(12, LOW);
  }
}