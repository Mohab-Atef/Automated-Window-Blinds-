#include"header.h"

int main() {
    initIO();
    /* Initialize ADC for LDR reading */
    /* Set the ADC input channel, reference voltage, and prescaler */
    ADMUX = (1 << REFS0);  /* Reference voltage at AVCC, ADC0 as the input channel */
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);  /* Enable ADC, set prescaler to 64 */
    /* Enable global interrupt */
    sei();
    while (1) {
        /* Read light intensity from LDR */
        uint16_t lightIntensity = readLightIntensity();
        /* Check if light intensity is below the threshold */
        if (lightIntensity < LIGHT_THRESHOLD) {
            openBlinds();
        } else {
            closeBlinds();
        }
        _delay_ms(1000);  /* Adjust delay as needed */
        stopBlinds();
    }
    return 0;
}
