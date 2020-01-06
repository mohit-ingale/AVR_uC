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
int main(void)
 {

 DDRB=0XFF;
 TCNT2=0;
 OCR2=125;
 TIMSK|=(1<<OCIE2);
 sei();
 TCCR2|=(1<<CS20)|(1<<WGM20)|(1<<COM20)|(1<<COM21)|(1<<WGM21);
 while(1);

   }
ISR(TIMER2_COMP_vect)
{
}


