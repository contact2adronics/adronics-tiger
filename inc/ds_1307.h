

#ifndef DS_1307_INCLUDED
        #define DS_1307_INCLUDED
        
        #ifndef _MEGA32_INCLUDED_
                #include <mega32.h>
        #endif
        
        #include <delay.h>
        #include <i2c.h>
        # define I2C_BUS_ADDRESS 0xd0

        unsigned char ds1307_read (unsigned char address);
        void ds1307_write (unsigned char address, unsigned char data);
        void rtc_init(unsigned char rs,unsigned char sqwe,unsigned char out);

#endif