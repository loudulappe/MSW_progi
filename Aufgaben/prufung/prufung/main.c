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

    uint8_t inpower=0;
    uint8_t outpower=0;
    uint8_t intemperatur=0;
    uint8_t outtemperatur=0;
    uint8_t indrehknopf=0;
    uint8_t outdrehknopf=0;
    uint8_t heizstufe=0;
    while (1) 
    {
        uint8_t inswitch = SwitchReadAll();
        inpower = (inswitch&INMASKPOWER );                      //Eingabe
        intemperatur = (inswitch&INMASKTEMPERATUR);
        indrehknopf = ((inswitch&INMASKDREHKNOPF)>>4);
        
        heizstufe=indrehknopf/3;
        outdrehknopf= ~(0xff<<heizstufe)&OUTMASKDREHKNOPF;      //verarbeitung
        if (inpower)                                     
        {
            outpower = OUTMASKPOWER;
        }
        else
        {
            outpower=0;
        }
        if (intemperatur)
        {
            outtemperatur = 0;
        } 
        else
        {
            outtemperatur = OUTMAKSTEMPERATUR;
        }
//         if (heizstufe=0)
//         {
//             outdrehknopf=OUTMASKHEIZSTUFE0;
//         }
//         if (heizstufe=1)
//         {
//             outdrehknopf=OUTMASKHEIZSTUFE1;
//         }
//         if (heizstufe=2)
//         {
//             outdrehknopf=OUTMASKHEIZSTUFE2;
//         }
//         if (heizstufe=3)
//         {
//             outdrehknopf=OUTMASKHEIZSTUFE3;
//         }
//         if (heizstufe=4)
//         {
//             outdrehknopf=OUTMASKHEIZSTUFE4;
//         }
        
        ledWriteAll(outpower|outtemperatur|outdrehknopf);            //Ausgabe
    }
}

