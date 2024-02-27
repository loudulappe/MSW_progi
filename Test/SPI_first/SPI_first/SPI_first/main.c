/*********************************************************************************\
*
* MMMMMMMMMMMM   SSSSSSSSSSSS   WW   WW   WW   MECHATRONIK
* MM   MM   MM   SS             WW   WW   WW   SCHULE
* MM   MM   MM   SSSSSSSSSSSS   WW   WW   WW   WINTERTHUR
* MM   MM   MM             SS   WW   WW   WW
* MM   MM   MM   SSSSSSSSSSSS   WWWWWWWWWWWW   www.msw.ch
*
*
* Dateiname: SPI_first
*
* Projekt  : SPI_first
* Hardware : Mocca-Board, ATmega2560v von Atmel
*
*
* Copyright: MSW, AE3
\*********************************************************************************/

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "AdvancedDriverMocca.h"
#include "SPI.h"

#define     FADESTEP 15
#define     COLORSTEP 15


int main(void)
{
    uint16_t pos=1;
    uint8_t flagcount=1;
    uint8_t right[10]={0};
    uint8_t bight[10]={0};
    uint8_t gight[10]={0};
    uint8_t rink=0;
    uint8_t bink=1;
    uint8_t gink=0;
    uint8_t ved=FADESTEP;
    uint8_t vue=172;
    uint8_t veen=172;
    

    SPI_Masterinit();
    adm_ADC_init();
    while (1)
    {

        for (uint8_t i=0;i<10;i++)
        {
            SPI_mastertransmit(right[i]);
            SPI_mastertransmit(bight[i]);
            SPI_mastertransmit(gight[i]);
        }
        for (uint8_t i=0; i<10; i++)
        {
            if(pos==i)
            {
                right[pos]=ved;
            }
            else
            {
                if (right[i]<FADESTEP)
                {
                    right[i]=0;
                }
                else
                {
                    right[i]=right[i]-FADESTEP;
                }
            }
        }
        
        for (uint8_t i=0; i<10; i++)
        {
            if(pos==i)
            {
                bight[pos]=vue;
            }
            else
            {
                if (bight[i]<FADESTEP)
                {
                    bight[i]=0;
                }
                else
                {
                    bight[i]=bight[i]-FADESTEP;
                }
            }
        }
        
        for (uint8_t i=0; i<10; i++)
        {
            if(pos==i)
            {
                gight[pos]=veen;
            }
            else
            {
                if (gight[i]<FADESTEP)
                {
                    gight[i]=0;
                }
                else
                {
                    gight[i]=gight[i]-FADESTEP;
                }
            }
        }        
        
        if ((!pos)||(pos==9))
        {
            flagcount=!flagcount;
        }
        
        if (flagcount)
        {
            pos=pos+1;
        }
        else
        {
            pos=pos-1;
        }
        
        if ((ved<30)||(ved>225))
        {
            rink=!rink;
        }
        if ((vue<30)||(vue>225))
        {
            bink=!bink;
        }
        if ((veen<30)||(veen>225))
        {
            gink=!gink;
        }
        
        if (rink)
        {
            ved=ved+COLORSTEP;
        } 
        else
        {
            ved=ved-COLORSTEP;
        }
        
        if (bink)
        {
            vue=vue+COLORSTEP;
        }
        else
        {
            vue=vue-COLORSTEP;
        }
        
        if (gink)
        {
            veen=veen+COLORSTEP;
        }
        else
        {
            veen=veen-COLORSTEP;
        }
        
        
        _delay_ms(100);
    }
}




