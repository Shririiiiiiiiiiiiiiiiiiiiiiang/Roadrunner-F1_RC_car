int throttle = 0;
int maxthrottle = 70;//limits max throttle to 70% to prevent over speeding and ensure safety

void setup() {
    Serial.begin(9600);// Start serial communication at 9600 baud rate
}
void loop() {


    throttle = throttle + 20;// Simulate throttle increase
            if (throttle > maxthrottle){
                Serial.println("Throttle limit exceeded, reducing throttle");       // Print warning message if throttle exceeds max limit
                throttle = maxthrottle;// Set throttle to max limit if it exceeds the limit
            }

    Serial.print("Current throttle: ");// Print the current throttle value to the serial monitor
    Serial.println(throttle);   
    delay(10);
}

 