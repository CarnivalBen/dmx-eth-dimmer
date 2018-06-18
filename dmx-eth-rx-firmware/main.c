#pragma warning disable 373
#pragma warning disable 359

// PIC16F877A Configuration Bit Settings

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include "enc28j60.h"

#define TXBUFFER_START 0x1C00
#define RXBUFFER_START 0x0000
#define DEFAULT_IP { 0xC0, 0xA8, 0xB2, 0x58 }
#define MAC_ADDRESS { 0x12, 0x4E, 0x04, 0x0A, 0x00, 0x00}
#define DEFAULT_DMXCHANNEL 33


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

volatile ipaddr ip;
volatile macaddr mac;
volatile word dmxchannel;
volatile byte dmx[8] = {0, 0, 0, 0, 0, 0, 0, 0};

int main(void) {
   
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
    
    OPTION_REGbits.nRBPU = 0;
        
    // Read IP + MAC from eeprom
    ip.b1 = readEEPROM(0x00);
    
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
    
    dmxchannel = (readEEPROM(0x04) << 8) || readEEPROM(0x05);
    if (dmxchannel == 0) {
        dmxchannel = DEFAULT_DMXCHANNEL;
        writeEEPROM(0x04, dmxchannel >> 8);
        writeEEPROM(0x05, dmxchannel | 0xFF);
    }
    
    const char mca[6] = MAC_ADDRESS;
    mac.b1 = mca[0];
    mac.b2 = mca[1];
    mac.b3 = mca[2];
    mac.b4 = mca[3];
    mac.b5 = mca[4];
    mac.b6 = ip.b4;  
    
    initSPI();
    initENC28J60(0, TXBUFFER_START, RXBUFFER_START, &mac, &ip);
    
    byte dmxout = 0;
    word dmxupdate = 0xFFFF;
    
    while (1) {
        
        // PROCESS ETHERNET PACKETS
        if (RC6 == 0) {
            byte intFlags = readReg(EIR);
            
            if (intFlags & EIR_PKTIF) {                
                packetReceive(handlePacket);
            }
        }
        
        // SEND DMX TO NODES
        dmxupdate--;
        if (dmxupdate == 0) {        
            RC0 = 0;
            RC1 = 0;
            PORTD = 0x01 << dmxout;
            byte dmxv = dmx[dmxout];
            for (byte b = 0x01; b != 0; b = b * 2){
                RC1 = dmxv & b ? 1 : 0;
                RC0 = 1;
                _delay(15);
                RC0 = 0;
                _delay(15);
            }       
            dmxout++;
            if (dmxout >= 8) dmxout = 0;
            PORTD = 0;
            dmxupdate = 0x0200;
        }
        
        
        // STORE IP ADDRESS/DMX ADDRESS
        if (PORTA != 0b00111111) {
            TRISEbits.TRISE0 = 0;
            RE0 = 0;
            
            _delay(500);
            byte newval = ~PORTB;
            if (RA0 == 0) {
                ip.b1 = newval;
                writeEEPROM(0x00, newval);
                
            } else if (RA1 = 0) {
                ip.b2 = newval;
                writeEEPROM(0x01, newval);
                
            } else if (RA2 = 0) {
                ip.b3 = newval;
                writeEEPROM(0x02, newval);
                
            } else if (RA3 = 0) {
                ip.b4 = newval;
                mac.b6 = newval;
                writeEEPROM(0x03, newval);  
                
            } else if (RA4 = 0) {
                dmxchannel = (newval << 8) | (dmxchannel & 0xFF);
                writeEEPROM(0x04, newval);    
                
            } else if (RA5 = 0) {
                dmxchannel = (dmxchannel & 0xFF00) | newval;
                writeEEPROM(0x05, newval);
            }
            
            initENC28J60(0, TXBUFFER_START, RXBUFFER_START, &mac, &ip);
           
            for (byte n = 0; n < 8; n++) {
                _delay(500000);
                RE0 = ~RE0;
            }   
            while (PORTA != 0b00111111);
            TRISEbits.TRISE0 = 1;
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
        if (dmxlength >= DEFAULT_DMXCHANNEL) {
            bufferSkip(DEFAULT_DMXCHANNEL - 1);
            readBuffer(&dmx, 8);            
            
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