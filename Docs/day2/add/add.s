.text 
.org 0x00
.global _start
.global __start


_start:
__start:

	

start:	ldi r16 , 0x21 ;load the reg with val 
		ldi r17 , 0x22 ;
		add r0 , r1
	
		ldi r30 , lo8(my_data)
		ldi r31 , hi8(my_data)
		
		ldi r16 , 0x4
	
back:	lpm r0,z+
		dec r16
		brne back 


loop : rjmp loop

my_data:
.byte 0x12 , 0x34 , 0x23 , 0x45


.end 

