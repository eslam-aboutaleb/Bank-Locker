/* ///////////////////////////////////////////////////////////////////////////
 * 
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#ifndef PASS_HANDLING_H_
#define PASS_HANDLING_H_

#define CORRECT_PASSWORD '1'
#define WRONG_PASSWORD   '0'
#define PASS_LENGTH      (4)

void Pass_init(void);
uint8 Pass_Exist(void);
void Pass_Recv_FirstTime(void);
void Pass_Recv(uint8 *EntryPassword);
uint8 Pass_Check(uint8 *UserPass);


#endif /* PASS_HANDLING_H_ */