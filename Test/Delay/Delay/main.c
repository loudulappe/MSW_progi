/*
 * Delay.c
 *
 * Created: 09.11.2022 13:00:16
 * Author : e1Derung
 */ 

#include "ADtreiber.h"


int main(void)
{
    #define ON_TIME_sm      4000
    #define OFF_TIME_ms     1000
    #define PERIOD_TIME_ms  (ON_TIME_sm+OFF_TIME_ms)
    uint64_t systemzeit=0;
    uint8_t power=0;
    uint16_t oled =0;
    initBoard();
    while (1) 
    {
//eingabe
        power=SwitchRead(0);

//verarbeitung
      
        if ((!systemzeit&&power)||(systemzeit>=PERIOD_TIME_ms&&power))
        {
            oled=0xffff;
            systemzeit =0;
        }
        if (systemzeit>=ON_TIME_sm)
        {
            oled=0;
        }
   
                    

        
        
//ausgabe
        ledWriteAll(oled);

//systemzeit
        _delay_ms(10);
        systemzeit = systemzeit+10;
    }
}