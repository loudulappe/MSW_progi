/*
 * Widerstandtester.c
 *
 * Created: 28.11.2022 15:44:46
 * Author : e1Derung
 */ 

#include "ADtreiber.h"


int main(void)
{
    initBoard();
    initAdc();
    typedef enum zustand_t {MESSUNG, KURZSCHLUSS, UNTERBRUCH, UNTERSPANNUNG}
    zustand_t;
    # define OUTGRUEN           0b1000000000000000
    # define OUTBLAU            0b0100000000000000
    # define OUTROT             0b0010000000000000
    # define OUTMAGENTA         0b0001000000000000
    uint16_t messwert=0;
    uint16_t adcinsgesamt=0;
    uint16_t strom=0;
    uint16_t umessung=0;
    uint16_t widerstand=0;
    
    while (1) 
    {
       messwert = 5*adcRead(0);
       adcinsgesamt = 5*adcRead(1);
       strom = adcinsgesamt-messwert;
       
       widerstand= ((messwert*100));
       
       ledWriteAll(widerstand);
       _delay_ms(10);
    }
}

