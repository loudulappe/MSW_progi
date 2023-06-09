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
    initBoard();
    while (1)           
    {
//Eingabe
        intastalt=intastneu;
        intastneu=tasterreadall();
        uint8_t flankall = (~intastalt)&intastneu;
        
//Verarbeitung
        if ((~intastalt)&intastneu)
        {
            oled=oled^flankall;
        } 


//Ausgabe
        ledWriteAll(intastneu);    
        
//Systemtakt
        _delay_ms(systemtakt);
        systemzeit=systemzeit+systemtakt;
    }
}    