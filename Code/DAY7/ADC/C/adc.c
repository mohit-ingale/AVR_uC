// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>         // here
int n;
void delay(unsigned int);
void lcd_string(char *str);
void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);

ISR(TIMER1_OVF_vect)
{
	n=0;
}


int main(void)
{
	int i,j,k,pos;
	
	DDRD=0XFF;
	DDRB=0XFF;
	PORTB|=(1<<PB1);
	TIMSK|=(1<<TOIE1);
	DDRC&=~(1<<PC1);
	PORTC|=(1<<PC1);
	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	ADMUX=(1<<REFS0)|(1<<MUX0);
	sei();
	lcd_init();
	lcd_string("hi");
	while(1)
	{
	ADCSRA|=(1<<ADSC);
	while((ADCSRA&(1<<ADIF))==0);
	i=ADCL;
	j=ADCH;
	ADCSRA&=~(1<<ADIF);
	j=j&0x03;
	//lcd_string("value converted");
	i=(i&0xff)|(j<<8);
	
		lcd_cmd(0x01);
		delay(2);
	   pos=0x82;	
		//	delay(200);
		for(k=0;k<3;k++)
		{
		   lcd_cmd(pos--);
		   delay(4);
			lcd_data((i%10+'0'));
			i=i/10;
		}
		delay(1000);
	}
	
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
	PORTB&=~(1<<PB5);
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


