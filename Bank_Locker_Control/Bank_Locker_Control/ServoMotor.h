#ifndef SERVOMOTOR_H_
#define SERVOMOTOR_H_

#define MOTOR_1_PORT_DR                     'D'
#define MOTOR_1_PORT_CR                     'D'
#define MOTOR_1_POLARITY_PIN_POSITIVE       (5)

typedef enum
{
	Motor_1
}tMotor;


typedef enum
{
	Motor_OFF = 0,
	Motor_ON  = 1
}tMotor_State;

typedef enum
{
	Motor_Stopped=0,
	Motor_ClockWise,
	Motor_AntiClockWise
}tMotor_Direction;

/*Motor info: State & Direction*/
typedef struct
{
	tMotor_State State;
	tMotor_Direction Direction;
}tMotor_Info;

/*Functions prototypes*/
void Motor_Init(tMotor Motor);
void Motor_SetState(tMotor Motor,tMotor_State State);
tMotor_Info * Motor_GetState(tMotor Motor);
void Motor_Stop(tMotor Motor);
void Motor_Out(tMotor Motor);




#endif /* SERVOMOTOR_H_ */