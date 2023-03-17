/*
 * Uebungspruefung_Wassertank.c
 *
 * Created: 22.02.2023 14:45:06
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"

#define     BLINKTAKT           50
#define     BLINKONTIME         500
#define     BLINKPERIOD         2000
#define     IMASKVOL            0b00011111
#define     IMASKPRESSURE       0b01000000
#define     IMASKPOW            0b10000000
#define     OMASKPOW            0b10000000
#define     OMASKOUTDRAW        0b01000000
#define     OMASKERR            0b00010000
#define     OMASKLOW            0b00000100
#define     OMASKCAP            2
#define     OMASKMAINT          1
#define     MAXVOL              20
#define     CAPLIMIT            17
#define     DRAWLIMIT           2
#define     LOWLIMIT            1

int main(void)
{
    initBoard(1);
    uint16_t blinktime=0;
    uint8_t inswitch=0;
    uint8_t invol=0;
    uint8_t inpressure=0;
    uint8_t inpow=0;
    uint8_t flagblink=0;
    uint8_t outleds=0;
    uint8_t altflagblink=0;
    

    while (1) 
    {
//Eingabe

        altflagblink=flagblink;
        inswitch=switchReadAll();
        inpow=inswitch&IMASKPOW;
        inpressure=inswitch&IMASKPRESSURE;
        invol=inswitch&IMASKVOL;
        if (invol>MAXVOL)
        {
            invol=MAXVOL;
        }

//Verarbeitung

        if (inpow)
        {
            outleds=outleds|OMASKPOW;
        if (inpressure)
        {
            outleds=outleds|OMASKMAINT;
        } 
        else
        {
            outleds=outleds&~OMASKMAINT;
        }
        if (invol>=CAPLIMIT)
        {
            outleds=outleds|OMASKCAP;
        } 
        else
        {
            outleds=outleds&~OMASKCAP;
        }
        if (invol<DRAWLIMIT)
        {
            if (invol<=DRAWLIMIT)
            {
                outleds=outleds|OMASKOUTDRAW;
            }
        } 
        else
        {
            outleds=outleds&~OMASKOUTDRAW;
        }
        if (invol<2)
        {
            flagblink=1;
            outleds=outleds|OMASKLOW;
        } 
        else
        {
            flagblink=0;
            outleds=outleds&~OMASKLOW;
        }
        if ((altflagblink<flagblink)||(blinktime>=BLINKPERIOD))
        {
            blinktime=0;
        }
        if (flagblink)
        {
            if (blinktime<BLINKONTIME)
            {
                outleds=outleds|OMASKERR;
            } 
            else
            {
                outleds=outleds&~OMASKERR;
            }
        }
        else
        {
            outleds=outleds&~OMASKERR;    
        }
        
        }
        else
        {
            outleds=0;
        }        
        
//Ausgabe

        ledWriteAll(outleds);

//systemtakt

        _delay_ms(BLINKTAKT);
        blinktime=blinktime+BLINKTAKT;
    }
}

