/*
 * tasterread.c
 *
 * Created: 11.11.2022 07:53:22
 * Author : e1Derung
 */ 

#include "ADtreiber.h"

int main(void)
{
    initBoard();
    ledWriteAll(0);
    while (1) 
    {
        ledWriteAll(tasterreadall());
    }
}

