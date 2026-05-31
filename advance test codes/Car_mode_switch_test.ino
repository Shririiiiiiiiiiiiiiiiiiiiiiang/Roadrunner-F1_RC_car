char mode = 'N';

bool drs_button = true;
bool drs_open = false;
int speed = 0;


void setup() {
    Serial.begin(9600);
}

void loop(){
    speed = speed + 10;
    if (mode == 'N'){
        Serial.println("current car mode = normal(N)");
    }
    if (drs_button == true){
        drs_open = true;
    }

    if (mode == 'R'){
        Serial.println("current car mode = race(R)");
        if(speed > 60){
            if (drs_open == true){
                Serial.println("DRS flap opened");
            }
            else{
                Serial.println("DRS flap closed");
            }
        }
    }
    if (mode == 'T'){
        Serial.println("current car mode = test(T)");
    }
    if (mode == 'P'){
        Serial.println("current car mode = parking(P)");
    }

    delay(2000);

if (mode == 'N') {
  mode = 'R';
}

else if (mode == 'R') {
  mode = 'T';
}

else if (mode == 'T') {
  mode = 'P';
}

else if (mode == 'P') {
  mode = 'N';
}



}