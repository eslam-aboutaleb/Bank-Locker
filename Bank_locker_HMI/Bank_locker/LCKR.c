/* ///////////////////////////////////////////////////////////////////////////
 * 
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LCD_interface.h"
#include "LCKR.h"
#include "Pass_Handling.h"
#include "Keypad.h"
#include "UART_interface.h"
#include "IN_EEPROM.h"
#include <string.h>


#define WARNING_COUNT  (3)

/*user input characters*/
#define CMD_OPEN_DOOR   'A'
#define CMD_CLOSE_DOOR  'B'
#define CMD_CHANGE_PASS 'C'

static void LCKR_OptionsMSG(void);
static void LCKR_Open_OptionsMSG(void);
static void LCKR_CloseLockerMSG(void);
static void LCKR_ChangePassMSG(void);
static void LCKR_WelcomeMSG(void);
static void LCKR_WrongOptionMSG(void);
static void LCKR_FirstPassMSG(void);
static void LCKR_Warning(void);
static uint8 First_ON_OP(void);
void LCKR_Init(void)
{
	Pass_init();
}


static void LCKR_OptionsMSG(void)
{
	LCD_Clear();
	LCD_SendString_RowColumn(0,0,"Choose option");
	LCD_SendString_RowColumn(1,0,"A-Open door");
	LCD_SendString_RowColumn(2,0,"B-Close Locker");
	LCD_SendString_RowColumn(3,0,"C-Change pass");
}

static void LCKR_Open_OptionsMSG(void)
{
	LCD_Clear();
	LCD_SendString_RowColumn(0,2,"Choose option");
	LCD_SendString_RowColumn(2,0,"B-Close locker");
	LCD_SendString_RowColumn(3,0,"C-Change pass");
}
static void LCKR_CloseLockerMSG(void)
{
	LCD_Clear();
	UART_SendByte(TURNOFFLOCKER);
	LCD_SendString_RowColumn(1,2,"Closing door");
	delay_ms(1500);
}
static void LCKR_ChangePassMSG(void)
{
	uint8 changedPass[PASS_LENGTH];
	uint8 Pass_Met[PASS_LENGTH];
	LCD_Clear();
		
	LCD_SendString_RowColumn(0,2,"enter new");
	LCD_SendString_RowColumn(1,3,"password");
	
   Pass_Recv(changedPass);
   Pass_Recv(Pass_Met);
   if (strcmp(Pass_Met,changedPass)==1)
   {
	   LCD_SendString_RowColumn(0,0,"Not the same");
	   LCD_SendString_RowColumn(1,1,"Try again");
	   LCKR_ChangePassMSG();
   }
   else
   {
   UART_SendByte(CHANGE_PASS);
   delay_ms(1000);
   UART_SendString(changedPass);
   LCD_Clear();
   LCD_SendString_RowColumn(0,0,"password changed");
   _delay_ms(1000);
   LCD_Clear();
   }
}
static void LCKR_WelcomeMSG(void)
{
	UART_SendByte(TURNOFF_BUZZER);
	LCD_Clear();
	LCD_SendString_RowColumn(2,4,"welcome");
	delay_ms(1000);
	LCD_Clear();
	
}
static void LCKR_WrongOptionMSG(void)
{
	LCD_SendString_RowColumn(0,2,"Enter valid");
	LCD_SendString_RowColumn(1,3,"Option");
	delay_ms(1500);
	LCD_Clear();
	LCKR_Open_OptionsMSG();
}

static void LCKR_Warning(void)
{
	uint8 index=0;
	UART_SendByte(WARNING_ALERT);
	for (index=0;index<3;index++)
	{
		LCD_SendString_RowColumn(2,4,"warning");
		delay_ms(500);
		LCD_Clear();
		delay_ms(200);
	}
	
	LCD_SendString_RowColumn(0,1,"To disable");
	delay_ms(1000);

	LCD_Clear();
}

static uint8 LCKR_APP(void)
{
	uint8 User_InputChoice=0;
	static uint8 First_Run=0;
	static uint8 Door_Open=0;
	uint8  OP_Done=0;
	/*Check if this first time after password entered right*/
	if (First_Run==0)
	{
		/*Put welcome msg*/
		LCKR_WelcomeMSG();
	}
	if (Door_Open==0)
	{
		/*If the door still closed */
		LCKR_OptionsMSG();
	}
	else
	{
		/*IF the door is opened*/
		LCKR_Open_OptionsMSG();
	}
	/*makes the user enters his pass*/
	User_InputChoice=Keypad_GetKey();
	LCD_Clear();
	/*To avoid showing Welcome message again while the locker still used*/
	First_Run=1;
	switch(User_InputChoice)
	{
	
		case CMD_OPEN_DOOR:
		UART_SendByte(OPEN_LOCKER);
		LCD_SendString_RowColumn(1,0,"Opening door");
		delay_ms(1000);
		LCD_Clear();
		LCKR_Open_OptionsMSG();
		/*To avoid repeating open the door while it is already opened*/
		Door_Open=1;
		break;
		
		case CMD_CLOSE_DOOR:
		LCKR_CloseLockerMSG();
		/*To put the closed door options next operation*/
		Door_Open=0;
		/*Door is closed and welcome message can be shown next operation*/
		First_Run=0;
		OP_Done=1;
		break;
		
		case CMD_CHANGE_PASS:
		LCKR_ChangePassMSG();
		/*Recursive call to put out options again*/
		LCKR_APP();
		break;
		
		default:
		LCKR_WrongOptionMSG();
		/*Recursive call to put out options again*/
		LCKR_APP();
		break;
	}
	return OP_Done;
}

static void LCKR_FirstPassMSG(void)
{
	LCD_Clear();
	LCD_SendString_RowColumn(0,1,"Enter First");
	LCD_SendString_RowColumn(1,2,"Password");
}

static void LCKR_PassMSG(void)
{
	LCD_Clear();
	LCD_SendString_RowColumn(0,1,"Enter Password");
}

static void LCKR_WrongPassMSG(void)
{
	LCD_Clear();
	LCD_SendString_RowColumn(1,3,"Wrong");
	LCD_SendString_RowColumn(2,5,"password");
	delay_ms(1000);
}

static uint8 First_ON_Flag=0;

static void First_ON_Check(void)
{
	uint16 Check;
	Check=IN_EEPROM_ReadByte(FIRST_TIME_ADDRESS);
	if(Check==PASS_FOUND)
	{
		First_ON_Flag=0;
	}
	else
	{
		First_ON_Flag=1;
	}
}

static uint8 First_ON_OP(void)
{
	First_ON_Check();
	if (First_ON_Flag==1)
	{
		LCKR_FirstPassMSG();
		return 1;
	}
	else
	{
		LCKR_PassMSG();
		return 0;
	}
}

void LCKR_Update(void)
{
	uint8 Pass[PASS_LENGTH];
	uint8 Passed=0;
	/*Initialize warning counter by 0*/
	uint8 Warning_Counter=0;
	uint8 Index=0;
	/*Check if there already password on the system 
	or is it first time*/
	if (First_ON_OP()==1)
	{
		/*Enter user pass*/
		Pass_Recv(Pass);
		IN_EEPROM_write(FIRST_TIME_ADDRESS,PASS_FOUND);
		Passed=1;
	}
	else
	{
		if(Pass_Check(Pass)==1)
		{
			Passed=1;
		}
		
	
		else
		{
			while (Passed==0)
			{
				LCKR_WrongPassMSG();
				/*Put on screen enter password MSG again*/
				LCKR_PassMSG();
				
				Warning_Counter++;
				
				if (Warning_Counter==WARNING_COUNT)
				{
					/*Put out warning msg*/
					LCKR_Warning();
					/*To turn off alarm user should enter pass or it will keep running*/
					LCKR_PassMSG();
					/*system closed*/
				}
				else
				{
					/*Ask again for password*/
				}
				/*End of checking warning counter condition*/
				
				if (Pass_Check(Pass)==1)
				{
					Passed=1;
				}
				else
				{
					/*Returns to first of while loop again*/
				}
				/*End of Pass check condition*/
			}
			/*End of while loop*/
		}
		/*End of wrong password condition*/
	}
	/*End of Pass found condition*/
			
	if (Passed==1)
	{
		/*Start the app*/
		while(LCKR_APP()==0); /*While the Locker is open*/
	}
	

}

