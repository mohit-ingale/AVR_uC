.include "C:\VMLAB\include\m8def.inc"

;declaring initial stack pointer for each task and total no of task
.EQU    TASKNO=3	;total no of task
.EQU    CURRENTTASKNO=(RAMEND)	;CURRENTTASKNO to know which is current task
.EQU    STACK_BACKUP=(RAMEND-2)   ;to backup stack pointer
.EQU    TASK1_STACK=(RAMEND-100)   ;stack pointer for task1
.EQU    TASK2_STACK=(RAMEND-400)  ;stack pointer for task2
.EQU    TASK3_STACK=(RAMEND-700)  ;stack pointer for task3


.CSEG
.ORG 0x0000                            ;reset vector
    rjmp start                    ;jump to start code
	reti      ; Addr $01
   reti      ; Addr $02
   reti      ; Addr $03
   reti      ; Addr $04
   reti      ; Addr $05
   reti      ; Addr $06        Use 'rjmp myVector'
   reti      ; Addr $07        to define a interrupt vector
   rjmp ISRTIMER      ; Addr $08
   reti      ; Addr $09
   reti      ; Addr $0A
reti   ; Addr $0B        This is just an example
  reti     ; Addr $0C        Not all MCUs have the same
  reti      ; Addr $0D        number of interrupt vectors
   reti      ; Addr $0E
   reti      ; Addr $0F
   reti      ; Addr $10
   reti
   reti

;
start:
;init timer 1 for regular time intervals e.g sys tick timer
    LDI R16,(1<<CS10)
  OUT TCCR1B,R16
  CLR R16
  LDI R16,1<<TOIE1
  OUT TIMSK,R16
  LDI R16,0X00
	  OUT TCNT1H,R16
	  LDI R16,0X00
	  OUT TCNT1L,R16


;init all stacks
    ldi r31,HIGH(STACK_BACKUP)
    ldi r30,LOW(STACK_BACKUP)

    ldi r16, HIGH(TASK1_STACK)
    st z, r16
    out SPH, r16
    ldi r16, LOW(TASK1_STACK)
    st -z, r16
    out SPL, r16



    ldi r16, HIGH(TASK2_STACK-35)
    st -z, r16
    ldi r16, LOW(TASK2_STACK-35)
    st -z, r16



    ldi r16, HIGH(TASK3_STACK-35)
    st -z, r16
    ldi r16, LOW(TASK3_STACK-35)
    st -z, r16


    clr r16
    sts CURRENTTASKNO, r16

;pc init
;why to put address of next task on stack
;because in avr when isr is executed only pc is pushed to stack
;and on return only pc i popped
;we dont do for task one beause we start executing from task 1
    ldi r16, LOW(TASK2)
    sts TASK2_STACK, r16
    ldi r16, HIGH(TASK2)
    sts TASK2_STACK-1, r16


    ldi r16, LOW(TASK3)
    sts TASK3_STACK, r16
    ldi r16, HIGH(TASK3)
    sts TASK3_STACK-1, r16



    sei
    rjmp TASK1



TASK1:
    ldi r16,0xff;
    out ddrb,r16
    always:
    	ldi r16,0xaa
    	out portb,r16                                                 ; here i an toggling port b
    	ldi r16,0x55
    	out portb,r16
    	rjmp always
  ;  ret


TASK2:                                                                ;here simply i am sending some data serailly
	ldi r16,0x33
	out ubrrl,r16
   ldi r16,(1<<TXEN)
   out ucsrb,r16
   ldi r16,(1<<ucsz1)|(1<<ucsz0)|(1<<ursel)
   out ucsrc,r16
   agin:
   ldi r17,'y'
   call trns
   ldi r17,'e'
   call trns
   ldi r17,'s'
   call trns
   ldi r17,' '
   call trns
   rjmp agin
   trns:
   sbis ucsra,udre
   rjmp trns
   out udr,r17
    ret

TASK3:
    ldi r16,0xff;
    out ddrb,r16
    als:
    	ldi r16,0xff                                                ; here i am toggling port d
    	out portb,r16
    	ldi r16,0x00
    	out portb,r16
    	rjmp als
  ;  ret





ISRTIMER:
    push r31
    push r30
    push r29
    push r28
    push r27
    push r26                                         ;i am pushing al registers beacause they are not pushed automatically when isr is called
    push r25
    push r24
    push r23
    push r22
    push r21
    push r20
    push r19
    push r18
    push r17
    push r16
    push r15
    push r14
    push r13
    push r12
    push r11
    push r10
    push r9
    push r8
    push r7
    push r6
    push r5
    push r4
    push r3
    push r2
    push r1
    push r0
    in r17, SREG
    push r17


;stack pointer manupulation
    lds r16, CURRENTTASKNO
    ldi r30, low(STACK_BACKUP)
    ldi r31, high(STACK_BACKUP)
    clr r0
  sub r30,r16
    sbc r31,r0

    sub r30,r16
    sbc r31,r0

    in r17, SPH
    st Z, r17
    in r17, SPL
    st -Z, r17

    inc r16

    cpi r16, TASKNO
    brne SKIP1
    ldi r30, low(STACK_BACKUP)
    ldi r31, high(STACK_BACKUP)
    clr r16
    sts CURRENTTASKNO, r16
    ld r17, Z
    rjmp SKIP2
SKIP1:
    sts CURRENTTASKNO,r16
    ld r17, -Z
SKIP2:
    out SPH,r17
    ld r17, -Z
    out SPL,r17

;

;restore all
    pop r17
    out SREG, r17
    pop r0
    pop r1
    pop r2
    pop r3
    pop r4
    pop r5
    pop r6
    pop r7
    pop r8
    pop r9
    pop r10
    pop r11
    pop r12
    pop r13
    pop r14
    pop r15
    pop r16
    pop r17
    pop r18
    pop r19
    pop r20
    pop r21
    pop r22
    pop r23
    pop r24
    pop r25
    pop r26
    pop r27
    pop r28
    pop r29
    pop r30
    pop r31
    reti




