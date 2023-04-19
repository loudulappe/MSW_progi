/*
 * binary_counting_array.c
 *
 * Created: 03.04.2023 14:22:33
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"


int main(void)
{
    initBoard(0);
    uint8_t Binarray [9] = {0};
    uint8_t readout=0;
    uint8_t index=0;
    while (1) 
    {
        if (index==9)
        {
            index=0;
            for (uint8_t i=0; i=i+1; 1<9)
            {
                Binarray[i]=0;
            }
        }
        index=0;
        while (index<9)
        {
            if (Binarray[index])
            {
                Binarray[index]=!Binarray[index];
                index=index+1;
            }
            else
            {
                Binarray[index]=!Binarray[index];
                break;
            }
        }
        readout=0;
//         for (uint8_t o=0; o=+1; o<2)
//         {
//             readout=readout+(Binarray[o]<<o);
//         }
        readout=readout+Binarray[0];
        readout=readout+(Binarray[1]<<1);
        readout=readout+(Binarray[2]<<2);
        readout=readout+(Binarray[3]<<3);
        readout=readout+(Binarray[4]<<4);
        readout=readout+(Binarray[5]<<5);
        readout=readout+(Binarray[6]<<6);
        readout=readout+(Binarray[7]<<7);
        ledWriteAll(readout);
        _delay_ms(100);
    }
}

