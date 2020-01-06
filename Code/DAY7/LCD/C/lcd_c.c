// ****stri*******************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here

int n;

ISR(TIMER1_OVF_vect)
{
	n=0;
}
void delay(unsigned int);
void lcd_string(char *str);
void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);

int main(void)
{
	DDRD=0XFF;
	DDRB=0XFF;
	PORTB|=(1<<PB1);
	TIMSK|=(1<<TOIE1);
	sei();
	lcd_init();
	//lcd_data('a');
	lcd_string("HELLO");
	while(1);	
	
}

void lcd_init(void)
{
	delay(16);
	lcd_cmd(0x33);
	lcd_cmd(0x32);
	lcd_cmd(0x28);
	lcd_cmd(0x01);
	lcd_cmd(0x0e);
	delay(10);
	
}

void lcd_string(char *str)
{
	while(*str)
	{
		lcd_data(*str);
		str++;
	}
}
void lcd_cmd(unsigned char data)
{
	PORTD=(data&0xf0);
	PORTB&=~(1<<PB3);
	PORTB|=(1<<PB4);
	delay(1);
	PORTB&=~(1<<PB4);
	delay(2);
	PORTD=(data<<4);
	PORTB|=(1<<PB4);
	delay(1);
	PORTB&=~(1<<PB4);
	delay(2);	
}

void lcd_data(unsigned char data)
{
	PORTD=(data&0xf0);
	PORTB|=(1<<PB5);
	PORTB|=(1<<PB4);
	delay(1);
	PORTB&=~(1<<PB4);
	delay(2);
	PORTD=(data<<4);
	PORTB|=(1<<PB4);
	delay(1);
	PORTB&=~(1<<PB4);
	delay(2);	
}

void delay(unsigned int cnt)
{
	int i;
	for(i=0;i<cnt;i++)
	{  n=1;
		TCNT1H=0XFF;
		TCNT1L=0X84;
		TCCR1B|=(1<<CS10)|(1<<CS11);
		while(n);
	}
}
