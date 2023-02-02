/*
 * prufung LEDtester.c
 *
 * Created: 12.12.2022 15:32:31
 * Author : e1Derung
 */ 

#include "ADtreiber.h"



int main(void)
{
    initBoard();
    initAdc();
//     typedef enum zustand_t {MESSUNG, KURZSCHLUSS, UNTERBRUCH, UNTERSPANNUNG}
//     zustand_t;
    #define OUTGRUEN            0b1000000000000000
    #define OUTBLAU             0b0100000000000000
    #define OUTROT              0b0010000000000000
    #define OUTMAGENTA          0b0001000000000000
    #define OUTWEISS            0b0000100000000000
    #define OUTCYAN             0b0000010000000000
    #define OUTGELB             0b0000001000000000       
    uint32_t messwert=0;
    uint32_t ExternSpannung=0;
    uint32_t anzahlLEDs=0;
    uint32_t widerstand=0;
    uint16_t outbalken =0;
    uint16_t outfarben =0;
    
    while (1)
    {
        //Eingabe
        messwert = 5*adcRead(1);
        ExternSpannung = 5*adcRead(0);
        //Verarbeitung
        anzahlLEDs = messwert / 500+1;
        if (ExternSpannung<4500)
        {
            //Gelb=1;
        }
        else
        {
           // Gelb=0;
        }
        if (messwert<20)
        {
           // Magenta=1;
        }
        else
        {
           // Magenta=0;
        }
        if (messwert>(ExternSpannung-100))
        {
            //cyan=1;
        } 
        else
        {
           // cyan=0;
        }
        if((messwert>3500)&(messwert<3000))
        {
            //Blau=1;
        }
        else
        {
            //Blau=0;
        }
        if ((messwert>2500)&(messwert<2000))
        {
            //rot=1;
        } 
        else
        {
            //rot=0;
        }
        if ((messwert>3000)&(messwert<2500))
        {
           // =grün=1;
        } 
        else
        {
            //grün=0;
        }
        outbalken = (0xff>>(8-anzahlLEDs));
        //Ausgabe
        outfarben=0;
        ledWriteAll(outbalken);
        _delay_ms(10);
    }        
}

