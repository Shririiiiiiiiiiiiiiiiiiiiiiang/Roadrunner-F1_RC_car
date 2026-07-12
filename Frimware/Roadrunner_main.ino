#include <ESP32Servo.h>
#include <esp_task_wdt.h>

Servo steering_servo;
Servo motor_ESC;

int esc_signal = 1000;
int max_power_percent = 0;
int max_steer_angle = 0;
int ers_duration = 0;
int pot_value = 0; //potentiometer value
int power_percent = 0;
bool simulation_mode = true; //giving fake values till i get  the NRF
int throttle_input = 0;
int steering_input = 2048;
int steering_angle = 0;
int servo_angle = 90;
int requested_power_percent = 0;
int final_power_percent = 0;
bool ERS_pressed = false;//for simulation
bool DRS_pressed = false;//for simulation
bool ERS_allowed = false;
bool DRS_allowed = false;
unsigned long DRS_open_time= 0;
const unsigned long DRS_min_use_Time = 2000;
const int DRS_close_steering_angle = 10;
bool ERS_active = false;
bool DRS_active = false;
bool pit_mode = false;
int power_delta_percent = 0;
int effective_power_limit_percent = 0;
unsigned long ERS_start_time = 0;
unsigned long ERS_last_time_used = 0;
const unsigned long ERS_MAX_DURATION = 7000; // 7 sec
const unsigned long ERS_COOLDOWN = 20000; //20 sec
bool ERS_on_cooldown = false;

int pot_pin = 34;
int esc_pin = 19;




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
        power_percent = map(pot_value, 0, 4095, 0, 100);//plots pot values of 0 to1023 to 0 to 100 %
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
   unsigned long current_time = millis();
   if(current_time - ERS_last_time_used < ERS_COOLDOWN) {
    ERS_on_cooldown = true;
   }
   else {
    ERS_on_cooldown = false;
   }
   if(ERS_allowed == true && ERS_pressed == true && ERS_on_cooldown == false &&  ERS_active == false) {
        ERS_active = true;
        ERS_start_time = current_time;
   }

    if(ERS_active == true) {
        if(current_time - ERS_start_time >= ERS_MAX_DURATION) {
            ERS_active = false;
            ERS_last_time_used = current_time; // current_time gets created in line 59
        }
        if(ERS_pressed == false || ERS_allowed == false) {
            ERS_active = false;
            ERS_last_time_used = current_time;
        }
    }

}

void handleSafetySystems() {

}


void readRemoteInputs() {
    if(simulation_mode == true) {
        throttle_input = 4095; // Only for SIMULATIONN
        steering_input = 2048; // for Wowki testings
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
    max_steer_angle = map(final_power_percent, 0, 100, 45, 15);
    steering_angle = map(steering_input, 0, 4095, -max_steer_angle, max_steer_angle);

    servo_angle = map(steering_angle, -max_steer_angle, max_steer_angle, 60, 120);
    steering_servo.write(servo_angle);
}

void handleThrottle() {
    requested_power_percent = map(throttle_input, 0, 4095, 0, 100);
    
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
    Serial.println(requested_power_percent);

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

    Serial.print(" | ERS cooldown: ");
    Serial.print(ERS_on_cooldown);

    Serial.print(" | Steering angle: ");
    Serial.println(steering_angle);

    Serial.print(" | Servo angle: ");
    Serial.println(servo_angle);

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

void handleMotorOutput() {
    esc_signal = map(final_power_percent, 0, 100, 1000, 2000);
    motor_ESC.writeMicroseconds(esc_signal);
}

void setup() {
Serial.begin(115200);
pinMode(pot_pin, INPUT);
esp_task_wdt_init(3,true);
esp_task_wdt_add(NULL);
ERS_last_time_used = millis() - ERS_COOLDOWN;
steering_servo.attach(18);
motor_ESC.attach(esc_pin);
motor_ESC.writeMicroseconds(1000);
delay(2000);
}

void loop() {

    esp_task_wdt_reset();

    readRemoteInputs();

    readSensors();

    handleCommunication();

    handleSpeedLimiter();

    handleERS();

    handleDRS();

    handleThrottle();

    handleMotorOutput();

    handleSteering();

    handleFailSafe();

    handleTelemetry();
    
}

