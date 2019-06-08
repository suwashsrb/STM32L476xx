#ifndef BUTTON_H
#define BUTTON_H

#include "stm32l476.h"
/*Enum for buttons */
typedef enum
{
	BUTTON_CENTRE_E = 0,
	BUTTON_UP_E,
	BUTTON_DOWN_E,
	BUTTON_LEFT_E,
	BUTTON_RIGHT_E,
	BUTTON_NONE_E
}BUTTON_T;

/**********************************************************************************************/
/*Function declaration*/
/**********************************************************************************************/
void BUTTON_vInit(BUTTON_T eEnableButton);
uint8_t BUTTON_Read(BUTTON_T eButtonRead);


#endif/*BUTTON_H*/