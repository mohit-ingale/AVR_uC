; ******************************************************
; BASIC .ASM template file for AVR
; ******************************************************

.include "C:\VMLAB\include\m8def.inc"

; Define here the variables
;
.DEF FLAG1 = R17
.DEF FLAG2 = R18

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
   rjmp ISR_RX      ; Addr $0B        This is just an example
   RJMP ISR_UDRE     ; Addr $0C        Not all MCUs have the same
   RJMP ISR_TX      ; Addr $0D        number of interrupt vectors
   reti      ; Addr $0E
   reti      ; Addr $0F
   reti      ; Addr $10

; Program starts here after Reset
;
start:
	
	LDI R16,0X33
	OUT UBRRL,R16
	CLR R16
	LDI R16,(1<<RXEN)|(1<<TXEN)|(1<<RXCIE)|(1<<TXCIE)|(1<<UDRIE)
	OUT UCSRB,R16
	CLR R16
	LDI R16,(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1)
	OUT UCSRC,R16
	SEI
	CLR FLAG1
	CLR FLAG2
	
forever:
	LOOP1:
   CPI FLAG1,0X01
   BRNE LOOP1
   INC R20
   OUT UDR,R20
   LOOP2:
   CPI FLAG2,0X01
   BRNE LOOP2
   LDI FLAG1,0X00

rjmp forever

ISR_RX:
	IN R20,UDR
	LDI FLAG1,0X01
	RETI
	
ISR_TX:
	RETI

ISR_UDRE:
	LDI FLAG2,0X01
	RETI	
