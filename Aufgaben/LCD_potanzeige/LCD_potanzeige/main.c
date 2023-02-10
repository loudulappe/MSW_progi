/*
 * LCD_potanzeige.c
 *
 * Created: 10.02.2023 08:07:09
 * Author : e1Lou
 */ 

#include "ucBoardDriver.h"
#pragma GCC optimize 0
#define ADCMAX      1023
#define AP          50
#define TRUEMAX     5000

int main(void)
{
    initBoard(0);
    initAdc();
    uint16_t pot1=0;
    uint16_t outz01=0;
    uint16_t outz02=0;
    uint8_t flagmv1=0;
    uint16_t propot1=0;
    uint16_t propunkt1=0;
    uint16_t flagpro1=0;
    uint16_t pot2=0;
    uint16_t outz21=0;
    uint16_t outz22=0;
    uint8_t flagmv2=0;
    uint16_t propot2=0;
    uint16_t rangepos=0;
    uint16_t proneg=0;
    uint16_t valpos=0;
    uint16_t valneg=0;
    uint16_t rangeneg=0;
    char prozentzeichen= 0x25;
    lcdWriteText(0,0,"U-Poti1:  .     V");
    lcdWriteText(1,0,"APO:   %c AP2.5: +  %c",prozentzeichen,prozentzeichen);
    lcdWriteText(2,0,"U-poti2            ");
    lcdWriteText(3,0,"APpoti2:   %c",prozentzeichen);
    while (1) 
    {
//eingabe
        pot1= (uint32_t)adcRead(9)*TRUEMAX/ADCMAX;
        pot2= (uint32_t)adcRead(8)*TRUEMAX/ADCMAX;
        propot1= pot1/50;
        propot2= pot2/50;
        rangepos= TRUEMAX-propot2;
        rangeneg= propot2;
//verarbeitung        
        if (pot1<1000)
        {
            flagmv1=1;
            outz01=0;
            outz02=pot1;
        } 
        else
        {
            flagmv1=0;
            outz01=pot1/1000;
            outz02=pot1%1000;
        }
        
        if (propot1<AP)
        {
            propunkt1=AP-propot1;
            flagpro1=0;
        } 
        else
        {
            propunkt1=propot1-AP;
            flagpro1=1;
        }
        
        if (pot2<1000)
        {
            flagmv2=1;
            outz21=0;
        }
        else
        {
            flagmv2=0;
            outz21=pot2/1000;
        }
        outz22=pot2%1000;
        
        if (propot1<propot2)
        {
            proneg=propot1*100/propot2;
            valneg=100-proneg;
        } 
        else
        {
            valpos=(propot1*100/propot2)-100;
        }
         
//ausgabe
        if (flagmv1)
        {
            lcdWriteText(0,9,"  %03u mV", outz02);
        } 
        else
        {
            lcdWriteText(0,9,"%u.%03u V   ",outz01, outz02);
        }
        lcdWriteText(1,4,"%3u",propot1);
        if (flagpro1)
        {
            lcdWriteText(1,16,"+%2u",propunkt1);
        } 
        else
        {
            lcdWriteText(1,16,"-%2u",propunkt1);
        }
        if (flagmv2)
        {
            lcdWriteText(2,9,"  %03u mV", outz22);
        }
        else
        {
            lcdWriteText(2,9,"%u.%03u V   ",outz21,outz22);
        }
        
        if (propot1<propot2)
        {
            lcdWriteText(3,9,"-%3u",valneg);
        } 
        else
        {
            lcdWriteText(3,9,"+%3u%c     ",valpos,prozentzeichen);
        }
    }
}

