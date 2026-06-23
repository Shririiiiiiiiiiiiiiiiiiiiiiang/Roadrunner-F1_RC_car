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
bool ERS_pressed = true;//for simulation
bool DRS_pressed = true;//for simulation
bool ERS_allowed = false;
bool DRS_allowed = false;
bool ERS_active = false;
bool DRS_active = false;
bool pit_mode = false;
int power_delta_percent = 0;
int effective_power_limit_percent = 0;

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
    if(ERS_allowed == true && ERS_pressed == true) {
        ERS_active = true;
    }
    else{
        ERS_active = false;
    }

}

void handleSafetySystems() {

}


void readRemoteInputs() {
    if(simulation_mode == true) {
        throttle_input = 1023; // Only for SIMULATIONN
        steering_input = 512;
        ERS_pressed = true;
        DRS_pressed = true;
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
    
    power_delta_percent = 0;
    if(DRS_active == true) {
        power_delta_percent += 5;
    }
    if(ERS_active == true) {
        power_delta_percent += 15;
    }

    effective_power_limit_percent = max_power_percent + power_delta_percent;

    if(effective_power_limit_percent > 100) {
        effective_power_limit_percent = 100;

    }

    if(requested_power_percent > effective_power_limit_percent) {
        final_power_percent = effective_power_limit_percent;
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

    Serial.print(" | Pit mode: ");
    Serial.print(pit_mode);

    Serial.print(" | Requested Power: ");
    Serial.print(requested_power_percent);

    Serial.print(" | ERS Active: ");
    Serial.print(ERS_active);

    Serial.print(" | DRS active: ");
    Serial.print(DRS_active);

    Serial.print(" | Power Delta: ");
    Serial.print(power_delta_percent);

    Serial.print(" | Effective power limit: ");
    Serial.print(effective_power_limit_percent);

    Serial.print(" | Final power: ");
    Serial.println(final_power_percent);
    delay(500);
}



void handleDRS() {
    if(DRS_allowed == true && DRS_pressed == true) {
        DRS_active = true;
    }
    else {
        DRS_active = false;
    }

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

    handleERS();

    handleDRS();

    handleSteering();

    handleThrottle();

    handleFailSafe();

    handleTelemetry();
    
}

