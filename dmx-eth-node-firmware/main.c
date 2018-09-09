
// PIC12F1571 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    //  (INTOSC oscillator; I/O function on CLKIN pin)
#pragma config WDTE = ON       // Watchdog Timer Enable (WDT disabled)
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
#pragma config LVP = OFF         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <pic12f1571.h>

typedef unsigned char byte;
typedef unsigned int word;

volatile byte dmxrx;
volatile byte dmxrxp;
volatile byte dmx;

word zctmr;


void alert() {

    RA1 = 1;
    _delaywdt(1000000);
    RA1 = 0;
    _delaywdt(1000000);
    
    RA1 = 1;
    _delaywdt(3000000);
    RA1 = 0;
    _delaywdt(1000000);
    
    RA1 = 1;
    _delaywdt(1000000);
    RA1 = 0;
    _delaywdt(1000000);
    
    RA1 = 1;
    _delaywdt(3000000);
    RA1 = 0;
    _delaywdt(1000000);
    
    
}

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
            
            _delaywdt(30);
            iocclear = 0b11101111;  
            if (!RA4) {

                // STORE TIMER VALUES                
                zctmr = TMR1;
                TMR1 = 0;
                RA1 = 0;
                
            }                           
        }        
        INTCONbits.IOCIF = 0;
        IOCAF &= iocclear;
    }
       

}

void main(void) {
    
    CLRWDT();
    
    // Configure Oscillator
    OSCCON = 0b01111010;
    
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
    
    INTCONbits.GIE = 1;
    
    _delaywdt(10000);
    
    dmx = 128;
    
    while(1) {

        word mark = (word)(zctmr - (((unsigned long)zctmr * dmx) >> 8));
        if (TMR1 >= mark) RA1 = 1;

        CLRWDT();
    }
}
