char driving_mode = 'N'; // "P" for Pit mode, "N" for normal, "A" for attack
int max_speed = 0;
int max_steer_angle = 0;
int ers_duration = 0;
bool ERS_allowed = false;
bool DRS_allowed = false;











void startupCheck() {

}

void handleDrivingModes() {

    if(driving_mode == 'P') {

        max_speed = 5;
        max_steer_angle = 30;
        ERS_allowed = false;
        DRS_allowed = false;
        ers_duration = 0;

    }

    else if (driving_mode == 'N') {
        max_speed = 35;
        max_steer_angle = 30
        ERS_allowed = true;
        DRS_allowed = true;
        ers_duration = 5;
 
    }

    else if (driving_mode == 'A') {
        max_speed = 50
        max_steer_angle 
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

}

void loop() {

    readRemoteInputs();

    readSensors();

    handleCommunication();

    handleDrivingModes();

    handleSteering();

    handleThrottle();

    handleERS();

    handleDRS();

    handleFailSafe();

    handleTelemetry();
    
}

