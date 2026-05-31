int joystick_val;
int throttle;

void.setup() {
    serial.begin(9600)
}

void loop() {
    joystick_val = joystick_val + 100;
     if (joystick_val > 1023){
         joystick_val = 0;
     }
     throttle = map(joystick_val, 0, 1023, 0, 100);
        Serial.print("Joystick value: ");
        Serial.println(joystick_val);
    }
    
        