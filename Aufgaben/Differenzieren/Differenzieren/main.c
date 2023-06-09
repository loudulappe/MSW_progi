/*
 * Differenzieren.c
 *
 * Created: 05.06.2023 15:28:31
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"

#define SYSTEMTAKT      10
#pragma GCC OPTIMIZE 0

int main(void)
{
    initBoard(0);
    uint16_t timesave [100]={0};
    uint16_t input=0;
    uint16_t inputalt=0;
    uint16_t counter=0;
    uint32_t total=0;
    uint16_t output=0;
    uint32_t tottime=0;
    uint32_t roundtime=0;
    uint32_t acttime=0;
    while (1) 
    {
        inputalt=input;
        input=adcRead(1);
        if ((inputalt<500)&&(input>500))
        {
            for (uint8_t i=0; i=i+1; i<100)
            {
                total=total+timesave[i];
            }
            output=total/counter;
            ledWriteAll(output);
            total=0;
            counter=0;
            for (uint8_t i=0; i=i+1; i<100)
            {
                timesave[i]=0;
            }            
        }
        timesave[counter]=input;
        counter=counter+1;
        _delay_ms(SYSTEMTAKT);
    }
}

