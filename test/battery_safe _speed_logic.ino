int speed=0;
int battery_temp=30;

void setup(){
    Serial.begin(9600); 

}
void loop(){

    battery_temp = battery_temp + 10;

if (battery_temp>50){
    Serial.println("Battery temperature high, User is recommened to reduce speed");

}

if (battery_temp>70){
    Serial.println("Battery temperature critical, reducing car speed");

    speed = speed - 30;

}

Serial.println("speed reduced as battery temp critical");
Serial.print("Current speed: ");
Serial.println(speed);

}