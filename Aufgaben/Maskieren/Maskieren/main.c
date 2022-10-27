/*
 * Maskieren.c
 *
 * Created: 27.10.2022 08:08:06
 * Author : e1Derung
 */ 

#include <avr/io.h>


int main(void)
{
    #include <avr/io.h>
    #define F_CPU 16000000UL
    #define __DELAY_BACKWARD_COMPATIBLE_
    DDRA = 0xff;
    DDRB = 0xff;
    DDRC = 0;
    PORTC = 0xff;
    PORTA = 0xff;
    PORTB = 0xff;
    while (1) 
    {
           if (PINC&(1<<1))
           {
               PORTA=PORTA | 0x03;
           }               
           else
           {
               PORTA=PORTA & 0b11111100;
           }
           if (PINC&(1<<2))
           {
               PORTA=PORTA & 0b10111111;
           } 
           else
           {
               PORTA=PORTA | 0x40;
           }
           if (PINC&(1<<3))
           {
               PORTA=PORTA | 0x80;
           } 
           else
           {
               PORTA=PORTA & 0x7f;
           }
    }
}

