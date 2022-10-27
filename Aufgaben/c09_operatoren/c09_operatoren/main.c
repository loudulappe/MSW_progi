/*
 * c09_operatoren.c
 *
 * Created: 27.10.2022 15:30:10
 * Author : e1Derung
 */ 

#include "ADtreiber.h"


int main(void)
{
    uint8_t is0 = SwitchRead(0);
    uint8_t is1 = SwitchRead(1);
    uint8_t is2 = SwitchRead(2);
    uint8_t is3 = SwitchRead(3);
    uint8_t is4 = SwitchRead(4);
    uint8_t is5 = SwitchRead(5);
    uint8_t is6 = SwitchRead(6);
    uint8_t is7 = SwitchRead(7);
    
    uint8_t oled0=0;
    uint8_t oled1=0;
    uint8_t oled2=0;
    uint8_t oled3=0;
    uint8_t oled4=0;
    uint8_t oled5=0;
    uint8_t oled6=0;
    uint8_t oled7=0;
    
    initBoard();
    while (1) 
    {
        uint8_t is0 = SwitchRead(0);
        uint8_t is1 = SwitchRead(1);
        uint8_t is2 = SwitchRead(2);
        uint8_t is3 = SwitchRead(3);
        uint8_t is4 = SwitchRead(4);
        uint8_t is5 = SwitchRead(5);
        uint8_t is6 = SwitchRead(6);
        uint8_t is7 = SwitchRead(7);
        
        uint8_t oled0=0;
        uint8_t oled1=0;
        uint8_t oled2=0;
        uint8_t oled3=0;
        uint8_t oled4=0;
        uint8_t oled5=0;
        uint8_t oled6=0;
        uint8_t oled7=0;
        
        oled0 = is7;
        //oled1 = (is7&&is6&&!is5);
        //oled2 = !(is6&&is5&&is4);
        
        ledWriteAll(oled0|oled1|oled2|oled3|oled4|oled5|oled6|oled7);
    }
}

