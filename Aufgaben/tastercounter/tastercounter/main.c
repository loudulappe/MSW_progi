/*
 * tastercounter.c
 *
 * Created: 11.11.2022 15:29:42
 * Author : e1Derung
 */ 

#include "ADtreiber.h"


int main(void)
{
    #define IMPOW 0x01
    #define IMRES 0x02
    uint8_t tall=0;
    uint8_t talt=0;
    uint8_t flall=0;
    uint8_t flapo=0;
    uint8_t flapopow=0;
    uint8_t flapores=0;
    uint16_t count =0;
    while (1)
    {
        //Eingabe
        talt=tall;
        tall=tasterreadall();
        
        flall= tall^talt;
        flapo= flall&tall;
        flapopow= flapo&IMPOW;
        flapores= flapo&IMRES;
        
        //Verarbeitung
        if (flapopow)
        {
            count=count+1;
        }
        if (flapores)
        {
            count=0;
        }
        //Ausgabe
        ledWriteAll(count);
        //Systemtakt
        _delay_ms(10);
    }
}
