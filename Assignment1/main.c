/*
 * main.c
 *
 *  Created on: Aug 24, 2019
 *      Author: lenovo
 */
#include <avr/delay.h>
#include <avr/io.h>
#include <util/delay>
int main()
{
	DDRD=0xFF;
	DDRA=0x00;
	PORTA=0xFF;
	while(1)
	{
		if(((PINA&(1<<0))!=0)&&((PINA&(1<<1))==0))
		{
			for(int i=0; i<8; i++)
				{
					PORTD|=(1<<i);
					_delay_ms(250);
					PORTD&=~(1<<i);
				}
		}
			else if(((PINA&(1<<0))==0)&&((PINA&(1<<1))!=0))
			{
				for(int i=7; i>=0; i--)
					{
						PORTD|=(1<<i);
						_delay_ms(250);
						PORTD&=~(1<<i);
					}
			}
			else if(((PINA&(1<<0))!=0)&&((PINA&(1<<1))!=0))
			{
				PORTD=0xFF;
				_delay_ms(500);
				PORTD=0x00;
				_delay_ms(500);
			}
			else if(((PINA&(1<<0))==0)&&((PINA&(1<<1))==0))
			{
				for(int i=0; i<4; i++)
				{
					PORTD|=(1<<i)|(1<<7-i);
					_delay_ms(300);
					PORTD&=~(1<<i);
					PORTD&=~(1<<7-i);
				}
			}




		/*PORTA|=(1<<0);
		_delay_ms(100);
		PORTA|=(1<<1);
		_delay_ms(100);
		PORTA|=(1<<2);
		_delay_ms(100);
		PORTA|=(1<<3);
		_delay_ms(100);
		PORTA|=(1<<4);
		_delay_ms(100);
		PORTA|=(1<<5);
		_delay_ms(100);
		PORTA|=(1<<6);
		_delay_ms(100);
		PORTA|=(1<<7);
		_delay_ms(1000);
		PORTA&=~(1<<7);
		_delay_ms(100);
		PORTA&=~(1<<6);
		_delay_ms(100);
		PORTA&=~(1<<5);
		_delay_ms(100);
		PORTA&=~(1<<4);
		_delay_ms(100);
		PORTA&=~(1<<3);
		_delay_ms(100);
		PORTA&=~(1<<2);
		_delay_ms(100);
		PORTA&=~(1<<1);
		_delay_ms(100);
		PORTA&=~(1<<0);
		_delay_ms(1000);//all off
		PORTA|=(1<<0);
		_delay_ms(500);
		PORTA&=~(1<<0);
		_delay_ms(100);
		PORTA|=(1<<0);
		_delay_ms(100);
		PORTA|=(1<<2);
		_delay_ms(100);
		PORTA|=(1<<4);
		_delay_ms(100);
		PORTA|=(1<<6);
		_delay_ms(100);
		PORTA=0x00;
		_delay_ms(1000);*/

	}
}

