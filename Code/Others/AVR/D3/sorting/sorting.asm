; ******************************************************
; BASIC .ASM template file for AVR
; ******************************************************

.include "C:\VMLAB\include\m8def.inc"

; Define here the variables
;

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
	ldi r16,10
	 ldi xl,0x60
	 ldi xh,0x00
   ldi yl,0x70
	ldi yh,0x00
	ldi zl,0x80
	ldi zh,0x00

	st x+,r16
	
	ldi r16,15
	st x+,r16
	ldi r16,8
	st x+,r16
	ldi r16,12
	st x+,r16
	ldi r16,20
	st x+,r16
	ldi r16,5
	st x+,r16
	ldi r16,30
	st x+,r16
	ldi r16,16
	st x+,r16
	ldi r16,4
	st x+,r16
	ldi r16,24
	st x,r16
	
	loop:ld r16,x
			ld r17,-x
			cp r16,r17
			brge next
			st y+,r17
			
			jmp loop
			
			
			
			
	next: cp r17,zh
			mov r18,r16
			mov r16,r17
			mov r17,r18
			
			st y+,r16
			
			breq again
	      jmp loop
	   	
	again:
			ld r16,-y
			ld r16,-y
			ld r16,-y
			ld r17,-y
			cp r16,r17
			brge then
			st z,r17
		
			jmp again
			
			
			
			
	then:mov r18,r16
			mov r16,r17
			mov r17,r18
			
			st z+,r16
			cp r17,zh
			breq loop
	      jmp again
	
	
	
	

 forever:
rjmp forever


