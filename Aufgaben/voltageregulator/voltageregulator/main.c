/*
 * voltageregulator.c
 *
 * Created: 15.05.2023 16:24:57
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"

int main(void)
{
    uint32_t messwert=0;
    uint8_t out=0;
    initBoard(0);
    DDRL=DDRL|4;
    
    while (1) 
    {
        //messwert=adcRead(0);
        messwert=(uint32_t)adcRead(0)*5000/1023;

        if (messwert>3300)
        {
            PORTL=PORTL|4;
        }
        else
        {
            PORTL=PORTL|~4;
        }
    }
}

