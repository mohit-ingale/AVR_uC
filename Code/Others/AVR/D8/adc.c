// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here

ISR(ADC_vect)
{	PORTD=ADCL;
	PORTB=ADCH;
	ADCSRA|=(1<<ADSC);
}


// ***********************************************************
// Main program
//
int main(void)
 {
   DDRB=0XFF;
   DDRD=0XFF;
   DDRC=0X00;
   sei();
   ADCSRA=0X8F;
   ADMUX=0XC0;
   ADCSRA|=(1<<ADSC);
   while(1);
   return 0;
}

