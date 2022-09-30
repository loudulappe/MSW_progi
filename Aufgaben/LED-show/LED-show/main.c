/*
 * LED-show.c
 *
 * Created: 30.09.2022 11:23:06
 * Author : e1Derung
 */ 

#include "ADtreiber.h"

int main(void)
{
    initBoard();
//1    
//  while (1)
//  {   
//      uint8_t i = 0;
//      for (i=0; i<16; i= i+1)
//      {
//          ledWriteAll(1<<i);
//          _delay_ms(100);
//      }               
//  }
//2 
//  while (1)
//  {    
//      uint8_t i = 0;
//      for (i=0; i<16; i= i+1)
//      {
//          ledWriteAll(1<<i);
//          _delay_ms(100);  
//      } 
//      uint8_t e = 15;
//      for (e=15; e>0; e= e-1)
//      {
//          ledWriteAll(1<<e);
//          _delay_ms(100);
//      }            
//  }
//3
    while (1)
    {
        ledWriteAll(0);
        uint8_t i=0;
        for (i=0; i<16; i=i+1)
        {
            PORTA=PORTA|1<<i;
            PORTB=PORTB|((i>7)<<(i-8));
            _delay_ms(500);
        }
    }
        
}

