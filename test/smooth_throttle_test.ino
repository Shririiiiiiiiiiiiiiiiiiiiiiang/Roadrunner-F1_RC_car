int throttle = 0;
int targetthrottle= 100;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (throttle < targetthrottle) {
        throttle++;
    }
    Serial.print("Throttle: ");
    Serial.println(throttle);

    if (throttle = targetthrottle){
        Serial.println("Target throttle reached");
    }

    if (throttle > targetthrottle) {
        Serial.println("Throttle exceeded target, reducing throttle");
        throttle = targetthrottle;
    }
    delay(10);
}