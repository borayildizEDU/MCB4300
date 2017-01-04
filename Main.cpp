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
#include "LED.h"
#include "LCD.h"

osThreadId tid_system;                  /* Thread id of thread: system      */


/*----------------------------------------------------------------------------
 *      Hardware Definitions
 *---------------------------------------------------------------------------*/
LED Led_0(0);
LCD LCD_0(0);


/*----------------------------------------------------------------------------
 *      Thread 1 'system': System monitoring
 *---------------------------------------------------------------------------*/
void system (void const *argument) {
  for (;;) {
    osSignalWait(0x0001, osWaitForever);    
    Led_0.On();
		osSignalWait(0x0001, osWaitForever);    
    Led_0.Off();
  }
}

osThreadDef(system, osPriorityNormal, 1, 0);



/*----------------------------------------------------------------------------
 *      Main: Initialize and start RTX Kernel
 *---------------------------------------------------------------------------*/
int main (void) {

  LED::Initialize();    
	LCD::Initialize();
	
  tid_system = osThreadCreate(osThread(system), NULL);
	LCD_0.Show_Page_Main();
         
  while(1){
		osDelay(250);
		osSignalSet(tid_system, 0x0001); 
	}
}
