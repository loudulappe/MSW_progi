//*********************************************************************************\
*
// * MMMMMMMMMMMM   SSSSSSSSSSSS   WW   WW   WW   MECHATRONIK
// * MM   MM   MM   SS             WW   WW   WW   SCHULE
// * MM   MM   MM   SSSSSSSSSSSS   WW   WW   WW   WINTERTHUR
// * MM   MM   MM             SS   WW   WW   WW
// * MM   MM   MM   SSSSSSSSSSSS   WWWWWWWWWWWW   www.msw.ch
// *
// *
// * Dateiname: SPI
// * Projekt  : SPI
// * Hardware : ATmega2560 von Atmel
// * Copyright: MSW, E3
// * Beschreibung:
// * Siehe Prüfungsaufgabe
// * Portbelegung:
// * Siehe Hardwarestruktur
// * Verlauf:
// * Datum:      Autor:         Version   Grund der Änderung:
// * 27.02.2024  Adrian Derungs    V1.0       Neuerstelung
// *
// \*********************************************************************************/

#include <avr/io.h>
#include "SPI.h"
#define DDR_SPI DDRB

void SPI_Masterinit (void)
{
    //MOSI&clk out, rest in
    DDR_SPI |= (1<<CLK)|(1<<MOSI)|(1<<SS);
    //set SPE, MSTR, clk/32 (SPR1, SPI2X)
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR1);
    SPSR = (1<<SPI2X) ;
}
void SPI_mastertransmit(uint8_t cData)
{
    //Sample
    SPDR = cData;
    //wait til complete
    while (!(SPSR&(1<<SPIF)))
    {
    }
}

unsigned char USART_Receive( void )
{
    /* Wait for data to be received */
    while ( !(UCSR0A & (1<<RXC0)) )
    ;
    /* Get and return received data from buffer */
    return UDR0;
}

void USART_9_Transmit( unsigned int data )
{
    /* Wait for empty transmit buffer */
    while ( !( UCSR0A & (1<<UDRE0))) 
    ;
    /* Copy 9th bit to TXB8 */
    UCSR0B &= ~(1<<TXB80);
    if ( data & 0x0100 )
    UCSR0B |= (1<<TXB80);
    /* Put data into buffer, sends the data */
    UDR0 = data;
}


void USART_Init( unsigned int ubrr){
    /* Set baud rate */
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;
    /* Enable receiver and transmitter */
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    /* Set frame format: 8data, 2stop bit */
    UCSR0C = (1<<USBS0)|(3<<UCSZ00);
} // USART_Init