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
    uint8_t zaehler = 0;
    DDRA = 0xff;
    DDRB = 0xff;
    for (zaehler = 0; zaehler < 10; zaehler++)
    {
        PORTA = 0;
        PORTB = 0; 
        _delay_ms(500);
        PORTA = 255;
        PORTB = 255;
        _delay_ms(500); 
        //zaehler = zaehler + 1;
    }   
}


