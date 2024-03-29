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
// * Siehe Pr�fungsaufgabe
// * Portbelegung:
// * Siehe Hardwarestruktur
// * Verlauf:
// * Datum:      Autor:         Version   Grund der �nderung:
// * 27.02.2024  Adrian Derungs    V1.0       Neuerstelung
// *
// \*********************************************************************************/





#ifndef SPI_H_
#define SPI_H_


#define MOSI 2
#define CLK 1
#define SS 0

#define FOSC 1843200// Clock Speed
#define BAUD 9600
#define MYUBRR (FOSC/16/BAUD-1)



#include <stdint.h>
void SPI_Masterinit(void);
void SPI_mastertransmit(uint8_t cData);
unsigned char USART_Receive( void );
void USART_9_Transmit( unsigned int data );



#endif /* SPI_H_ */