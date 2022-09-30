/*
 * ADtreiber.c
 *
 * Created: 29.09.2022 14:22:08
 *  Author: e1Derung
 */ 
#include "ADtreiber.h"

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
void ledWrite(uint16_t ledNr0_15, uint8_t wert0_1)
{
    if (wert0_1)
    {
        PORTA = PORTA | 1<< (ledNr0_15-1);
        PORTB = PORTB | ((ledNr0_15>7)<<(ledNr0_15-8));
    } 
    else
    {
        PORTA = PORTA & ~(1<< (ledNr0_15-1));
        PORTB = PORTB & ~((ledNr0_15>7)<<(ledNr0_15-8)) ;       
    }
} 
uint16_t ledReadAll()
{
    return PORTA|(PORTB<<8);
}