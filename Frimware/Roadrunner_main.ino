int max_power_percent = 0;
int max_steer_angle = 0;
int ers_duration = 0;
int pot_value = 0; //potentiometer value
int power_percent = 0;
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

}

void readSensors() {

}

void handleSteering() {

}

void handleThrottle() {

}

void handleCommunication() {

}

void handleGyromode() {
    
}

void handleTelemetry() {

}

void handleDRS() {

}

void handleFailSafe() {

}

void setup() {
Serial.begin(9600);
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

