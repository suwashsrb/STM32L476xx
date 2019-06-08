#include "LED.h"
#include "Button.h"

#include <math.h>
void toggleLED(void);
void delay(unsigned dly)
{
    while(dly--);
}
int main()
{
	/*Init Red LED*/
	LED_init(LED_COLOR_RED_E);
	LED_init(LED_COLOR_GREEN_E);
	BUTTON_vInit(BUTTON_CENTRE_E);
	toggleLED();
	return 0;
}
void toggleLED()
{
	uint8_t u8Button;
	while(1)
	{
		u8Button = BUTTON_Read(BUTTON_CENTRE_E);
		if(u8Button == 0x01)
		{
			while(1)
			{
				/*Turn ON Red LED*/
				LED_On(LED_COLOR_RED_E);
				LED_Off(LED_COLOR_GREEN_E);
				/*Introdue some delay*/
				delay(200000);
				LED_Off(LED_COLOR_RED_E);
				LED_On(LED_COLOR_GREEN_E);
				/*Introdue some delay*/
				delay(200000);	
			}	
		}
		else
		{
			LED_On(LED_COLOR_RED_E);
		}
	}
}