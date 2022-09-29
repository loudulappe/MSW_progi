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
    uint8_t counter = 0;
    uint8_t i = 0;
    DDRA = 0xff;
    DDRB = 0xff;
    while (1)
    {
        counter = 0;
        for (i = 0; i < 10; i++)
        {
            PORTA = counter;
            PORTB = 0; 
            _delay_ms(1000);
            counter = counter + 1;
        }        
    }
       
}


