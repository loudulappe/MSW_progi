/*
 * Flankentest.c
 *
 * Created: 11.11.2022 11:15:18
 * Author : e1Derung
 */ 

#include "ADtreiber.h"


int main(void)
{
    #define     systemtakt      10
    #define     OMLED           0xffff
    uint16_t    systemzeit=0;
    uint16_t oled=0;
    uint8_t intastneu=0;
    uint8_t intastalt=0;
    uint8_t outtast=0;
    uint8_t hitcount=0;
    initBoard();
    while (1)           
    {
//Eingabe
        intastalt=intastneu;
        intastneu=tasterreadall();
        
//Verarbeitung
        if ((!intastalt)&&intastneu)
        {
            hitcount=hitcount+1;
        } 
        
        outtast= hitcount%2;
        if (outtast)
        {
            oled=OMLED;
        } 
        else
        {
            oled=0;
        }
        
//Ausgabe
        ledWriteAll(oled);    
        
//Systemtakt
        _delay_ms(systemtakt);
        systemzeit=systemzeit+systemtakt;
    }
}

