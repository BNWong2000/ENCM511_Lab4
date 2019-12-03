/*************************************************************************************
* AUTO-GENERATED COMMENT - DO NOT MODIFY 
* Author: safwan.jamal1
* Date: Sat 2019/11/30 at 05:51:37 PM
* File Type: uTTCOS Task Header File
*************************************************************************************/

#ifndef LAB4_CORE0_UTTCOSG2017_H
#define LAB4_CORE0_UTTCOSG2017_H

#include <uTTCOSg2017/uTTCOSg.h>
#include <GPIO2017/ADSP_GPIO_interface.h>
#include "adi_initialize.h"
#include "faultyLED1_Thread.h"
#include "LCD_Threads.h"
#include "Temp_Functions.h"
// extern "C" void BlackfinBF533_uTTCOSg_Audio_Rx_Tx_Task(void); 
extern "C" void SHARC21469_uTTCOSg_Audio_Rx_Tx_Task(void);
extern "C" void ADSP_SC589_uTTCOSg_Audio_Rx_Tx_Task(void);


#define GP_TIMER_TEMP_SENSOR 0x3

// TODO -- Once you have demonstrated the idea of uTTCOS working with print statements
// Comment out the following include statement
// DON'T USE PRINT STATEMENT INSIDE uTTCOS as it is a real time system and
// print statements run on the HIGH priority emulator interrupt and disrupt real time operations

#include <stdio.h>

void Custom_uTTCOS_OS_Init(unsigned long int);
extern "C" void Idle_WaitForInterrupts_ASM(void);
void uTTCOSg_Start_CoreTimer_Scheduler(unsigned int maxNumberThreads);

#endif
