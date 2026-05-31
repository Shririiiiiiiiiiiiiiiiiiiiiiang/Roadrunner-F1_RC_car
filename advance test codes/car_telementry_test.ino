int car_temp = 30;
bool drs_button = true;
bool DRS_open = false;
int battery_level = 100;
int speed = 0;
bool ERS_button = true;
bool ERS_active = false;
bool kill_switch = false;

void setup(){
    Serial.begin(9600);
}

void loop() {
    car_temp = car_temp + 10;
    Serial.print("Current car temp: ");
    Serial.println(car_temp);
    if (car_temp > 60){
        Serial.println("Car temp is high slow down!!");
    
    }
    if (car_temp > 80){
        Serial.println("Car temp critical, engaging kill switch in 5 sec, pls take the car to a side");
        delay(4000);
        kill_switch = true;
    }
    speed= speed + 10;
    if(speed> 35 ){
        if (DRS_button==true){
            DRS_open=true;

        }
        if (DRS_open==true){
            Serial.print("DRS flap open, current speed: ");
            Serial.println(speed);
        }
        else{
            DRS_open=false;
        }
        if (ERS_button==true){
            ERS_active=true;

        }
        else{
            ERS_active=false;
        }

        battery_level = battery_level - 10;
        Serial.print("Current battery level: ");
        Serial.println(battery_level);


        if(kill_switch==true){
            speed=0;
            DRS_open=false;
            ERS_active=false;
            Serial.println("Kill switch engaged, car shutting down");
        }
    }
    