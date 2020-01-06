;-------------------------------------------------------------------------------------------------------------
;File Name:	
;Descryption:	
;Date:		24th April 2006 
;Version:	V1.0
;Author:	vivekn@C-DAC, Hyderabad
;-------------------------------------------------------------------------------------------------------------

.include "m8def.inc"           ;Including the standard file required for atmega128 MCU.
.text                           ;Directive for program memory 
.org 0                          ;Off set of program start location. 
.global _start			;Directive for _assemblers,specifying start location.
.global __start                 ;Directive for __assemblers,specifying start location.
_start:				;Program _start location.
__start:                        ;Program __start location.

;-----------------------------------------------------------------------------------------------------------//
;                                  Interrupt Vector Table                                                   //
;-----------------------------------------------------------------------------------------------------------//

rjmp RESET			; Reset Handler
rjmp EXT_INT0			; IRQ0 Handler
rjmp EXT_INT1			; IRQ1 Handler
rjmp TIM2_COMP			; Timer2 Compare Handler
rjmp TIM2_OVF			; Timer2 Overflow Handler
rjmp TIM1_CAPT			; Timer1 Capture Handler
rjmp TIM1_COMPA			; Timer1 CompareA Handler
rjmp TIM1_COMPB			; Timer1 CompareB Handler
rjmp TIM1_OVF			; Timer1 Overflow Handler
rjmp TIM0_OVF			; Timer0 Overflow Handler
rjmp SPI_STC			; SPI Transfer Complete Handler
rjmp USART_RXC			; USART RX Complete Handler
rjmp USART_UDRE			; UDR Empty Handler
rjmp USART_TXC			; USART TX Complete Handler
rjmp ADC_Handler		; ADC Conversion Complete Handler
rjmp EE_RDY			; EEPROM Ready Handler
rjmp ANA_COMP			; Analog Comparator Handler
rjmp TWSI			; Two-wire Serial Interface Handler
rjmp SPM_RDY			; Store Program Memory Ready Handler

;-----------------------------------------------------------------------------------------------------------//
;                                  	Interrupt Service Routine                                           //
;-----------------------------------------------------------------------------------------------------------//

RESET:				;Reset Handler
	ldi r16,hi8(RAMEND)
	out SPH,r16
	ldi r16,lo8(RAMEND)
	out SPL,r16
	rjmp main

EXT_INT0	:reti
EXT_INT1	:reti
TIM2_COMP	:reti
TIM2_OVF	:reti
TIM1_CAPT	:reti
TIM1_COMPA	:reti
TIM1_COMPB	:reti
TIM1_OVF	:reti
TIM0_OVF	:
		inc r24
		reti

SPI_STC		:reti
USART_RXC	:reti
USART_UDRE	:reti
USART_TXC	:reti
ADC_Handler	:reti
EE_RDY		:reti
ANA_COMP	:reti
TWSI		:reti
SPM_RDY		:reti

;-----------------------------------------------------------------------------------------------------------//
;                                     Program Start Location                                                //
;-----------------------------------------------------------------------------------------------------------//

main:
	;initilize timer counter
	ldi r16,0x00
	out TCNT0,r16

	;start timer 
	ldi r16, 0x1
	out TCCRO , r16

	;enable GI
	sei
	
	;enable Local Interrupt
	ldi r16 , 0x1
	out TIMSK , r16
	

LOOP:
	rjmp	LOOP

;-----------------------------------------------------------------------------------------------------------//

END:
.end				;End of the program







