// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>
#include <avr\interrupt.h>
#include <avr\signal.h>
ISR(TIMER1_COMPA_vect)
{		
}

ISR(TIMER1_COMPB_vect)
{
}

int main(void) {
   DDRB=0XFF;
   TCNT1H=0X00;
   TCNT1L=0X00;
   OCR1AH=0X00;
   OCR1AL=0X80;
   OCR1BH=0X00;
   OCR1BL=0X40;
   TIMSK=(1<<OCIE1A)|(1<<OCIE1B);
   PORTB=0X00;
   sei();
   TCCR1A=(1<<WGM10)|(1<<COM1A1)|(1<<COM1B1)|(1<<COM1A0)|(1<<COM1B0);
   TCCR1B=(1<<CS10)|(1<<CS11)|(0<<WGM12);

   while(1);

}



