bool signalconnected = true;
int throttle = 80;

void setup() {
    Serial.begin(9600);
}
void loop (){
    if (signalconnected=false){
        throttle = 0;
        Serial.println("Signal lost, reducing throttle to 0 for safety");
    
    
}
else{
    Serial.println("Signal connected, throttle at normal level");
    Serial.print("Current throttle: ");
    Serial.println(throttle);




}