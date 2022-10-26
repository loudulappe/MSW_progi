/*
 * ADC-aufgabe.c
 *
 * Created: 03.10.2022 14:41:08
 * Author : e1Derung
 */ 

#include "ADtreiber.h"


int main(void)
{
    initBoard();
    while (1) 
    {
        uint16_t LEDanzahl = 1600/(102300/adcRead(0));
        ledWriteAll(~(0xfff >> LEDanzahl));
    }
}

