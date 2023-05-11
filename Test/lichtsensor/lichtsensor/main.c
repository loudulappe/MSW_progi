/*
 * lichtsensor.c
 *
 * Created: 11.05.2023 10:08:22
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"


int main(void)
{
    uint16_t licht=0;
    initBoard(0);
    while (1) 
    {
        licht=adcRead(12);
        ledWriteAll(licht);
        
    }
}

