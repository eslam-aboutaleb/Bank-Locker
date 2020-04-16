/* ///////////////////////////////////////////////////////////////////////////
 * 
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "ServoMotor.h"

/* ///////////////////////////////////////////////////////////////////////////////////////////////////////////
Function: Motor_Init
Parameters: Motor from type structure tMotor
return: void
function job: Initialize Motor pins & first state & direction
///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void Motor_Init(tMotor Motor)
{
    /* Initialize Motor pins*/
    switch(Motor)
    {
    case Motor_1:
        DIO_InitPin(MOTOR_1_PORT_CR,MOTOR_1_POLARITY_PIN_POSITIVE,OUTPUT,Motor_OFF);
        break;

    default:
        /* No Action*/
        break;
    }

    /*set Motor OFF*/
    Motor_SetState(Motor,Motor_OFF);
}

/* ///////////////////////////////////////////////////////////////////////////////////////////////////////////
Function: Motor_Setstate
Parameters: Motor from type struct tMotor,State form type struct tMotor_State, Direction from type struct
tMotor_Direction
return: void
function job: Set Motor state & direction
///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void Motor_SetState(tMotor Motor,tMotor_State State)
{
    switch(Motor)
    {
   case Motor_1:
 
       /*Check if state is on*/
       if(State==Motor_ON)
        {
        DIO_SetPinValue(MOTOR_1_PORT_DR,MOTOR_1_POLARITY_PIN_POSITIVE,State);

        }
        /*Motor State is off*/
       else
        {
            Motor_Stop(Motor_1);
        }
 
    break;

   default:
       /* No Action */
    break;

    }
}

/* ///////////////////////////////////////////////////////////////////////////////////////////////////////////
Function: Motor_GetState
Parameters: Motor from type structure tMotor
return: struct tMotor_Info
function job: Read motor state & direction
///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
tMotor_Info * Motor_GetState(tMotor Motor)
{
    tMotor_Info *Motor_ConfigType=(void*)0;
    /*Initialize Motor info*/
    Motor_ConfigType->State=Motor_OFF;
    Motor_ConfigType->Direction=Motor_Stopped;

    switch(Motor)
    {
    case Motor_1:
        Motor_ConfigType->State=DIO_ucGetPinValue(MOTOR_1_PORT_CR,MOTOR_1_POLARITY_PIN_POSITIVE);
        if(Motor_ConfigType->State==Motor_ON)
            {
               Motor_ConfigType->Direction=Motor_ClockWise;
            }
         else
            {
                /* No Action*/
            }


        /*If Motor state is off*/
        if(Motor_ConfigType->State==Motor_OFF)
           {
           /*Return the initialized states at first of function*/
           }
        else
            {
                /* No Action*/
            }

        break;

    default:
        /* No Action*/
        break;

    }
    /*End of Switch*/
            return Motor_ConfigType;

}

/* ///////////////////////////////////////////////////////////////////////////////////////////////////////////
Function: Motor_Stop
Parameters: Motor from type structure tMotor
return: void
function job: Stop Motor
///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void Motor_Stop(tMotor Motor)
{
    switch (Motor)
    {
      case Motor_1:

      DIO_SetPinValue(MOTOR_1_PORT_DR,MOTOR_1_POLARITY_PIN_POSITIVE,0);
    break;
	
    default:
        break;
    }

}

/* ///////////////////////////////////////////////////////////////////////////////////////////////////////////
Function: Motor_Out
Parameters: Motor from type structure tMotor
return: void
function job: Start the motor in clockwise direction
///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void Motor_Out(tMotor Motor)
{
    Motor_SetState(Motor,Motor_ON);
}