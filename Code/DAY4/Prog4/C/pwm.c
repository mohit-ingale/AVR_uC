// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here
ISR(TIMER2_COMP_vect)
{
	
}

int main(void) {
	DDRB=0XFF;
	TCNT2=0;
	OCR2=128;
	TIMSK=(1<<OCIE2);
	sei();
	TCCR2|=(1<<WGM20)|(1<<WGM21)|(1<<CS20)|(1<<CS21)|(1<<COM21)|(1<<COM20);
   while(1) {
   }

}

