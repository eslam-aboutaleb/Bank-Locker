/* ///////////////////////////////////////////////////////////////////////////
 * 
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 
#include <avr/interrupt.h>
#include <string.h>
#include "UART_interface.h"
#include "LCD_interface.h"
#include "Keypad.h"
#include "LCKR.h"
#define F_CPU 8000000
#include <util/delay.h>


int main(void)
{
	/*Initialize UART*/
	UART_configType UART_Configuration;
	memset(&UART_Configuration ,0,sizeof(UART_Configuration));
	UART_Configuration.CharacterSize= EightBits;
	UART_Configuration.State= Transmiter_Reciever;
	UART_Configuration.BaudRate=9600;
	UART_Configuration.Speed=LOWSpeed;
	UART_Configuration.StopBit=OneBit;
	UART_Configuration.ClockPolarity=Transmit_Falling_Edge_Recieve_Rising_Edge;
	UART_Configuration.Mode=Asynchronous;
	UART_Configuration.Parity=Parity_OFF;
	UART_init(&UART_Configuration);

	/*Initialize LCD*/
	LCD_configType LCD_Configuration;
	memset(&LCD_Configuration ,0,sizeof(LCD_Configuration));
	LCD_Configuration.Mode=LCD_4_pins;
	LCD_Configuration.lines=Two_lines;
	LCD_Configuration.font=Format_5x11;
	LCD_Configuration.display=DisplayON;
	LCD_Configuration.cursor_state=CursorOFF;
	LCD_Configuration.cursor_blink=CursorBlinkOFF;
	LCD_Configuration.cursor_shift=CursorToRight;
	LCD_Configuration.display_shift=DisplayShiftOFF;
	LCD_Init(&LCD_Configuration);
	
	/*Initialize keypad*/
	Keypad_Init();
	
	while (1)
	{
		LCKR_Update();
	}
}

