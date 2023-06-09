/*
 * rgb_control.c
 *
 * Created: 12.05.2023 15:26:58
 * Author : Fabrin
 */ 

#include "ucBoardDriver.h"

int main(void)
{
    uint16_t blueval=0;
    uint16_t redval=0;
    uint16_t greenval=0;
    uint16_t diff=0;
    uint16_t across=0;
    initBoard(0);

    while (1) 
    {
        blueval=adcRead(11);
        across=adcRead(10);
        greenval=(uint32_t)((blueval*173/100)+across)*1023/2793; 
        
        rgbWrite(0, greenval, 0);
    }
}


