/*
 * boardrepair.c
 *
 * Created: 07.06.2023 13:05:06
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"


int main(void)
{
    uint16_t vared=1;
    uint16_t vablu=600;
    uint16_t vagre=600;
    uint8_t flagred=0;
    uint8_t flagblu=0;
    uint8_t flaggre=1;
    initBoard(1);
    while (1) 
    {
        if (!vared||vared==900)
        {
            flagred=!flagred;
        }
        if (!vablu||vablu==900)
        {
            flagblu=!flagblu;
        }
        if (!vagre||vagre==900)
        {
            flaggre=!flaggre;
        }
        
        if (flagred)
        {
            vared=vared-1;
        } 
        else
        {
            vared=vared+1;
        }
        if (flagblu)
        {
            vablu=vablu-1;
        }
        else
        {
            vablu=vablu+1;
        }
        if (flaggre)
        {
            vagre=vagre-1;
        }
        else
        {
            vagre=vagre+1;
        }
        

        rgbWrite(vared,0,0);
        _delay_ms (3);
    }
}

