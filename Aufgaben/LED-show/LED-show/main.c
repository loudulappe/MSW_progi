/*
 * LED-show.c
 *
 * Created: 30.09.2022 11:23:06
 * Author : e1Derung
 */ 

#include "ADtreiber.h"
void lauflicht(uint8_t delay_ms);
void lauflichtRL(uint8_t delay_ms);
void lauflichtFull(uint8_t delay_ms);
void lauflichtFullR(uint8_t delay_ms);
void ladeBalken(uint16_t maximumWert, uint16_t aktuellerWert);


int main(void)
{
    initBoard();
    while (1)
    {
         lauflichtFullR(50);                   //Aufgabe hier einfügen
    }

}

void lauflicht(uint8_t delay_ms)
{
    uint8_t i = 0;
    for (i=0; i<16; i= i+1)
    {
        ledWriteAll(1<<i);
        _delay_ms(delay_ms);
    }
}

void lauflichtRL(uint8_t delay_ms)
{
    uint8_t i = 0;
    for (i=0; i<16; i= i+1)
    {
        ledWriteAll(1<<i);
        _delay_ms(delay_ms);
    }
    uint8_t e = 15;
    for (e=15; e>0; e= e-1)
    {
        ledWriteAll(1<<e);
        _delay_ms(delay_ms);
    }
}

void lauflichtFull(uint8_t delay_ms)
{
    ledWriteAll(0);
    uint8_t i=0;
    for (i=0; i<16; i=i+1)
    {
        PORTA=PORTA|1<<i;
        PORTB=PORTB|((i>7)<<(i-8));
        _delay_ms(delay_ms);
    }
}

void lauflichtFullR(uint8_t delay_ms)
{
    uint8_t i=0;
    for (i=0; i<16; i=i+1)
    {
        ledWriteAll(ledReadAll()^(1<<i));
        _delay_ms(delay_ms);
    }
}

void ladeBalken(uint16_t maximumWert, uint16_t aktuellerWert)
{
    ledWriteAll(~(0xffff>>(1600/((maximumWert*100)/aktuellerWert))));    
}
