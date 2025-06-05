/*
 * File:   main.c
 * Author: saran
 *
 * Created on June 5, 2025, 11:00 PM
 */


#include <xc.h>

// CONFIG
#pragma config FOSC = INTRCIO   // Internal oscillator, GP4/GP5 as I/O
#pragma config WDTE = OFF       // Watchdog Timer disabled
#pragma config PWRTE = ON       // Power-up Timer enabled
#pragma config MCLRE = OFF      // GP3/MCLR pin function is digital I/O
#pragma config BOREN = OFF      // Brown-out Reset disabled
#pragma config CP = OFF         // Code protection off
#pragma config CPD = OFF        // Data code protection off

#define _XTAL_FREQ 4000000      // 4MHz internal oscillator

void __interrupt() ISR(void);

void main() {
    ANSEL = 0;
    CMCON = 0x7;

    // GPIO setup
    TRISIObits.TRISIO1 = 0;
    TRISIObits.TRISIO2 = 1;   // GP2 (INT) as input, others as output
    GPIObits.GP1 = 0;;           // Clear outputs

    // Interrupt setup
    OPTION_REGbits.INTEDG = 0;  // Interrupt on falling edge = 0, Interrupt on rising edge = 1
    INTCONbits.INTE = 1;        // Enable GP2/INT interrupt
    INTCONbits.GIE = 1;         // Enable global interrupts

    while (1) {
        // Main loop does nothing, all action in ISR
    }
}

void __interrupt() ISR(void) {
    if (INTCONbits.INTF) { // External interrupt on GP2
        GPIObits.GP1 = ~GPIObits.GP1;   // Toggle LED on GP1
        INTCONbits.INTF = 0;     // Clear interrupt flag
    }
}