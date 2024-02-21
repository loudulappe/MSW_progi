/*
 * casio.c
 *
 * Created: 09.06.2023 08:53:21
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"


int main(void)
{
    initBoard(0);
    uint32_t systime=0;
    uint32_t cotime=0;
    uint32_t tottime=0;
    uint32_t cytime=0;
    uint32_t subtime=0;
    uint32_t sec=0;
    uint8_t min=0;
    uint8_t hour=0;
    uint8_t day=0;
    uint8_t weekday=0;
    uint8_t month=0;
    char Tage[7][3]={
        "Mo",
        "Di",
        "Mi",
        "Do",
        "Fr",
        "Sa",
        "So"};
    
    while (1) 
    {
        cotime=systime;
        systime=getSystemTimeMs();
        cytime=systime-cotime;
        subtime=subtime+cytime;
        sec=subtime/1000;
        if (subtime>999)
        {
            sec=sec+1;
        }
        if (sec>59)
        {
            sec=0;
            min=min+1;
        }        
        if (min>59)
        {
            min=0;
            hour=hour+1;
        }

        lcdWriteText(0,1,"%2u:%02u:%02lu", hour, min, sec);
          
    }
}

