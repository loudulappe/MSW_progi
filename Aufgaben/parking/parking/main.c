/*
 * parking.c
 *
 * Created: 22.06.2023 10:03:21
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"

#define MASKREQIN           1
#define MASKLIGHTIN         2
#define MASKREQOUT          0X40
#define MASKLIGHTOUT        0X80
#define MASKPOWER           1
#define MASKGATEIN          0X04
#define MASKGATEOUT         0X08
#define MASKGREEN           0X10
#define MASKYELLOW          0X20 
#define MASKRED             0X40
#define SYSTEMTAKT          10
#define BLINKPERIODE        1000

int main(void)
{
    typedef enum zustand_t {aus, betrieb, raus, rein}
        zustand_t;
    zustand_t zustand=aus;
    uint8_t besucheranzahl=0;
    uint8_t flagerr=0;
    uint8_t butin=0;
    uint8_t altbutin=0;
    uint8_t flank=0;
    uint8_t negflank=0;
    uint8_t posflank=0;
    uint8_t power=0;
    uint8_t lightin=0;
    uint8_t lightout=0;
    uint8_t reqin=0;
    uint8_t reqout=0;
    uint8_t flightin=0;
    uint8_t flightout=0;
    uint8_t ledout=0;
    uint16_t blinktimer=0;
    
    initBoard(0);
    while (1) 
    {
        altbutin=butin;
        butin=buttonReadAllPL();
        flank=altbutin^butin;
        posflank=flank&butin;
        negflank=flank&altbutin;
        power=switchReadAll()&MASKPOWER;
        lightin=butin&MASKLIGHTIN;
        flightin=negflank&MASKLIGHTIN;
        lightout=butin&MASKLIGHTOUT;
        flightout=negflank&MASKLIGHTOUT;
        reqin=posflank&MASKREQIN;
        reqout=posflank&MASKREQOUT;
        
        if (power)
        {
            ledout=ledout|MASKPOWER;
        } 
        else
        {
            ledout=ledout&~MASKPOWER;
            zustand=aus;
        }
        switch (zustand)
        {
            case aus:
            ledout=0;
            if (power)
            {
                zustand=betrieb;
                flagerr=1;
            }
            break;
            
            case betrieb:
            if (!lightin&&!lightout)
            {
                flagerr=0;
            }
            if (!flagerr)
            {
                ledout=ledout|MASKGATEOUT|MASKGATEIN;
                if (besucheranzahl==10)
                {
                    ledout=ledout|MASKRED;
                    ledout=ledout&~MASKYELLOW;
                    ledout=ledout&~MASKGREEN;
                }
                else
                {
                    if (besucheranzahl>8)
                    {
                        ledout=ledout&~MASKRED;
                        ledout=ledout|MASKYELLOW;
                        ledout=ledout&~MASKGREEN;
                    }
                    else
                    {
                        ledout=ledout&~MASKRED;
                        ledout=ledout&~MASKYELLOW;
                        ledout=ledout|MASKGREEN;
                    }                     
                }
                if (reqout)
                {
                    zustand=raus;
                }
                if ((besucheranzahl<10)&&reqin)
                {
                    zustand=rein;
                }
            }
            break;
            
            case raus:
            ledout=ledout&~MASKGATEOUT;
            if (flightout)
            {
                zustand=betrieb;
                if (besucheranzahl)
                {
                    besucheranzahl=besucheranzahl-1;
                }
            }
            break;
            
            case rein:
            ledout=ledout&~MASKGATEIN;
            if (flightin)
            {
                zustand=betrieb;
                besucheranzahl=besucheranzahl+1;
            }
            break;
        }
        if (flagerr)
        {
            if (blinktimer>BLINKPERIODE)
            {
                blinktimer=0;
            }
            if (blinktimer>(BLINKPERIODE/4))
            {
                ledout=ledout&~MASKPOWER;
            }
        }
        else
        {
            blinktimer=0;
        }
        ledWriteAll(ledout);
        _delay_ms(SYSTEMTAKT);
        blinktimer=blinktimer+SYSTEMTAKT;
    }
}

