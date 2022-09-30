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