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
void delay(void);

int main(void)
{
	DDRD=0xFF;
	GICR|=(1<<INT0)|(1<<INT1);
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
	int i;
	for(i=0;i<10;i++)
	{   n=1;
		TCNT1H=0XFF;
		TCNT1L=0X84;
		TCCR1B|=(1<<CS10)|(1<<CS11);
			while(n);
		}
	

}


