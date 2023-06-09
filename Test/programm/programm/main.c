/*
 * programm.c
 *
 * Created: 12.05.2023 10:26:25
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"

#define BALKENGROESSE       8
#define OUTMASKBALKEN       0xff
int main(void)
{
    uint16_t stufe=0;
    uint16_t outBalken=0;
    uint16_t outbalke = 0;
    uint16_t counter=0;
    initBoard(0);
    while (1) 
    {
        stufe=adcRead(8)*BALKENGROESSE/1023;                                    //Balkengrösse z.b. =8 für 8-bit Balken
        outBalken=(~(OUTMASKBALKEN<<stufe))&OUTMASKBALKEN;                      //Bitmuster speichern und maskieren
               
        ledWriteAll(outBalken);
        _delay_ms(5);
    }
}

