/*
 * elevator.c
 *
 * Created: 16.06.2023 13:27:14
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"

#define INCALL      1
#define INRIDE      2
#define INLOC       7
#define INTARGET    0XE0

int main(void)
{
    uint8_t stock=0;
    uint8_t ziel=0;
    uint8_t butin=0;
    uint8_t call=0;
    uint8_t ride=0;
    uint8_t flank=0;
    uint8_t posflank=0;
    uint8_t stop=0;
    uint16_t speed=0;
    uint8_t swin=0;
    uint8_t loc=0;
    uint8_t target=0;
    uint8_t altbutin=0;
    uint8_t negflank=0;
    
    while (1) 
    {
        altbutin=butin;
        swin=switchReadAll();
        target=swin&INTARGET;
        loc=swin&INLOC;
        butin=buttonReadAllPL();
        flank=altbutin^butin;
        posflank=flank&butin;
        stop=flank&altbutin&INRIDE;
        
        
        ledWriteAll(INLOC);
    }
}

