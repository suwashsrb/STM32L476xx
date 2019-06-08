#include "Button.h"
/******************************************************************************/
/*Private Function declaration*/
/******************************************************************************/
/******************************************************************************/
/*Function definition*/
/******************************************************************************/
void BUTTON_vInit(BUTTON_T eEnableButton)
{
	/*Enable clock for GPIO_A*/
	RCC_AHB2ENR |=BIT0;
	if(BUTTON_CENTRE_E == eEnableButton)
	{
		/*Enable GPIOA PIN 0*/
		GPIOA_MODER &= ~BIT0;
		GPIOA_MODER &= ~BIT1;
	}
	else if(BUTTON_LEFT_E == eEnableButton)
	{
		GPIOA_MODER &= ~BIT2;
		GPIOA_MODER &= ~BIT3;
	}
	else if(BUTTON_RIGHT_E == eEnableButton)
	{
		GPIOA_MODER &= ~BIT4;
		GPIOA_MODER &= ~BIT5; 
	}
	else if(BUTTON_UP_E == eEnableButton)
	{
		GPIOA_MODER &= ~BIT6;
		GPIOA_MODER &= ~BIT7;
	}
	else if(BUTTON_DOWN_E == eEnableButton)
	{
		GPIOA_MODER &= ~BIT10;
		GPIOA_MODER &= ~BIT11;
	}
}
uint8_t BUTTON_Read(BUTTON_T eButtonRead)
{
	uint8_t u8ReadButton;
	u8ReadButton = (GPIOA_IDR & (0x00000001));
}