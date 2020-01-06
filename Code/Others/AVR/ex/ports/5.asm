; ******************************************************
; BASIC .ASM template file for AVR
; ******************************************************

.include "C:\VMLAB\include\m8def.inc"
; .include "M32DEF.inc"
; .MACRO INITSTACK

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
         LDI R20,HIGH(RAMEND)
         OUT SPH,R20
         LDI R20,LOW(RAMEND)
         OUT SPL,R20
         LDI R16,1<<5
         SBI DDRB,5
         LDI R17,0
         OUT PORTB,R17
   BEGIN: RCALL DELAY
          EOR R17,R16
          OUT PORTB,R17
          RJMP BEGIN
    DELAY: LDI  R20,0XF2
           OUT TCNT0,R20
           LDI R20,0X01
           OUT TCCR0,R20
    AGAIN:IN R20,TIFR
          SBRS R20,TOV0
          RJMP AGAIN
          LDI R20,0X00
          OUT TCCR0,R20
          LDI R20,(1<<TOV0)
          OUT TIFR,R20
          RET













forever:
   nop
   nop       ; Infinite loop.
   nop       ; Define your main system
   nop       ; behaviour here
rjmp forever

