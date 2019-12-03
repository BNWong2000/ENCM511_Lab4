/*
 * LCD_Threads.h
 *
 *  Created on: Nov 30, 2019
 *      Author: safwan.jamal1{}
 */

#ifndef LCD_THREADS_H_
#define LCD_THREADS_H_

#include "Lab4_Core0_uTTCOSg2017_main.h"
#include <string.h>
#include <stdio.h>
#include "Temp_Functions.h"
#include "../../ENCM511_SpecificFiles/ENCM511_include/REB_SPI_Library.h"

#define EN_HIGH 0x0100
#define IS_DATA 0x0400
#define SPIF_COMPLETE 0x01

void MyInitLCD(void);
void MSG0(void);
void MSG1(void);
void MSG2(void);
void DisplayLAB3Temp(void);
void MyInitREBSPI(void);
void SendMSG(void);
void MSGTest(void);
void Print_Temp(void);
void clearScreen(void);


#endif /* LCD_THREADS_H_ */
