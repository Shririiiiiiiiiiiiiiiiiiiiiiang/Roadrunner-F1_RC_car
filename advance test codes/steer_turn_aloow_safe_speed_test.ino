int speed = 0;
int turn = 0;
bool turn_safe_speed = false;

void setup() {
    Serial.begin(9600);
}

void loop() {
    speed = speed + 10;
    turn = turn + 2;
    if (speed > 30) {
        if(turn >10) {
            turn = turn -5;
            delay(900);
            turn = 10
        }
    }
    if (speed > 20) {
        if (turn > 20) {
            turn = turn - 5;
            delay(900);
            turn = 20;
        }


    }

    if (speed > 10) {
        turn_safe_speed = true;
        Serial.println("Safe speed for turning, turn angle adjusted");
        }
    }
}
