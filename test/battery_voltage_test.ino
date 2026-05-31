int battery = 75;
void setup() {
    Serial.begin(9600);
} 
void loop(){
    if (battery>80)
        Serial.println("Battery is full");
    else if (battery>50)
        Serial.println("Battery is at medium level");
    else if (battery>20)
    Serial.println("Battery is low");       
    else
    Serial.println ("Battery is critical")
}