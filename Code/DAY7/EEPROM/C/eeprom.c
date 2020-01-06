// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here

int main(void)
{
	DDRD=0XFF;
	while((EECR&0x02)!=0);
	EEARH=0X00;
	EEARL=0X5F;
	EEDR=0X56;
	EECR|=(1<<EEMWE);
	EECR|=(1<<EEWE);
	while((EECR&0X02)!=0);
	EEARH=0X00;
	EEARL=0X5F;
	EECR|=(1<<EERE);
	PORTD=EEDR;
	while(1);
}

