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
    
    while (1); 
    {
        ledWriteAll(0xffff); 
        _delay_ms(100); 
        ledWriteAll(0x0000); 
        _delay_ms(100); 
    }
}




