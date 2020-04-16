#include <string.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_interface.h"
#include "EX_EEPROM.h"
#include "PaswordHandling_Control.h"


void Pass_Get(uint8 *Pass)
{
	/*Receive password*/
	UART_RecieveString(Pass);
}

uint8 Pass_RecvCMP(uint8 *Pass)
{
	uint8 Read_PW[PASS_LENGTH];
	memset(Read_PW,0,sizeof(Read_PW));
	EX_EEPROM_ReadBlocks(START_PW_SECTION_IN_MEM,Read_PW,PASS_LENGTH);
	if(strcmp(Read_PW,Pass)==0)
	{
		UART_SendByte(CORRECT_PASSWORD);
		return True;
	}
	else
	{
		UART_SendByte(WRONG_PASSWORD);
		return False;
	}
}

uint8 Pass_RecvFirst(void )
{
	uint8 First=0;
	EX_EEPROM_ReadByte (&First,START_PW_SECTION_IN_MEM);
	if (First==0xff)
	{
		return True;
	}
	else
	{
		return False;
	}
}

void Pass_Change(uint8 *Pass)
{
	uint8 Temp[PASS_LENGTH];

	strcpy(Temp,Pass);
	EX_EEPROM_WriteBlocks(START_PW_SECTION_IN_MEM,Temp);
}

void Pass_Write(uint8 *Pass)
{
	EX_EEPROM_WriteBlocks(START_PW_SECTION_IN_MEM,Pass);
}