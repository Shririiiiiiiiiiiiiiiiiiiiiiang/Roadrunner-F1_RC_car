int speed = 0;

void setup(){
    Serial.begin(9600);

}

void loop(){
    speed = speed+10;
    if (speed>50){
        Serial.println("Speed to high initilising brakes");
        speed = speed - 30; 
    

    }
    Serial.println("Brakes applied, reducing speed");
    Serial.print("Current speed: ");
    Serial.println(speed);
}