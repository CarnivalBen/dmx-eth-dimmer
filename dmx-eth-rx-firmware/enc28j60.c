#pragma warning disable 373
#pragma warning disable 359
#pragma warning disable 751

#include <xc.h>
#include "enc28j60.h"

volatile byte enc28j60bank;
volatile ipaddr localip;
volatile macaddr localmac;
volatile byte duplexmode;
volatile word rxpacketptr;
volatile word txStart;
volatile word txEnd;
volatile word rxStart;
volatile word rxEnd;
volatile word ipid = 0;

void initSPI() {
    
    TRISC2 = 0; // RESET
    TRISC3 = 0; // SCK
    TRISC4 = 1; // SDI
    TRISC5 = 0; // SDO
    TRISC7 = 0; // CS
    RC2 = 1;    // DEFAULT RESET HIGH
    RC7 = 1;    // DEFAULT CS STATE HIGH    
    SSPSTATbits.SMP = 0;
    SSPSTATbits.CKE = 1;
    SSPCONbits.CKP = 0;
    SSPCONbits.SSPM3 = 0;
    SSPCONbits.SSPM2 = 0;
    SSPCONbits.SSPM1 = 0;
    SSPCONbits.SSPM0 = 1;
    SSPCONbits.SSPEN = 1;    
    
}

void setBank (byte address) {
        
    if (((address & ADDR_MASK) < 0x1B) && ((address & BANK_MASK) != enc28j60bank)) {        
        enc28j60bank = address & BANK_MASK;
        
        RC7 = 0;        
        SSPBUF = ENC28J60_BIT_FIELD_CLR | (ECON1 & ADDR_MASK);
        while (SSPSTATbits.BF == 0);
        SSPBUF = ECON1_BSEL1 | ECON1_BSEL0;
        while (SSPSTATbits.BF == 0);   
        RC7 = 1;
        
        RC7 = 0;        
        SSPBUF = ENC28J60_BIT_FIELD_SET | (ECON1 & ADDR_MASK);
        while (SSPSTATbits.BF == 0);
        SSPBUF = enc28j60bank >> 5;
        while (SSPSTATbits.BF == 0);
        RC7 = 1;

    }    
}

void setBits(byte address, byte mask) {
    
    setBank(address);
 
    RC7 = 0;        
    SSPBUF = ENC28J60_BIT_FIELD_SET | (address & ADDR_MASK);
    while (SSPSTATbits.BF == 0) {}        
    SSPBUF = mask;
    while (SSPSTATbits.BF == 0) {}        
    RC7 = 1;
}

void clrBits(byte address, byte mask) {
    
    setBank(address);
 
    RC7 = 0;        
    SSPBUF = ENC28J60_BIT_FIELD_CLR | (address & ADDR_MASK);
    while (SSPSTATbits.BF == 0) {}        
    SSPBUF = mask;
    while (SSPSTATbits.BF == 0) {}        
    RC7 = 1;
}

void writeReg(byte address, byte data) {
    
    setBank(address);
    
    RC7 = 0;
    SSPBUF = ENC28J60_WRITE_CTRL_REG | (address & ADDR_MASK);
    while (SSPSTATbits.BF == 0) {}
    SSPBUF = data;
    while (SSPSTATbits.BF == 0) {} 
    RC7 = 1;    
}

void writeRegPair(byte address, word data) {
    
    setBank(address);
    
    RC7 = 0;
    SSPBUF = ENC28J60_WRITE_CTRL_REG | (address & ADDR_MASK);
    while (SSPSTATbits.BF == 0) {}
    SSPBUF = data & 0xFF;
    while (SSPSTATbits.BF == 0) {} 
    RC7 = 1;
    
    RC7 = 0;
    SSPBUF = ENC28J60_WRITE_CTRL_REG | ((address + 1) & ADDR_MASK);
    while (SSPSTATbits.BF == 0) {}
    SSPBUF = data >> 8;
    while (SSPSTATbits.BF == 0) {} 
    RC7 = 1;
}

byte readReg(byte address) {
    
    setBank(address);
    
    RC7 = 0;
    SSPBUF = ENC28J60_READ_CTRL_REG | (address & ADDR_MASK);
    while (SSPSTATbits.BF == 0) {}
    SSPBUF = 0;
    while (SSPSTATbits.BF == 0) {} 
    if (address & 0x80) {
        SSPBUF = 0;
        while (SSPSTATbits.BF == 0) {}
    }
    RC7 = 1;
    
    return SSPBUF;    
}

word readRegPair(byte address) {
    
    setBank(address);
    
    RC7 = 0;
    SSPBUF = ENC28J60_READ_CTRL_REG | (address & ADDR_MASK);
    while (SSPSTATbits.BF == 0) {}
    SSPBUF = 0;
    while (SSPSTATbits.BF == 0) {} 
    if (address & 0x80) {
        SSPBUF = 0;
        while (SSPSTATbits.BF == 0) {}
    }
    RC7 = 1;
    
    byte lowbyte = SSPBUF;
 
    RC7 = 0;
    SSPBUF = ENC28J60_READ_CTRL_REG | ((address + 1) & ADDR_MASK);
    while (SSPSTATbits.BF == 0) {}
    SSPBUF = 0;
    while (SSPSTATbits.BF == 0) {} 
    if (address & 0x80) {
        SSPBUF = 0;
        while (SSPSTATbits.BF == 0) {}
    }
    RC7 = 1;
    
    return (SSPBUF << 8) | lowbyte;
}

void writePhyReg(byte address, word data) {
    
    writeReg(MIREGADR, address);
    writeRegPair(MIWR, data);
    while (readReg(MISTAT) & MISTAT_BUSY) {}    
}

word readPhyReg(byte address) {
    
    writeReg(MIREGADR, address);
    setBits(MICMD, MICMD_MIIRD);
    while (readReg(MISTAT) & MISTAT_BUSY) {}   
    clrBits(MICMD, MICMD_MIIRD);
    
    return readRegPair(MIRD);
}

void reset() {
    
    RC7 = 0;
    SSPBUF = ENC28J60_SOFT_RESET;
    while (SSPSTATbits.BF == 0) {}    
    RC7 = 1;
}

void readBufferStart(word address) {

    writeRegPair(ERDPT, address);
        
    RC7 = 0;
    
    SSPBUF = ENC28J60_READ_BUF_MEM;    
    while (SSPSTATbits.BF == 0) {}
}

byte readBufferByte() {
    
    SSPBUF = 0;
    while (SSPSTATbits.BF == 0) {}
    return SSPBUF;
}

word readBufferWord() {
    
    SSPBUF = 0;
    while (SSPSTATbits.BF == 0) {}
    byte highbyte = SSPBUF;
    
    SSPBUF = 0;
    while (SSPSTATbits.BF == 0) {}
    return (highbyte << 8) | SSPBUF;
}

word readBufferLEWord() {
    
    SSPBUF = 0;
    while (SSPSTATbits.BF == 0) {}
    byte lowbyte = SSPBUF;
    
    SSPBUF = 0;
    while (SSPSTATbits.BF == 0) {}
    return (SSPBUF << 8) | lowbyte;
}

void readBuffer(byte* address, byte bytes) {

    if (bytes == 0) return;
    
    while (bytes) {        
        SSPBUF = 0;
        while (SSPSTATbits.BF == 0) {}
        *address = SSPBUF;
        address++;
        bytes--;
    }  
    
}

#define readBufferEnd() RC7 = 1

void writeBufferStart(word address) {

    writeRegPair(EWRPT, address);
        
    RC7 = 0;
    
    SSPBUF = ENC28J60_WRITE_BUF_MEM;    
    while (SSPSTATbits.BF == 0) {}
}

void writeBufferByte(byte data) {
    
    SSPBUF = data;
    while (SSPSTATbits.BF == 0) {}
    
}

void writeBufferWord(word data) {
    
    SSPBUF = data >> 8;
    while (SSPSTATbits.BF == 0) {}    
    
    SSPBUF = data;
    while (SSPSTATbits.BF == 0) {}
}

void writeBufferLEWord(word data) {
    
    SSPBUF = data;
    while (SSPSTATbits.BF == 0) {}    
    
    SSPBUF = data >> 8;
    while (SSPSTATbits.BF == 0) {}
}

void writeBuffer(byte* address, byte bytes) {

    if (bytes == 0) return;
    
    while (bytes) {        
        SSPBUF = *address;
        while (SSPSTATbits.BF == 0) {}       
        address++;
        bytes--;
    }  
    
}

#define writeBufferEnd() RC7 = 1


void bufferSkip(byte bytes) {
    
    if (bytes == 0) return;
    
    while (bytes) {        
        SSPBUF = 0;
        while (SSPSTATbits.BF == 0) {}               
        bytes--;
    }
}

void copy(word from, word to, byte bytes) {
    
    if (bytes < 2) return;  
   
    writeRegPair(EDMAST, from);
    writeRegPair(EDMAND, from + bytes - 1);
    writeRegPair(EDMADST, to);
    clrBits(ECON1, ECON1_CSUMEN);
    setBits(ECON1, ECON1_DMAST);
  
    word timeout = 0xFFFF;
    while ((readReg(ECON1) & ECON1_DMAST) && --timeout > 0);
    clrBits(ECON1, ECON1_DMAST);
  
}

word checksum(word from, byte bytes) {
       
    if (bytes < 2) return 0;

    union {
        unsigned long sum;
        struct {
            word checksum;
            word carry;
        };
    } calc;
    calc.sum = 0;
    
    writeRegPair(ERDPT, from);        
    RC7 = 0;    
    SSPBUF = ENC28J60_READ_BUF_MEM;    
    while (SSPSTATbits.BF == 0);
        
    while (bytes > 1) {
        
        SSPBUF = 0;
        while (SSPSTATbits.BF == 0);
        byte highbyte = SSPBUF;

        SSPBUF = 0;
        while (SSPSTATbits.BF == 0);         
        
        calc.sum += ((word)highbyte << 8) | SSPBUF;
        
        bytes--;
        bytes--;
    }
         
    if (bytes == 1) {        
        SSPBUF = 0;
        while (SSPSTATbits.BF == 0);        
        calc.sum += ((word)SSPBUF) << 8;
    }
    
    RC7 = 1;
    
    while (calc.carry) {
        byte carry = calc.carry;        
        calc.carry = 0;
        calc.sum += carry;
    }    
    
    return ~calc.checksum;
        
}

void initENC28J60(byte fullDuplex, word txBuffer, word rxBuffer, macaddr* macAddr, ipaddr* ipAddr) {
    
    localip = *ipAddr;
    localmac = *macAddr;
    txStart = txBuffer;
    rxStart = rxBuffer;
    duplexmode = fullDuplex;
    
    if (txStart > rxStart) {
        txEnd = 0x1FFF;
        rxEnd = txStart - 1;
    } else {
        txEnd = rxStart - 1;
        rxEnd = 0x1FFF;
    }
    
    RC2 = 0; // ENC28J60 Hardware Reset
    _delay(50000);
    RC2 = 1;
    _delay(50000);
    
    
    while (!readReg(ESTAT) & ESTAT_CLKRDY);   
       
    writeRegPair(ERXST, rxStart);
    writeRegPair(ERXND, rxEnd);
    writeRegPair(ERXRDPT, rxEnd);
    writeRegPair(ETXST, txStart);
    writeRegPair(ETXND, txEnd);
    rxpacketptr = rxStart;
    writeReg(ERXFCON, ERXFCON_UCEN | ERXFCON_CRCEN | ERXFCON_BCEN);    
    writeReg(MACON1, MACON1_MARXEN | MACON1_RXPAUS | MACON1_TXPAUS);     
    writeReg(MACON3, (MACON3_FULDPX & fullDuplex) | MACON3_FRMLNEN | MACON3_TXCRCEN | MACON3_PADCFG0);
    writeReg(MACON4, MACON4_DEFER);
    writeReg(MABBIPG, fullDuplex ? 0x15 : 0x12);
    writeRegPair(MAIPG, 0x0C12);
    writeRegPair(MAMXFL, 1518);
    writeReg(MACLCON1, 0x0F);
    writeReg(MACLCON2, 0x37);   
    writeReg(MAADR1, localmac.b1);
    writeReg(MAADR2, localmac.b2);
    writeReg(MAADR3, localmac.b3);
    writeReg(MAADR4, localmac.b4);
    writeReg(MAADR5, localmac.b5);
    writeReg(MAADR6, localmac.b6);
    writePhyReg(PHCON1, PHCON1_PDPXMD & fullDuplex);
    writePhyReg(PHCON2, PHCON2_HDLDIS);
    writeReg(ECON2, ECON2_AUTOINC);
    writeReg(EIE, EIE_INTIE | EIE_PKTIE);
    setBits(ECON1, ECON1_TXRST | ECON1_RXRST);
    _delay(5000);
    clrBits(ECON1, ECON1_TXRST | ECON1_RXRST);
    writeReg(ECON1, ECON1_RXEN);   
    
}


void txPacket(byte length) {
    
    writeRegPair(ETXST, txStart);
    writeRegPair(ETXND, txStart + length);
    clrBits(ESTAT, ESTAT_TXABRT | ESTAT_LATECOL);
    setBits(ECON1, ECON1_TXRST);
    clrBits(ECON1, ECON1_TXRST);
    setBits(ECON1, ECON1_TXRTS);
        
    //RB5 = 1;
    while (readReg(ECON1) & ECON1_TXRTS);       
    //RB5 = 0;
}

void packetReceive(void (*callback)()) {    
    
    word thispacket = rxpacketptr;
    readBufferStart(thispacket);
    
    rxpacketptr = readBufferLEWord();
    
    word pklen = (rxpacketptr < thispacket ? (rxpacketptr + rxEnd) : rxpacketptr) - thispacket;
    if (pklen > 1600) {
        initSPI();
        initENC28J60(duplexmode, txStart, rxStart, &localmac, &localip);
        byte errcount = PORTB >> 4;
        errcount++;
        PORTB = errcount << 4;
        return;
    }
    
    rxstatusvector rxsv;
    rxsv.rxByteCount = readBufferLEWord();
    readBuffer(&rxsv + 2, 2);
    
    eth2info eth2;
    eth2.flags = rxsv.broadcast;
    
    bufferSkip(6);    
    readBuffer(&eth2.remotemac, 6);
    
    word packetType = readBufferWord();
    readBufferEnd();               
    
    if (packetType == PACKETTYPE_ARP) {
        processArp(thispacket + 6 + 14);
    }
       
    
    if (packetType == PACKETTYPE_IPV4) {
        processIP(thispacket + 6 + 14, &eth2, callback);
    }
    
    writeRegPair(ERXRDPT, rxpacketptr == rxStart ? rxEnd : rxpacketptr - 1);    
    setBits(ECON2, ECON2_PKTDEC);      

    
}


void processArp(word bufferAddress) {
    
    word opcode;
    macaddr sendermac;
    ipaddr senderip;
    macaddr targetmac;
    ipaddr targetip;
    
    readBufferStart(bufferAddress + 6);
    word opcode = readBufferWord();
    
    if (opcode != 0x0001) {
        readBufferEnd();
        return;
    }
    
    readBuffer(&sendermac, 6);
    readBuffer(&senderip, 4);
    readBuffer(&targetmac, 6);
    readBuffer(&targetip, 4);
    readBufferEnd();
    
    if (targetip.b1 != localip.b1 
            || targetip.b2 != localip.b2 
            || targetip.b3 != localip.b3 
            || targetip.b4 != localip.b4) return;
    
    writeBufferStart(txStart);
    writeBufferByte(0);
    writeBuffer(&sendermac, 6);    
    writeBuffer(&localmac, 6);
    writeBufferWord(PACKETTYPE_ARP);
    writeBufferWord(0x0001);
    writeBufferWord(0x0800);
    writeBufferByte(0x06);
    writeBufferByte(0x04);
    writeBufferWord(0x0002);
    writeBuffer(&localmac, 6);
    writeBuffer(&localip, 4);
    writeBuffer(&sendermac, 6);
    writeBuffer(&senderip, 4);
    writeBufferEnd();
    
    txPacket(42);
    
}


void processIP(word bufferAddress, eth2info* eth2 , void (*callback)()) {
    
    byte version;
    byte headerlength;    
    byte protocol;
    ipinfo ip;
    
    readBufferStart(bufferAddress);
    byte vl = readBufferByte();
    version = vl >> 4;
    
    if (version != 4) {
        readBufferEnd();
        return;
    }
    
    headerlength = (vl & 0xF) * 4;
    bufferSkip(1);
    ip.iplength = readBufferWord();
    bufferSkip(4);
    ip.ttl = readBufferByte();
    protocol = readBufferByte();
    bufferSkip(2);
    readBuffer(&ip.remoteip, 4);
    readBuffer(&ip.targetip, 4);
    readBufferEnd();
    
    if (protocol == IPPROTOCOL_ICMP 
            && ip.targetip.b1 == localip.b1 
            && ip.targetip.b2 == localip.b2 
            && ip.targetip.b3 == localip.b3
            && ip.targetip.b4 == localip.b4) {
        
        processICMP(bufferAddress + headerlength, eth2, &ip);
        
    }
    
    if (protocol == IPPROTOCOL_UDP 
            && ((ip.targetip.b1 == localip.b1 
              && ip.targetip.b2 == localip.b2 
              && ip.targetip.b3 == localip.b3 
              && ip.targetip.b4 == localip.b4)
            || ip.targetip.b4 == 255)) {
        
        processUDP(bufferAddress + headerlength, eth2, &ip, callback);
        
    }
    
}

void processICMP(word bufferAddress, eth2info* eth2, ipinfo* ip) {
    
    byte icmptype;
    word icmpid;
    word icmpseq;
    word cs;
    
    readBufferStart(bufferAddress);
    icmptype = readBufferByte();
    bufferSkip(3);
    icmpid = readBufferWord();
    icmpseq = readBufferWord();
    readBufferEnd();
    
    if (icmptype != ICMPTYPE_ECHOREQUEST) return;
    
    writeBufferStart(txStart);
    
    writeBufferByte(0);
    
    writeBuffer(&eth2->remotemac, 6);
    writeBuffer(&localmac, 6);
    writeBufferWord(PACKETTYPE_IPV4);
    
    writeBufferByte((4 << 4) | (20 / 4));
    writeBufferByte(0x00);
    writeBufferWord(ip->iplength);
    writeBufferWord(ipid++);
    writeBufferWord(0x0000);
    writeBufferByte(ip->ttl / 2);
    writeBufferByte(IPPROTOCOL_ICMP);
    writeBufferWord(0);
    writeBuffer(&localip, 4);
    writeBuffer(&ip->remoteip, 4);
    
    writeBufferByte(ICMPTYPE_ECHOREPLY);
    writeBufferByte(0);
    writeBufferWord(0);
    writeBufferWord(icmpid);
    writeBufferWord(icmpseq);
    writeBufferEnd();

    copy(bufferAddress + 8, txStart + 1 + 14 + 20 + 8, ip->iplength - 20 - 8);

    cs = checksum(txStart + 1 + 14, 20);
    writeBufferStart(txStart + 1 + 14 + 10);
    writeBufferWord(cs);
    writeBufferEnd();

    cs = checksum(txStart + 1 + 14 + 20, ip->iplength - 20);
    writeBufferStart(txStart + 1 + 14 + 20 + 2);
    writeBufferWord(cs);
    writeBufferEnd();
        
    txPacket(14 + ip->iplength);    
    
}

void processUDP(word bufferAddress, eth2info* eth2, ipinfo* ip, word (*callback)(packetinfo* packet)) {
        
    word cs;
    udpinfo udp;
    packetinfo packet;
    
    readBufferStart(bufferAddress);
    udp.sourceport = readBufferWord();
    udp.destinationport = readBufferWord();
    udp.udplength = readBufferWord();
    bufferSkip(2);
    readBufferEnd();
    
    packet.address = bufferAddress + 8;
    packet.eth2 = eth2;
    packet.ip = ip;
    packet.udp = &udp;
        
    writeBufferStart(txStart);
    
    writeBufferByte(0);
    
    // ETH II
    writeBuffer(&eth2->remotemac, 6);
    writeBuffer(&localmac, 6);
    writeBufferWord(PACKETTYPE_IPV4);
    
    // IPv4
    writeBufferByte((4 << 4) | (20 / 4));
    writeBufferByte(0x00);
    writeBufferWord(0);
    writeBufferWord(ipid++);
    writeBufferWord(0x0000);
    writeBufferByte(128);
    writeBufferByte(IPPROTOCOL_UDP);
    writeBufferWord(0);
    writeBuffer(&localip, 4);
    writeBuffer(&ip->remoteip, 4);
       
    writeBufferEnd();
    
    word pcklen = (*callback)(&packet);
    
//    
//    if (pcklen > 0) {
//
//        writeBufferStart(txStart + 1 + 14 + 2);
//        writeBufferWord(pcklen + 20);
//        
//        cs = checksum(txStart + 1 + 14, 20);
//        writeBufferStart(txStart + 1 + 14 + 10);
//        writeBufferWord(cs);
//        writeBufferEnd();
//
//        txPacket(14 + 20 + pcklen);    
//    }
    
}