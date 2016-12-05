/*----------------------------------------------------------------------------
 *      RL-ARM - RTX
 *----------------------------------------------------------------------------
 *      Name:    Main.c
 *      Purpose: RTX example program
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2014 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include "cmsis_os.h"
#include "LPC43xx.h"
#include "Board_LED.h"

osThreadId tid_system;                  /* Thread id of thread: system      */


#define LED_A   0

/*----------------------------------------------------------------------------
 *      Switch LED on
 *---------------------------------------------------------------------------*/
void Switch_On (unsigned char led) {
  LED_On(led);
}

/*----------------------------------------------------------------------------
 *      Switch LED off
 *---------------------------------------------------------------------------*/
void Switch_Off (unsigned char led) {
  LED_Off(led);
}


/*----------------------------------------------------------------------------
 *      Thread 1 'system': System monitoring
 *---------------------------------------------------------------------------*/
void system (void const *argument) {
  for (;;) {
    osSignalWait(0x0001, osWaitForever);    /* wait for an event flag 0x0001 */
    Switch_On (LED_A);
		osSignalWait(0x0001, osWaitForever);    /* wait for an event flag 0x0001 */
    Switch_Off(LED_A);
  }
}

osThreadDef(system, osPriorityNormal, 1, 0);


/*----------------------------------------------------------------------------
 *      Main: Initialize and start RTX Kernel
 *---------------------------------------------------------------------------*/
int main (void) {

  LED_Initialize();                         
  tid_system = osThreadCreate(osThread(system), NULL);
         
  while(1){
		osDelay(500);
		osSignalSet(tid_system, 0x0001); 
	}
}
