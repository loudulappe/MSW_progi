/*
 * SchalterTest.c
 *
 * Created: 26.10.2022 15:26:16
 * Author : e1Derung
 */ 

#include "ADtreiber.h"

int main(void)
{
    initBoard();
    while (1) 
    {
        PORTA = PINC;
    }
}

