


#ifndef TiGERv10_INCLUDED
#define TiGERv10_INCLUDED

// I2C Bus functions
#asm
   .equ __i2c_port=0x15 ;PORTC
   .equ __sda_bit=1
   .equ __scl_bit=0
#endasm

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x1B ;PORTA
#endasm

#ifndef ADC_VREF_TYPE  
#define ADC_VREF_TYPE 0x00
#endif

#endif