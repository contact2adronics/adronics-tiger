

#ifndef RC5_INCLUDED
        #define RC5_INCLUDED
        #define IR_ip PINB.7

        #ifndef _MEGA32_INCLUDED_
                #include <mega32.h>
        #endif
        #ifndef TIMER0_USED
                unsigned int get_rc5(); 
        #else
              #error *** TIMER0 is in use. Can not use rc5 function :( ***
        #endif        
        
#endif