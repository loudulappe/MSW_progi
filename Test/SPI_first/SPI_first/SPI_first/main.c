//*********************************************************************************\
*
// * MMMMMMMMMMMM   SSSSSSSSSSSS   WW   WW   WW   MECHATRONIK
// * MM   MM   MM   SS             WW   WW   WW   SCHULE
// * MM   MM   MM   SSSSSSSSSSSS   WW   WW   WW   WINTERTHUR
// * MM   MM   MM             SS   WW   WW   WW
// * MM   MM   MM   SSSSSSSSSSSS   WWWWWWWWWWWW   www.msw.ch
// *
// *
// * Dateiname: spi_first
// * Projekt  : spi_first
// * Hardware : ATmega2560 von Atmel
// * Copyright: MSW, E3
// * Beschreibung:
// * Siehe Prüfungsaufgabe
// * Portbelegung:
// * Siehe Hardwarestruktur
// * Verlauf:
// * Datum:      Autor:         Version   Grund der Änderung:
// * 27.02.2024  Adrian Derungs    V1.0       Neuerstelung
// *
// \*********************************************************************************/

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "AdvancedDriverMocca.h"
#include "SPI.h"
#include "ws2801.h"

#define     FADESTEP 15
#define     COLORSTEP 7


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
    uint8_t ved=15;
    uint8_t vue=172;
    uint8_t veen=172;
    uint8_t times=0;
    uint8_t pot=0;

    SPI_Masterinit();
    adm_ADC_init();
    while (1)
    {
        pot= (uint32_t)adm_ADC_read(3)/100;
        for (uint8_t o=0; o<10;o++)
        {
            SPI_mastertransmit(right[o]);
            SPI_mastertransmit(bight[o]);
            SPI_mastertransmit(gight[o]);
        }
         for (uint8_t i=0; i<10; i++)
        {
            if(pot==i)
            {
                right[pot]=ved;
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
            if(pot==i)
            {
                bight[pot]=vue;
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
            if(pot==i)
            {
                gight[pot]=veen;
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
        
              _delay_ms(60);
    }
}




