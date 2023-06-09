/*
 * Reparatur LCD.c
 *
 * Created: 11.05.2023 10:17:30
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"


int main(void)
{
    initBoard(1);
    while (1) 
    {
        lcdShowText("alive");
    }
}

