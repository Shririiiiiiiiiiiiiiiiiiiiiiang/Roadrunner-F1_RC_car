int speed = 0;
bool brakeMode = false;

void setup() {

  Serial.begin(9600);

}

void loop() {

  speed = speed + 15;

  if(speed > 80) {

    brakeMode = true;

  }

  if(brakeMode == true) {

    speed = speed - 25;

    Serial.println("BRAKING");

  }

  if(speed < 20) {

    brakeMode = false;

  }

  Serial.print("Speed: ");
  Serial.println(speed);

  delay(1000);

}