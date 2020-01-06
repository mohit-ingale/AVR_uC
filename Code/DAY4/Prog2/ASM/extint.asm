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
   rjmp ISR1      ; Addr $01
   rjmp ISR2  ; Addr $02
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
  LDI R16,0X00
  OUT DDRD,R16
  LDI R16,0XFF
  OUT PORTD,R16
  LDI R22,1
  LDI R17,0XFF
  OUT DDRB,R17
  LDI R16,(1<<CS11)|(1<<CS10)
  OUT TCCR1B,R16
  CLR R16
  LDI R16,1<<TOIE1
  OUT TIMSK,R16
  CLR R16
  LDI R16,(1<<INT0)|(1<<INT1)
  OUT GICR,R16
  CLR R16
  LDI R16,(1<<ISC11)|(1<<ISC01)
  OUT MCUCR,R16
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
	MOV R21,R22
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

ISR1:
	ldi r22,1
	RETI
	
ISR2:
	ldi r22,2
	RETI

ISR:
	LDI R20,0X00
	RETI

