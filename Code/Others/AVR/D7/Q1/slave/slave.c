// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here
 #define MISO 6


// ***********************************************************
// Main program
//
int main(void)
 {
      DDRC=0XFF;
      DDRB=(1<<MISO);
      SPCR=(1<<SPE);
      while(1)
     		 {
            SPDR='b';
            while(!(SPSR&(1<<SPIF)));
            PORTC=SPDR;		
         }
       return 0;
   }




