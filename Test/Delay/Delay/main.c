/*
 * Delay.c
 *
 * Created: 09.11.2022 13:00:16
 * Author : e1Derung
 */ 

#include "ADtreiber.h"


int main(void)
{
    #define ON_WARNTIME_ms      500
    #define OFF_WARNTIME_ms     500
    #define PERIOD_WARNTIME_ms  (ON_WARNTIME_ms+OFF_WARNTIME_ms)
    #define OMWLED           0xfffe
    
    #define ON_POWTIME_ms      100
    #define OFF_POWTIME_ms     100
    #define PERIOD_POWTIME_ms  (ON_POWTIME_ms+OFF_POWTIME_ms)
    #define OMPLED           0x0001
       
    uint64_t warnblinktimer=0;
    uint8_t power=0;
    uint16_t owarnled =0;
    uint8_t flagwarnblinker =0;
    uint8_t flagpowblinker =0;
    uint64_t powblinktimer=0;
    uint16_t opowled=0;
    
    initBoard();
    while (1) 
    {
//eingabe
        power=SwitchRead(0);

//verarbeitung

        if (power)
        {
            flagwarnblinker=1;
            flagpowblinker=1;
        } 
        else
        {
            flagwarnblinker=0;
            flagpowblinker=0;
        }
        

        if (flagwarnblinker)
        {
            if ((!warnblinktimer)||(warnblinktimer>=PERIOD_WARNTIME_ms))
            {
                owarnled=OMWLED;
                warnblinktimer =0;
            }
            if ((warnblinktimer>=ON_WARNTIME_ms))
            {
                owarnled=0;
            }
        } 
        else
        {
            owarnled=0;
            warnblinktimer=PERIOD_WARNTIME_ms;
        }
        
        if (flagpowblinker)
        {
            if ((!powblinktimer)||(powblinktimer>=PERIOD_POWTIME_ms))
            {
                opowled=OMPLED;
                powblinktimer =0;
            }
            if ((powblinktimer>=ON_POWTIME_ms))
            {
                opowled=0;
            }
        }
        else
        {
            opowled=0;
            powblinktimer=PERIOD_POWTIME_ms;
        }


//ausgabe
        ledWriteAll(owarnled|opowled);

//systemzeit
        _delay_ms(10);
        warnblinktimer = warnblinktimer+10;
        powblinktimer = powblinktimer+10;
    }        
}