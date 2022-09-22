/*
 * First program.c
 *
 * Created: 22.09.2022 11:33:37
 * Author : e1Derung
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
	DDRA = 0xff; // alles ausgang
	while(1)
	{
		PORTA = 0xf0; //rechte LEDs
		_delay_ms(500); //leuchten lassen
		PORTA = 0x0f;  //linke LEDs
		_delay_ms(500);  //leuchten lassen

}
