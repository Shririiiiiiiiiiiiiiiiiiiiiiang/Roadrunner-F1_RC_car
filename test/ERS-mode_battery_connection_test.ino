int battery = 100;
bool ersmode = false;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (battery > 50) {
        ersmode=true;
 
       Serial.println("ERS mode activated, battery level sufficient");
    }

    if (ersmode=true){
        battery = battery - 25;
        Serial.println("battery reducing fast in ERS mode");
       }
    else if (battery <= 50) {
        ersmode=false;
        Serial.println("battery too low to use ERS pls Use normal/DRS mode");
       }
    else if (battery <= 20) {
        Serial.println("Battery depleted, car stopped");
    }
    if (ersmode==false){
        battery = battery - 5;
        Serial.println("battery reducing slow in normal mode");
    }
}