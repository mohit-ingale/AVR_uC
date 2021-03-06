// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here
void init_devices(void);
void timer0_init(void);
void reset_task(char tsk);
void set_task(char tsk);
void task_dispatch(void);
void task0(void);
void task1(void);
void task2(void);
void task3(void);
void task4(void);
void task5(void);
void task6(void);
void task7(void);

#define NUM_TASKS 8
char task_bits = 0;  /* lsb is hi priority task */
volatile char tick_flag = 0;    /* if non-zero, a tick has elapsed */
unsigned int task_timers[NUM_TASKS]={0,0,0,0,0,0,0,0};                  /* init the timers to 0 on startup */
static const PROGMEM char bit_mask[]={1,2,4,8,16,32,64,128};            /* value -> bit mask xlate table */

int main(void)
{

  init_devices();
//
//	start at least one task here
//
set_task(7);	//task7 runs
set_task(6);	//task6 runs

//      main loop

  while(1)
    {
    if (tick_flag)
      {
      tick_flag = 0;
	  task_dispatch();              // well....
	  }
	}
  return 0;
}
//
//	a task gets dispatched on every tick_flag tick (10ms)
//
void task_dispatch(void)
{
  /* scan the task bits for an active task and execute it */

  char task;
	

/* take care of the task timers. if the value ==0 skip it
	else decrement it. If it decrements to zero, activate the task associated with it */

  task=0;
  while (task < NUM_TASKS )
    {
    if (task_timers[task])
	   {
  	   task_timers[task]--;            /* dec the timer */
	   if (task_timers[task] == 0 )
	   		{
	    	set_task(task); /* if ==0 activate the task bit */
			}
	   }
    task++;
    }

  task = 0; /* start at the most significant task */
  while (task <= NUM_TASKS )
    {
	  if ((task_bits & pgm_read_byte(&bit_mask[task])))
	  		{
	  		break; /* if activate task found..*/
			}
      task++;         /* else try the next one */
    }
  switch(task)            /* if task bit is active..execute the task */
    {
    case 0:
      task0();
      break;
    case 1:
      task1();
      break;
    case 2:
      task2();
      break;
    case 3:
      task3();
      break;
    case 4:
      task4();
      break;
    case 5:
      task5();
      break;
    case 6:
      task6();
      break;
    case 7:
      task7();
      break;
    default:
      break;                  /* no task was active!! */
    }
}

// enable a task for execution
void set_task(char tsk)
{
  task_bits |= pgm_read_byte(&bit_mask[tsk]);       /* sets a task bit */
}
// disable a task from executing
void reset_task(char tsk)
{
  task_bits &= (~pgm_read_byte(&bit_mask[tsk]));  /* resets a task bit */
}

void task0(void)
{
  reset_task(0);
}
void task1(void)
{
  reset_task(1);
}
void task2(void)
{
  reset_task(2);
}
void task3(void)
{
  reset_task(3);
}
void task4(void)
{
  reset_task(4);
}
void task5(void)
{
  reset_task(5);
}
//
//	flash PORTB.4 at 2hz
//
void task6(void)
{
PORTB ^= (1<<4);
task_timers[6] = 25;		//every 250ms
reset_task(6);
}
//
//	flash PORTB.5 at 1hz
//
void task7(void)
{
PORTB ^= (1<<5);
task_timers[7] = 50;		//every 500ms
reset_task(7);
}
//call this routine to initialize all peripherals
void init_devices(void)
{
 //stop errant interrupts until set up
 cli(); //disable all interrupts


 DDRB = 0x30;	//port 4 & 5 as outputs

 timer0_init();

 MCUCR = 0x00;
 EICRA = 0x00; //extended ext ints
 EIMSK = 0x00;

 TIMSK0 = 0x02; //timer 0 interrupt sources

 PRR = 0x00; //power controller
 sei(); //re-enable interrupts
 //all peripherals are now initialized
}
//TIMER0 initialize - prescale:1024
// WGM: CTC
// desired value: 10mSec
// actual value: 10.048mSec (-0.5%)
void timer0_init(void)
{
 TCCR0B = 0x00; //stop
 TCNT0 = 0x00; //set count
 TCCR0A = 0x02;	//CTC mode
 OCR0A = 0x9C;
 TCCR0B = 0x05; //start timer
}

ISR(TIMER0_COMPA_vect)
{
 //TIMER0 has overflowed
 	tick_flag = 1;
}

