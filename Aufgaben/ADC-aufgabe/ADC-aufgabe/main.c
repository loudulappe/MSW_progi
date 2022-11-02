/*
 * ADC-aufgabe.c
 *
 * Created: 03.10.2022 14:41:08
 * Author : e1Derung
 */ 

#include "ADtreiber.h"


int main(void)
{
    initAdc();
    initBoard();
    while (1) 
    {
        adcRead(8);
        uint16_t spannung= 3*100;
        ledWriteAll(~(0xffff>>(1600/((5*10000)/spannung))));
    }
}