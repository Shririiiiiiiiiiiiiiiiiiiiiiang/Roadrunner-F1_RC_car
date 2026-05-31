int remote_speed = 0;
int remote_throttle = 0;
int car_speed = 0;
int car_throttle = 0;
bool remote_drs_button = true;
bool car_drs_open = false;
bool remote_ers_button = true;
bool car_ers_active = false;
int remote_steer_angle = 90;
int car_steer_angle = 90;

 

void setup(){
    Serial.begin(9600);
 }

 void loop(){
    remote_speed = remote_speed + 10;
    remote_throttle = remote_throttle + 20;
    car_speed = remote_speed;
    car_throttle = remote_throttle;
    if(remote_speed >= 30 && remote_throttle >= 50 && car_steer_angle == 90){
        if(remote_drs_button == true){
            car_drs_open = true;
            Serial.println("DRS opened");
            else{
            car_drs_open = false;
            Serial.println("DRS closed");
            }
        }
        if(remote_ers_button == true){
            car_ers_active = true;
            Serial.println("ERS activated");
        }
        else{
            car_ers_active = false;
            Serial.println("ERS deactivated");
        }
        }
    }
    remote_steer_angle = remote_steer_angle + 10;
    car_steer_angle = remote_steer_angle;
   if(car_speed > 30){

    if(car_steer_angle > 20){

        car_steer_angle = 20;

    }
    if(car_steer_angle = 90 ){
        Serial.println("Steering straight");
    }






 }