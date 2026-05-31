int battery_temp = 30;
bool kill_switch = false;

void setup() {
    Serial.begin(9600);

}

void loop() {
    battery_temp = battery_temp + 5;
    if (battery_temp > 60){
        Serial.println("battery temp high, consider slowing down");)

    }
    if (battery_temp>80){
        Serial.println("battery temp exceeded working range, engagaing kill switch in 5 sec, pls take the car to a side");
    
    }
    
    if (battery_temp > 80 && kill_switch == false) {
  Serial.println("battery temp exceeded working range, engaging kill switch in 5 sec");
  delay(5000);
  kill_switch = true;
  Serial.println("Kill switch engaged, shutting down the car for safety");
}
}