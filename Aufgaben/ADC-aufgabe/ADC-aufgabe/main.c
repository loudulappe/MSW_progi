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
        uint16_t auslese = 0;
        auslese = adcRead(0);
        ledWriteAll(auslese);
    }
}

