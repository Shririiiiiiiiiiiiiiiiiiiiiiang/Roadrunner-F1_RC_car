#include <Servo.h>

Servo steering;

void setup() {
  steering.attach(9);
}

void loop() {
  steering.write(90); // Set servo to 90 degrees
  delay(1000);        // Wait for 1 second
  steering.write(0);  // Set servo to 0 degrees
  delay(1000);        // Wait for 1 second
}