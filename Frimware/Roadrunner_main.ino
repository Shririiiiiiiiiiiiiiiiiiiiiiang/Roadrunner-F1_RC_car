int max_speed = 0;
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
        max_speed = 7;
        ERS_allowed = false;
        DRS_allowed = false;

    }
    else{
        pot_value = analogRead(pot_pin);
        power_percent = map(pot_value, 0, 1023, 0, 100);//plots pot values of 0 to1023 to 0 to 100 %
        max_speed = map(power_percent, 0, 100, 0, 45);//plots 0 to 100 % to 0 to 45 kmph(approxspeed considered 45 may be lesser)

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

