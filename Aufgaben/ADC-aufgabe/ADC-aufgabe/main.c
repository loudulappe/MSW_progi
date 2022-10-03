/*
 * ADC-aufgabe.c
 *
 * Created: 03.10.2022 14:41:08
 * Author : e1Derung
 */ 

#include <avr/io.h>
#include "ADtreiber.h"


int main(void)
{
    initBoard();
    while (1) 
    {
        ledWriteAll(adcRead(8));
    }
}

