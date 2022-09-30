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
    ledWriteAll(0);
    
    
    while (1) 
    {
        ledWrite(1, 0);
        _delay_ms(200);
        ledWrite(15, 0);
        _delay_ms(400);
    }
}




