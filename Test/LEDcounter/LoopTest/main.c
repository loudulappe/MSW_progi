/*
 * LoopTest.c
 *
 * Created: 29.09.2022 08:40:38
 * Author : e1Derung
 */ 

#include <avr/io.h>


#define F_CPU 16000000UL
#include <util/delay.h>
/* Replace with your application code */



int main(void)
{
    uint16_t i = 0;
    uint16_t counter = 0;
    DDRA = 0xff;
    DDRB = 0xff;
    while (1)
    {
        counter = 0;
        for (i = 0; i < 9999999999; i++)
        {
            PORTA = counter;
            _delay_ms(30);
            counter = counter + 1;
            PORTB = (counter >> 8);           
        }        
    }
       
}


