int battery = 78
int temperature = 35
bool signalconnected = true;
bool carready=false;

void setup() {
    Serial.begin(9600);

}

void loop() {
    if (battery > 30 && temperature < 70 && signalconnected == true) {
        carready = true;
        Serial.println("Car is ready to goooooooo");

}
    else{
        carready = false;
        serial.println("car unsafe to drive);


    }