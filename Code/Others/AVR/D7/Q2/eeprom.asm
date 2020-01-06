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
  ;//WRITE OPERATION
   L1:
   SBIC EECR,EEWE
   RJMP L1
   LDI R18,0X0;
   LDI R17,0X05;
   OUT EEARH,R18;
   OUT EEARL,R17;
   LDI R16,4;
   OUT EEDR,R16;
   SBI EECR,EEMWE;
   SBI EECR,EEWE;

  LDI R16,0XFF;
  OUT DDRB,R16;
 ; //READ OPERATION
  LOOP:
  SBIC EECR,EEWE
  RJMP LOOP
  LDI R18,0
  LDI R17,0X05;
  OUT EEARH,R18;
  OUT EEARL,R17;
  SBI EECR,EERE
  IN R16,EEDR;
  OUT PORTB,R16

forever:
   nop
   nop       ; Infinite loop.
   nop       ; Define your main system
   nop       ; behaviour here
rjmp forever
