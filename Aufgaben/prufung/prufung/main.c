/*
 * prufung.c
 *
 * Created: 02.11.2022 14:05:39
 * Author : e1Derung
 */ 

#include "ADtreiber.h"


int main(void)
{
    initBoard();
    uint8_t inswitch = SwitchReadAll();
    #define INMASKPOWER         0b00000001
    #define OUTMASKPOWER        0b10000000
    #define INMASKTEMPERATUR    0b00000100
    #define OUTMAKSTEMPERATUR   0b01000000
    #define INMASKDREHKNOPF     0b11110000
    #define OUTMASKDREHKNOPF    0b00001111
    #define OUTMASKGROSSESFELD  0b00010000

    uint8_t inpower=0;
    uint8_t outpower=0;
    uint8_t intemperatur=0;
    uint8_t outtemperatur=0;
    uint8_t indrehknopf=0;
    uint8_t outdrehknopf=0;
    uint8_t heizstufe=0;
    uint8_t ingrossesfeld=0;
    uint8_t outgrossesfeld=0;
    while (1) 
    {
        uint8_t inswitch = SwitchReadAll();
        inpower = (inswitch&INMASKPOWER );                      //Eingabe
        intemperatur = (inswitch&INMASKTEMPERATUR);
        indrehknopf = ((inswitch&INMASKDREHKNOPF)>>4);
        ingrossesfeld = indrehknopf>14;
            
        if (inpower)                                            //Verarbeitung        
        {
            outpower = OUTMASKPOWER;                         
        }
        else
        {
            outpower=0;
            outgrossesfeld=0;
        }
        if (intemperatur)
        {
            outtemperatur = 0;
        } 
        else
        {
            outtemperatur = OUTMAKSTEMPERATUR;
        }
        if (inpower)
        {
            heizstufe=indrehknopf/3;
            outdrehknopf= ~(0xff<<heizstufe)&OUTMASKDREHKNOPF;
        }
        else
        {
            outdrehknopf=0;
        }
        if (ingrossesfeld&&outpower)
        {
            outgrossesfeld=OUTMASKGROSSESFELD;
        }
        else
        {
            outgrossesfeld=outgrossesfeld;
        }
        
        ledWriteAll(outpower|outtemperatur|outdrehknopf|outgrossesfeld);            //Ausgabe
    }
}

