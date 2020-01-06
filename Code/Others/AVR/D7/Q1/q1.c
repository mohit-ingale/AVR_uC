// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here

#define MOSI 5
#define SCK 7

// ***********************************************************
// Main program
//
int main(void)
 {

  DDRB=(1<<MOSI)|(1<<SCK);
  DDRC=0XFF;
  SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
  while(1)
  		{
  		 SPDR='A';
  		 while(!(SPSR&(1<<SPIF)));
  		 PORTC=SPDR;  		  		
  		}
  		return 0;
   }



