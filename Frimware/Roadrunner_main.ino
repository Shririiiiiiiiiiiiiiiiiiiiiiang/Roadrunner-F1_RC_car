int max_power_percent = 0;
int max_steer_angle = 0;
int ers_duration = 0;
int pot_value = 0; //potentiometer value
int power_percent = 0;
bool simulation_mode = true; //giving fake values till i get  the NRF
int throttle_input = 0;
int steering_input = 512;
int requested_power_percent = 0;
int final_power_percent = 0;
bool ERS_pressed = false;
bool DRS_pressed = false;
bool ERS_allowed = false;
bool DRS_allowed = false;
bool pit_mode = false;

int pot_pin = A0;


void startupCheck() {

}

void handleSpeedLimiter() {
    if(pit_mode == true){
        max_power_percent = 10;
        ERS_allowed = false;
        DRS_allowed = false;

    }
    else{
        pot_value = analogRead(pot_pin);
        power_percent = map(pot_value, 0, 1023, 0, 100);//plots pot values of 0 to1023 to 0 to 100 %
        max_power_percent = power_percent;

        if(power_percent <= 20) {
            ERS_allowed = false;
            DRS_allowed = false;
             
        }
        else{
            ERS_allowed = true;
            DRS_allowed = true;
        }
    }

}

void handleERS() {

}

void handleSafetySystems() {

}


void readRemoteInputs() {
    if(simulation_mode == true) {
        throttle_input = 0;
        steering_input = 512;
        ERS_pressed = false;
        DRS_pressed = false;
        pit_mode = false;
    
    }
    else{
        //future NRF repute inpput code
    }
}

void readSensors() {

}

void handleSteering() {

}

void handleThrottle() {
    requested_power_percent = map(throttle_input, 0, 1023, 0, 100);
    if(requested_power_percent > max_power_percent) {
        final_power_percent = max_power_percent;
    }
    else{
        final_power_percent = requested_power_percent;  
    }

}

void handleCommunication() {

}

void handleGyromode() {
    
}

void handleTelemetry() {
    Serial.print("Throttle: ");
    Serial.print(throttle_input);

    Serial.print(" | Steering: ");
    Serial.print(steering_input);

    Serial.print(" | Max power: ");
    Serial.print(max_power_percent);

    Serial.print(" | ERS allowed: ");
    Serial.print(ERS_allowed);

    Serial.print(" | DRS Allowed: ");
    Serial.print(DRS_allowed);

    Serial.print(" Pit mode: ");
    Serial.print(pit_mode);

    Serial.print("Requested Power: ");
    Serial.print(requested_power_percent);

    Serial.print(" | Final power: ");
    Serial.print(final_power_percent);
    delay(500);
}



void handleDRS() {

}

void handleFailSafe() {

}

void setup() {
Serial.begin(9600);
pinMode(pot_pin, INPUT);
}

void loop() {

    readRemoteInputs();

    readSensors();

    handleCommunication();

    handleSpeedLimiter();

    handleSteering();

    handleThrottle();

    handleERS();

    handleDRS();

    handleFailSafe();

    handleTelemetry();
    
}

