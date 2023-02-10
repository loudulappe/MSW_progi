/*
 * LCD_test.c
 *
 * Created: 08.02.2023 10:36:21
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"


int main(void)
{
    initBoard(1); 
    uint16_t zeit=0;   
    while (1) 
    {
        zeit=getSystemTimeMs();
        lcdShowText("time: %02u:%02u:%02u",zeit/60000,(zeit/100)%60,zeit);
    }
}

