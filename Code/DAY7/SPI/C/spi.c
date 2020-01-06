// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here
int i=6,FLAG;

ISR(SPI_STC_vect)
{
	
	FLAG=0;
}

int main(void)
{
	DDRB=(1<<PB3)|(1<<PB5);
	PORTB|=(1<<PB4);
	SPCR|=(1<<SPIE)|(1<<SPE)|(1<<MSTR);
   sei();
   while(1)
   {
   	FLAG=1;
   	SPDR=i;
   	while(FLAG);
   }
}




