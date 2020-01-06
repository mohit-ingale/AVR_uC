; ******************************************************
; BASIC .ASM template file for AVR
; ******************************************************

.include "C:\VMLAB\include\m8def.inc"

.DEF FLAG = R17
.DEF C = R18

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
   rjmp ISR      ; Addr $0A
   reti      ; Addr $0B        This is just an example
   reti      ; Addr $0C        Not all MCUs have the same
   reti      ; Addr $0D        number of interrupt vectors
   reti      ; Addr $0E
   reti      ; Addr $0F
   reti      ; Addr $10

; Program starts here after Reset
;
start:
	LDI R16,HIGH(RAMEND)
	OUT SPH,R16
	LDI R16,LOW(RAMEND)
	OUT SPL,R16
	CLR R16
	LDI R16,(1<<PB3)|(1<<PB5);
	OUT DDRB,R16
	CLR R16
	LDI R16,(1<<PB4);
	OUT PORTB,R16
	CLR R16
	LDI R16,(1<<SPIE)|(1<<SPE)|(1<<MSTR);
	OUT SPCR,R16
	SEI
	LDI FLAG,1
	CLR C
	
forever:
	OUT SPDR,C
	LOOP:
	CPI FLAG,0
	BRNE LOOP
	LDI FLAG,1
rjmp forever

ISR:
	CLR FLAG
	INC C
	RETI
	

