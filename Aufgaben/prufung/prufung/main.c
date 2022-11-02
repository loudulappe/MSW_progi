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
    #define INMASKPOWER  0b00000001
    #define OUTMASKPOWER  0b10000000
    #define INMASKTEMPERATUR 0b00000100
    #define OUTMAKSTEMPERATUR 0b01000000
    uint8_t inpower=0;
    uint8_t outpower=0;
    uint8_t intemperatur=0;
    uint8_t outtemperatur=0;
    while (1) 
    {
        uint8_t inswitch = SwitchReadAll();
        inpower = (inswitch&INMASKPOWER );    //Eingabe
        intemperatur =  (inswitch&INMASKTEMPERATUR);
        
        if (inpower)                                  //Verarbeitung
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
        
        ledWriteAll(outpower|outtemperatur);
    }
}

