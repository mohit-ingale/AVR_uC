// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here
	
// Define here the global static variables
//
int My_global;

// Interrupt handler example for INT0
//
SIGNAL(SIG_INTERRUPT0) {

}

// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//
void my_function(void) {  // Put the open brace '{' here

   asm("nop");          // Inline assembly example
}

// ***********************************************************
// Main program
//
int main(void) {

   UCSRB=(1<<TXEN)|(1<<RXEN);
   UCSRC= (1<<UCSZ1)|(1<<UCSZ0)|(1<<URSEL);
   UBRRL=0X33;
   unsigned char ch;
   while(1)
   {
 		while(!(UCSRA&(1<<RXC)));
 		ch=UDR;
 		if(ch>='a'&&ch<='c')

}
   }

}

