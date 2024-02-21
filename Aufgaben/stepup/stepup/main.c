/*
 * stepup.c
 *
 * Created: 12.06.2023 14:38:48
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"


int main(void)
{
    initBoard(0); 
    DDRF=DDRF|1;
    uint16_t flagadc =0;   
    uint8_t i=0;
    uint8_t goRight=0;
    while (1) 
    {
        if (goRight)
        {
            ledWriteAll(0x8000>>i);
        }
        else
        {
            ledWriteAll(0x0001<<i);
        }
        i++;
        if (i>16)
        {
            i=0;
            goRight=!goRight;
        }
        flagadc=adcRead(1);
        if (flagadc<350)
        {
            PORTF=PORTF^00000001;
            _delay_ms(6);
        }
        _delay_ms(3);
    }
}

