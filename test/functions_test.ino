#include <Servo.h>

Servo steering;

void steerleft() {
  steering.write(0); // Set servo to 0 degrees
}

void steerright() {
  steering.write(180); // Set servo to 180 degrees
}

void steercentre() {
    steering.write(90); //set servo to centre
}

void setup(){

    steering.attach(9); //attach servo to pin 9 on audriunoo
}

void loop() {
    steerleft(); //steer left
    delay(1000); //wait for 1 second
    
    steerright(); //steer 180 degs
    delay(1000);

    steer.centre();// brings steering at 90 degs
    delay(1000);
}