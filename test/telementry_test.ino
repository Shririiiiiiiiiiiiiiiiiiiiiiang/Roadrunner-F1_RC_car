int speed=45;

void setup() {
    Serial.begin(9600); // Start serial communication at 9600 baud rate

}

void loop(){
    Serial.print("current speed; ");
    Serial.println(speed); // Print the current speed to the serial monitor
    delay(1000); // Wait for 1 second before the next print
}

