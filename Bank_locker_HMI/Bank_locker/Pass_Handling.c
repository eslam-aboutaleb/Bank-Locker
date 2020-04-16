/* ///////////////////////////////////////////////////////////////////////////
 * 
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Keypad.h"
#include <string.h>
#include "LCD_interface.h"
#include "UART_interface.h"
#include "Pass_Handling.h"

uint8 Locker_Open=0;	
void Pass_init(void)
{	
	UART_configType UART_Configuration={
		UART_Configuration.CharacterSize= EightBits
		,UART_Configuration.State= Transmiter_Reciever
		,UART_Configuration.BaudRate=9600
		,UART_Configuration.Speed=LOWSpeed
		,UART_Configuration.Interrupt=Interrupt_RX_ON
	};
	UART_init(&UART_Configuration);
}	


void Pass_Recv(uint8 *EntryPassword)
{
	uint8 index=0;
	for (index=0;index<PASS_LENGTH;index++)
	{
		/*Get password from the user*/
		EntryPassword[index]=Keypad_GetKey();
		delay_us(20);
		/*Print on screen * indicates character has been typed*/ 
		LCD_SendString_RowColumn(3,index,"*");
	}
	EntryPassword[index]='\0';
}


uint8 Pass_Check(uint8 *UserPass)
{
	uint8 CheckPass=0;	
	/*Receive pass*/
	Pass_Recv(UserPass);
	/*Send the entered pass*/
	UART_SendString(UserPass);
	_delay_ms(200);
	CheckPass=UART_RecieveByte();
	/*Check if the password right*/
	if (CheckPass==CORRECT_PASSWORD)
	{
		return 1;
	}
	else if (CheckPass==WRONG_PASSWORD)
	{
		return 0;
	}
	
	return 0;
	
}