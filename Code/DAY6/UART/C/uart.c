// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here

unsigned char ch;
volatile int FLAG,FLAG1;

void transmit(void);
void init_uart(void);

ISR(USART_RXC_vect)
{
	ch=UDR;
	FLAG1=1;	
}

ISR(USART_TXC_vect)
{
   FLAG=0;
}

ISR(USART_UDRE_vect)
{
	FLAG=0;
}

int main(void)
{
	init_uart();
	sei();	

   while(1)
   {
   	if(FLAG1)
   		transmit();
   }

}

void init_uart(void)
{    UBRRL=0X33;
	UCSRB|=(1<<RXEN)|(1<<TXEN)|(1<<RXCIE)|(1<<TXCIE)|(1<<UDRIE);
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	
}

void transmit(void)
{
	FLAG=1;
	ch=ch+1;
	UDR=ch;
	while(FLAG);
	FLAG1=0;	
}





