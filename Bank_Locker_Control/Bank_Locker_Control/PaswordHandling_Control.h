/* ///////////////////////////////////////////////////////////////////////////
 * 
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 
#ifndef PASWORDHANDLING_CONTROL_H_
#define PASWORDHANDLING_CONTROL_H_

#define PASS_LENGTH                 4
#define CORRECT_PASSWORD           '1'
#define WRONG_PASSWORD             '0'
#define FIRST_TIME                 'f'

#define START_PW_SECTION_IN_MEM     0

void Pass_Get(uint8 *Pass);
void Pass_Change(uint8 *Pass);
uint8 Pass_RecvCMP(uint8 *Pass);

#endif /* PASWORDHANDLING_CONTROL_H_ */