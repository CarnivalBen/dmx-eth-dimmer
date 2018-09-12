#pragma warning disable 373
#pragma warning disable 359

// PIC16F877A Configuration Bit Settings

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = ON       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON      // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include "enc28j60.h"

#define TXBUFFER_START 0x1C00
#define RXBUFFER_START 0x0000
#define DEFAULT_IP { 192, 168, 178, 200 }
#define MAC_ADDRESS { 0x12, 0x4E, 0x04, 0x0A, 0x00, 0x00}
#define DEFAULT_DMXCHANNEL 10

#define CFG_RED TRISEbits.TRISE0 = 0; RE0 = 0
#define CFG_GRN TRISEbits.TRISE0 = 0; RE0 = 1
#define CFG_OFF TRISEbits.TRISE0 = 1
#define ETH_RED TRISEbits.TRISE1 = 0; RE1 = 0
#define ETH_GRN TRISEbits.TRISE1 = 0; RE1 = 1
#define ETH_OFF TRISEbits.TRISE1 = 1



// RA0 = IP1 SAVE
// RA1 = IP2 SAVE
// RA2 = IP3 SAVE
// RA3 = IP4 SAVE
// RA4 = DMX ADDRESS HIGH BYTE SAVE
// RA5 = DMX ADDRESS LOW BYTE SAVE

// RB0 = CONFIG BIT 0
// RB1 = CONFIG BIT 1
// RB2 = CONFIG BIT 2
// RB3 = CONFIG BIT 3
// RB4 = CONFIG BIT 4
// RB5 = CONFIG BIT 5
// RB6 = CONFIG BIT 6
// RB7 = CONFIG BIT 7

// RC0 = SLAVE CLOCK
// RC1 = SLAVE DATA
// RC2 = ENC28J60 RESET
// RC3 = ENC28J60 SPI CLOCK
// RC4 = ENC28J60 SPI DATA IN
// RC5 = ENC28J60 SPI DATA OUT
// RC6 = ENC28J60 INTERRUPT
// RC7 = ENC28J60 CHIP SELECT

// RD0 = SLAVE CH1 SELECT
// RD1 = SLAVE CH2 SELECT
// RD2 = SLAVE CH3 SELECT
// RD3 = SLAVE CH4 SELECT
// RD4 = SLAVE CH5 SELECT
// RD5 = SLAVE CH6 SELECT
// RD6 = SLAVE CH7 SELECT
// RD7 = SLAVE CH8 SELECT

// RE0 = CONFIG STORE STATUS LED
// RE1 = ETHERNET STATUS LED
// RE2 = 

word handlePacket(packetinfo* packet);
void writeEEPROM(byte address, byte data);
byte readEEPROM(byte address);

ipaddr ip;
macaddr mac;
volatile word dmxchannel;
volatile byte dmx[8] = {0, 0, 0, 0, 0, 0, 0, 0};

const byte dmxmap[] = { 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
    0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05,
    0x05, 0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x08, 0x08, 0x08, 0x09, 0x09, 0x0A, 0x0A, 0x0B, 0x0B,
    0x0C, 0x0C, 0x0D, 0x0D, 0x0E, 0x0F, 0x0F, 0x10, 0x11, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
    0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1F, 0x20, 0x21, 0x23, 0x24, 0x26, 0x27, 0x29, 0x2B, 0x2C,
    0x2E, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3A, 0x3C, 0x3E, 0x40, 0x43, 0x45, 0x47, 0x4A, 0x4C, 0x4F,
    0x51, 0x54, 0x57, 0x59, 0x5C, 0x5F, 0x62, 0x64, 0x67, 0x6A, 0x6D, 0x70, 0x73, 0x76, 0x79, 0x7C,
    0x7F, 0x82, 0x85, 0x88, 0x8B, 0x8E, 0x91, 0x94, 0x97, 0x9A, 0x9C, 0x9F, 0xA2, 0xA5, 0xA7, 0xAA,
    0xAD, 0xAF, 0xB2, 0xB4, 0xB7, 0xB9, 0xBB, 0xBE, 0xC0, 0xC2, 0xC4, 0xC6, 0xC8, 0xCA, 0xCC, 0xCE,
    0xD0, 0xD2, 0xD3, 0xD5, 0xD7, 0xD8, 0xDA, 0xDB, 0xDD, 0xDE, 0xDF, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5,
    0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xED, 0xEE, 0xEF, 0xEF, 0xF0, 0xF1, 0xF1, 0xF2,
    0xF2, 0xF3, 0xF3, 0xF4, 0xF4, 0xF5, 0xF5, 0xF6, 0xF6, 0xF6, 0xF7, 0xF7, 0xF7, 0xF8, 0xF8, 0xF8,
    0xF9, 0xF9, 0xF9, 0xF9, 0xFA, 0xFA, 0xFA, 0xFA, 0xFA, 0xFB, 0xFB, 0xFB, 0xFB, 0xFB, 0xFB, 0xFC,
    0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD,
    0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF
};

int main(void) {
    
           
    ADCON0bits.ADON = 0;
    ADCON1bits.PCFG = 0b0110;
    TRISA = 0b00111111;
    TRISB = 0b11111111;
    TRISC = 0b01010000;
    TRISD = 0b00000000;
    TRISE = 0b00000011;
       
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;   
    
    CFG_RED;
    _delaywdt(1000000);
    CFG_GRN;
    _delaywdt(1000000);
    CFG_OFF;
    ETH_RED;
    _delaywdt(1000000);
    ETH_GRN;
    _delaywdt(1000000);
    ETH_OFF;
    
    OPTION_REGbits.nRBPU = 0;
    OPTION_REGbits.PSA = 1;
    OPTION_REGbits.PS = 0b111;
        
    // Read IP + MAC from eeprom
    ip.b1 = readEEPROM(0x00);
    CLRWDT();
    if (ip.b1 == 0 || ip.b1 == 0xFF) {
        const char ipa[4] = DEFAULT_IP;
        ip.b1 = ipa[0];
        ip.b2 = ipa[1];
        ip.b3 = ipa[2];
        ip.b4 = ipa[3];
        writeEEPROM(0x00, ip.b1);
        writeEEPROM(0x01, ip.b2);
        writeEEPROM(0x02, ip.b3);
        writeEEPROM(0x03, ip.b4);
        
    } else {
        ip.b2 = readEEPROM(0x01);
        ip.b3 = readEEPROM(0x02);
        ip.b4 = readEEPROM(0x03);
    }
    
    dmxchannel = (readEEPROM(0x04) << 8) | readEEPROM(0x05);
    if (dmxchannel > 512 || dmxchannel == 0) {
        dmxchannel = DEFAULT_DMXCHANNEL;
        writeEEPROM(0x04, dmxchannel >> 8);
        writeEEPROM(0x05, dmxchannel & 0xFF);
        CLRWDT();
    }
    
    const char mca[6] = MAC_ADDRESS;
    mac.b1 = mca[0];
    mac.b2 = mca[1];
    mac.b3 = mca[2];
    mac.b4 = mca[3];
    mac.b5 = mca[4];
    mac.b6 = ip.b4;  
    
    initSPI();
    CLRWDT();
    initENC28J60(0, TXBUFFER_START, RXBUFFER_START, &mac, &ip);
    CLRWDT();
    
    byte dmxout = 0;
    word dmxupdate = 0xFFFF;
    

    TRISE = 0b00000000;     
    PORTE = 0b00000001;      
    for (byte n = 0; n < 8; n++) {    
        _delaywdt(1000000);
        PORTE = ~PORTE;      
    } 
    TRISE = 0b00000001;

    
    
    while (1) {
        CLRWDT();
        
        // PROCESS ETHERNET PACKETS
        if (RC6 == 0) {
            
            byte intFlags = readReg(EIR);
            
            if (intFlags & EIR_PKTIF) {                
                packetReceive(&handlePacket);
            }
            RE1 = ~RE1;
        }
        
        // SEND DMX TO NODES
        if (dmxchannel < 512) {
            TRISD = 0x00;
            dmxupdate--;
            if (dmxupdate == 0) {        
                RC0 = 0;
                RC1 = 0;
                PORTD = 0x01 << dmxout;
                _delaywdt(200);
                //byte dmxv = dmxmap[dmx[dmxout]];
                byte dmxv = dmx[dmxout];
                for (byte b = 0x01; b != 0; b = b * 2){
                    RC1 = (dmxv & b) ? 1 : 0;
                    RC0 = 1;
                    _delaywdt(200);
                    RC0 = 0;
                    _delaywdt(186);
                }       
                dmxout++;
                if (dmxout >= 8) dmxout = 0;
                PORTD = 0;
                RC1 = 0;
                dmxupdate = 0x0200;
            }
            
        } else { // PROGRAMMING MODE REQUESTED
            TRISD = 0xFF;
            CFG_RED;
            _delaywdt(1000000);
            CFG_OFF;
            _delaywdt(1000000);
        }
        
        // STORE IP ADDRESS/DMX ADDRESS
        if (PORTA != 0b00111111) {
            CFG_RED;
            
            _delaywdt(5000);            
            byte newval = 0; //~PORTB;
            if (RB0 == 0) newval |= 0b10000000;
            if (RB1 == 0) newval |= 0b01000000;
            if (RB2 == 0) newval |= 0b00100000;
            if (RB3 == 0) newval |= 0b00010000;
            if (RB4 == 0) newval |= 0b00001000;
            if (RB5 == 0) newval |= 0b00000100;
            if (RB6 == 0) newval |= 0b00000010;
            if (RB7 == 0) newval |= 0b00000001;
                
            if (RA0 == 0) {
                ip.b1 = newval;
                writeEEPROM(0x00, newval);
                
            } else if (RA1 == 0) {
                ip.b2 = newval;
                writeEEPROM(0x01, newval);
                
            } else if (RA2 == 0) {
                ip.b3 = newval;
                writeEEPROM(0x02, newval);
                
            } else if (RA3 == 0) {
                ip.b4 = newval;
                mac.b6 = newval;
                writeEEPROM(0x03, newval);  
                
            } else if (RA4 == 0) {
                dmxchannel = (newval << 8) | (dmxchannel & 0xFF);
                writeEEPROM(0x04, newval);    
                
            } else if (RA5 == 0) {
                dmxchannel = (dmxchannel & 0xFF00) | newval;
                writeEEPROM(0x05, newval);
            }
            
            initENC28J60(0, TXBUFFER_START, RXBUFFER_START, &mac, &ip);
           
            for (byte n = 0; n < 8; n++) {
                _delaywdt(500000);
                CFG_GRN;
                _delaywdt(500000);
                CFG_OFF;
            }   
            while (PORTA != 0b00111111);
            
        }
        
    }
}


word handlePacket(packetinfo* packet) {
    
    byte artnetid[8];
    word opcode;
    word universe;
    word dmxlength;
    
    if (packet->udp->destinationport != 0x1936) return 0;    
    
    readBufferStart(packet->address);    
    readBuffer(artnetid, 8);
    opcode = readBufferLEWord();
    bufferSkip(2);    
    
//        bufferEnd();
//    writeBufferStart(0x1FF0);
//    RB1 = 1; RB1 = 0;
//    writeBufferWord(opcode);
//    bufferEnd();
    
    if (artnetid[0] != 'A' || artnetid[1] != 'r' || artnetid[2] != 't') {
        bufferEnd();
        return 0;
    }    
    
    if (opcode == 0x5000) {
        bufferSkip(2);
        universe = readBufferWord();
        dmxlength = readBufferWord();
        //RB2 = RB2 == 1 ? 0 : 1;
        if (dmxlength >= dmxchannel) {
            bufferSkip(dmxchannel - 1);
            readBuffer(((byte*)&dmx), 8);            
            
            bufferEnd();
            return 0;
        }
    }
    
    
    
    bufferEnd();
    return 0;
}

void writeEEPROM(byte address, byte data) {
    
    while (EECON1bits.WR);
    EEADR = address;
    EEDATA = data;
    EEPGD = 0;
    EECON1bits.WREN = 1;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    EECON1bits.WREN = 0;
    while (EECON1bits.WR);
    
}

byte readEEPROM(byte address) {

    EEADR = address;
    EEPGD = 0;
    EECON1bits.RD = 1;
    return EEDATA;
    
}

