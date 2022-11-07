/*
 * struktogramm test.c
 *
 * Created: 07.11.2022 14:14:07
 * Author : e1Derung
 */ 

#include "ADtreiber.h"


int main(void)
{
    initBoard();
    while (1) 
    {
        for (uint8_t i=0; i<16; i=i+1)
        {
            ledWriteAll(0x5555);
            ledWriteAll(ledReadAll()&~(1<<i));
            _delay_ms(100);
        }
    }
}

