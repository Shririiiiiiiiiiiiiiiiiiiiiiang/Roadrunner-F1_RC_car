int speed = 0;
int acc = 0;
bool ers_button = false;
bool ers_start = false
bool safe_mode = false;
bool normal_mode = false;
bool attack_mode = false;

void setup() {
    Serial.begin(9600);

}

void loop() {
    speed = speed + 10;
    acc = acc + 2;
    if(ers_button == false){
        ers_start = false;

    }
    
if (safe_mode == true){
Serial.println("mode = safe");
    if(speed > 20){
    speed = 20;
    }
    if(acc > 4){
        acc = 4;
    }
    if(ers_button == true && speed > 15){
        ers_start = true;
        delay (2000);
        ers_start = false;
    }
}
else if (normal_mode == true){
    Serial.println("mode = normal");

    if(speed > 35){
        speed = 35;
    }
    if(acc > 10){
        acc = 10;
    }
    if(ers_button == true && speed > 30){
        ers_start = true;
        delay (5000);
        ers_start = false;
    }
}
else if (attack_mode == true){
    Serial.println("mode = attack");

    if(speed > 45){
        speed = 45;
    }
    if(acc > 15){
        acc = 15;
    }
    if(ers_button == true && speed > 30){
        ers_start = true;
        delay (10000);
        ers_start = false;
    }
}