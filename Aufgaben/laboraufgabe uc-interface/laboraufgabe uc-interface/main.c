/*
 * laboraufgabe uc-interface.c
 *
 * Created: 07.11.2022 15:37:17
 * Author : e1Derung
 */ 

#include "ADtreiber.h"


int main(void)
{
    initBoard();
    DDRF = DDRF|0x01;
    PORTF = PORTF|0x01;
    while (1) 
    {
        if (SwitchReadAll()&0x01)
        {
            PORTF = PORTF|0x01;
        } 
        else
        {
            PORTF=PORTF&0xfe;
        }
    }
}

