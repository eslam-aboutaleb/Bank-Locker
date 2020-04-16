/* ///////////////////////////////////////////////////////////////////////////
 * 
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 
#include <string.h>
#include <avr/io.h>
#include "Std_Types.h"
#include "BIT_MATH.h"
#include "UART_interface.h"
#include "Timer1_PWM.h"
#include "ServoMotor.h"
#include "EX_EEPROM.h"
#include "Alarm.h"
#include "BankLocker_Control.h"
#include "Door.h"
#ifndef F_CPU
#define F_CPU 8000000
#endif

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
   
   
   /*Initialize PWM*/
   PWM_Typedef *pPWM=(void*)0;
   pPWM->Mode=TIMER1_WGM_FPWM_ICR;
   pPWM->COM_Mode=Clr_OC1A_OC1B_CompMatchNonInvert;
   pPWM->Channel=OC1A_Pin;
   PWM_Init(pPWM);
   PWM_SetPrescaler(PWM_Prescaler_64);
   PWM_SetPWM_Freq_ICR1(50);
   /*Initialize Motor*/
   Motor_Init(Motor_1);
   /*Initialize the door as it is closed*/
   Door_Init();
   /*Initialize Alarm*/
   Alarm_Init(ALARM_1,Alarm_OFF);
   /*Initialize EEPROM*/
   EX_EEPROM_Init(STD_HIGH,STD_HIGH,STD_LOW);
   
   
    while (1) 
    {
		LckrCtrl_Update();
    }
}


