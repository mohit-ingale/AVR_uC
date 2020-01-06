; ******************************************************
; BASIC .ASM template file for AVR
; ******************************************************

.include "C:\VMLAB\include\m8def.inc"

; Define here the variables
;
.MACRO DELAY
		LDI R16,2
LOOP1:LDI R17,255
LOOP2:LDI R18,200
LOOP3:DEC R18
			NOP
			NOP
			NOP
		BRNE LOOP3
		DEC R17
		BRNE LOOP2
		DEC R16
		BRNE LOOP1
.ENDMACRO

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
  LDI R17,HIGH(RAMEND)
  OUT SPH,R17
  OUT SPL,R16
  LDI R20,0XFF
  OUT DDRB,R20

forever:
 LDI R20,0X55
 OUT PORTB,R20
 DELAY
 LDI R20,0XAA
 OUT PORTB,R20
 DELAY
rjmp forever

