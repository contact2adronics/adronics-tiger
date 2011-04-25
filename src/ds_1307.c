

#include "ds_1307.h"

unsigned char ds1307_read (unsigned char address)  {
        unsigned char data;
        i2c_start();
        i2c_write(I2C_BUS_ADDRESS);
        i2c_write(address);
        i2c_start();
        i2c_write(I2C_BUS_ADDRESS | 1);
        data=i2c_read(0);
        i2c_stop();
        return data;
}

void ds1307_write (unsigned char address, unsigned char data)  {
        i2c_start();
        i2c_write(I2C_BUS_ADDRESS);
        i2c_write(address);
        i2c_write(data);
        i2c_stop();
        delay_ms(10);
}

void rtc_init(unsigned char rs,unsigned char sqwe,unsigned char out)    {

        unsigned char ctrl_reg = (unsigned char) ( out<<7 | sqwe<<4 | rs );  
        ds1307_write(0x07,ctrl_reg);
        
}