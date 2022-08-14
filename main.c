/*
 * File:   main.c
 * Author: Fabio Jr. Rossi.
 *
 * Main file of the project.
 */

// PIC16F628A Configuration Bit Settings
#pragma config FOSC = INTOSCCLK // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 4000000      // Frequency setting in 4 Mhz, needed to use __delay_ms function.
#include <xc.h>                 // Standard compiler library.

void main(void) {
    
    CMCON = 0x07;               // Disables PORTA comparators, necessary to use the pins in digital setting.        
    TRISAbits.TRISA0 = 0;       // RA0(Led) configured as output.
    
    while(1) {                  // Infinity loop.
        PORTAbits.RA0 = 1;      // Led on.
        __delay_ms(1000);       // Wait 1 second.
        PORTAbits.RA0 = 0;      // Led off.
        __delay_ms(1000);       // Wait 1 second.
    }
    
    return;                     
}

