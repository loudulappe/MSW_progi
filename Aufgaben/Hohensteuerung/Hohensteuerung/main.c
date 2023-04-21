/*
 * Hohensteuerung.c
 *
 * Created: 21.04.2023 14:34:09
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"
#define INMASKSWITCH            3             
#define INMASKBUTTONS           0X43
#define INMASKPOWER             1
#define INMASKFAHRWERK          2
#define INMASKUP                1
#define INMASKDOWN              2
#define INMASKCARDSENS          0X40
#define OUTMASKFAHRWERK         0X80
#define OUTMASKWARNUNG          0X20
#define OUTMASKHOHE             0X0F
#define OUTMASKLOW              1
#define BLINKTAKT               10
#define DANGERPERIOD            200
#define LOWPERIOD               1000
#define LOCKPERIOD              2000
#define LOCKONTIME              200

int main(void)
{
    typedef enum zustand_t {AUS, STARTLANDEN, SPERRUNG, ABSTURZGEFAHR, FLUG} zustand_t;
    zustand_t zustand=AUS;
    
    uint8_t switchin=0;
    uint8_t powerin=0;
    uint8_t fahrwerkin=0;
    uint8_t buttonin=0;
    uint8_t altbuttonin=0;
    uint8_t posflank=0;
    uint8_t upin=0;
    uint8_t downin=0;
    uint8_t flaglow=0;
    uint8_t flagcontrol=0;
    uint8_t flagdanger=0;
    uint8_t flaglock=0;
    uint8_t flughohe=0;
    uint32_t blinktimer=0;
    uint8_t anzeige=0;
    uint8_t cardsensin=0;
    uint8_t control=0;
    
    uint8_t hex_to_display[]= {
        0,
        0,
        1,
        3,
        2,
        6,
        4,
        12,
        8
    };
    
    initBoard(0);

    while (1) 
    {
        altbuttonin=buttonin;
        
        switchin=switchReadAll();
        buttonin=buttonReadAllPL();
        powerin= switchin&INMASKPOWER;
        fahrwerkin= switchin&INMASKFAHRWERK;
        
        posflank=(altbuttonin^buttonin)&buttonin;
        upin=posflank&INMASKUP;
        downin=posflank&INMASKDOWN;
        cardsensin=posflank&INMASKCARDSENS;
        
        if (flagcontrol)
        {
            if (upin&&(flughohe<8))
            {
                flughohe=flughohe+1;
            }
            if (downin&&flughohe)
            {
                flughohe=flughohe-1;
            }
        }
        switch (zustand)
        {
            case AUS: 
            anzeige=0;
            flagcontrol=0;
            flughohe=0;
            if (powerin)
            {
                zustand=STARTLANDEN;
            }
            control=1;
        	break;
            
            case STARTLANDEN:
            flaglow=1;
            anzeige=anzeige|OUTMASKFAHRWERK;
            flagcontrol=1;
            if (fahrwerkin)
            {
                if (flughohe)
                {
                    zustand=ABSTURZGEFAHR;
                } 
                else
                {
                    zustand=SPERRUNG;
                }
                flaglow=0;
                blinktimer=0;
            }
            if (!powerin&&!flughohe)
            {
                zustand=AUS;
                flaglow=0;
                blinktimer=0;
            }
            if (flughohe>1)
            {
                zustand=FLUG;
                flaglow=0;
                blinktimer=0;
            }
            control=2;
            break;
            
            case SPERRUNG:
            flaglock=1;
            flagcontrol=0;
            if (cardsensin&&!fahrwerkin)
            {
                zustand=STARTLANDEN;
                flaglock=0;
                blinktimer=0;
                anzeige=0;
            }
            control=4;
            break;
            
            case ABSTURZGEFAHR:
            if (fahrwerkin)
            {
                anzeige=anzeige&~OUTMASKFAHRWERK;
            }
            else
            {
                anzeige=anzeige|OUTMASKFAHRWERK;
            }
            flagdanger=1;
            if (flughohe>1)
            {
                zustand=FLUG;
                flagdanger=0;
                blinktimer=0;
            }
            control=8;
            break;
            
            case FLUG:
            anzeige=anzeige|hex_to_display[flughohe];
            anzeige=anzeige&(hex_to_display[flughohe]&OUTMASKHOHE);
            if (fahrwerkin)
            {
                anzeige=anzeige&~(OUTMASKFAHRWERK|OUTMASKWARNUNG);
            } 
            else
            {
                anzeige=anzeige|(OUTMASKFAHRWERK|OUTMASKWARNUNG);
            }
            if (flughohe<2)
            {
                anzeige=anzeige&~OUTMASKWARNUNG;
                zustand=STARTLANDEN;
            }
            control=16;
            break;
        }
        if (flaglock)
        {
            if (blinktimer>LOCKPERIOD)
            {
                blinktimer=0;
            }
            if (blinktimer>LOCKONTIME)
            {
                anzeige=0;
            } 
            else
            {
                anzeige=OUTMASKHOHE|OUTMASKFAHRWERK|OUTMASKWARNUNG;
            }
        } 
        else
        {
            if (flagdanger)
            {
                if (blinktimer>DANGERPERIOD)
                {
                    blinktimer=0;
                }
                if (blinktimer>(DANGERPERIOD/2))
                {
                    anzeige=anzeige&~OUTMASKHOHE;
                } 
                else
                {
                    anzeige=anzeige|OUTMASKHOHE;
                }
            } 
            else
            {
                if (flaglow)
                {
                    if (blinktimer>LOWPERIOD)
                    {
                        blinktimer=0;
                    }
                    if (blinktimer>(LOWPERIOD/2))
                    {
                        anzeige=anzeige&~OUTMASKLOW;
                    } 
                    else
                    {
                        anzeige=anzeige|OUTMASKLOW;
                    }
                } 
                else
                {
                    blinktimer=0;
                }
            }
        }
        ledWriteAll(anzeige);
        
        _delay_ms(BLINKTAKT);
        blinktimer=blinktimer+BLINKTAKT;
    }
}

