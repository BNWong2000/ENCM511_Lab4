/*
 * LCD_Thread.cpp
 *
 *  Created on: Nov 30, 2019
 *      Author: safwan.jamal1
 */
#include "LCD_Threads.h"

bool commandStringBeingSent;
bool commandStringToSend;
bool commandStringIsInstruction;
bool LCDInitialized = false;

volatile char SPI_MessageBuffer[256];
volatile char MSG_Number = 0;

void MSG0(void)
{
	//FLASH LED
	if(commandStringBeingSent){ return; }
	if(commandStringToSend){ return; }
	commandStringToSend = true;
	commandStringIsInstruction = false;
	strcpy((char *) SPI_MessageBuffer, "ENCM 511");
}

void MSG1(void)
{
	//
	if(commandStringBeingSent){ return; }
	if(commandStringToSend){ return; }
	commandStringToSend = true;
	commandStringIsInstruction = false;
	strcpy((char *) SPI_MessageBuffer, "Branden Wong");
}

void MSG2(void)
{
	//
	if(commandStringBeingSent){ return; }
	if(commandStringToSend){ return; }
	commandStringToSend = true;
	commandStringIsInstruction = false;
	strcpy((char *) SPI_MessageBuffer, "Safwan Jamal");
}

void DisplayLAB3Temp(void)
{
	//

}

void MyInitREBSPI()
{
	Init_REB_SPI();
}



volatile char ID_InitFunction;
void MyInitLCD()
{
	static int CommandIndex = 0;
	static unsigned short int initCommands[16] = {0x0100,
												  0x0130, 0x0030, 0x0130,
												  0x0130, 0x0030, 0x0130,
												  0x013C, 0x003C, 0x013C,
												  0x010F, 0x000F, 0x010F,
												  0x0101, 0x0001, 0x0101
												 };
	if(CommandIndex < 16)
	{
		//printf("command %x\n", initCommands[CommandIndex]);
		REB_Write_SPI((REB_Read_SPI() & 0xF800) | (initCommands[CommandIndex++]));
	}
	else
	{
		LCDInitialized = true;
	}
}

volatile char ID_MSG_Selector;

void MSG_Selector()
{
	switch(MSG_Number)
	{
	case 0:
		MSG0();
		break;
	case 1:
		clearScreen();
		break;
	case 2:
		MSG1();
		break;
	case 3:
		clearScreen();
		break;
	case 4:
		MSG2();
		break;
	case 5:
		clearScreen();
		break;
	case 6:
		Print_Temp();
	}
}

volatile char ID_sendMessage;

void SendMSG()
{
	if(!LCDInitialized)
	{
		return;
	}
	static unsigned int Read_Index = 0;
	static unsigned int state = 0;
	unsigned short int MessageToSend;
	if(!commandStringToSend)
	{
		return;
	}
	if((SPI_MessageBuffer[Read_Index] == '\0' && !commandStringIsInstruction) | (commandStringIsInstruction && Read_Index == 2))
	{
		Read_Index = 0;
		commandStringBeingSent = false;
		commandStringToSend = false;
		if(MSG_Number < 6)
		{
			++MSG_Number;
		}
		else
		{
			--MSG_Number;
		}
		return;
	}
	commandStringBeingSent = true;
	switch(state)
	{
	case 0:
		++state;
		MessageToSend = ((REB_Read_SPI() & 0xF800) | (SPI_MessageBuffer[Read_Index]) | EN_HIGH);
		if(commandStringIsInstruction)
		{
			MessageToSend = MessageToSend & ~IS_DATA;
		}
		else
		{
			MessageToSend = MessageToSend | IS_DATA;
		}
		break;
	case 1:
		++state;
		MessageToSend = ((REB_Read_SPI() & 0xF800) | (SPI_MessageBuffer[Read_Index]) & ~EN_HIGH);
		if(commandStringIsInstruction)
		{
			MessageToSend = MessageToSend & ~IS_DATA;
		}
		else
		{
			MessageToSend = MessageToSend | IS_DATA;
		}
		break;
	case 2:
		state = 0;
		MessageToSend = ((REB_Read_SPI() & 0xF800) | (SPI_MessageBuffer[Read_Index]) | EN_HIGH);
		++Read_Index;
		if(commandStringIsInstruction)
		{
			MessageToSend = MessageToSend & ~IS_DATA;
		}
		else
		{
			MessageToSend = MessageToSend | IS_DATA;
		}
		break;
	}
	REB_Write_SPI(MessageToSend);
}


//void MSGTest()
//{
//	//printf("In MSG LCD\n");
//	static unsigned short int messages[4] = {0x0500, 0x0552, 0x0452, 0x0552};
//	static int messageIndex = 0;
//	if(!LCDInitialized)
//	{
//		return;
//	}
//	if(messageIndex < 4)
//	{
//		REB_Write_SPI((REB_Read_SPI() & 0xF800) | (messages[messageIndex++]));
//	}
//	else
//	{
//		messageIndex = 1;
//	}
//}

void Print_Temp()
{
	if(commandStringBeingSent){ return; }
	if(commandStringToSend){ return; }
	commandStringToSend = true;
	commandStringIsInstruction = false;
	char Temperature[6];
	int n;
	float Current_Temp = GetTemperature(GP_TIMER_TEMP_SENSOR);
	n = sprintf(Temperature, "%2.2f", Current_Temp);
	strcpy((char *)SPI_MessageBuffer, "Temp: " );
	strcpy((char *)SPI_MessageBuffer + 6, Temperature);
}

void clearScreen()
{
	if(commandStringBeingSent){ return; }
	if(commandStringToSend){ return; }
	commandStringToSend = true;
	commandStringIsInstruction = true;
	SPI_MessageBuffer[0] = 0x0F;
	SPI_MessageBuffer[1] = 0x01;
	//strcpy((char *) SPI_MessageBuffer, "\0");
	//static unsigned int state = 0;
	//unsigned short int Instruction;
	/*
	switch(state)
	{
	case 0:

		Instruction = (~IS_DATA) & (0x0001 | EN_HIGH);
		++state;
		break;
	case 1:
		Instruction = (~IS_DATA) & (0x0001 & (~EN_HIGH));
		++state;
		break;
	case 2:
		Instruction = (~IS_DATA) & (0x0001 | EN_HIGH);
		++state;
		break;
	}
	*/
}

//bool isSPIReady(void) {
//	unsigned short int SPIF_done = *pSPI_STAT & SPIF_COMPLETE;
//	if (SPIF_done == SPIF_COMPLETE)
//		return true;
//	else
//		return false;
//}





