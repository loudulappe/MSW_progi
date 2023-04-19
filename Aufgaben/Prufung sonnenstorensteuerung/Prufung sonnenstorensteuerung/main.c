/*
 * Prufung sonnenstorensteuerung.c
 *
 * Created: 19.04.2023 14:40:26
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"
#define INPOW           0X01
#define INSUN           0X02
#define INAUT           0X08
#define ININLIMIT       0X04
#define INOUTLIMIT      0X80
#define BUTTONIN        0X40
#define BUTTONOUT       0X80
#define OUTPOW          0X01
#define OUTAUT          0X04
#define OUTMAN          0X10
#define OUTOUT          0X40
#define OUTIN           0X80
#define BLINKTAKT       10
#define BLINKPERIODE    200




int main(void)
{
    typedef enum zustand_t {manuell, automatik, ausschalten, aus}
    zustand_t;
    zustand_t zustand= aus;
    uint8_t flagblink=0;
    uint8_t flagaus=0;
    uint8_t flagread=0;
    uint8_t flagout=0;
    uint16_t blinktimer=0;
    uint8_t swin=0;
    uint8_t bin=0;
    uint8_t flankpos=0;
    uint8_t buttonin=0;
    uint8_t altbutton=0;
    uint8_t flanks=0;
    uint8_t flankin=0;
    uint8_t flankout=0;
    uint8_t inpow=0;
    uint8_t insun=0;
    uint8_t inaut=0;
    uint8_t ininlimit=0;
    uint8_t inoutlimit=0;
    uint8_t ausgabe=0;
    
    initBoard(0);
    
    while (1) 
    {
        altbutton=buttonin;
        buttonin=buttonReadAllPL();
        swin=switchReadAll();
        flanks= (altbutton^buttonin)&buttonin;
        flankin= flanks&BUTTONIN;
        flankout= flanks&BUTTONOUT;
        ininlimit= swin&ININLIMIT;
        inoutlimit= swin& INOUTLIMIT;
        inaut= swin& INAUT;
        insun= swin& INSUN;
        
        if (ininlimit||inoutlimit)
        {
            flagread=1;
        }
        else
        {
            flagread=0;
        }
        switch (zustand)
        {
            case aus: 
            flagaus=1;
            if (inpow&&ininlimit)
            {
                if (inaut)
                {
                    zustand=automatik;
                }
                else
                {
                    zustand=manuell;
                }
                flagaus=0;
                ausgabe=ausgabe|OUTPOW;  
            }
            break;   
            
            case manuell:
            flagblink=1;
            if (flagread)
            {
                if (flankin)
                {
                    flagout=0;
                }
                if (flankout)
                {
                    flagout=1;
                }
                if (inaut)
                {
                    zustand=automatik;
                    flagblink=0;
                }
            }
            if (!inpow)
            {
                zustand=ausschalten;
                flagblink=0;
            }
            
            case automatik:
            ausgabe=ausgabe|OUTAUT;
            if(flagread)
            {
                if (insun)
                {
                    flagout=1;
                } 
                else
                {
                    flagout=0;
                }
                if (!inaut)
                {
                    zustand=manuell;
                    ausgabe=ausgabe&~OUTAUT;
                }
            }
            if (!inpow)
            {
                zustand=ausschalten;
                ausgabe=ausgabe&~OUTAUT;
            }
            break;
            
            case ausschalten:
            
            flagout=0;
            if (ininlimit)
            {
                zustand=aus;
            }
            break;
        }
    }
}

