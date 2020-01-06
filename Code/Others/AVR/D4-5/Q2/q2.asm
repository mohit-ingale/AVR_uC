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
  start:
  LDI R16,HIGH(RAMEND);
  LDI R16,LOW(RAMEND);
  OUT SPH,R16;
  OUT SPL,R16;
 LDI R16,0XFF;
 OUT DDRB,R16;
 LDI R16,0X55
 BEGIN:OUT PORTB,R16;
 RCALL DELAY
 LDI R16, 0XAA;
 OUT PORTB,R16;
 RCALL DELAY
 RJMP BEGIN
 DELAY:
 LDI R20,HIGH(12500-1)
 OUT OCR1AH,R20;
 LDI R20,LOW(12500-1)
 OUT OCR1AL,R20;
 LDI R20,0;
 OUT TCNT1H,R20;
 OUT TCNT1L,R20;
 LDI R20,0X00;
 OUT TCCR1A,R20
 LDI R20,0X3;
 OUT TCCR1B,R20
 LOOP:IN R20,TIFR
 SBRS R20,OCF1A;
 RJMP LOOP
 LDI R20,1<<OCF1A
 OUT TIFR,R20
 LDI R19,0
 OUT TCCR1B,R19
 OUT TCCR1A,R19
 RET

forever:
   nop
   nop       ; Infinite loop.
   nop       ; Define your main system
   nop       ; behaviour here
rjmp forever

