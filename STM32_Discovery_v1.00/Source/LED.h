/*************************************************************************/
/**/

#ifndef LED_H
#define LED_H
#include "stm32l476.h"
// RED LED on PB2 
// GREEN LED ON PE8
typedef enum
{
	LED_COLOR_RED_E = 0,
	LED_COLOR_GREEN_E
}LED_COLOR_T;


/***********************************************************************/
/*Function declaration*/
/***********************************************************************/
void LED_init(LED_COLOR_T eLedColor);
void LED_On(LED_COLOR_T eLedColor);
void LED_Off(LED_COLOR_T eLedColor);

#endif