#include <Servo.h

Servo steering;

int currentangle = 50;

int targetangle = 150;

void setup() {
    steering.attach(9);
    steering.write(currentangle);

}

void loop() {
    if (currentangle<targetangle){
        currentangle=currentangle+1;

    }

    if(currentangle>targetangle){
        currentangle=currentangle-1;
    }
}

steering.write(currentangle);
delay(10);
