
// PIC12F1571 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    //  (INTOSC oscillator; I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = OFF       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = ON       // PLL Enable (4x PLL enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOREN = OFF    // Low Power Brown-out Reset enable bit (LPBOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <pic12f1571.h>

typedef unsigned char byte;
typedef unsigned int word;

volatile byte dmxrx;
volatile byte dmxrxp;
volatile byte dmx;

#define AVG_SAMPLE 16
#define ZC_TIMER_TOLERANCE 32
volatile byte lockdown; // TOLERANCE LOCKDOWN - CHECK TOLERANCES WHEN BELOW 0x7F
volatile word zc[AVG_SAMPLE];
volatile byte zcptr;
volatile word zcavg;
volatile word pwmsync;
volatile signed char bias;

void __interrupt() isr(void) {
    
    
    if (INTCONbits.IOCIE && INTCONbits.IOCIF) {
        
        byte iocclear = 0xFF;
        
        // CHIP SELECT START
        if (IOCAFbits.IOCAF0 && RA0) {

            IOCAPbits.IOCAP2 = 1;  // Switch on clock interrupt
            dmxrxp = 0b00000001;   // Set up receive pointer     
            dmxrx = 0;             // Clear DMX RX ready for new value
            iocclear = 0b11111110;
            
        }

        // RECEIVE BIT
        else if (IOCAFbits.IOCAF2) {

            if (RA5) dmxrx |= dmxrxp;
            dmxrxp *= 2;
            iocclear = 0b11111011;
            
        }
        
        // CHIP SELECT END
        else if (IOCAFbits.IOCAF0 && !RA0) {
        
            IOCAPbits.IOCAP2 = 0;
            iocclear = 0b11111110;
                                
            dmx = dmxrx;            
                     
        }
        
        // ZERO CROSSING TRIGGER
        else if (IOCAFbits.IOCAF4 && !RA4) {
            
            _delay(30);
            iocclear = 0b11101111;  
            if (!RA4) {

                // STORE TIMER VALUES
                pwmsync = PWM1TMR;
                word zctmr = TMR1;
                TMR1 = 0;

                // CHECK TOLERANCE
                byte withintolerance = (zctmr > (zcavg - ZC_TIMER_TOLERANCE) && zctmr < (zcavg + ZC_TIMER_TOLERANCE)) ? 1 : 0;
                
                // ONLY UPDATE AVERAGES IF WITHIN TOLERANCE DURING LOCKDOWN
                if (lockdown > 0x7F || withintolerance) {
                    zc[zcptr] = zctmr;
                    zcptr++;
                    if (zcptr >= AVG_SAMPLE) zcptr = 0;
                }
                
                // UPDATE LOCKDOWN
                if (withintolerance && lockdown > 0) lockdown--;                
                if (!withintolerance && lockdown < 255) lockdown++;
                
            }
                           
        }        
        INTCONbits.IOCIF = 0;
        IOCAF &= iocclear;
    }
       

}

void main(void) {
    
    // Configure Oscillator
    OSCCON = 0b01111000;
    
    // PORT SETUP
    INLVLA = 0;
    ANSELA = 0;
    TRISA = 0b00111101;
    TRISAbits.TRISA0 = 1; // CHIP SELECT
    TRISAbits.TRISA1 = 0; // TRIAC OUTPUT
    TRISAbits.TRISA2 = 1; // CLOCK IN
    TRISAbits.TRISA4 = 1; // ZERO CROSS IN
    TRISAbits.TRISA5 = 1; // DATA IN
    ODCONAbits.ODA1 = 0;
    SLRCONAbits.SLRA1 = 0;
    
    
    RA1 = 1;
    _delay(1000000);
    RA1 = 0;
    _delay(1000000);
    
    RA1 = 1;
    _delay(3000000);
    RA1 = 0;
    _delay(1000000);
    
    RA1 = 1;
    _delay(1000000);
    RA1 = 0;
    _delay(1000000);
    
    RA1 = 1;
    _delay(3000000);
    RA1 = 0;
    _delay(1000000);
    
    
    
    
    // IOC INTERRUPT SETUP
    IOCAP = 0;
    IOCAN = 0;
    IOCAPbits.IOCAP0 = 1; // CHIP SELECT RISE INTERRUPT
    IOCAPbits.IOCAP2 = 1; // CLOCK IN RISE INTERRUPT
    IOCANbits.IOCAN0 = 1; // CHIP SELECT FALL INTERRUPT
    IOCANbits.IOCAN4 = 1; // ZERO CROSS PULSE
    INTCONbits.IOCIE = 1;
   
    
    // TIMER 1 SETUP
    APFCONbits.T1GSEL = 0; // T1G configured on RA4
    TMR1 = 0;    
    T1GCONbits.TMR1GE = 0;
    T1CONbits.TMR1CS = 0; // TMR1 uses Fosc/4
    T1CONbits.T1CKPS = 0b10; // TMR1 Prescaler set to /4
    PIE1bits.TMR1GIE = 0;
    INTCONbits.PEIE = 0;
    T1CONbits.TMR1ON = 1;

    
    // PWM SETUP
    APFCONbits.P1SEL = 0; // Set to use RA1
    PWM1CLKCONbits.PS = 0b100; // PWM1 prescaler set to /4
    PWM1CLKCONbits.CS = 0b00; // PWM1 uses Fosc/4
    PWM1LDCONbits.LDT = 0; // Non triggered reload
    PWM1OFCONbits.OFM = 0b00;  // Offset mode independent
    PWM2OFCONbits.OFM = 0b00;  // Offset mode independent
    PWM3OFCONbits.OFM = 0b00;  // Offset mode independent
    PWM1PR = 0x1710;           // Default roughly at 100Hz (half mains cycle)
    PWM1PH = 0x09C4;
    dmx = 64;
    PWM1DC = PWM1PR;
    PWM1LDCONbits.LDA = 1;     // Load params on next period
    PWM1INTFbits.PWM1PRIF = 0; 
    PWM1INTEbits.PWM1PRIE = 1; // Interrupt on PERIOD match
    PWM1CONbits.POL = 0;       // Active high
    PWM1CONbits.MODE = 0b00;   // Standard mode
    PWM1CONbits.OE = 1;        // Output enabled
    PWM1CONbits.EN = 1;        // Module enabled
    
    lockdown = 0xFF;
    zcptr = 0;
    for (byte n = 0; n < AVG_SAMPLE; n++) zc[n] = PWM1PR;    
    
    INTCONbits.GIE = 1;
    
    _delay(10000);
    
    while(1) {
       
        // CALCULATE THE AVERAGE ZC TIME
        unsigned long avg = 0;
        for (byte n = 0; n < AVG_SAMPLE; n++) avg += zc[n];
        zcavg = (avg >> 4) + bias;
        
        // UPDATE TIMER IF AVG CHANGES
        if (zcavg != PWM1PR) {
            PWM1PR = zcavg;
            PWM1DC = PWM1PR;
            if (PWM1PH > PWM1PR) PWM1PH = zcavg;
            PWM1LDCONbits.LDA = 1;
            while (PWM1LDCONbits.LDA);
        }
             
        // APPLY OFFSET TO BRING ZC BACK BEFORE THE ZC PULSE
        word pwmoffset = pwmsync + zcavg - 570;
        if (pwmoffset > zcavg) pwmoffset -= zcavg;
                        
        // SYNC
        word midpoint = zcavg >> 1;        
        if (pwmoffset < midpoint) {
            
            // INCREASE PERIOD TO PULL BACK SYNC
            if (pwmoffset > 2) bias = 1;
            else if (pwmoffset > 16) bias = 2;
            else if (pwmoffset > 32) bias = 8;
            else if (pwmoffset > 64) bias = 48;
            else bias = 0;
            
        } else {
            
            // DECREASE PERIOD TO PUSH FORWARD SYNC
            pwmoffset = zcavg - pwmoffset;
            if (pwmoffset > 2) bias = -1;
            else if (pwmoffset > 16) bias = -2;
            else if (pwmoffset > 32) bias = -8;
            else if (pwmoffset > 64) bias = -48;
            else bias = 0;            
            
        }

                    
        // UPDATE DMX DUTY CYCLE
        word ph = (word)(PWM1PR - (((unsigned long)PWM1PR * dmx) >> 8));
        if (ph != PWM1PH) {               
            PWM1PH = ph;
            PWM1LDCONbits.LDA = 1;                
            while (PWM1LDCONbits.LDA == 1);
        }
 
        
        
    }
}
