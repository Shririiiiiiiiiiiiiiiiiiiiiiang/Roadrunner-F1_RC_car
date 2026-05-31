bool remote_connected = false;
int signal_strength = 0;

void setup() {
    Serial.begin(9600);
}

void loop(){
    signal_strength = signal_strength + 10
    
    if (signal_strength>= 60){
        remote_connected = true;
        Serial.println("remote is connected");
    }
    else{
        remote_connected=false;
        Serial.println("remote disconnected due to low signal strength");
    
    }

    if (signal_strength>100){
        signal_strength = 0; // to stimulate signal loss
    
    }
}