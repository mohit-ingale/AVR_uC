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
	FLAG=1;
}

ISR(INT1_vect)
{     FLAG=2;
}

ISR(TIMER1_OVF_vect)
{
	n=0;
}
void delay(void);

int main(void)
{
	DDRB=0xFF;
	DDRD=0X00;
	PORTD=0XFF;
	MCUCR|=(1<<ISC11)|(1<<ISC01);//FALLING EDGE INT
	GICR|=(1<<INT0)|(1<<INT1);                     //ENABLE LOCAL EXTERNAL INT FLAG
	TIMSK|=(1<<TOIE1);                            //ENABLE TIMER OVERFLOG INT
	sei();                                        // ENABLE GLOBAL INT
   while(1) {
 	  PORTB=0X55;
	   delay();
 	  PORTB=0XAA;
 	  delay();
   }

}
void delay(void)
{
	int i;
	for(i=0;i<FLAG;i++)
	{
		n=1;
		TCNT1H=0XFF;
		TCNT1L=0X84;
		TCCR1B|=(1<<CS10)|(1<<CS11);
		while(n);
	}
}

