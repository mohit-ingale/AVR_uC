; ******************************************************
; BASIC .ASM template file for AVR
; ******************************************************

.include "C:\VMLAB\include\m8def.inc"
  ; Define here the variables
;
;.def

; Define here Reset and interrupt vectors, if any
;
.org 0x00

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
LDI R26,0x60
LDI R27,0x00
LDI R18,10
LDI R17,15

LOOP:
ST X+,R17
INC R17
DEC R18
BRNE LOOP

LDI R18,10
LDI R26,0x60
LDI R27,0x00
LDI R16,0

LOOP1:
LD R17,X+
ADC R16,R17
DEC R18
CPI R18,0
BRNE LOOP1
STS 0x75,R16

forever:
   nop
   nop       ; Infinite loop.
   nop       ; Define your main system
   nop       ; behaviour here
rjmp forever





