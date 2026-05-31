int car_speed = 0;
int wheel_speed = 0;
bool traction_control = false;
int throttle = 0;
bool ers_eneabled=true;

void setup() {
    Serial.begin(9600);

}

void loop() {
    car_speed = car_speed + 10;
    wheel_speed = wheel_speed + 15;
    throttle = throttle + 10;
    if (wheel_speed - car_speed >= 20) {
        traction_control = true;

    } 
    if(traction_control == true) {
        ers_eneabled = false;
        throttle = throttle - 20;
        car_speed = car_speed - 10;
        Serial.println("Traction control enabled to reduce wheel spin");
    }
    if (wheel_speed - car_speed < 20) {
        traction_control = false;
        ers_eneabled = true;
    }
}