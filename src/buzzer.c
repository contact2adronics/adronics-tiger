

#include "buzzer.h"

void buzzer_on()        {
        // Timer/Counter 2 initialization
        // Clock source: System Clock
        // Clock value: 15.625 kHz
        // Mode: Normal top=FFh
        // OC2 output: Toggle on compare match
        ASSR=0x00;
        TCCR2=0x17;
        TCNT2=0x00;
        OCR2=0x03;                        
}

void buzzer_off()       {
        // Timer/Counter 2 initialization
        // Clock source: System Clock
        // Clock value: 15.625 kHz
        // Mode: Normal top=FFh
        // OC2 output: Toggle on compare match
        ASSR=0x00;
        TCCR2=0x10;
        TCNT2=0x00;
        OCR2=0x03;
}