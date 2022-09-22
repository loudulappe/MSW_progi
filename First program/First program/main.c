/*
* First program.c
*
* Created: 22.09.2022 11:33:37
* Author : e1Derung
*/

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
    DDRA = 0xff; // alles ausgang
    DDRH = 0b00111000;
    PORTH = 0;
    while(1)
    {
        PORTA = 0b10000000; //rechte LEDs
        _delay_ms(90); //leuchten lassen
        PORTA = 0b01000000;  //linke LEDs
        _delay_ms(70);  //leuchten lassen
        PORTA = 0b00100000;
        _delay_ms(55);
        PORTA = 0b00010000;
        _delay_ms(40);
        PORTA = 0b00001000;
        _delay_ms(30);
        PORTA = 0b00000100;
        _delay_ms(30);
        PORTA = 0b00000010;
        _delay_ms(20);
        PORTA = 0b00000001;
        _delay_ms(20);
        
        
        
    }
}
