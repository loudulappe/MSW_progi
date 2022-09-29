/*
 * OperatorenTest.c
 *
 * Created: 22.09.2022 14:32:52
 * Author : Adrian Derungs
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    DDRA = 0xff;
    while (1) 
    {
        PORTA = 8 + 7;
        _delay_ms(1000);
        PORTA = 255-15;
        _delay_ms(1000);
        PORTA = 60 / 4;
        _delay_ms(1000);
        PORTA = 24 * 10;
        _delay_ms(1000);
        PORTA = 31 % 16;
        _delay_ms(1000);
        PORTA = 0b00001111 << 4;
        _delay_ms(1000);
        PORTA = 0b11110000 >> 4;
        _delay_ms(1000);
        PORTA = 0b11110101 & 0b11111010;
        _delay_ms(1000); 
        PORTA = 0b00000101 | 0b00001010;  
        _delay_ms(1000);
        PORTA = 0b10101010 ^ 0b01011010;
        _delay_ms(1000);
        PORTA = 0b00001000 || 0b10000000;
        _delay_ms(1000);
        PORTA = 0b10000000 && 0b00000000;
        _delay_ms(1000);
        PORTA = 5 < 7;
        _delay_ms(1000);
        PORTA = 5 > 7;
        _delay_ms(1000);
        PORTA = 5 >= 5;
        _delay_ms(1000);
        PORTA = 5 <= 4;
        _delay_ms(1000);
        PORTA = 4 == 4; 
        _delay_ms(1000);
        PORTA = 4 !=4;
        _delay_ms(1000);
        if PORTA = true, 
    }
}
