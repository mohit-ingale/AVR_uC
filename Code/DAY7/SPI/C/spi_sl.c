// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here

ISR(SPI_STC_vect)
{
	PORTD=SPDR;
//	SPDR=7;
}

int main(void)
{
	DDRD=0xFF;
	DDRB=(1<<PB4);
//	PORTB&=~(1<<PB2);
	//PORTB|=(1<<PB3)|(1<<PB5);
	SPCR|=(1<<SPIE)|(1<<SPE);
	SPDR=7;
	sei();
   while(1){
}

}




