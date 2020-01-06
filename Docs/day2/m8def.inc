;***************************************************************************
;* A P P L I C A T I O N   N O T E   F O R   T H E   A V R   F A M I L Y
;* 
;* Number				:AVR000
;* File Name			:"m8def.inc"
;* Title				:Register/Bit Definitions for the ATmega8
;* Date                 :07.09.2001
;* Version              :1.00
;* Support E-mail		:avr@atmel.no
;* Target MCU			:ATmega8
;*
;* DESCRIPTION
;* When including this file in the assembly program file, all I/O register	
;* names and I/O register bit names appearing in the data book can be used.
;* In addition, the six registers forming the three data pointers X, Y and
;* Z have been assigned names XL - ZH. Highest RAM address for Internal 
;* SRAM is also defined 
;*
;* The Register names are represented by their hexadecimal address.
;* 
;* The Register Bit names are represented by their bit number (0-7).
;* 
;* Please observe the difference in using the bit names with instructions
;* such as "sbr"/"cbr" (set/clear bit in register) and "sbrs"/"sbrc" 
;* (skip if bit in register set/cleared). The following example illustrates
;* this:
;* 
;* in	r16,PORTB				;read PORTB latch
;* sbr	r16,(1<<PB6)+(1<<PB5)	;set PB6 and PB5 (use masks, not bit#)
;* out  PORTB,r16				;output to PORTB
;*
;* in	r16,TIFR				;read the Timer Interrupt Flag Register
;* sbrc	r16,TOV0				;test the overflow flag (use bit#)
;* rjmp	TOV0_is_set				;jump if set
;* ...							;otherwise do something else
;***************************************************************************

;***** Specify Device
;***** I/O Register Definitions
.equ	SREG	 , 0x3f
.equ	SPH	 , 0x3e
.equ	SPL	 , 0x3d
.equ	GIMSK	 , 0x3b
.equ	GICR	 , 0x3b		; new name for GIMSK
.equ	GIFR	 , 0x3a
.equ	TIMSK	 , 0x39
.equ	TIFR	 , 0x38
.equ	SPMCR	 , 0x37
.equ    I2CR     , 0x36
.equ    TWCR     , 0x36
.equ    MCUCR    , 0x35
.equ    MCUSR    , 0x34		; For compatibility, 
.equ    MCUCSR   , 0x34		; keep both names until further
.equ	TCCR0	 , 0x33
.equ	TCNT0	 , 0x32
.equ    OSCCAL   , 0x31
.equ    SFIOR    , 0x30
.equ	TCCR1A	 , 0x2f
.equ	TCCR1B	 , 0x2e
.equ	TCNT1H	 , 0x2d
.equ	TCNT1L	 , 0x2c
.equ	OCR1AH	 , 0x2b
.equ	OCR1AL	 , 0x2a
.equ	OCR1BH	 , 0x29
.equ	OCR1BL	 , 0x28
.equ	ICR1H	 , 0x27
.equ	ICR1L	 , 0x26
.equ	TCCR2	 , 0x25
.equ	TCNT2	 , 0x24
.equ	OCR2	 , 0x23
.equ	ASSR	 , 0x22
.equ	WDTCR	 , 0x21
.equ    UBRRH    , 0x20		;  Note! UCSRC equals UBRRH
.equ	EEARH	 , 0x1f
.equ	EEARL	 , 0x1e
.equ	EEDR	 , 0x1d
.equ	EECR	 , 0x1c
.equ	PORTB	 , 0x18
.equ	DDRB	 , 0x17
.equ	PINB	 , 0x16
.equ	PORTC	 , 0x15
.equ	DDRC	 , 0x14
.equ	PINC	 , 0x13
.equ	PORTD	 , 0x12
.equ	DDRD	 , 0x11
.equ	PIND	 , 0x10
.equ	SPDR	 , 0x0f
.equ	SPSR	 , 0x0e
.equ	SPCR	 , 0x0d
.equ	UDR	 , 0x0c
.equ	UCSRA	 , 0x0b
.equ	UCSRB	 , 0x0a
.equ	UCSRC	 , 0x20		;  Note! UCSRC equals UBRRH
.equ	UBRRL	 , 0x09
.equ	ACSR	 , 0x08
.equ    ADMUX    , 0x07
.equ    ADCSR    , 0x06
.equ	ADCSRA	 , 0x06
.equ    ADCH     , 0x05
.equ    ADCL     , 0x04
.equ    I2DR     , 0x03
.equ    I2AR     , 0x02
.equ    I2SR     , 0x01
.equ    I2BR     , 0x00
.equ    TWDR     , 0x03
.equ    TWAR     , 0x02
.equ    TWSR     , 0x01
.equ    TWBR     , 0x00



;***** Bit Definitions
;GICR  (former GIMSK)
.equ	INT1	 , 7
.equ	INT0	 , 6
.equ	IVSEL	 , 1		; interrupt vector select
.equ	IVCE	 , 0		; interrupt vector change enable

;GIFR
.equ	INTF1	 , 7
.equ	INTF0	 , 6

;TIMSK
.equ    TOIE0    , 0
.equ    TOIE1    , 2
.equ    OCIE1B   , 3
.equ    OCIE1A   , 4
.equ    TICIE1   , 5
.equ    TOIE2    , 6
.equ    OCIE2    , 7

;TIFR
.equ    TOV0     , 0
.equ    TOV1     , 2
.equ    OCF1B    , 3
.equ    OCF1A    , 4
.equ    ICF1     , 5
.equ    TOV2     , 6
.equ    OCF2     , 7

;SPMCR
.equ	SPMIE	 , 7
.equ	RWWSB	 , 6
.equ	RWWSRE	 , 4
.equ	BLBSET	 , 3
.equ	PGWRT	 , 2
.equ	PGERS	 , 1
.equ	SPMEN	 , 0

;MCUCR
.equ    SE       , 7
.equ    SM2      , 6
.equ    SM1      , 5
.equ    SM0      , 4
.equ    ISC11    , 3
.equ    ISC10    , 2
.equ    ISC01    , 1
.equ    ISC00    , 0

;MCUCSR
.equ    WDRF     , 3
.equ    BORF     , 2
.equ    EXTRF    , 1
.equ    PORF     , 0

;TCCR0
.equ	CS02	 , 2
.equ	CS01	 , 1
.equ	CS00	 , 0

;TCCR1A
.equ	COM1A1	 , 7
.equ	COM1A0	 , 6
.equ	COM1B1	 , 5
.equ	COM1B0	 , 4
.equ	FOC1A	 , 3
.equ	FOC1B	 , 2
.equ	PWM11	 , 1	; OBSOLETE! Use WGM11
.equ	PWM10	 , 0	; OBSOLETE! Use WGM10
.equ	WGM11	 , 1
.equ	WGM10	 , 0
;TCCR1B
.equ	ICNC1	 , 7
.equ	ICES1	 , 6
.equ	CTC11	 , 4	; OBSOLETE! Use WGM13
.equ	CTC10	 , 3	; OBSOLETE! Use WGM12
.equ	WGM13	 , 4
.equ	WGM12	 , 3	
.equ	CTC1	 , 3		; Obsolete - Included for backward compatibility
.equ	CS12	 , 2
.equ	CS11	 , 1
.equ	CS10	 , 0

;TCCR2
.equ	FOC2	 , 7
.equ    PWM2     , 6	; OBSOLETE! Use WGM20
.equ	WGM20	 , 6	
.equ    COM21    , 5
.equ    COM20    , 4
.equ    CTC2     , 3	; OBSOLETE! Use WGM21
.equ	WGM21	 , 3	
.equ    CS22     , 2
.equ    CS21     , 1
.equ    CS20     , 0

;SFIOR
.equ    ADHSM    , 4
.equ    ACME     , 3
.equ    PUD      , 2
.equ	PSR2	 , 1
.equ	PSR10	 , 0

;WDTCR
.equ	WDCE	 , 4
.equ	WDTOE	 , 4
.equ	WDE	 , 3
.equ	WDP2	 , 2
.equ	WDP1	 , 1
.equ	WDP0	 , 0

;EECR
.equ    EERIE    , 3
.equ	EEMWE	 , 2
.equ	EEWE	 , 1
.equ	EERE	 , 0

;PORTB
.equ	PB7	 , 7
.equ	PB6	 , 6
.equ	PB5	 , 5
.equ	PB4	 , 4
.equ	PB3	 , 3
.equ	PB2	 , 2
.equ	PB1	 , 1
.equ	PB0	 , 0

;DDRB
.equ	DDB7	 , 7
.equ	DDB6	 , 6
.equ	DDB5	 , 5
.equ	DDB4	 , 4
.equ	DDB3	 , 3
.equ	DDB2	 , 2
.equ	DDB1	 , 1
.equ	DDB0	 , 0

;PINB
.equ	PINB7	 , 7
.equ	PINB6	 , 6
.equ	PINB5	 , 5
.equ	PINB4	 , 4
.equ	PINB3	 , 3
.equ	PINB2	 , 2
.equ	PINB1	 , 1
.equ	PINB0	 , 0

;PORTC
.equ	PC6	 , 6
.equ	PC5	 , 5
.equ	PC4	 , 4
.equ	PC3	 , 3
.equ	PC2	 , 2
.equ	PC1	 , 1
.equ	PC0	 , 0

;DDRC
.equ	DDC6	 , 6
.equ	DDC5	 , 5
.equ	DDC4	 , 4
.equ	DDC3	 , 3
.equ	DDC2	 , 2
.equ	DDC1	 , 1
.equ	DDC0	 , 0

;PINC
.equ	PINC6	 , 6
.equ	PINC5	 , 5
.equ	PINC4	 , 4
.equ	PINC3	 , 3
.equ	PINC2	 , 2
.equ	PINC1	 , 1
.equ	PINC0	 , 0

;PORTD
.equ	PD7	 , 7
.equ	PD6	 , 6
.equ	PD5	 , 5
.equ	PD4	 , 4
.equ	PD3	 , 3
.equ	PD2	 , 2
.equ	PD1	 , 1
.equ	PD0	 , 0

;DDRD
.equ	DDD7	 , 7
.equ	DDD6	 , 6
.equ	DDD5	 , 5
.equ	DDD4	 , 4
.equ	DDD3	 , 3
.equ	DDD2	 , 2
.equ	DDD1	 , 1
.equ	DDD0	 , 0

;PIND
.equ	PIND7	 , 7
.equ	PIND6	 , 6
.equ	PIND5	 , 5
.equ	PIND4	 , 4
.equ	PIND3	 , 3
.equ	PIND2	 , 2
.equ	PIND1	 , 1
.equ	PIND0	 , 0

;UCSRA
.equ	RXC	 , 7
.equ	TXC	 , 6
.equ	UDRE	 , 5
.equ	FE	 , 4
.equ	OR	 , 3		; old name kept for compatibilty
.equ	DOR	 , 3
.equ	UPE	 , 2
.equ	PE	 , 2
.equ	U2X	 , 1
.equ	MPCM	 , 0

;UCSRB
.equ	RXCIE	 , 7
.equ	TXCIE	 , 6
.equ	UDRIE	 , 5
.equ	RXEN	 , 4
.equ	TXEN	 , 3
.equ	CHR9	 , 2		; old name kept for compatibilty
.equ	UCSZ2	 , 2
.equ	RXB8	 , 1
.equ	TXB8	 , 0

;UCSRC
.equ	URSEL	 , 7
.equ	UMSEL	 , 6
.equ	UPM1	 , 5
.equ	UPM0	 , 4
.equ	USBS	 , 3
.equ	UCSZ1	 , 2
.equ	UCSZ0	 , 1
.equ	UCPOL	 , 0
		
;SPCR
.equ	SPIE	 , 7
.equ	SPE	 , 6
.equ	DORD	 , 5
.equ	MSTR	 , 4
.equ	CPOL	 , 3
.equ	CPHA	 , 2
.equ	SPR1	 , 1
.equ	SPR0	 , 0

;SPSR
.equ	SPIF	 , 7
.equ	WCOL	 , 6
.equ	SPI2X	 , 0

;ACSR
.equ	ACD	 , 7
.equ    ACBG     , 6
.equ	ACO	 , 5
.equ	ACI	 , 4
.equ	ACIE	 , 3
.equ	ACIC	 , 2
.equ	ACIS1	 , 1
.equ	ACIS0	 , 0

;ADMUX
.equ    REFS1    , 7
.equ    REFS0    , 6
.equ    ADLAR    , 5
.equ    MUX3     , 3
.equ    MUX2     , 2
.equ    MUX1     , 1
.equ    MUX0     , 0

;ADCSR
.equ    ADEN     , 7
.equ    ADSC     , 6
.equ    ADFR     , 5
.equ    ADIF     , 4
.equ    ADIE     , 3
.equ    ADPS2    , 2
.equ    ADPS1    , 1
.equ    ADPS0    , 0

; TWCR
.equ    TWINT    , 7
.equ    TWEA     , 6
.equ    TWSTA    , 5
.equ    TWSTO    , 4
.equ    TWWC     , 3
.equ    TWEN     , 2

.equ    TWIE     , 0

; TWAR
.equ    TWA6     , 7
.equ    TWA5     , 6
.equ    TWA4     , 5
.equ    TWA3     , 4
.equ    TWA2     , 3
.equ    TWA1     , 2
.equ    TWA0     , 1
.equ    TWGCE    , 0

; TWSR
.equ    TWS7     , 7
.equ    TWS6     , 6
.equ    TWS5     , 5
.equ    TWS4     , 4
.equ    TWS3     , 3
.equ	TWPS1	 , 1
.equ	TWPS0	 , 0

;ASSR
.equ    AS2      , 3
.equ    TCN2UB   , 2
.equ    OCR2UB   , 1
.equ    TCR2UB   , 0

.equ	XL	 , r26
.equ	XH	 , r27
.equ	YL	 , r28
.equ	YH	 , r29
.equ	ZL	 , r30
.equ	ZH	 , r31

.equ 	RAMEND  , 0x45F
.equ	FLASHEND  , 0xFFF

						;  byte groups
						;  /\/--\/--\/--\ 
.equ 	SMALLBOOTSTART	 , 0b00111110000000  ;(0x0F80) smallest boot block is 256
.equ 	SECONDBOOTSTART	 , 0b00111100000000  ;(0x0F00) 2'nd boot block size is 512
.equ 	THIRDBOOTSTART	 , 0b00111000000000  ;(0x0E00) third boot block size is 1K
.equ 	LARGEBOOTSTART	 , 0b00110000000000  ;(0x0C00) largest boot block is 2K
.equ 	BOOTSTART		 , THIRDBOOTSTART  ;OBSOLETE!!! kept for compatibility
.equ	PAGESIZE		 , 32     ;number of WORDS in a page

.equ	INT0addr , 0x001	; External Interrupt0 Vector Address
.equ	INT1addr , 0x002	; External Interrupt1 Vector Address
.equ	OC2addr  , 0x003	; Output Compare2 Interrupt Vector Address
.equ	OVF2addr , 0x004	; Overflow2 Interrupt Vector Address
.equ	ICP1addr , 0x005	; Input Capture1 Interrupt Vector Address
.equ	OC1Aaddr , 0x006	; Output Compare1A Interrupt Vector Address
.equ	OC1Baddr , 0x007	; Output Compare1B Interrupt Vector Address
.equ	OVF1addr , 0x008	; Overflow1 Interrupt Vector Address
.equ	OVF0addr , 0x009	; Overflow0 Interrupt Vector Address
.equ	SPIaddr  , 0x00a	; SPI Interrupt Vector Address
.equ	URXCaddr , 0x00b	; USART Receive Complete Interrupt Vector Address
.equ	UDREaddr , 0x00c	; USART Data Register Empty Interrupt Vector Address
.equ	UTXCaddr , 0x00d	; USART Transmit Complete Interrupt Vector Address
.equ	ADCCaddr , 0x00e	; ADC Interrupt Vector Address
.equ	ERDYaddr , 0x00f	; EEPROM Interrupt Vector Address
.equ	ACIaddr  , 0x010	; Analog Comparator Interrupt Vector Address
.equ    TWIaddr  , 0x011   ; Irq. vector address for Two-Wire Interface
.equ	SPMaddr  , 0x012	; SPM complete Interrupt Vector Address
.equ	SPMRaddr  , 0x012	; SPM complete Interrupt Vector Address
