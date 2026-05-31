int battery_percent = 100;
int car_temp = 30;
int signal_strength = 0;
bool remote_disconnected = true;
bool batter_low = false;
bool temp_high = false;

void setup() {
    Serial.begin(9600);
    
Serial.print("Car in config mode wait for some time");

}


void loop() {
    battery_percent = battery_percent - 10;
    car_temp = car_temp + 10;
    signal_strength = signal_strength + 10;
    if (signal_strength > 100){
        signal_strength = 0;
    }
    if (battery_percent < 60){
        battery_low = true;
        Serial.print("battery low to race the car pls charge first");
    }
    if (signal_strength < 60){
        remote_connected = false;
        Serial.print("signal strength low reposition anteena for good signal");

    
    }
    if (car_temp > 60){
        temp_high = true;
        Serial.print("car temp high let it cool down before starting");
    }

    if (temp_high == true && remote_connected == true && battery_low == true) {
        Serial.print("Car Critical");
    }
    if (temp_high == false || remote_disconnected == true || battery_low == false) {
        Serial.print("Car can be driven drive slowly
        ");
}