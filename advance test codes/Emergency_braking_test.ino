int speed = 0;
int signal_strength = 0;
bool remote_connected = true;
bool emergency_brakes = false;
bool brakes=false;

void setup() {
    Serial.begin(9600);

}

void loop() {
    signal_strength = signal_strength + 10;
    if (signal_strength > 100) {
        signal_strength = 0; // to simulate signal loss
    }
    if (speed > 60){
        if (signal_strength < 60){
            Serial.print("signal strength bad and speed is high");
            remote_connected = false;
        }
        if(remote_connected == false) {
            emergency_brakes = true;
            speed = speed -17;
            Serial.print("Emergency brakes applied, reducing speed");
        }
     else if (speed > 30 ) {
        brakes = true;
        speed = speed - 5;
        Serial.print("Brakes applied, reducing speed");
     }   


    }





}