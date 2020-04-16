/* ///////////////////////////////////////////////////////////////////////////
 * 
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ServoMotor.h"
#include "Timer1_PWM.h"
#include "Door.h"

void Door_Init(void)
{
	Motor_Init(Motor_1);
	Door_Close();
}

void Door_Open(void)
{
	Motor_Out(Motor_1);
	PWM_Set_TONus(1500,OC1A_Pin);
}

void Door_Close(void)
{
	Motor_Out(Motor_1);
	PWM_Set_TONus(1000,OC1A_Pin);
}
