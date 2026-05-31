int currentspeed = 0;
int previousspeed = 0;
int acceleration = 0;

void setup(){
  Serial.begin(9600);
}

void loop() {
    currentspeed=previousspeed;
    current speed = currentspeed + 10
    acceleration = currentspeed - previous speed;
    Serial.print("speed= ");
    Serial.println(currentspeed);

    Serial.print("ACCELERATION= ");
    Serial.println(accleration);

    delay(1000);
}
