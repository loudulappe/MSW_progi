/*
 * Pruefung_loetstation.c
 *
 * Created: 15.03.2023 14:25:24
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"

#define     BLINKPERIOD         2000
#define     INPOW               0x80
#define     INTEMP              0x0f
#define     INUP                0x01
#define     INDOWN              0x02
#define     OUTPOW              0x80
#define     OUTHEAT             0x40
#define     OUTTEMP             0X3F
#define     SYSTEMTAKT          10


int main(void)
{
    initBoard(0);
    uint8_t ledout=0;
    uint8_t gray_to_hex[16]=
    {
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
    uint8_t hex_to_LED[11]=
    {
        0x01,
        0x03,
        0x02,
        0x06,
        0x04,
        0x0c,
        0x08,
        0x18,
        0x10,
        0x30,
        0x20,
    };
    uint8_t swin=0;
    uint8_t tin=0;
    uint8_t inpow=0;
    uint8_t tinup=0;
    uint8_t tindown=0;
    uint8_t alttinup=0;
    uint8_t alttindown=0;
    uint8_t intemp=0;
    uint8_t idealtemp=0;
    uint32_t blinktakt=0;
    uint8_t istemp=0;
    uint8_t altinpow=0;
    uint8_t control=0;
    uint8_t outtemp=0;
    uint8_t heat=0;
    uint8_t power=0;
    
    while (1) 
    {
        if (blinktakt>BLINKPERIOD)
        {
            blinktakt=0;
        }
        alttindown=tindown;
        alttinup=tinup;
        altinpow=inpow;
        swin=switchReadAll();
        tin=buttonReadAllPL();
        tinup=tin&INUP;
        tindown=tin&INDOWN;
        inpow=swin&INPOW;
        intemp=swin&INTEMP;
        
        if (inpow>altinpow)
        {
            idealtemp=35;
            blinktakt=0;
        }
        if (inpow)
        {
            intemp=gray_to_hex[intemp];
            istemp=intemp+28;
            if (intemp)
            {
                if (idealtemp>31&&(tindown>alttindown))
                {
                    idealtemp=idealtemp-1;
                } 
                if (idealtemp<41&&(tinup>alttinup))
                {
                    idealtemp=idealtemp+1;
                }
                if (istemp<idealtemp)
                {
                    heat=OUTHEAT;
                }
                else
                {
                    heat=0;
                }
                if ((idealtemp<42)&&(idealtemp>30))
                {
                     if (idealtemp==istemp)
                     {
                         outtemp=hex_to_LED[idealtemp-31];
                     }
                     else
                     {
                         if ((blinktakt%(BLINKPERIOD/4))<BLINKPERIOD/8)
                         {
                             outtemp=hex_to_LED[idealtemp-31];
                         }
                         else
                         {
                             outtemp=0;
                         }
                     }
                }                 
                else
                {
                    outtemp=0x00;
                }
            }            
            else
            {
                if (blinktakt<BLINKPERIOD/2)
                {
                    outtemp=OUTTEMP;
                } 
                else
                {
                    outtemp=0;
                }
                heat=0;
            }
            power=OUTPOW;
        } 
        else
        {
            outtemp=0;
            heat=0;
            power=0;
        }
        ledout= outtemp|power|heat;
        ledWriteAll(ledout);
        blinktakt=blinktakt+SYSTEMTAKT;
        _delay_ms(SYSTEMTAKT);
    }
}

