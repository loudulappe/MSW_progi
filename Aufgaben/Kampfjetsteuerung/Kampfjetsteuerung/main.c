/*
 * Kampfjetsteuerung.c
 *
 * Created: 10.05.2023 14:34:46
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"
#define INPOW           0X80
#define INTARGET        0X20
#define INSPEED         0X0F
#define INSWAP          0X40
#define INREADY         0X80
#define INFIRE          0X01
#define OUTPOW          0X80
#define OUTTARGET       0X20
#define OUTWHEELS       0X10
#define OUTCOMBAT       0X04
#define OUTFLIGHT       0X02 
#define OUTSTART        0X01

#define SYSTEMTAKT      10
#define PERIOD          1000
#define PPERIOD         200
#define PPPERIOD        100

int main(void)
{
    uint8_t inswitch=0;
    uint8_t inpow=0;
    uint8_t intarget=0;
    uint8_t inspeed=0;
    uint8_t speed=0;
    uint8_t inbutton=0;
    uint8_t altinbutton=0;
    uint8_t flanks=0;
    uint8_t flankpos=0;
    uint8_t inswap=0;
    uint8_t inready=0;
    uint8_t infire=0;
    
    uint8_t weapon=0;
    uint8_t flagtarget=0;
    uint8_t flagready=0;
    uint32_t blinktimer=0;
    uint8_t ledout=0;
    uint8_t ammo=0;
    uint8_t control=1;
    
    
    typedef enum zustand_t {START, MID, COMBAT}
    zustand_t;
    zustand_t zustand =START;
    
    initBoard(0);
    
    while (1) 
    {
        control=1;
        altinbutton=inbutton;
        inswitch=switchReadAll();
        inbutton=buttonReadAllPL();
        inpow=inswitch&INPOW;
        inspeed=inswitch&INSPEED;
        intarget=inswitch&INTARGET;
        flanks= altinbutton^inbutton;
        flankpos=flanks&inbutton;
        inswap= flankpos&INSWAP;
        inready= flankpos&INREADY;
        infire= flankpos&INFIRE;
        
        if (inpow)
        {
            speed=inspeed;
            ledout=ledout|OUTPOW;
        }
        else
        {
            if (inspeed<speed)
            {
                speed=inspeed;
            }
            ledout=ledout&~OUTPOW;
        }
        switch (zustand)
        {
            case START:
            ledout=ledout|OUTSTART;
            ledout=ledout|OUTWHEELS;
            if (speed>2)
            {
                ledout=ledout&~OUTSTART;
                ledout=ledout&~OUTWHEELS;
                zustand=MID;
            }
            control=0xf;
            break;
            
            case MID:
            ledout=ledout|OUTFLIGHT;
            if (speed<3)
            {
                ledout=ledout&~OUTFLIGHT;
                zustand=START;
            }
            if (speed>7)
            {
                ledout=ledout&~OUTFLIGHT;
                zustand=COMBAT;    
            }
            break;
            
            case COMBAT:
            ledout=ledout|OUTCOMBAT;
            if (inready)
            {
                flagready=!flagready;
            }
            if (inswap)
            {
                ammo=ammo+1;
                blinktimer=0;
            }
            if (ammo>2)
            {
                ammo=0;
            }
            if (flagready)
            {
                if (intarget)
                {
                    flagtarget=1;
                }
                else
                {
                    flagtarget=0;
                }
            }
            else
            {
                flagtarget=0;
            }
            if (infire&&flagtarget)
            {
                flagready=0;
            }
            if (speed<8)
            {
                flagready=0;
                flagtarget=0;
                ledout=ledout&~OUTCOMBAT;
                zustand=MID;
            }
            break;
        }
        if (flagtarget)
        {
            ledout=ledout|OUTTARGET;
        } 
        else
        {
            if (flagready)
            {
                if (ammo)
                {
                    if (ammo>1)
                    {
                        if (blinktimer<(PPPERIOD/2))
                        {
                            ledout=ledout|OUTTARGET;
                        }
                        else
                        {
                            ledout=ledout&~OUTTARGET;
                        }
                        if (blinktimer>PPPERIOD)
                        {
                            blinktimer=0;
                        }
                    } 
                    else
                    {
                        if (blinktimer<(PPERIOD/2))
                        {
                            ledout=ledout|OUTTARGET;
                        }
                        else
                        {
                            ledout=ledout&~OUTTARGET;
                        }
                        if (blinktimer>PPERIOD)
                        {
                            blinktimer=0;
                        }
                    }
                } 
                else
                {
                    if (blinktimer<(PERIOD/2))
                    {
                        ledout=ledout|OUTTARGET;
                    } 
                    else
                    {
                        ledout=ledout&~OUTTARGET;
                    }
                    if (blinktimer>PERIOD)
                    {
                        blinktimer=0;
                    }
                }
            } 
            else
            {
                ledout=ledout&~OUTTARGET;
            }
        }
        ledWriteAll(ledout);
        _delay_ms(SYSTEMTAKT);
        blinktimer=blinktimer+SYSTEMTAKT;
    }
}

