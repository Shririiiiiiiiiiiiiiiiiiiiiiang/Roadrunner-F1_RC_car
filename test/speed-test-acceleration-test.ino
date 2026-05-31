int speed = 0

void setup() {
    Serial.begin(9600); // Start serial communication at 9600 baud rate
}

void loop() {
speed = speed + 5;
serial.print("current speed:- ");      
serialprinln(speed);
delay(2000); // Wait for 1 second before the next print

}