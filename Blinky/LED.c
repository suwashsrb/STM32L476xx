#include "LED.h"



/************************************************************************/
/* Private function declaration */
/************************************************************************/




/***********************************************************************/
/*Function definition*/
/***********************************************************************/
void LED_init(LED_COLOR_T eLedColor)
{
	if(LED_COLOR_RED_E == eLedColor)
	{
		/*Enable GPIOB*/
		RCC_AHB2ENR |= BIT1;
		/*Enable GPIOB MODE Register*/
		GPIOB_MODER |= BIT4;
		GPIOB_MODER &= ~BIT5;
	}
	else if(LED_COLOR_GREEN_E == eLedColor)
	{	/*Enable GPIOE*/
		RCC_AHB2ENR |= BIT4;
		/*Enable GPIOE MODE Register*/
		GPIOE_MODER |= BIT16;
		GPIOE_MODER &= ~BIT17;
	}
}
void LED_On(LED_COLOR_T eLedColor)
{
	if(LED_COLOR_RED_E == eLedColor)
	{
		/*Turn ON RED Led*/
		GPIOB_ODR |= BIT2;
	}
	else if(LED_COLOR_GREEN_E == eLedColor)
	{
		/*Turn ON GREEN Led*/
		GPIOE_ODR |= BIT8;
	}
}
void LED_Off(LED_COLOR_T eLedColor)
{
	if(LED_COLOR_RED_E == eLedColor)
	{
		/*Turn OFF RED Led*/
		GPIOB_ODR &= ~BIT2;
	}
	else if(LED_COLOR_GREEN_E == eLedColor)
	{
		/*Turn OFF Green LED*/
		GPIOE_ODR  &= ~BIT8;
	}
}

