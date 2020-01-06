; ******************************************************
; BASIC .ASM template file for AVR
; ******************************************************

.include "C:\VMLAB\include\m8def.inc"

; Define here the variables
;
.def  temp  =r16

; Define here Reset and interrupt vectors, if any
;
reset:
   rjmp start
   reti      ; Addr $01
   reti      ; Addr $02
   reti      ; Addr $03
   reti      ; Addr $04
   reti      ; Addr $05
   reti      ; Addr $06        Use 'rjmp myVector'
   reti      ; Addr $07        to define a interrupt vector
   reti      ; Addr $08
   reti      ; Addr $09
   reti      ; Addr $0A
   reti      ; Addr $0B        This is just an example
   reti      ; Addr $0C        Not all MCUs have the same
   reti      ; Addr $0D        number of interrupt vectors
   reti      ; Addr $0E
   reti      ; Addr $0F
   reti      ; Addr $10

; Program starts here after Reset
;
start:
		LDI R16,LOW(RAMEND)
		OUT SPL,R16
		LDI R16,HIGH(RAMEND)
		OUT SPH,R16
 		LDI R16,0XFF
 		OUT DDRB,R16
 		LDI R16,0X00
 		OUT TCNT2,R16
 		LDI R16,128
 		OUT OCR2,R16
 		CLR R16
 		LDI R16,(1<<OCIE2)
 		OUT TIMSK,R16
 		SEI
 		CLR R16
 		LDI R16,(1<<WGM20)|(1<<WGM21)|(1<<COM21)|(1<<COM20)|(1<<CS22)
 		OUT TCCR2,R16
forever:
   nop
   nop       ; Infinite loop.
   nop       ; Define your main system
   nop       ; behaviour here
rjmp forever
