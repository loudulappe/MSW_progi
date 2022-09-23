/*
 * GccApplication1.c
 *
 * Created: 23.09.2022 08:19:47
 * Author : e1Derung
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
void initLeds (void);
void LedsEin (void);
void LedsAus (void);
void zeigewert (uint8_t anzeigewert);

int main(void)
{
    while (1) 
    {
        zeigewert(255);
        _delay_ms(1000);
        zeigewert (0);
        _delay_ms(1000);
    }
}



void zeigewert(uint8_t anzeigewert)
{
    PORTA = anzeigewert;
}

void initLeds(void)
{
    DDRA = 0xff;
}
void LedsEin(void)
{
    zeigewert (255);
}
void LedsAus(void)
{
    zeigewert (0);
}
