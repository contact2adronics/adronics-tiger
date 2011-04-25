


#ifndef Buzzer_INCLUDED
        #define Buzzer_INCLUDED 
        #ifndef _MEGA32_INCLUDED_
                #include <mega32.h>
        #endif
        #ifndef TIMER2_USED
                void buzzer_on();
                void buzzer_off();
        #else
              #error *** TIMER2 is in use. Can not use buzzer function :( ***
        #endif

#endif