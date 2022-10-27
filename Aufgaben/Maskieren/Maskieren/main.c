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
    #define __DELAY_BACKWARD_COMPATIBLE__
    DDRA = 0xff;
    DDRB = 0xff;
    DDRC = 0;
    PORTC = 0xff;
    PORTA = 0xff;
    PORTB = 0xff;
    while (1) 
    {
          
    }
}

