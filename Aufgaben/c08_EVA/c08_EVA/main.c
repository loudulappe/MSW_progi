/*
 * c08_EVA.c
 *
 * Created: 27.10.2022 09:55:40
 * Author : e1Derung
 */
#include "ADtreiber.h"


int main(void)
{
    uint8_t ilights=0;
    initBoard();
    while (1) 
    {
        ilights=SwitchReadAll();
    }
}

