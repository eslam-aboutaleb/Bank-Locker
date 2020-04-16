/* ///////////////////////////////////////////////////////////////////////////
 * 
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */  


#ifndef LCKR_H_
#define LCKR_H_

/*UART Messages*/
#define TURNOFF_BUZZER 'M'
#define TURNOFFLOCKER  'B'
#define CHANGE_PASS    'C'
#define OPEN_LOCKER    'A'
#define WARNING_ALERT  'W'
#define FIRST_TIME     'F'


#define FIRST_TIME_ADDRESS 0x0D
#define PASS_FOUND         'P'

void LCKR_Init(void);
void LCKR_Update(void);


#endif /* LCKR_H_ */