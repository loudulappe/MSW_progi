/*
 * ubung_loetstation.c
 *
 * Created: 17.03.2023 08:26:03
 * Author : e1Derung
 */ 

#include   "ucBoardDriver.h"
#define     MTIN            0XC0
#define     IMTEMP          0XF
#define     IMPOW           0X80
#define     IMUP            0X40
#define     IMDOWN          0X80
#define     OMTEMP          0X3F
#define     OMPOW           0X80
#define     OMHEAT          0X40
#define     SYSTEMTAKT      5    
#define     BLINKPERIOD     2000


int main(void)
{
    typedef enum zustand_t{aus, ein, err}
    zustand_t;
    
    const uint8_t gray_to_dez[16]={
        0,
        1,
        3,
        2,
        7,
        6,
        4,
        5,
        15,
        14,
        12,
        13,
        8,
        9,
        11,
        10
    };
    const uint8_t dez_to_display[11]={
        1,
        3,
        2,
        6,
        4,
        12,
        8,
        24,
        16,
        48,
        32
    };
    
    uint8_t  swin=0;
    uint8_t  tin=0;
    uint8_t  altin=0;
    uint8_t  flank=0;
    uint8_t  flankneg=0;
    uint8_t  up=0;
    uint8_t  down=0;
    uint8_t  temperaturead=0;
    uint8_t  intemp=0;
    uint8_t  istemp=0;
    uint8_t  goaltemp=0;
    uint8_t  flagofftime=0;
    uint8_t  flagblink=0;
    uint16_t blinktimer=0;
    uint8_t  inpow=0;
    uint8_t  output=0;
    uint8_t  control=0;
    
    zustand_t zustand=aus;
    
    initBoard(0);
    
    while (1) 
    {
//Eingabe

        swin=switchReadAll();
        temperaturead=swin&IMTEMP;
        inpow=swin&IMPOW;
        altin=tin;
        tin=buttonReadAllPL()&MTIN;
        flank=tin^altin;
        flankneg=flank&altin;
        up=flankneg&IMUP;
        down=flankneg&IMDOWN;
        intemp=gray_to_dez[temperaturead];
        istemp=intemp+28;
        
//Verarbeitung

        if (blinktimer>BLINKPERIOD)
        {
            blinktimer=0;
        }
        if (!inpow)
        {
            zustand=aus;
        }
        switch (zustand)
        {
            case aus:
            output=0;
            if (inpow)
            {
                goaltemp=35;
                output=output|OMPOW;
                blinktimer=0;
                if (intemp)
                {
                    zustand=ein;
                } 
                else
                {
                    flagblink=0;
                    zustand=err;
                }
            }
            break;
            
            case err:
            if (blinktimer>(BLINKPERIOD/2))
            {
                output=output&~OMTEMP;
            } 
            else
            {
                output=output|OMTEMP;
            }
            if (intemp)
            {
                blinktimer=0;
                zustand=ein;
            }
            break;
            
            case ein:
            if ((goaltemp<41)&&up)
            {
                goaltemp=goaltemp+1;
            }
            if ((goaltemp>31)&&down)
            {
                goaltemp=goaltemp-1;
            }
            if (goaltemp==istemp)
            {
                flagblink=0;
                blinktimer=0;
            } 
            else
            {
                flagblink=1;
            }
            output=output|(OMTEMP&dez_to_display[goaltemp-31]);
            output=output&(0xc0+(OMTEMP&dez_to_display[goaltemp-31]));
            if (goaltemp>istemp)
            {
                output=output|OMHEAT;
            }
            else
            {
                output=output&~OMHEAT;
            }       
            if (!intemp)
            {
                flagblink=0;
                blinktimer=0;
                output=output&~OMHEAT;
                zustand=err;
            }                        
            break;
        }
        if ((blinktimer%(BLINKPERIOD/4))>(BLINKPERIOD/8))
        {
            flagofftime=1;
        } 
        else
        {
            flagofftime=0;
        }
        if (flagofftime&&flagblink)
        {
            output=output&~OMTEMP;
        }
        
//Ausgabe

        ledWriteAll(output);
        
//systemtakt

        blinktimer=blinktimer+SYSTEMTAKT;
        _delay_ms(SYSTEMTAKT);        
    }
}

