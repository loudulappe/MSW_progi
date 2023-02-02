/*
 * CustomLEDlightshow.c
 *
 * Created: 14.11.2022 14:14:34
 * Author : e1Derung
 */ 

#include "ADtreiber.h"


int main(void)
{
    initBoard();
    uint16_t position=0;
    uint8_t flagnachlinks =1;
    while (1) 
    {
        uint8_t bitmuster=SwitchReadAll();
        uint16_t ausgabespeicher=0;
        ausgabespeicher=bitmuster<<position;
        if (flagnachlinks)
        {
            position=position+1;
        }
        else
        {
            position=position-1;
        }
        if (position==8)
        {
            flagnachlinks=0;
        } 
        else if (position==0)
        {
            flagnachlinks=1;
        }
        _delay_ms(100);
        ledWriteAll(ausgabespeicher);
    }
}

