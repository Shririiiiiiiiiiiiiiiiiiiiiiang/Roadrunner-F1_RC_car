int speed = 0;
int signal_strength = 0;
bool signalconnected = true;
bool failsafe_engaged = false;
bool remote_connected = false;
bool kill_switch = false;
bool drs_button = true;
bool drs_open = false;
bool ers_button = true;
bool ers_active = false;

void setup() {
    Serial.begin(9600);

}

void loop () {
speed = speed + 10;
signal_strength = signal_strength + 10;
if (signal_strength > 100) {
    signal_strength = 0; // to simulate signal loss
}
if (signal_strength >= 60) {
    signalconnected = true;
    remote_connected = true;
    Serial.println("Signal strength good, remote connected");
}
else {
    signalconnected = false;
    remote_connected = false;
    Serial.println("Signal lost, rechaecking for signal...");
    delay(3000);
    if (signalconnected == false) {
    failsafe_engaged = true;
}
if (failsafe_engaged == true) {
    kill_switch = true;
    Serial.println("Failsafe engaged, kill switch activated, car shutting down for safety");

}

if (kill_switch == true) {
    drs_open = false;
    ers_active = false;
    speed = speed - 10;
    delay (1500);
    speed = 0;
    
    Serial.println("Car stopped, DRS closed, ERS deactivated");













}