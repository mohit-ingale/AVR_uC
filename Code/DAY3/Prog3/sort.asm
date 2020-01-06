; ******************************************************
; BASIC .ASM template file for AVR
; ******************************************************

.include "C:\VMLAB\include\m8def.inc"

; Define here the variables
;
.DEF MIN = R16
.DEF MAX = R17
.DEF TEMP = R18
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
 LDI TEMP,5
 STS 0X60,TEMP
 LDI TEMP,10
 STS 0X61,TEMP
 LDI TEMP,3
 STS 0X62,TEMP
 LDI TEMP,22
 STS 0X63,TEMP
 LDI TEMP,1
 STS 0X64,TEMP
 LDI TEMP,2
 STS 0X65,TEMP
 LDI TEMP,4
 STS 0X66,TEMP
 LDI TEMP,8
 STS 0X67,TEMP
 LDI TEMP,12
 STS 0X68,TEMP
 LDI TEMP,20
 STS 0X69,TEMP

 LDI TEMP,0
 STS 0X70,TEMP
 STS 0X80,TEMP
 CLR R22
 LDI R23,0XFF
 LDI MIN,0XFF
 LDI MAX,0X00

 CLR YH
 LDI YL,0X70
 CLR ZH
 LDI ZL,0X80

 LDI R20,10
 LOOP1:
 CLR XH
 LDI XL,0X60
 LDI R21,10

 LOOP2:
 	LD TEMP,X+
 	
 	CP R22,TEMP
 	BRGE AEND
 	CP MIN,TEMP
 	BRCS AEND
 	MOV MIN,TEMP
 	AEND:
 	
 	CP R23,TEMP
 	BRCS DEND
 	CP TEMP,R23
 	BREQ DEND
 	CP TEMP,MAX
 	BRCS DEND
 	MOV MAX,TEMP
 	DEND:
 	 	
 	DEC R21
 	BRNE LOOP2
 	
 ST Y,MIN
 LD R22,Y+
 ST Z,MAX
 LD R23,Z+
 LDI MAX,0X00
 LDI MIN,0XFF
 DEC R20
 BRNE LOOP1
 	
forever:
   nop
   nop       ; Infinite loop.
   nop       ; Define your main system
   nop       ; behaviour here
rjmp forever

	
	
	


