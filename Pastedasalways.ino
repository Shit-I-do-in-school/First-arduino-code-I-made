
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.println(voltage);

  if (voltage < 2.9) {
    digitalWrite(2, 1);
    digitalWrite(3, 0);
    digitalWrite(4, 0);
  } else if (voltage > 2.9 && voltage < 3.7) {
    digitalWrite(2, 0);
    digitalWrite(3, 1);
    digitalWrite(4, 0);
  } else if (voltage > 3.7) {
    digitalWrite(2, 0);
    digitalWrite(3, 0);
    digitalWrite(4, 1);
  }
}