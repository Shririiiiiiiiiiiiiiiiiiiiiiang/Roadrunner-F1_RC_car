int speed=0
int maxturnangle=35

void setup() {
    Serial.begin(9600);

}

void loop() {
    speed = speed + 10;
    if (speed > 50) {
        maxturnangle = 15;
    }
    else if(speed >30)
    {
        maxturnangle = 25;
    }
    else{
        maxturnangle = 35;
    }







}