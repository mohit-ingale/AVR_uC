; ******************************************************
; BASIC .ASM template file for AVR
; ******************************************************

.include "C:\VMLAB\include\m8def.inc"

; Define here the variables
;
.def  temp  =r16

; Define here Reset and interrupt vectors, if any
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
  LDI R20,HIGH(RAMEND);
  OUT SPH,R20
  LDI R20,LOW(RAMEND);
  OUT SPL,R20;
  SBI DDRD,4;
  SBI PORTD,2;
  LDI R20,1<<INT0
  OUT GICR,R20
  SEI
  LOOP1:RJMP LOOP1
  ISR:
  IN R21,PIND
  LDI R22,0X08
  EOR  R21,R22;
  OUT PORTC ,R21
  RETI

forever:
   nop
   nop       ; Infinite loop.
   nop       ; Define your main system
   nop       ; behaviour here
rjmp forever

