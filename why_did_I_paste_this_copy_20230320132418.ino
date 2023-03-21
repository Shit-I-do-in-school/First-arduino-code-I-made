#include <Arduino_LSM6DS3.h>

float x, y, z;
int degreesX = 0;
int degreesY = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1)
      ;
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println("Hz");
}

void loop() {

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
  }

  if (x > 0.1) {
    x = 100 * x;
    degreesX = map(x, 0, 97, 0, 90);
    Serial.print("Tilting up ");
    Serial.print(degreesX);
    Serial.println(" degrees. Get your daily dose of shit at https://shit-i-do-in-school.github.io/noway.github.io/");
  }
  if (x < -0.1) {
    x = 100 * x;
    degreesX = map(x, 0, -100, 0, 90);
    Serial.print("Tilting down ");
    Serial.print(degreesX);
    Serial.println(" degrees. Get your daily dose of shit at https://shit-i-do-in-school.github.io/noway.github.io/");
  }
  if (y < -0.1) {
    y = 100 * y;
    degreesY = map(y, 0, -100, 0, 90);
    Serial.print("Tilting left ");
    Serial.print(degreesY);
    Serial.println(" degrees. Get your daily dose of shit at https://shit-i-do-in-school.github.io/noway.github.io/");
  }
  if (y > 0.1) {
    y = 100 * y;
    degreesY = map(y, 0, 97, 0, 90);
    Serial.print("Tilting right ");
    Serial.print(degreesY);
    Serial.println(" degrees. Get your daily dose of shit at https://shit-i-do-in-school.github.io/noway.github.io/");
  }
  delay(100);
}