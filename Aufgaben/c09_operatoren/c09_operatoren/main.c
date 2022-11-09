/*
 * c09_operatoren.c
 *
 * Created: 27.10.2022 15:30:10
 * Author : e1Derung
 */ 

#include "ADtreiber.h"


int main(void)
{
    #define IMSW0 0x01
    #define IMSW1 0x02
    #define IMSW2 0x04
    #define IMSW3 0x08
    #define IMSW4 0x10
    #define IMSW5 0x20
    #define IMSW6 0X40
    #define IMSW7 0x80
    
    #define OMLED0 0x01
    #define OMLED1 0x02
    #define OMLED2 0x04
    #define OMLED3 0x08
    #define OMLED4 0x10
    #define OMLED5 0x20
    #define OMLED6 0x40
    #define OMLED7 0x80
    
    uint8_t oled0=0;
    uint8_t oled1=0;
    uint8_t oled2=0;
    uint8_t oled3=0;
    uint8_t oled4=0;
    uint8_t oled5=0;
    uint8_t oled6=0;
    uint8_t oled7=0;
    
    uint8_t is0 = 0;
    uint8_t is1 = 0;
    uint8_t is2 = 0;
    uint8_t is3 = 0;
    uint8_t is4 = 0;
    uint8_t is5 = 0;
    uint8_t is6 = 0;
    uint8_t is7 = 0;
    uint8_t is13= 0;

    
    initBoard();
    
    while (1) 
    {
        uint8_t swinput = SwitchReadAll();
        
        is0 = swinput & IMSW0;
        is1 = swinput & IMSW1;
        is2 = swinput & IMSW2;
        is3 = swinput & IMSW3;
        is4 = swinput & IMSW4;
        is5 = swinput & IMSW5;
        is6 = swinput & IMSW6;
        is7 = swinput & IMSW7;
        
        oled0=is7&&is7;
        oled1 = (is7&&is6&&!is5);
        if (oled1)
        {
            oled1=OMLED1;
        }
        if (!(is6&&is5&&is4))
        {
            oled2=OMLED2;
        } 
        else
        {
            oled2=0;
        }
        if (is1)    
        {
            oled3=OMLED3;
            oled4=0;
        } 
        else
        {
            oled3=0;
            oled4=OMLED4;
        }
        if (!(swinput%17))
        {
            oled5=OMLED5;
        } 
        else
        {
            oled5=0;
        }
        

        
        ledWriteAll(oled0|oled1|oled2|oled3|oled4|oled5|oled6|oled7);
    }
}

