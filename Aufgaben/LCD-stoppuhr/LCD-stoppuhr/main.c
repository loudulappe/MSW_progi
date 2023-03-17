/*
 * LCD-stoppuhr.c
 *
 * Created: 10.02.2023 14:26:04
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"
#define RUNDENMAX       100
#define MASKINGO         0x80
#define MASKINRES       0x40
#define MASKINLAP       0X02
#define SYSTEMTAKT      10

int main(void)
{
    initBoard(1);
    uint32_t alltime=0;
    uint32_t looptime=0;
    uint32_t pasttime=0;
    uint32_t runtime=0;
    uint8_t counter=0;
    uint32_t laps[RUNDENMAX]={0};
    uint8_t ingo=0;
    uint8_t inres=0;
    uint8_t inlap=0;
    uint8_t inbutton=0;
    uint8_t altinbutton=0;
    uint8_t flankpos=0;
    uint8_t flagrun=0;
    uint8_t timezwischensp=0;
    uint32_t deadtime=0;
    
    
    lcdShowText("00:00:00.00         last 00: 00:00:00.00fast 00: 00:00:00.00slow 00: 00:00:00.00");
    while (1)
    {
//eingabe 
        alltime=getSystemTimeMs();
        looptime=timezwischensp;
        timezwischensp=alltime;
        looptime=timezwischensp-looptime;
        altinbutton=inbutton;
        inbutton=buttonReadAllPL();
        flankpos=(altinbutton^inbutton)&inbutton;
        ingo=flankpos&MASKINGO;
        inres=flankpos&MASKINRES;
        inlap=flankpos&MASKINLAP;
//verarbeitung
        
        if (ingo)
        {
            flagrun=!flagrun;
        }
        if (flagrun)
        {
            runtime=runtime+looptime;
        }
        else 
        {
            deadtime=deadtime+runtime;
            runtime=0;
        }
//ausgabe

        lcdWriteText(0,0,"%015lu",runtime);
        ledWriteAll(flagrun);
        
        _delay_ms(SYSTEMTAKT);
    }
}

