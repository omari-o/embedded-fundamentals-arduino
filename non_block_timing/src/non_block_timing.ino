// project #2 - non block timing
// program doesn't stop cpu execution, multiple tasks can be handled concurrently

int led1Pin = 2;
int led2Pin = 3;
int led1State = HIGH;
int led2State = HIGH;
unsigned long led1Timer = 0;
unsigned long led2Timer = 0;
unsigned long led1Delay = 3000;
unsigned long led2Delay = 5000;

void setup() {
    // set led pins as outputs
    pinMode(led1Pin, OUTPUT);
    pinMode(led2Pin, OUTPUT);
    // set led states
    digitalWrite(led1Pin, led1State);
    digitalWrite(led2Pin, led2State);
}

void loop() {
    // store current millis reading to calculate delays for respective leds
    unsigned long currMillis = millis();

    if (currMillis - led1Timer > led1Delay) {  // delay time reached for 1st led 
        led1Timer = currMillis;
        led1State = !led1State;
        digitalWrite(led1Pin, led1State);
    }
    if (currMillis - led2Timer > led2Delay) {  // delay time reached for 2nd led
        led2Timer = currMillis;
        led2State = !led2State;
        digitalWrite(led2Pin, led2State);
    }
}
