# Driver Development for STM32L476xx Project
### Development Board 	- 	 'STM32L476VG Discovery Kit'
### Microcontroller 	-	'STM32L476VG'

### Documentation : Documents can be found at the below paths
### Reference manual of controller (STM32L4x6) - 
	
Datasheet of controller(STM32L476xx) - 
	
User Manual for discovery kit- 

Commit Information - 

|**Date**				| 		**Changes Description**		|
|-----------------------|-----------------------------------|
|26-April-2020: 		|	Initial Project created,Written MCU specific header file Header file contains, memories base address of Flash, SRAM1,SRAM2 and ROM Base address of BUS domains (AHB1, AHB2, APB1 and APB2) Base address of periphers - GPIO, SPI, I2C, USART, UART, LPUART, EXTI and SYSCFG		Structure definition of GPIO peripheral registers.|
|28-April-2020			| Added RCC register structure. Added clock enable and disable functions for GPIO, SPI, I2C, USART and SYSCFG peripherls. Added peripheral definition for GPIO and RCC |
