/*
 * Delay.c
 *
 * Created: 09.11.2022 13:00:16
 * Author : e1Derung
 */ 

#include "ADtreiber.h"


int main(void)
{
    #define ON_TIME_sm      500
    #define OFF_TIME_ms     500
    #define PERIOD_TIME_ms  (ON_TIME_sm+OFF_TIME_ms)
    #define OMLED           0xfffe
    uint64_t warnblinktimer=0;
    uint8_t power=0;
    uint16_t oled =0;
    uint8_t flagwarnblinker =0;
    
    initBoard();
    while (1) 
    {
//eingabe
        power=SwitchRead(0);

//verarbeitung

        if (power)
        {
            flagwarnblinker=1;
        } 
        else
        {
            flagwarnblinker=0;
        }

        if (flagwarnblinker)
        {
            if ((!warnblinktimer)||(warnblinktimer>=PERIOD_TIME_ms))
            {
                oled=OMLED;
                warnblinktimer =0;
            }
            if ((warnblinktimer>=ON_TIME_sm))
            {
                oled=0;
            }
        } 
        else
        {
            oled=0;
            warnblinktimer=PERIOD_TIME_ms;
        }


//ausgabe
        ledWriteAll(oled);

//systemzeit
        _delay_ms(10);
        warnblinktimer = warnblinktimer+10;
    }
}