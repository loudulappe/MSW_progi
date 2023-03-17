/*
 * ADC_Prozent_LEDbalken.c
 *
 * Created: 20.02.2023 14:40:43
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"



int main(void)
{
    initBoard(1);
    
    uint32_t adcwert=0;
    uint16_t umV=0;
    uint8_t balkenpos=0;
    uint8_t anzahlledspos=0;
    uint8_t balkenneg=0;
    uint8_t anzahlledsneg=0;
    
    
    while (1) 
    {
//Eingabe

        adcwert=adcRead(0);
        umV=adcwert*5000/1023;
        
//Verarbeitung

        if (umV>=2500)
        {
            anzahlledspos=(umV-2500)/277;
            anzahlledsneg=0;
        }
        else
        {
            anzahlledsneg=9-(umV/277);
            anzahlledspos=0;
        }
        
//Ausgabe

        balkenpos=~(0xff>>anzahlledspos);
        balkenneg=~(0xff<<anzahlledsneg);
//        ledWriteAll((balkenneg<<8)|balkenpos);
        lcdShowText("test test");
    }
}

