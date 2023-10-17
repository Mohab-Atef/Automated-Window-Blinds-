#ifndef HEADER_H
#define HEADER_H
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
/* Define motor control pins */
#define MOTOR_PORT PORTD
#define MOTOR_PIN1 (1 << PD0)
#define MOTOR_PIN2 (1 << PD1)
/* Define LDR input pin */
#define LDR_PIN (1 << PC0)
/* Define light threshold for automatic control */
#define LIGHT_THRESHOLD 512  /* Adjust this value based on LDR sensitivity */
void initIO();
void openBlinds();
void closeBlinds();
void stopBlinds();
uint16_t readLightIntensity();
#endif
