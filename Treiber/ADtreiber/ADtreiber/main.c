/*
 * ADtreiber.c
 *
 * Created: 29.09.2022 13:31:41
 * Author : e1Derung
 */ 

#include "ADtreiber.h"



int main(void)
{    
    initBoard();
    ledWriteAll(0xffff);
    
    
    while (1) 
    {
        ledWrite(13, 1);
        _delay_ms(400);
        ledWrite(13, 0);
        _delay_ms(400);
    }
}




