/* ///////////////////////////////////////////////////////////////////////////
 * 
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#ifndef BANKLOCKER_CONTROL_H_
#define BANKLOCKER_CONTROL_H_

#define WARNING_COUNTS 3

/*UART Messages*/
#define CLOSE_LOCKER  'B'
#define CHANGE_PASS    'C'
#define OPEN_LOCKER    'A'

/*EEPROM*/
#define FIRST_TIME_ADDRESS 0x0D
#define PASS_FOUND         'P'


/*Functions prototype*/
void LckrCtrl_Update(void);




#endif /* BANKLOCKER_CONTROL_H_ */