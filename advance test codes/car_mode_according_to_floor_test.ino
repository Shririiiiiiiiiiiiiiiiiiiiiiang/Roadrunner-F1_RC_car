int speed = 0;
int turn_angle = 0;
int acc = 0;
bool tiles = false;
bool concrete = false;
char car_mode='t';
 
void setup() {
    Serial.begin(9600);
}
speed = speed + 10;
acc = acc + 1;
turn_angle = turn_angle + 2;
void loop(){
    speed = speed + 10;
acc = acc + 1;
turn_angle = turn_angle + 2;
    if (car_mode == 't'){
        tiles = true;
    }
    else if (car_mode == 'c'){
        concrete = true;
    }
    if (tiles == true){
        Serial.print("car in tiles mode speed will be limited");
        if(speed > 30){
            speed = 30;
        }
        if(acc > 6){
            acc = 6;
        }
        if (turn_angle > 20) {
            turn_angle = 20;

        }

    }
    if (concrete == true)
    Serial.print("full poteintial!!");
       speed = speed + 15;
       acc = acc + 15;
         if (turn_angle > 35) {
            turn_angle = 35;//max angle for safe turning

        }





}