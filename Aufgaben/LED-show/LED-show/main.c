/*
 * LED-show.c
 *
 * Created: 30.09.2022 11:23:06
 * Author : e1Derung
 */ 

#include "ADtreiber.h"
void aufgabe1(void);
void aufgabe2(void);
void aufgabe3(void);
void aufgabe4(void);
void aufgabe5(void);
void aufgabe6(void);

int main(void)
{
    initBoard();
    while (1)
    {
         aufgabe4();                   //Aufgabe hier einfügen
    }

}

void aufgabe1(void)
{
    uint8_t i = 0;
    for (i=0; i<16; i= i+1)
    {
        ledWriteAll(1<<i);
        _delay_ms(30);
    }
}

void aufgabe2(void)
{
    uint8_t i = 0;
    for (i=0; i<16; i= i+1)
    {
        ledWriteAll(1<<i);
        _delay_ms(30);
    }
    uint8_t e = 15;
    for (e=15; e>0; e= e-1)
    {
        ledWriteAll(1<<e);
        _delay_ms(30);
    }
}

void aufgabe3(void)
{
    ledWriteAll(0);
    uint8_t i=0;
    for (i=0; i<16; i=i+1)
    {
        PORTA=PORTA|1<<i;
        PORTB=PORTB|((i>7)<<(i-8));
        _delay_ms(30);
    }
}

void aufgabe4(void)
{
    uint8_t i=0;
    for (i=0; i<16; i=i+1)
    {
        ledWriteAll(ledReadAll()^(1<<i));
        _delay_ms(30);
    }
}

void aufgabe5(void)
{
    uint16_t readout = 75;
    uint16_t goal =100;
    ledWriteAll(~(0xffff>>(1600/((goal*100)/readout))));    
}
