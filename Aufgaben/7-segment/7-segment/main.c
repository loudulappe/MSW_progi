/*
 * 7-segment.c
 *
 * Created: 01.02.2023 13:27:03
 * Author : e1Derung
 */ 

#include "ADtreiber.h"
    #define     ZAHLTAKT_ms 50
    #define     sim0        1
    #define     sim1        2
    #define     sim2        4
    #define     sim3        8
    #define     sin1m       0xf
    

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
            0b00011111,
            0b00111001,
            0b01011110,
            0b00111011,
            0b00110011,
            0b00000010,
            0b00000000
        };
    const uint8_t GRAY_TO_HEX[17]=
        {
            0b0000,
            0b0001,
            0b0011,
            0b0010,
            0b0111,
            0b0110,
            0b0100,
            0b0101,
            0b1111,
            0b1110,
            0b1100,
            0b1101,
            0b1000,
            0b1001,
            0b1011,
            0b1010,
            0
        };
    char nummer[]={"0774742340"};
    
    uint8_t zalt=0;
    uint8_t systemtakt=10;
    uint32_t systemzeit=0;
    uint8_t err=0;
    uint16_t zahl=0;
    uint8_t ziffer=0;
    uint16_t diff=0;
    uint8_t swin=0;
    uint8_t i=0;
    
    
    initBoard();

    while (1) 
    {
//eingabe

    
//verarbeitung
    if (!(systemzeit%600))
    {
        if (nummer[i])
        {
            if ((nummer[i]>='0')&&(nummer[i]<='9'))
            {
                zahl=nummer[i]-48;
            }
            else
            {
                zahl=16;
            }
        }
        else
        {
            i=0;
        }        
    i=i+1;
    }            

//ausgabe
    if ((systemzeit%600)<500)
    {
        PORTB=HEX_TO_7SEG[zahl];
    }
    else
    {
        PORTB=HEX_TO_7SEG[17];
    }
   
//systemtakt
    systemzeit=systemzeit+systemtakt;
    _delay_ms(systemtakt);
    }
}

