

#ifndef ADC_INCLUDED
        #define ADC_INCLUDED
        
        #ifndef _MEGA32_INCLUDED_
                #include <mega32.h>
        #endif
                        
        #include <delay.h>
        #ifndef ADC_VREF_TYPE  
                #define ADC_VREF_TYPE 0x00
        #endif

        unsigned int read_adc(unsigned char adc_input);

#endif