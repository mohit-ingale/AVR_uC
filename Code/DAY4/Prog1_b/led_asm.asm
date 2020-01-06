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
   rjmp ISR      ; Addr $08
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
  LDI R20,LOW(RAMEND)
  OUT SPL,R20
  LDI R20,HIGH(RAMEND)
  OUT SPH,R20
  LDI R17,0XFF
  OUT DDRB,R17
  LDI R16,(1<<CS11)|(1<<CS10)
  OUT TCCR1B,R16
  CLR R16
  LDI R16,1<<TOIE1
  OUT TIMSK,R16
  SEI
forever:
	LDI R16,0X55
	OUT PORTB,R16
	RCALL DELAY
	LDI R16,0XAA
	OUT PORTB,R16
	RCALL DELAY
	
rjmp forever
	
	
DELAY:
	LDI R21,0X0A
	LOOP:
 	 LDI R16,0XFF
	  OUT TCNT1H,R16
	  LDI R16,0X83
	  OUT TCNT1L,R16
	  LDI R20,0X01
  LOOP1:
  	CPI R20,0X00
  	BRNE LOOP1	
  DEC R21
  BRNE LOOP
  RET


ISR:
	LDI R20,0X00
	RETI

