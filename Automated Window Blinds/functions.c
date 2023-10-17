#include"header.h"

void initIO() {
    /* Motor control pins as outputs */
    DDRD |= (MOTOR_PIN1 | MOTOR_PIN2);
    /* LDR pin as input */
    DDRC &= ~LDR_PIN;
}
/* Function to open the blinds */
void openBlinds() {
    MOTOR_PORT |= MOTOR_PIN1;
    MOTOR_PORT &= ~MOTOR_PIN2;
}
/* Function to close the blinds */
void closeBlinds() {
    MOTOR_PORT |= MOTOR_PIN2;
    MOTOR_PORT &= ~MOTOR_PIN1;
}
/* Function to stop the blinds */
void stopBlinds() {
    MOTOR_PORT &= ~(MOTOR_PIN1 | MOTOR_PIN2);
}
/* Function to read light intensity from LDR */
uint16_t readLightIntensity() {
    /* Set the reference voltage for ADC (e.g., AVCC with external capacitor at AREF pin) */
    ADMUX = (1 << REFS0);  /* Reference voltage at AVCC, ADC0 as the input channel */
    /* Enable ADC, set prescaler to 64 for a reasonable conversion speed */
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);
    /* Start an ADC conversion */
    ADCSRA |= (1 << ADSC);
    /* Wait for the conversion to complete */
    while (ADCSRA & (1 << ADSC));
    /* Retrieve the 10-bit ADC result */
    uint16_t adcValue = ADC;
    return adcValue;
}
