/* ///////////////////////////////////////////////////////////////////////////
 * 
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_interface.h"
#include "PaswordHandling_Control.h"
#include "EX_EEPROM.h"
#include "BankLocker_Control.h"
#include "Alarm.h"
#include "Door.h"
#include "IN_EEPROM.h"
#include <string.h>

/*Local functions prototype*/
static uint8 First_ON_Check(void);
static uint8 LckrCtrl_APP(void);


static uint8 First_ON_Check(void)
{
	uint16 Check;
	Check=IN_EEPROM_ReadByte(FIRST_TIME_ADDRESS);
	if(Check==PASS_FOUND)
	{
		/*There is password in MEM*/
		return 0;
	}
	else
	{
		/*There isn't password in MEM*/
		return 1;
	}
}

static uint8 LckrCtrl_APP(void)
{
	uint8 Ch_Pass[PASS_LENGTH];
	uint8 User_Choice=0;
	uint8 APP_ON=0;
    uint8 OP_Done=0;
	
 while (APP_ON==0)
 {
	User_Choice=UART_RecieveByte();
	switch(User_Choice)
	{
		case OPEN_LOCKER:
		Door_Open();
		break;
		case CLOSE_LOCKER:
		Door_Close();
		OP_Done=1;
		APP_ON=1;
		break;
		case CHANGE_PASS:
		Pass_Change(Ch_Pass);
		break;
		default:
		break;
	}
 }
 return OP_Done;
}

void LckrCtrl_Update(void)
{
	uint8 Passed=0;
	uint8 Pass[PASS_LENGTH];
	uint8 Warning_Counter=0;
	memset(Pass,0,sizeof(Pass));
	/*Get Password over communication protocol between MCUs*/
	Pass_Get(Pass);
	/*Check is it first login or not*/
	if(First_ON_Check()==0)
	{
		/*If it there a password in the MEM compare the entered password with it*/
		if (Pass_RecvCMP(Pass)==1)
		{
			Passed=1;
		}
		else
		{
			/*Lock the App in warning mode*/
			while(Passed==0)
			{
				Warning_Counter++;
				
				if (Warning_Counter==WARNING_COUNTS)
				{
					/*Turn ON alarm and break loop to receive new password again*/
					Alarm_SetState(ALARM_1,Alarm_ON);
				}
				/*End of warning count condition*/
				
				if (Pass_RecvCMP(Pass)==1)
				{
					Passed=1;
				}
					
			}
		}
	}
	else
	{
		/*If it is the first time to run locker write over the first entered password*/
		Pass_Change(Pass);
		Passed=1;
	}
	/*End of check first login condition*/
	
	
	if(Passed==1)
	{
		/*If the password right turn off alarm by default*/
		Alarm_SetState(ALARM_1,Alarm_OFF);
		/*Start the App*/
		while (LckrCtrl_APP()==0);
	}
}

