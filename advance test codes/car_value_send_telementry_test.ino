int car_speed = 43;
int battery_level = 79;
bool drs_button = true;
bool DRS_open = false;
int car_temp = 30;
int signal_strength = 0;
bool remote_connected = false;

void setup(){
    Serial.begin(9600);

}

void loop() {
    car temp = car_temp + 10;
    battery_level = battery_level - 10;
    signal_strength = signal_strength + 10;
     Serial.print("curent speed:   ");
        Serial.println(car_speed);
    Serial.print("current battery level: ");
    Serial.println(battery_level);
    Serial.print("current car temp: ");
    Serial.println(car_temp);
    Serial.print("current signal strength: ");
    Serial.println(signal_strength);

    if (signal_strength >= 60) {
        Serial.println("signal strength good,remote connected");
    }

    if (signal_strength < 60) {
        Serial.println("signal strength low,remote disconnected");
    }

    if (signal_strength > 100) {
        signal_strength = 0; // to simulate signal loss
    }

    if (car_speed > 35) {
        if (drs_button == true) {
            DRS_open = true;
            Serial.println("DRS flap opened");
        }
    }
    if (car_temp > 60) {
        Serial.println("Car temp high, slow down!!");
        if (car_speed > 20) {
            car_speed = 20;
        }
    }


}