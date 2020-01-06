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
	LDI R16,0XFF
	OUT DDRD,R16
	LOOP1:
	IN R16,EECR
		SBRC R16,1
		RJMP LOOP1
	LDI R16,0X00
	OUT EEARH,R16
	LDI R16,0X5F
	OUT EEARL,R16
	LDI R16,0X58
	OUT EEDR,R16
	SBI EECR,EEMWE
	SBI EECR,EEWE
	LOOP2:
	IN R16,EECR
		SBRC R16,1
		RJMP LOOP2
	CLR R16
	OUT EEARH,R16
	LDI R16,0X5F
	OUT EEARL,R16
	CLR R16
	LDI R16,(1<<EERE)
	OUT EECR,R16
	IN R16,EEDR
	OUT PORTD,R16
forever:
   nop
   nop       ; Infinite loop.
   nop       ; Define your main system
   nop       ; behaviour here
rjmp forever

