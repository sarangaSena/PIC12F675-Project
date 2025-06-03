/*
 * File:   main.c
 * Author: Saranga Senarathna
 *
 * Created on June 3, 2025, 12:19 PM
 */

#include "main.h"


void main(void) {
    
    ANSEL &= ~(1 << 0);   //  GP0 is digital
    
    TRISIO &= ~(1 << 0);  // GP0 = output,
    GPIO &= ~(1 << GPIO0); //clear GP0

    while (1) {   
         GPIO |= (1 << GPIO0);        // Set GP0 high (turn ON LED)
         __delay_ms(500);
         GPIO &= ~(1 << GPIO0);       // Set GP0 low (turn OFF LED)
         __delay_ms(500); 
    }
}
