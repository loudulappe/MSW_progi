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
    while (1) 
    {
        uint8_t inswitch = SwitchReadAll();
        uint8_t power = (inswitch&INMASKPOWER );    //Eingabe
        
        if (power)                                  //Verarbeitung
        {
            power = OUTMASKPOWER;
        }
        
        ledWriteAll(power);
    }
}

