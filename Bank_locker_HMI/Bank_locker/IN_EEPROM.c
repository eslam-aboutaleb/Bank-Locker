/* ///////////////////////////////////////////////////////////////////////////
 * 
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "IN_EEPROM.h"
#include <avr/io.h>
/*Local functions prototype*/
static void IN_EEPROM_WaitBusy(void);

void IN_EEPROM_write(uint16 uiAddress, uint8 ucData)
{
	IN_EEPROM_WaitBusy();
	
	/* Set up address and data registers */
	EEAR = uiAddress;
	EEDR = ucData;
	
	/*Writing sequence: */
	/* Write logical one to EEMWE */
	SET_BIT(EECR,EEMWE);
	/* Start eeprom write by setting EEWE */
	SET_BIT(EECR,EEWE);
}

static void IN_EEPROM_WaitBusy(void)
{
	/* Wait for completion of previous write */
	while(BIT_IS_SET(EECR,EEWE));
}


uint16 IN_EEPROM_ReadByte(uint16 uiAddress)
{
	IN_EEPROM_WaitBusy();
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}

void IN_EEPROM_SetInterrpt(IN_EEPROM_Interrupt Interrupt)
{
	switch(Interrupt)
	{
		case Disable_Interrupt:
		CLEAR_BIT(EECR,EERIE);
		break;
		case Enable_Interrupt:
		SET_BIT(EECR,EERIE);
		break;
		default:
		break;
	}
}