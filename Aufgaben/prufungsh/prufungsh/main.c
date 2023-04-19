/*
 * prufungsh.c
 *
 * Created: 17.04.2023 07:54:43
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"3
#define ADCMAX
#define OUTHALF     0b0000000100000000
#define OUTHYS      0b0000001000000000
#define OUTSENS     0b1111110000000000
#define FLANKLED    0b0000000010000000 

int main(void)
{
    initBoard(0);
    uint32_t pot1proz=0;
    uint8_t outproz1=0;
    uint16_t ledout=0;
    uint8_t flaghys=0;
    uint32_t pot2proz=0;
    uint16_t out2=0;
    uint8_t flagflank=0;
    uint16_t flanktimer=0;
    uint8_t button1=0;
    uint8_t altbutton1=0;
    uint16_t range2=0;
    
    
    
    while (1) 
    {
        pot1proz=(uint32_t) adcRead(8)*100/1013;
        pot2proz=adcRead(9)*50/1012;
        altbutton1=button1;
        button1=buttonReadAllPL()&1;
        outproz1=pot1proz&0x7F;
        ledout=outproz1&0x7f;
        
        if (pot1proz>50)
        {
            ledout=ledout|OUTHALF;
        }
        else
        {
            ledout=ledout&~OUTHALF;
        } 
        if (pot1proz>55)
        {
            flaghys=1;
        }
        if (pot1proz<45)
        {
            flaghys=0;
        }
        if (flaghys)
        {
            ledout=ledout|OUTHYS;
        }
        else
        {
            ledout=ledout&~OUTHYS;
        } 
        range2=(pot2proz*2)-10;
        if (pot2proz<10)
        {
            out2=10;
        }
        else if (pot2proz>30)
        {
            out2=50;
        }
        else
        {
            out2=range2;
        }
        if (altbutton1<button1)
        {
            flagflank=1;
            flanktimer=300;
        }
        if (!flanktimer)
        {
            flagflank=0;
        }
        ledout=ledout|((out2<<10)&OUTSENS);
        ledout=ledout|flagflank<<7;
        ledWriteAll(ledout);
        
        if (flanktimer)
        {
            _delay_ms(10);
            flanktimer=flanktimer-1;
        }
        
    }
}

