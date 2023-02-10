/*********************************************************************************\
*
* MMMMMMMMMMMMMMMMMM   SSSSSSSSSSSSSSSSSS   WWWW   WWWW   WWWW
* MMMMMMMMMMMMMMMMMM   SSSSSSSSSSSSSSSSSS   WWWW   WWWW   WWWW   MECHATRONIK
* MMMMMMMMMMMMMMMMMM   SSSSS                WWWW   WWWW   WWWW
* MMMM   MMMM   MMMM   SSSSSSSSSSSSSSSSSS   WWWW   WWWW   WWWW   SCHULE
* MMMM   MMMM   MMMM   SSSSSSSSSSSSSSSSSS   WWWW   WWWW   WWWW
* MMMM   MMMM   MMMM                SSSSS   WWWWWWWWWWWWWWWWWW   WINTERTHUR
* MMMM   MMMM   MMMM   SSSSSSSSSSSSSSSSSS   WWWWWWWWWWWWWWWWWW
* MMMM   MMMM   MMMM   SSSSSSSSSSSSSSSSSS   WWWWWWWWWWWWWWWWWW   www.msw.ch
*
*
* Dateiname: main.c
*
* Projekt  : Muster
* Hardware : uC-Board, ATmega2560v von Atmel
*
* Copyright: MSW, E2
*
* Beschreibung:
* =============
* Siehe Prüfungsaufgabe
*
* Portbelegung:
* =============
* Port C:   Schalter
* Port A:   LEDs
* für genauere Beschreibung siehe Hardwarestruktur
*
* Verlauf:
* ========
* Datum:      Autor:         Version   Grund der Änderung:
* dd.mm.yyyy  M. Muster      V1.0      Neuerstellung
*
\*********************************************************************************/

//uC-Board-Treiber hinzufügen
#include <stdlib.h>
#include "ucBoardDriver.h"
#include "ws2812.h"
#define systemtakt  10
#define BRIGHTCAP   100
#define LEDGROUP    8


void set_pixel(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b, rgb_color * display);
//Hauptprogramm
int main(void)
{
    //Variablen
    rgb_color leds[LED_COUNT] = {0,0,0};
    rgb_color ledline[LED_COUNT/LEDGROUP] = {0,0,0};
    uint8_t valred=BRIGHTCAP;
    uint8_t valgreen=0;
    uint8_t valblue=0;
    uint8_t flagdir=0;
    rgb_color fade ={0,0,0};
    uint16_t systemzeit=0;
    rgb_color zwischenspeicher={0,0,0};
    uint8_t coord=0;
    rgb_color colour= {0,0,0};
    uint16_t counter=0;
    uint16_t counterflag=0;
    
    
    
    
    //Initialisieren
    initBoard(1);
    
    //Anfangswert für Zufallsgenerator setzen, gleicher Anfengswert ergibt die gleiche
    //.. Abfolge von Zufallszahlen. Wir lesen einen offenen (undefinierten) ADC ein
    //.. und setzen somit einen undefinierten (zufälligen) Anfangswert.
    srandom(adcRead(ADC_00_X4_PORTF_BIT0));
    
    //Unendlichschlaufe
    while(1)
    {   
        if ((valred==BRIGHTCAP)||(valgreen==BRIGHTCAP)||(valblue==BRIGHTCAP))
        {
            flagdir=flagdir+1;
            if (flagdir==3)
            {
                flagdir=0;
            }
        }

        if (flagdir==1)
        {
            valred=valred-2;
            valgreen=valgreen+2;
        } 
        else if (flagdir==2)
        {
            valgreen=valgreen-2;
            valblue=valblue+2;
        }
        else
        {
            valblue=valblue-2;
            valred=valred+2;
        }

        if ((counter==LED_COUNT/LEDGROUP)||!counter)
        {
            counterflag=!counterflag;
        }
        
//         ledline[counter]= (rgb_color){valred, valgreen, valblue};
//         for (uint16_t i=0; i<LED_COUNT; i=i+1)
//         {
//             leds[i]=ledline[i/LEDGROUP];
//         }
//         set_pixel(2,2,0,0,0, leds);
//         set_pixel(2,3,0,0,0, leds);
//         set_pixel(2,4,0,0,0, leds);
//         set_pixel(2,5,0,0,0, leds);
//         set_pixel(2,6,0,0,0, leds);
//         set_pixel(3,6,0,0,0, leds);
//         set_pixel(4,6,0,0,0, leds);
//         set_pixel(7,6,0,0,0, leds);
//         set_pixel(8,6,0,0,0, leds);
//         set_pixel(9,5,0,0,0, leds);
//         set_pixel(9,4,0,0,0, leds);
//         set_pixel(8,3,0,0,0, leds);
//         set_pixel(7,3,0,0,0, leds);
//         set_pixel(6,4,0,0,0, leds);
//         set_pixel(6,5,0,0,0, leds);
        
        led_strip_write(leds);
        _delay_ms(systemtakt);
        systemzeit=systemzeit+systemtakt; 
        if (counterflag)
        {
            counter=counter+1;
        }
        else
        {
            counter=counter-1;
        }              
    }
    
}

void set_pixel (uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b, rgb_color * display)
{

    if (x%2)
    {
        x=x*LEDGROUP;
        x=x+(LEDGROUP-1-y);
    }
    else
    {
        x=x*LEDGROUP;
        x=x+y;    
    }
    
    display[x]=(rgb_color){r,g,b};
}