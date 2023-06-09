/*
 * systemtakt wadafak.c
 *
 * Created: 05.06.2023 14:52:20
 * Author : e1Derung
 */ 

#include "ucBoardDriver.h"


int main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    //CTC Mode
    TCCR1A = TCCR1A & 0b11111100;
    TCCR1B = TCCR1B & 0b11101111;
    TCCR1B = TCCR1B | 0b00001000;

    //Zählermaximum wählen
    OCR1A = 25000;

    //Flag durch Schreibvorgang löschen
    TIFR1 = TIFR1 | 0b00000010;

    //CS wählen und starten
    TCCR1B = TCCR1B & 0b11111011;
    TCCR1B = TCCR1B | 0b00000011;


    while (1)
    {
        while (!(TIFR1 & 0b00000010))
        {
            //Warten bis Flag gesetzt wird....
        }
        TIFR1 = TIFR1 | 0b00000010;//Flag durch Schreibvorgang löschen
        PORTA = ~PORTA;
        PORTB = ~PORTB;
    
    }
}

