/*********************************************************************************\
*
* MMMMMMMMMMMM   SSSSSSSSSSSS   WW   WW   WW   MECHATRONIK
* MM   MM   MM   SS             WW   WW   WW   SCHULE
* MM   MM   MM   SSSSSSSSSSSS   WW   WW   WW   WINTERTHUR
* MM   MM   MM             SS   WW   WW   WW
* MM   MM   MM   SSSSSSSSSSSS   WWWWWWWWWWWW   www.msw.ch
*
*
* Dateiname: SPI
*
* Projekt  : SPI
* Hardware : Mocca-Board, ATmega2560v von Atmel
*
*
* Copyright: MSW, AE3
\*********************************************************************************/

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