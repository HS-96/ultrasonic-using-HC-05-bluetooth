// C++ code
//
int US_sensor = 0;

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

  pinMode(11, OUTPUT);
}

void loop()
{
  US_sensor = 0.01723 * readUltrasonicDistance(6, 6);
  if (US_sensor <= 60) {
    Serial.println(US_sensor);
    delay(3000); // Wait for 3000 millisecond(s)
    digitalWrite(11, HIGH);
  } else {
    digitalWrite(11, LOW);
  }
}