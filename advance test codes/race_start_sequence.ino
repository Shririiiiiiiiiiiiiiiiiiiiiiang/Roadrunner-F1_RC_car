int speed = 0;
int throttle = 0;
bool race start= false;
bool start_button = true;
bool race_running = false;

void setup(){
    Serial.begin(9600);

}

void loop(){
    if (start_button == false) {
        race_start = false;
    }
    if (race_start == false) {
        throttle = 0;
        Serial.println("Race start sequence initiated,throttle at 0, waiting for start signal...");
    }
    if (start_button== true){
        race_start = true;
    }

    if(race_start == true && race_running == false) {
    Serial.println("race starting in");
    Serial.println(3);
    delay(1000);
    Serial.println(2);
    delay(1000);
    Serial.println(1);
    delay(1000);
    Serial.println("race started, race safe");
    throttle = throttle + 20;
        Serial.print("Throttle: ");
            Serial.println(throttle);
        }
    
    race_running = true;
    speed = speed + 20;
    Serial.print("Current speed: ");
    Serial.println(speed);
    if (speed > 50) {
        speed = 50;
    }
    if (throttle > 100) {
        throttle = 100;


    }
}
