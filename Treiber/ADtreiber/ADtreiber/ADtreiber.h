/*
 * ADtreiber.h
 *
 * Created: 29.09.2022 14:32:43
 *  Author: e1Derung
 * https://github.com/loudulappe/MSW_progi/blob/main/Treiber/ADtreiber/ADtreiber/ADtreiber.h
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>


#ifndef ADTREIBER_H_
#define ADTREIBER_H_




void initBoard (void);

void ledWriteAll (uint16_t bitmuster);

void ledWrite (uint16_t ledNr0_15, uint8_t wert0_1);

uint16_t ledReadAll(void);

void initAdc(void);

uint8_t SwitchReadAll(void);

uint8_t SwitchRead(uint8_t pos);
/**
 * \brief Liest einen Analogen Wert von einem ADC ein. Auflösung 10 Bit (0..1023)
 * 
 * \param kanal Einen ADC-Kanal, siehe adcChannel_t
 * 
 * \return uint16_t Eingelesener 10 Bit Wert zwischen 0...1023
 */

uint16_t adcRead(uint8_t kanal);



#endif /* ADTREIBER_H_ */