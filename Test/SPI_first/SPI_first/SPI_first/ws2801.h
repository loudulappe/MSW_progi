//*********************************************************************************\
*
// * MMMMMMMMMMMM   SSSSSSSSSSSS   WW   WW   WW   MECHATRONIK
// * MM   MM   MM   SS             WW   WW   WW   SCHULE
// * MM   MM   MM   SSSSSSSSSSSS   WW   WW   WW   WINTERTHUR
// * MM   MM   MM             SS   WW   WW   WW
// * MM   MM   MM   SSSSSSSSSSSS   WWWWWWWWWWWW   www.msw.ch
// *
// *
// * Dateiname: ws2801
// * Projekt  : ws2801
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


#ifndef WS2801_H_
#define WS2801_H_
#include <stdint.h>
void ws2801WriteUni (uint8_t anzahl, uint8_t red, uint8_t blue, uint8_t green);
void ws2801Writesingle (uint8_t anzahl, uint8_t red, uint8_t blue, uint8_t green);


#endif /* WS2801_H_ */