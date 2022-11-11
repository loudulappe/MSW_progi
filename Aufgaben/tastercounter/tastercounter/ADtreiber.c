/*
 * ADtreiber.c
 *
 * Created: 29.09.2022 14:22:08
 *  Author: e1Derung
 */ 

#include "ADtreiber.h"

void initBoard(void)
{
    DDRA = 0xff;
    DDRB = 0xff;
    DDRC = 0;
    PORTC = 0xff;
}

void ledWriteAll(uint16_t bitmuster)
{
    PORTA = bitmuster;
    PORTB = bitmuster >>8;
}

void ledWrite(uint16_t ledNr0_15, uint8_t wert0_1)
{
    if (wert0_1)
    {
        PORTA = PORTA | 1<< (ledNr0_15);
        PORTB = PORTB | ((ledNr0_15>7)<<(ledNr0_15-8));
    } 
    else
    {
        PORTA = PORTA & ~(1<< (ledNr0_15));
        PORTB = PORTB & ~((ledNr0_15>7)<<(ledNr0_15-8)) ;       
    }
} 

uint16_t ledReadAll()
{
    return PORTA|(PORTB<<8);
}

void initAdc(void)
{
    //PORTF (ADC, X4) Eingang ohne PullUps
    PORTF   = 0x00;
    DDRF    = 0x00;
    //PORTK (ADC-Inputs) alles auf Eingang ohne Pullup
    PORTK   = 0x00;
    DDRK    = 0x00;
    
    ADMUX  = 0x40;    //AVCC Als referenz
    DIDR0  = 0x0F;    // Digitale Register an ADC pins der Potentiometer deaktivieren
    DIDR2  = 0xFF;
    
    ADCSRA = 0b10100111; // ADC einschalten, ADC clok = 16MHz / 128 --> 8us/cycle
    ADCSRB = 0x00;    // Free runing mode
    
    ADCSRA |=  0b01000000;        // Dummy messung Starten
    while((ADCSRA&0x10) == 0);    // Warten bis Messung abgeschllossen
    
    ADCSRA &= 0xEF;                // Interruptflage löschen
}

uint16_t adcRead(uint8_t kanal)
{
    uint16_t messwert = 0;
    
    // Kanal definieren
    ADMUX  = 0x40;    //AVCC Als referenz
    if(kanal>=8)
    {    ADMUX  |= kanal-8;
        ADCSRB |= (3 << MUX5);
    }
    else
    {    ADMUX  |= kanal;
        ADCSRB &= ~(3 << MUX5);
    }
    
    
    ADCSRA |=  0b01000000;        // ADC Starten
    while((ADCSRA&0x10) == 0);    // Warten bis Messung abgeschllossen
    
    _delay_us(300);//25 ADC clock cycles
    
    messwert = ADCL;
    messwert |= ADCH <<8;
    
    ADCSRA &= 0xEF;                // Interruptflage löschen
    
    return messwert;
}

uint8_t SwitchReadAll()
{
    return PINC;
}

uint8_t SwitchRead(uint8_t pos)
{
    return ((1<<pos)&PINC);
}

uint8_t tasterreadall()
{
    return (((PINL&0x03)<<6)|((PINL&0xc0)>>6));
}
