/*
 * ADtreiber.c
 *
 * Created: 29.09.2022 13:31:41
 * Author : e1Derung
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
void initBoard (void);
void ledWriteAll (uint16_t bitmuster);



int main(void)
{    
    while (1) 
    {
        initBoard;
        ledWriteAll(1400);
    }
}
void initBoard(void)
{
     DDRA = 0xff;
     DDRB = 0xff;
}
void ledWriteAll(uint16_t bitmuster)
{
    PORTA = bitmuster;
    PORTB = bitmuster >>8;
}

