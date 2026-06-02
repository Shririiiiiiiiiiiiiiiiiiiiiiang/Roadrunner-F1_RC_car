int speed = 0;
bool ers_cooldown = false;
bool ers_active = true
bool ers_button = false;

void setup() {
    Serial.begin(9600);

}

void loop() {
 speed = speed + 10;
 if (speed > 30) {
    ers_active =     true;

 }   
 if (ers_active == true) {
    ers_button = true;
    ers_cooldown = false;
    Serial.println("ERS enabled for 10 seconds");
    speed = speed + 20;
    if (speed > 55) {
        speed = 55;
    }
    delay(10000);
    ers_active = false;
    ers_button = false;
    ers_cooldown = true;
    
 }
 if (ers_active == false && speed > 40) {
    speed = 35;
 }
 if (ers_cooldown == true) {
    Serial.println("ERS on cooldown for 30 sec");
    delay(30000);
    ers_cooldown = false;
    Serial.println("ERS ready again");

 }
 if (ers_cooldown == false && speed > 30)
{
    ers_active = true;
}
// same for DRS(mostly same**)