// ***********************************************************
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

int main(void)
{
	DDRD=0xFF;
	TIMSK|=(1<<TOIE1);
	sei();
   while(1) {
 	  PORTD=0X55;
	   delay();
 	  PORTD=0XAA;
 	  delay();
   }

}
void delay(void)
{
	n=1;
	TCNT1H=0X00;
	TCNT1L=0X00;
	TCCR1B|=(1<<CS12)|(1<<CS10);
	while(n);
}

