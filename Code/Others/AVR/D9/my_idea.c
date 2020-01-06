// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>
#include <util/delay.h>         // here

#define EN 4
#define RS 5
#define RW 6

// ***********************************************************
// Main program
//

void delay_us(unsigned int d)
{
 _delay_us(d);

}
void delay_ms(unsigned int d)
{
 _delay_ms(d);

}
void init (void);
void command(unsigned char c);
void data(unsigned char c);
void display(char *str);

int main(void)
 {
    delay_ms(20);
    init();
    //delay us(15000)
    command(0x80);
    delay_us(100);
    display("Hello CDAC");
    command(0xc0);
    display("Hi");

   while(1);    // system behaviour
   }
 void init()
 {
 DDRD =0xff;
 DDRB=0xff;
 PORTB|=(1<<PB1);
 //delay us(50);
 command(0x33);
 delay_us(50);
 command(0x32);
 delay_us(50);
 command(0x28);
 delay_us(50);
 command(0x1);
 delay_ms(5);
 command(0x0E);
 delay_us(50);
 }
void command(unsigned char c)
{
 PORTD=c&0XF0;//HIGHER NIBBLE
 PORTB&=~(1<<RS); //RS=0
 PORTB|=(1<<EN);//RS=0,EN=1
 delay_us(5);
 PORTB&=~(1<<EN);//EN=0
 delay_us(50);
 PORTD=c<<4;//lower nibble
 PORTB|=(1<<EN);//RS=0,EN=1;
 delay_us(5);
 PORTB&=~(1<<EN);//EN=0
 delay_us(50);
}

void data(unsigned char c)
{
   PORTD&=~(1<<RW);
   PORTD=c&0xf0;//higher nibble
   PORTB|=(1<<RS)|(1<<EN);
   delay_us(50);
   PORTB&=~(1<<EN);
   delay_us(50);
   PORTD=c<<4;//lower nibble
   PORTB|=(1<<EN);
   delay_us(50);
   PORTB&=~(1<<EN);
   delay_us(50);

}

void display(char *str)
{
 while(*str)
 {
 data(*str);
 str++;
 delay_us(50);
}
}


