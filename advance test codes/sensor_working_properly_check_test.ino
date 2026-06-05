int temp_sen = 0;
int battery_power = 100;
int nrf_strength = 0;
bool car_ready = true;


void setup(){
    Serial.begin(9600);
}

void loop(){
    car_ready = true;
    temp_sen = temp_sen + 10;
    battery_power = battery_power - 20;
    nrf_strength = nrf_strength + 20;

if (nrf_strength > 100){
    nrf_strength = 0;//to stiumulate signal losssss
}

if(temp_sen > 80 || temp_sen < 20) {
    Serial.println("car temp sensor printing vague values pls fix");
    car_ready = false;
}

if(nrf_strength < 60){
    Serial.println("car not getting enough signal fix anteena");
    car_ready = false;
}

if(battery_power < 50){
    Serial.println("pls charge battery before use");
    car_ready = false;
}

if (car_ready == false){
Serial.println("car not ready to drive pls fix the problems");
}

if(car_ready == true){
    Serial.println("car ready to drive, drive safe!")
}
}