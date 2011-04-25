

#include "rc5.h"

unsigned int get_rc5()  {
        
        unsigned char RC5[14];
        unsigned int rc5_code;
        
        #if _MCU_CLOCK_FREQUENCY_ 16000000
                // Timer/Counter 0 initialization
                // Clock source: System Clock
                // Clock value: 15.625 kHz
                // Mode: Normal top=FFh
                // OC0 output: Disconnected
                TCCR0=0x05;
                TCNT0=0x00;
                OCR0=0x00;       
                
                #define count1 21
                #define count2 28
        #elif _MCU_CLOCK_FREQUENCY_ 8000000
                // Timer/Counter 0 initialization
                // Clock source: System Clock
                // Clock value: 31.250 kHz
                TCCR0=0x04;
                TCNT0=0x00;
                
                #define count1 42
                #define count2 55
        #endif                   
        
        /*                                                             
        |bit1 |bit2 |bit3 |bit4 |bit5 |bit6 |bit7 |bit8 |bit9 |bit10|bit11|bit12|bit13|bit14|
        |-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|   
      __    __    _____    __    __       _____       __    __    _____       _____       __
        |  |  |  |     |  |  |  |  |     |     |     |  |  |  |  |     |     |     |     |  |
        |__|  |__|     |__|  |__|  |_____|     |_____|  |__|  |__|     |_____|     |_____|  |
        |--1--|--1--|--0--|--0--|--0--|--1--|--0--|--1--|--1--|--1--|--0--|--1--|--0--|--1--|
        |<-Startbit 1 & 2>|<TGL>|<----------ADDRESS---------->|<----------Command---------->| 
        
        Algo:
        1. Start counter at first falling edge
        2. After (1.5 x 889) uSec Capture bit1 and reset counter
        3. Capture bit 2-14 after 2x889 uSec interval each
        3. After capturing all 14 bit make sure both start bits are 1 else discard 
        
        Note: Here for Counter freq 31.25KHz (T=32uSec)1.5x889 uSec => count value 42
                                                         2x889 uSec => count Value 55
        For more details Read:
                http://ashishd.wordpress.com/2009/02/15/infrared-remote-control-rc-5/   
        */ 
      
        //0
        
        // Wait for Falling edge  
        while(IR_ip);
      
        TCNT0=0x0;
        while(~IR_ip);
        while(TCNT0<21);
        //printf("%u",TCNT0);
        TCNT0=0;         
        RC5[0]= IR_ip;
              
        while(TCNT0<28);
        TCNT0=0;         
        RC5[1]= IR_ip;
              
        while(TCNT0<28);
        TCNT0=0;         
        RC5[2]= IR_ip;
              
        while(TCNT0<28);
        TCNT0=0;         
        RC5[3]= IR_ip;
              
        while(TCNT0<28);
        TCNT0=0;         
        RC5[4]= IR_ip;
              
        while(TCNT0<28);
        TCNT0=0;         
        RC5[5]= IR_ip;
              
        while(TCNT0<28);
        TCNT0=0;         
        RC5[6]= IR_ip;
              
        while(TCNT0<28);
        TCNT0=0;         
        RC5[7]= IR_ip;
              
        while(TCNT0<28);
        TCNT0=0;         
        RC5[8]= IR_ip;
              
        while(TCNT0<28);
        TCNT0=0;         
        RC5[9]= IR_ip;
              
        while(TCNT0<28);
        TCNT0=0;         
        RC5[10]= IR_ip;
              
        while(TCNT0<28);
        TCNT0=0;         
        RC5[11]= IR_ip;
              
        while(TCNT0<28);
        TCNT0=0;         
        RC5[12]= IR_ip;
      
        while(TCNT0<28);
        TCNT0=0;         
        RC5[13]= IR_ip;
        
        rc5_code = (unsigned int) (RC5[13] | RC5[12]<<1 | RC5[11]<<2 \
                        | RC5[10]<<3 | RC5[9]<<4 | RC5[8]<<5 | RC5[7]<<6 \
                        | RC5[6]<<7 | RC5[5]<<8 | RC5[4]<<9 | RC5[3]<<10 \
                        | RC5[2]<<11 | RC5[1]<<12 | RC5[0]<<13);
        return rc5_code;
}