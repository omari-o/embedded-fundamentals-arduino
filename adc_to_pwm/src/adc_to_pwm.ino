/*
 * ADC to PWM Control Loop
 *
 * Samples an analog input from a 10k potentiometer and uses that value to
 * drive an LED with a pulse width modulated output with non blocking delays.
 */

// pin configuration
const uint8_t POT_PIN = A0;
const uint8_t LED_PIN = 9;

// timing configuration
const unsigned long SAMPLE_INTERVAL_MS = 100;
unsigned long lastSampleTime = 0;

// set up moving average filter
const uint8_t FILTER_SIZE = 5;
uint16_t adcSamples[FILTER_SIZE];
uint8_t sampleIndex = 0;
uint32_t sampleSum = 0;

void setup() {
    pinMode(LED_PIN, OUTPUT);

    // initialize filter buffer with zeroes
    for (uint8_t i = 0; i < FILTER_SIZE; i++)
        adcSamples[i] = 0;
}

void loop() {
    unsigned long currTime = millis();

    if (currTime - lastSampleTime >= SAMPLE_INTERVAL_MS) {
        lastSampleTime = currTime;

        // returns a 10 bit value (0-1023), hence need for uint16
        uint16_t adcVal = analogRead(POT_PIN);

        // update moving average
        sampleSum -= adcSamples[sampleIndex];
        adcSamples[sampleIndex] = adcVal;
        sampleSum += adcVal;
        uint16_t avgAdc = sampleSum / FILTER_SIZE;

        sampleIndex = (sampleIndex + 1) % FILTER_SIZE;

        // analogWrite outputs 8 bit value (0-255), scale adc value down
        uint8_t pwmVal = avgAdc >> 2;
        analogWrite(LED_PIN, pwmVal);
    }
}
