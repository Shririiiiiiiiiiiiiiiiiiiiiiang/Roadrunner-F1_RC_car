int battery_level = 100;
bool low_batterymode = false;
int speed = 0;
bool kill_switch = false;
bool emergency_evac_mode = false


void setup() {
    Serial.begin(9600);
}

void loop() {
    speed = speed + 10;
    battery_level = battery_level - 10;

    if (battery_level < 10) {
        Serial.println("battery critical engaging kill switch in 3 sec car will be out of power, pls take the car to a side");
        delay(3000);
        kill_switch = true;
        if(kill_switch==true){
            speed = 0;
            Serial.println("speed is 0 car has no power pls pick up the car and dismantle the battery and charge after cooling");
        }
    }

     else if (battery_level < 20) {
        Serial.println("battery very low engaging emergncy evac mode car speed limited to 7 kmph pls route out of the car");
        emergency_evac_mode = true;
        if (emergency_evac_mode == true) {
            if (speed > 7) {
                speed = 7;
            }
        }

    } 


    else if (battery_level < 35) {
        low_battery_mode = true;
        Serial.println("battery low engaging low battery mode");
            low batterymode = true;

        if (low_battery_mode == true) {
            if (speed > 20) {
                speed = 20;
                Serial.println("speed limited to 20 due to low battery");
            }
        }


    }

   

    

   
           
        
    }




}