                 // ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here

int n,FLAG=1;
ISR(INT0_vect)
{
   PORTD=PORTD^(0B00010000);
}



void delay(void);

int main(void)
{
	DDRD=(1<<PD4);
	PORTD=(1<<PD2);
	MCUCR|=(1<<ISC01);                    //LOGICAL CHANGE
	GICR|=(1<<INT0);                     //ENABLE LOCAL EXTERNAL INT FLAG                           //ENABLE TIMER OVERFLOG INT
	sei();                                        // ENABLE GLOBAL INT
   while(1);

}



