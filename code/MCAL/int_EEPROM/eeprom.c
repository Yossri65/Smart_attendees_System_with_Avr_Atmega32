/*
 * EEPROM.c
 *
 * Created: 14/08/2022 06:23:09
 *  Author: Mahmoud Abdelmoniem
 */
#include "eeprom.h"

static void (*(EEPROM_interrupt)) (void);
void EEPROM_Read_Byte(uint8 address,uint8 *_value)
{

	while(EECR & (1<<EEWE));


	EEAR = address;

	EECR |= (1<<EERE);


	*_value = EEDR;

}


void EEPROM_Write_Byte(uint8 address,uint8 _value)
{
	while(EECR & (1<<EEWE));
		EEAR = address;
		EECR |= (1<<EERE);
		if(EEDR != _value)
		{
			EEDR = _value;
			EECR |= (1<<EEMWE);
			EECR |= (1<<EEWE);
		}

}

void EEPROM_Interupt_Enable(void)
{
	SetBit(EECR,EERIE);

}
void EEPROM_Interupt_Disable(void)
{
	ClearBit(EECR,EERIE);

}
void EEPROM_Set_CallBack(void(*Local_ptr)(void))
{
	EEPROM_interrupt=Local_ptr;
}

 ISR(EE_RDY_vect)
{
	if(EEPROM_interrupt)
		EEPROM_interrupt();
};
