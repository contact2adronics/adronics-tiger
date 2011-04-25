

#ifndef ADC_INCLUDED
        #define ADC_INCLUDED

        #ifndef ADC_VREF_TYPE  
                #define ADC_VREF_TYPE 0x00
        #endif

        unsigned int read_adc(unsigned char adc_input);

#endif