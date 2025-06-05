/*
 * File:   main.c
 * Author: saranga Senarathna
 *
 * Created on June 2, 2025, 4:01 PM
 */

#include <xc.h>

// CONFIG
#pragma config FOSC = INTRCIO
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config MCLRE = OFF
#pragma config BOREN = OFF
#pragma config CP = OFF
#pragma config CPD = OFF

#define _XTAL_FREQ 4000000

volatile unsigned char prev_gpio;

void __interrupt() ISR(void) {
    if (INTCONbits.GPIF) {
        // Pin change detected on GP0, GP1, or GP3
//        if (((GPIO ^ prev_gpio)& 0b00001000) != (prev_gpio & 0b00001000)) {  //for the rising edge GPIO, the falling edge ~GPIO
          if ((GPIO & 0b00001000) != (prev_gpio & 0b00001000)) {   //both edges
        // GP0 changed                                                    
            GPIObits.GP0 = ~GPIObits.GP0;  // Toggle LED
        }

        prev_gpio = GPIO;       // Update previous state
        INTCONbits.GPIF = 0;    // Clear interrupt-on-change flag
    }
}

void main() {
    OSCCAL = 0xFF;         // Optional: oscillator calibration

    TRISIO = 0b00001000;   // GP0 as input, others as output
    GPIO = 0x00;           // Clear outputs
    ANSEL = 0x00;          // All pins digital
    CMCON = 0x07;          // Disable comparators

    prev_gpio = GPIO;      // Save initial GPIO state

    // Enable interrupt-on-change
    INTCONbits.GPIE = 1;   // Enable GPIO change interrupt
    INTCONbits.GIE = 1;    // Enable global interrupts
    IOCbits.IOC3 = 1;

    while (1) {
        // Main loop idle; all work in ISR
    }
}