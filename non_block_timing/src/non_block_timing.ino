/*
 * non-blocking timing using millis()
 * demonstrates cooperative multitasking with multiple time based tasks without blocking delays
*/

// PIN CONFIGURATIONS
const uint8_t LED1_PIN = 2;
const uint8_t LED2_PIN = 3;

// TIMING CONFIGURATIONS (MILLISECONDS)
const unsigned long LED1_INTERVAL = 3000;
const unsigned long LED2_INTERVAL = 5000;

// RUNTIME STATE
bool led1State = HIGH;
bool led2State = HIGH;

unsigned long led1LastToggleTime = 0;
unsigned long led2LastToggleTime = 0;

void setup() {
    // set led pins as outputs
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    // set led states
    digitalWrite(LED1_PIN, led1State);
    digitalWrite(LED2_PIN, led2State);
}

void loop() {
    // store current millis reading to calculate delays for respective leds
    unsigned long currMillis = millis();
    
    handleLedToggle(LED1_PIN, LED1_INTERVAL, currMillis, led1LastToggleTime, led1State);
    handleLedToggle(LED2_PIN, LED2_INTERVAL, currMillis, led2LastToggleTime, led2State);
}

void handleLedToggle( uint8_t pin,
                      unsigned long interval,
                      unsigned long currTime,
                      unsigned long &lastToggleTime,
                      bool &state )
{
    if (currTime - lastToggleTime > interval) {  // delay time reached for 2nd led
        lastToggleTime = currTime;
        state = !state;
        digitalWrite(pin, state);
    }
}
