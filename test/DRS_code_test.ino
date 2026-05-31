int speed = 0;
bool drs_button = true;
bool drs_open = false;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (speed > 60) {
        if (drs_button==true){
            drs_open=true;
            Serial.println("DRS flap opened");

        }
      else{
        drs_open=false; 
        Serial.println("DRS flap closed");
      }  

    }
    else{
        drs_open=false;

    
    }
}