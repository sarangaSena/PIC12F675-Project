/*
 * File:   main.c
 * Author: saranga Senarathna
 *
 * Created on June 2, 2025, 4:01 PM
 */

#include "main.h"


void main(void) {
    
    ANSEL &= ~(1 << 0)|~(1 << 3);   //  GP0 and GP3 are digital
    
    TRISIO &= ~(1 << 0);    // GP0 = output,
    TRISIO |= (1 << 3);     // GP3 = input,
    GPIO &= ~(1 << GPIO0);  //clear GP0

    while (1) {
        
        if (GPIO & (1 << 3)) {          //check GP3 is High
            
         GPIO |= (1 << GPIO0);          // Set GP0 high (turn ON LED)
         __delay_ms(500);
         GPIO &= ~(1 << GPIO0);         // Set GP0 low (turn OFF LED)
         __delay_ms(500);

        }else
        {
           GPIO &= ~(1 << GPIO0);       //Set GP0 low 
        }

      
    }
}
