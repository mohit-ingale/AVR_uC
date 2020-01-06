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
   rjmp ISR      ; Addr $01
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
   CLR R16
   LDI R16,(1<<PD4)
   OUT DDRD,R16
   CLR R16
   LDI R16,(1<<PD2)
   OUT PORTD,R16
   CLR R16
   LDI R16,(1<<INT0)
   OUT GICR,R16
   CLR R16
   LDI R16,(1<<ISC01)
   OUT MCUCR,R16
   SEI

forever:
	NOP
	NOP
	NOP
rjmp forever

ISR:
	IN R16,PORTD
	LDI R17,0X10
	EOR R16,R17
	OUT PORTD,R16
	RETI
