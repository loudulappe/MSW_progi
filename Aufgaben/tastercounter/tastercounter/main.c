/*
 * tastercounter.c
 *
 * Created: 11.11.2022 15:29:42
 * Author : e1Derung
 */ 

#include "ADtreiber.h"


int main(void)
{
    initBoard();
    #define INMASKPOWER 0x01
    #define INMASKRESET 0x02
    uint8_t tasterAll=0;
    uint8_t tasterAlt=0;
    uint8_t flankAll=0;
    uint8_t flankPositive=0;
    uint8_t flankPositivePower=0;
    uint8_t flankPowerReset=0;
    uint16_t count =0;
    while (1)
    {
        //Eingabe
        tasterAlt=tasterAll;
        tasterAll=tasterreadall();
        
        flankAll= tasterAll^tasterAlt;
        flankPositive= flankAll&tasterAll;
        flankPositivePower= flankPositive&INMASKPOWER;
        flankPowerReset= flankPositive&INMASKRESET;
        
        //Verarbeitung
        if (flankPositivePower)
        {
            count=count+1;
        }
        if (flankPowerReset)
        {
            count=0;
        }
        //Ausgabe
        ledWriteAll(count);
        //Systemtakt
        _delay_ms(10);
    }
}
