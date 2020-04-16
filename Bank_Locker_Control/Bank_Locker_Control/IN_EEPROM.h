/* ///////////////////////////////////////////////////////////////////////////
 * 
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#ifndef IN_EEPROM_H_
#define IN_EEPROM_H_

typedef enum
{
	Disable_Interrupt,
	Enable_Interrupt
}IN_EEPROM_Interrupt;

void IN_EEPROM_write(uint16 uiAddress,uint8 ucData);
uint16 IN_EEPROM_ReadByte(uint16 uiAddress);
void IN_EEPROM_SetInterrpt(IN_EEPROM_Interrupt Interrupt);




#endif /* IN_EEPROM_H_ */