/*
 * ADtreiber.h
 *
 * Created: 29.09.2022 14:32:43
 *  Author: e1Derung
 */ 
#ifndef ADTREIBER_H_
#define ADTREIBER_H_

#include <avr/io.h>
#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>


void initBoard (void);
void ledWriteAll (uint16_t bitmuster);
void ledWrite (uint16_t ledNr0_15, uint8_t wert0_1);
uint16_t ledReadAll(void);



#endif /* ADTREIBER_H_ */