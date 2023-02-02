/*
 * 7-segment.c
 *
 * Created: 01.02.2023 13:27:03
 * Author : e1Derung
 */ 

#include "ADtreiber.h"
    #define     ZAHLTAKT_ms 50
    #define     MASK_ERROR  0b10000000

int main(void)
{
    const uint16_t HEX_TO_7SEG[18]=
        {
            0b01111101,
            0b01000100,
            0b01111010,
            0b01101110,
            0b01000111,
            0b00101111,
            0b00111111,
            0b01100100,
            0b01111111,
            0b01101111,
            0b01110111,
            0b01011110,
            0b00111001,
            0b00011111,
            0b00111011,
            0b00110011,
            0b10000000,
            0
        };  
    
    uint8_t counter=0;
    uint8_t systemtakt=10;
    uint32_t systemzeit=0;
    uint8_t zehner=0;
    uint16_t zahl=0;
    uint8_t sin1=0;
    uint8_t sin2=0;
    
    initBoard();

    while (1) 
    {
//eingabe
        sin1= SwitchRead(0)|SwitchRead(1)|SwitchRead(2)|SwitchRead(3);
        sin2= (SwitchRead(4)|SwitchRead(5)|SwitchRead(6)|SwitchRead(7))>>4;  
    
//verarbeitung

    zahl=sin1+sin2;
    if (zahl>15)
    {
        zahl=18;
    }
    else if ((sin1>9)||(sin2>9))
    {
        zahl=17;
    }


    
//ausgabe
   PORTB=HEX_TO_7SEG[zahl];
//systemtakt
    systemzeit=systemzeit+systemtakt;
    _delay_ms(systemtakt);
    }
}

