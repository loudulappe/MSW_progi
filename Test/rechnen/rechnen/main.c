/*
 * rechnen.c
 *
 * Created: 23.01.2023 14:15:13
 * Author : e1Derung
 */ 

#include "ADtreiber.h"


int main(void)
{
    uint16_t adcval=0;
    uint16_t adcmV=0;
    uint16_t adcmax=1023;
    uint16_t weightMax= 65000;
    uint32_t adctemp =0;
    uint8_t  flagminus=0;
    uint32_t temp=0;
    initBoard();
    initAdc();
    while (1) 
    {
        adcval  =adcRead(8);
        adcmV   =(uint32_t) adcval*5000/1023;
        
        if (adcmV>2500)
        {
            temp=(adcmV-2500)/25;
            flagminus=0;
        }
        else if (adcmV<2500)
        {
            temp=(2500-adcmV)/25;
            flagminus=0x80;
        }
        else
        {
            temp=0;
            
        }
        
        ledWriteAll(temp|flagminus);
    }
}

