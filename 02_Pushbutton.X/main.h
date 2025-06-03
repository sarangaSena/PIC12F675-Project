/* 
 * File:   main.h
 * Author: saran
 *
 * Created on June 3, 2025, 2:30 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#pragma config FOSC = INTRCIO   // Use internal oscillator
#pragma config WDTE = OFF       // Disable watchdog timer
#pragma config PWRTE = ON       // Enable power-up timer
#pragma config MCLRE = OFF      // Use GP3 as I/O, not reset
#pragma config BOREN = OFF      // Disable brown-out reset
#pragma config CP = OFF         // Disable code protection
#pragma config CPD = OFF        // Disable data EEPROM protection

#include <xc.h>
#define _XTAL_FREQ 4000000

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

