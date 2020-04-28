/*
 * stm32l476xx.h
 *
 *  Created on: 26-Apr-2020
 *      Author: suwas
 */

#ifndef DRIVERS_INCLUDES_STM32L476XX_H_
#define DRIVERS_INCLUDES_STM32L476XX_H_

#include <stdint.h>

#define __IO volatile
/******************* Base addresses of Flash and SRAM *******************/
/*Base address of Flash memory */
#define BASE_ADDRESS_FLASH_D 				(uint32_t)0x08000000
/*Base address of SRAM1 memory */
#define BASE_ADDRESS_SRAM1_D				(uint32_t)0x20000000
/*Base address of SRM2 memory */
#define BASE_ADDRESS_SRAM2_D				(uint32_t)0x10000000
/*Base address of System memory or ROM*/
#define BASE_ADDRESS_ROM_D					(uint32_t)0x1FFF0000

/************************************************************************/

/******************* Base addresses BUS domain peripherals **************/
/*Base address of AHB1 BUS peripheral */
#define BASE_ADDRESS_AHB1_PERI_D				(uint32_t)0x40020000
/*Base address of AHB2 BUS peripheral */
#define BASE_ADDRESS_AHB2_PERI_D				(uint32_t)0x48000000
/*Base address of APB1 BUS peripheral */
#define BASE_ADDRESS_APB1_PERI_D				(unit32_t)0x40000000
/*Base address of APB2 BUS peripheral */
#define BASE_ADDRESS_APB2_PERI_D				(uint32_t)0x40010000
/************************************************************************/

/******************* Base addresses of AHB1 bus domain peripherals *****************************/
/*Base address of Reset and clock control(RCC) on AHB1 bus */
#define BASE_ADDRESS_RCC_D						(uint32_t)0x40021000
/***********************************************************************************************/
/******************* Base addresses of AHB2 bus domain peripherals *****************************/

/*Macro definition of GPIO register offset*/
#define GPIO_OFFSET_D							(uint32_t)(0x00000400)
/*Base address of GPIO port A on AHB2 bus */
#define BASE_ADDRESS_GPIO_A_D				(BASE_ADDRESS_AHB2_PERI_D + GPIO_OFFSET_D)
/*Base address of GPIO port B on AHB2 bus */
#define BASE_ADDRESS_GPIO_B_D				(BASE_ADDRESS_GPIO_A_D + GPIO_OFFSET_D)
/*Base address of GPIO port C on AHB2 bus */
#define BASE_ADDRESS_GPIO_C_D				(BASE_ADDRESS_GPIO_B_D + GPIO_OFFSET_D)
/*Base address of GPIO port D on AHB2 bus */
#define BASE_ADDRESS_GPIO_D_D				(BASE_ADDRESS_GPIO_C_D + GPIO_OFFSET_D)
/*Base address of GPIO port E on AHB2 bus */
#define BASE_ADDRESS_GPIO_E_D				(BASE_ADDRESS_GPIO_D_D + GPIO_OFFSET_D)
/*Base address of GPIO port F on AHB2 bus */
#define BASE_ADDRESS_GPIO_F_D				(BASE_ADDRESS_GPIO_E_D + GPIO_OFFSET_D)
/*Base address of GPIO port G on AHB2 bus */
#define BASE_ADDRESS_GPIO_G_D				(BASE_ADDRESS_GPIO_F_D + GPIO_OFFSET_D)
/*Base address of GPIO port H on AHB2 bus */
#define BASE_ADDRESS_GPIO_H_D				(BASE_ADDRESS_GPIO_G_D + GPIO_OFFSET_D)
/*********************************************************************************************/

/******************* Base addresses of APB1 bus domain peripherals **************************/
/* Macro definition of I2C or SPI register offset */
#define I2C_OR_SPI_OFFSET_D						(uint32_t)0x00000400
/* Base address of I2C 1 on APB1 bus */
#define BASE_ADDRESS_I2C_1_D					(uint32_t)0x40005400
/* Base address of I2C 2 on APB1 bus */
#define BASE_ADDRESS_I2C_2_D					(BASE_ADDRESS_I2C_1_D + I2C_OR_SPI_OFFSET_D)
/* Base address of I2C 3 on APB1 bus */
#define BASE_ADDRESS_I2C_3_D					(BASE_ADDRESS_I2C_2_D + I2C_OR_SPI_OFFSET_D)

/* Base address of SPI 2 on APB1 bus	*/
#define BASE_ADDRESS_SPI_2_D					(uint32_t)0x40003800
/* Base address of SPI 3 on APB1 bus	*/
#define BASE_ADDRESS_SPI_3_D					(BASE_ADDRESS_SPI_2_D + I2C_OR_SPI_OFFSET_D)

/* Macro definition of USART or UART register offset */
#define USART_UART_OFFSET_D						(uint32_t)0x00000400
/* Base address of USART 2 on APB1 bus */
#define BASE_ADDRESS_USART_2_D					(uint32_t)0x40004400
/* Base address of USART 3 on APB1 bus */
#define BASE_ADDRESS_USART_3_D					(BASE_ADDRESS_USART_2_D + USART_UART_OFFSET_D)
/* Base address of UART 4 on APB1 bus */
#define BASE_ADDRESS_UART_4_D					(BASE_ADDRESS_USART_3_D + USART_UART_OFFSET_D)
/* Base address of UART 5 on APB1 bus */
#define BASE_ADDRESS_UART_5_D					(BASE_ADDRESS_UART_4_D + USART_UART_OFFSET_D)
/* Base address of LPUART 1 on APB1 bus */
#define BASE_ADDRESS_LPUART_1_D					(uint32_t)0x40008000
/*********************************************************************************************/

/******************* Base addresses of APB2 bus domain peripherals **************************/
/*Base address of EXTI on APB2 bus */
#define BASE_ADDRESS_EXTI_D					(uint32_t)0x40010400
/*Base address of SYSCFG on APB2 bus*/
#define BASE_ADDRESS_SYSCFG_D				(uint32_t)0x40010000
/*Base address of SPI1 on APB2 bus*/
#define BASE_ADDRESS_SPI_1_D				(uint32_t)0x40013000
/*Base address of USART 1 on APB2 bus */
#define BASE_ADDRESS_USART_1_D				(uint32_t)0x40013800
/*********************************************************************************************/

/*************************Peripheral register definition structure****************************/

/* Structure definition for General Purpose Input Output peripheral register */
typedef struct
{
	 __IO uint32_t GPIO_MODR;		/*  GPIO port mode register
										Address offset 0x00
										00: Input mode
										01: General purpose output mode
										10: Alternate function mode
										11: Analog mode (reset state)
										All 32 bits are configurable for each port pin 2 bits are required
										Example - To configure pin 0 as input mode, we need to write bit 0 and 1 of this register as 0x00
									*/

	 __IO uint32_t GPIO_OTYPER;  /* 	GPIO output type register
									   	Address offset 0x04
									   	0: Output push-pull (reset state)
									   	1: Output open-drain
									   	Bit 0 to bit 15 is configurable, bit 16- bit 31 is reserved
									   	Example - To configure port pin 0 as Output open drain we need to write bit 0 of this register as 0x01
									*/
	 __IO uint32_t GPIO_OSPEEDR; /* 	GPIO Output speed register
	 	 	 	 	 	 	 	 	 	Address offset: 0x08
	 	 	 	 	 	 	 	 	 	00: Low speed
										01: Medium speed
										10: High speed
										11: Very high speed
										Note: Refer to the device data sheet for the frequency specifications and the power supply
										and load conditions for each speed(Table 72. I/O AC characteristics - DS10198 Rev 7)
	 	 	 	 	 	 	 	 	 	All 32 bits are configurable for each port pin 2 bits are required
	 	 	 	 	 	 	 	 	*/
	 __IO uint32_t GPIO_PUPDR;	/* 	GPIO pull-up/pull-down register
	 	 	 	 	 	 	 	 	 	Address offset: 0x0C
	 	 	 	 	 	 	 	 	 	00: No pull-up, pull-down
										01: Pull-up
										10: Pull-down
										11: Reserved
										All 32 bits are configurable for each port pin 2 bits are required
	 	 	 	 	 	 	 	 	*/
	 __IO uint32_t GPIO_IDR; 	/*	GPIO Input data register,
										Address offset: 0x10
	 	 	 	 	 	 	 	 	 	These bits are read-only.
	 	 	 	 	 	 	 	 	 	They contain the input value of the corresponding I/O port
	 	 	 	 	 	 	 	 	 	Bits 31:16 Reserved, must be kept at reset value.
									 	Bits 15:0 ID[15:0]: Port x input data
	 	 	 	 	 	 	 	 	*/
	 __IO uint32_t GIPO_ODR;		/*	GPIO Output data register
										Address offset: 0x14
										These bits can be read and written by software.
										Bits 31:16 Reserved, must be kept at reset value.
										Bits 15:0 OD[15:0]: Port output data I/O pin y (y = 15 to 0)
	 	 	 	 	 	 	 	 	*/
	 __IO uint32_t GPIO_BSRR; 	/*	GPIO Bit set or rest register
 	 	 	 	 	 	 	 	 		Address offset: 0x18
 	 	 	 	 	 	 	 	 		Bits 31:16 BR[15:0]: Port x reset I/O pin y (y = 15 to 0)
										These bits are write-only. A read to these bits returns the value 0x0000.
										0: No action on the corresponding ODx bit
										1: Resets the corresponding ODx(output data register) bit
										Note: If both BSx and BRx are set, BSx has priority.
										Bits 15:0 BS[15:0]: Port x set I/O pin y (y = 15 to 0)
										These bits are write-only. A read to these bits returns the value 0x0000.
										0: No action on the corresponding ODx(Output Data register) bit
										1: Sets the corresponding ODx bit

 	 	 	 	 	 	 	 	 	*/
	 __IO uint32_t GPPIO_LCKR; 	/* GPIO lock configuration register
	 	 	 	 	 	 	 	   Address offset: 0x1C

	  	  	  	  	  	  	  	*/
	 __IO uint32_t GPIO_AFR[2]; /* GPIO alternate function register
	 	 	 	 	 	 	 	   Address offset: 0x24
	 	 	 	 	 	 	 	   GPIO_AFR[0] is alternate function low register  - For port x I/O pin y (y = 7 to 0)
	 	 	 	 	 	 	 	   GPIO_AFR[1] is alternate function high register - For port x I/O pin y (y = 15 to 8)
	 	 	 	 	 	 	 	   0000: AF0; 0001: AF1; 0010: AF2;  0011: AF3;  0100: AF4;  0101: AF5;  0110: AF6;  0111: AF7;
	 	 	 	 	 	 	 	   1000: AF8; 1001: AF9; 1010: AF10; 1011: AF11; 1100: AF12; 1101: AF13; 1110: AF14; 1111: AF15;
	  	  	  	  	  	  	  	*/
	 __IO uint32_t GPIO_BRR;	/* GPIO bit rest register - Used to clear the corresponding output data register
	 	 	 	 	 	 	 	   Address offset: 0x28
	 	 	 	 	 	 	 	   Bits 31:16 Reserved, must be kept at reset value.
	 	 	 	 	 	 	 	   Bits 15:0 BR[15:0]: Port x reset IO pin y (y = 15 to 0)
	 	 	 	 	 	 	 	   These bits are write-only. A read to these bits returns the value 0x0000.
	 	 	 	 	 	 	 	   0: No action on the corresponding ODx bit
	 	 	 	 	 	 	 	   1: Reset the corresponding ODx bit
	  	  	  	  	  	  	  	*/
}GPIO_RegDef_t;

/* Structure definition for reset and clock control(RCC) registers*/
typedef struct
{
	__IO uint32_t RCC_CR;				/* 	Clock control register
											Address offset: 0x00
											Refer Reference manual - Section 6.4.1
								  	  	  	TODO: Add Reference manual Link
										*/
	__IO uint32_t RCC_ICSCR;			/* 	Internal clock sources calibration register
											Address offset: 0x04
										*/
	__IO uint32_t RCC_CFGR;				/* 	Clock configuration register
								   			Address offset: 0x08
										*/
	__IO uint32_t RCC_PLLCFGR;			/* 	PLL configuration register
								   	   	   	Address offset: 0x0C
	 	 	 	 	 	 	 	 	 	*/
	__IO uint32_t RCC_PLLSAI1CFGR;		/* 	PLLSAI1 configuration register
								   	   	   	Address offset: 0x10
										*/
	__IO uint32_t RCC_PLLSAI2CFGR; 		/* 	PLLSAI2 configuration register
								   	   	   	Address offset: 0x14
										*/
	__IO uint32_t RCC_CIER;				/* 	Clock interrupt enable register
								   	   	   	Address offset: 0x18
										*/
	__IO uint32_t RCC_CIFR; 			/* 	Clock interrupt flag register
								   	   	    Address offset: 0x1C
										*/
	__IO uint32_t RCC_CICR;				/* 	Clock interrupt clear register
										    Address offset: 0x20
										*/
	uint32_t Reserved0; 				/* 	4 bytes Reserved*/

	__IO uint32_t RCC_AHB1RSTR; 		/* 	AHB1 peripheral reset register
										    Address offset: 0x28
										*/
	__IO uint32_t RCC_AHB2RSTR; 		/* AHB2 peripheral reset register
										   Address offset: 0x2C
										*/
	__IO uint32_t RCC_AHB3RSTR;			/* AHB3 peripheral reset register
										   Address offset: 0x30
										*/
	uint32_t Reserved1;					/* 4 bytes Reserved */
	__IO uint32_t RCC_APB1RSTR1;        /* APB1 peripheral reset register 1
										  Address offset: 0x38
										*/
	__IO uint32_t RCC_APB1RSTR2; 		/* APB1 peripheral reset register 2
	    								   Address offset: 0x3C
										*/
	__IO uint32_t RCC_APB2RSTR;			/* APB2 peripheral reset register
										   Address offset: 0x40
										*/
	uint32_t Reserved2;					/* 4 Bytes Reserved */
	__IO uint32_t RCC_AHB1ENR; 			/*  AHB1 peripheral clock enable register
											Address offset: 0x48
										*/
	__IO uint32_t RCC_AHB2ENR; 			/* AHB2 peripheral clock enable register
										   Address offset: 0x4C
										*/
	__IO uint32_t RCC_AHB3ENR;  		/* AHB3 peripheral clock enable register
										   Address offset: 0x50
										*/
	uint32_t Reserved3;					/* Reserved 4 bytes */
	__IO uint32_t RCC_APB1ENR1; 		/* APB1 peripheral clock enable register 1
										   Address offset: 0x58
										*/
	__IO uint32_t RCC_APB1ENR2; 		/* APB1 peripheral clock enable register 2
										   Address offset: 0x5C
										*/
	__IO uint32_t RCC_APB2ENR; 			/* APB2 peripheral clock enable register
										   Address offset: 0x60
										*/
	uint32_t Reserved4; 				/* 4 bytes reserved */
	__IO uint32_t RCC_AHB1SMENR; 		/* AHB1 peripheral clocks enable in Sleep and Stop modes register
										   Address offset: 0x68
										*/
	__IO uint32_t RCC_AHB2SMENR; 		/* AHB2 peripheral clocks enable in Sleep and Stop modes register
										   Address offset: 6C
										*/
	__IO uint32_t RCC_AHB3SMENR; 		/* AHB3 peripheral clocks enable in Sleep and Stop modes register
										   Address offset: 0x70
										*/
	uint32_t Reserved5; 				/* 4 bytes reserved */
	__IO uint32_t RCC_APB1SMENR1; 		/* APB1 peripheral clocks enable in Sleep and Stop modes register 1
										   Address: 0x78
										*/
	__IO uint32_t RCC_APB1SMENR2; 		/* APB1 peripheral clocks enable in Sleep and Stop modes register 2
										   Address offset: 0x7C
										*/
	__IO uint32_t RCC_APB2SMENR; 		/* APB2 peripheral clocks enable in Sleep and Stop modes register
										   Address offset: 0x80
										*/
	uint32_t Reserved6;					/* Reserved 4 bytes */
	__IO uint32_t RCC_CCIPR; 			/* Peripherals independent clock configuration register
										   Address offset: 0x88
										*/
	__IO uint32_t RCC_BDCR; 			/* Backup domain control register
										   Address offset: 0x90
										*/
	__IO uint32_t RCC_CSR; 				/* Control/status register
										   Address offset: 0x94
										*/
}RCC_RegDef_t;
/****************************End of Peripheral register definition structure*****************************************************************/

/*
 * Peripheral definition (Peripheral base address type casted to xxx_RegDef_t)
 */
/* Peripheral definition for GPIOs */
#define GPIOA_D = (GPIO_RegDef_t*)BASE_ADDRESS_GPIO_A_D
#define GPIOB_D = (GPIO_RegDef_t*)BASE_ADDRESS_GPIO_B_D
#define GPIOC_D = (GPIO_RegDef_t*)BASE_ADDRESS_GPIO_C_D
#define GPIOD_D = (GPIO_RegDef_t*)BASE_ADDRESS_GPIO_D_D
#define GPIOE_D = (GPIO_RegDef_t*)BASE_ADDRESS_GPIO_E_D
#define GPIOF_D = (GPIO_RegDef_t*)BASE_ADDRESS_GPIO_F_D
#define GPIOG_D = (GPIO_RegDef_t*)BASE_ADDRESS_GPIO_G_D
#define GPIOH_D = (GPIO_RegDef_t*)BASE_ADDRESS_GPIO_H_D

/*Peripheral definition for Reset and clock control(RCC) register*/
#define RCC_D = (RCC_RegDef_t*)BASE_ADDRESS_RCC_D;

/************************************************** Macros to enable clocks for peripherals ***************************************************/
/* Enable clock for GPIOA */
#define ENABLE_GPIOA_PERI_D()					( RCC->RCC_AHB2ENR |= (1 << 0) )
/* Enable clock for GPIOB */
#define ENABLE_GPIOB_PERI_D()					( RCC->RCC_AHB2ENR |= (1 << 1) )
/* Enable clock for GPIOC */
#define ENABLE_GPIOC_PERI_D()					( RCC->RCC_AHB2ENR |= (1 << 2) )
/* Enable clock for GPIOD */
#define ENABLE_GPIOD_PERI_D()					( RCC->RCC_AHB2ENR |= (1 << 3) )
/* Enable clock for GPIOE */
#define ENABLE_GPIOE_PERI_D()					( RCC->RCC_AHB2ENR |= (1 << 4) )
/* Enable clock for GPIOF */
#define ENABLE_GPIOF_PERI_D()					( RCC->RCC_AHB2ENR |= (1 << 5) )
/* Enable clock for GPIOG */
#define ENABLE_GPIOG_PERI_D()					( RCC->RCC_AHB2ENR |= (1 << 6) )
/* Enable clock for GPIOH */
#define ENABLE_GPIOH_PERI_D()					( RCC->RCC_AHB2ENR |= (1 << 7) )

/* Enable clock for I2C 1*/
#define ENABLE_I2C1_PERI_D()					( RCC->RCC_APB1ENR1 |= (1 << 21) )
/* Enable clock for I2C 2*/
#define ENABLE_I2C2_PERI_D()					( RCC->RCC_APB1ENR1 |= (1 << 22) )
/* Enable clock for I2C 3*/
#define ENABLE_I2C3_PERI_D()					( RCC->RCC_APB1ENR1 |= (1 << 23) )

/* Enable clock for SPI 1*/
#define ENABLE_SPI1_PERI_D() 					( RCC->RCC_APB2ENR |= (1 << 12) )
/* Enable clock for SPI 2*/
#define ENABLE_SPI2_PERI_D() 					( RCC->RCC_APB1ENR1 |= (1 << 14) )
/* Enable clock for SPI 3*/
#define ENABLE_SPI3_PERI_D() 					( RCC->RCC_APB1ENR1 |= (1 << 15) )

/* Enable clock for USART 1*/
#define ENABLE_USART1_PERI_D() 					( RCC->RCC_APB2ENR |= (1 << 14) )
/* Enable clock for LPUART 1*/
#define ENABLE_LPUART1_PERI_D()					( RCC->RCC_APB1ENR2)|= (1 << 0) )
/* Enable clock for USART 2*/
#define ENABLE_USART2_PERI_D() 					( RCC->RCC_APB1ENR1 |= (1 << 17) )
/* Enable clock for USART 3*/
#define ENABLE_USART3_PERI_D() 					( RCC->RCC_APB1ENR1 |= (1 << 18) )
/* Enable clock for UART 4*/
#define ENABLE_UART2_PERI_D() 					( RCC->RCC_APB1ENR1 |= (1 << 19) )
/* Enable clock for USART 5*/
#define ENABLE_UART5_PERI_D() 					( RCC->RCC_APB1ENR1 |= (1 << 20) )

/* Enable clock for EXTI */
/* TODO: Add Macro*/
/* Enable clock for SYSCFG */
#define ENABLE_SYSCFG_PERI_D() 					( RCC->RCC_APB2ENR |= (1 << 0) )
/*********************************************************************************************************************************************/

/************************************************** Macros to disable clocks for peripherals *************************************************/
/* Disable clock for GPIOA */
#define DISABLE_GPIOA_PERI_D()					( RCC->RCC_AHB2ENR &= ~(1 << 0) )
/* Disable clock for GPIOB */
#define DISABLE_GPIOB_PERI_D()					( RCC->RCC_AHB2ENR &= ~(1 << 1) )
/* Disable clock for GPIOC */
#define DISABLE_GPIOC_PERI_D()					( RCC->RCC_AHB2ENR &= ~(1 << 2) )
/* Disable clock for GPIOD */
#define DISABLE_GPIOD_PERI_D()					( RCC->RCC_AHB2ENR &= ~(1 << 3) )
/* Disable clock for GPIOE */
#define DISABLE_GPIOE_PERI_D()					( RCC->RCC_AHB2ENR &= ~(1 << 4) )
/* Disable clock for GPIOF */
#define DISABLE_GPIOF_PERI_D()					( RCC->RCC_AHB2ENR &= ~(1 << 5) )
/* Disable clock for GPIOG */
#define DISABLE_GPIOG_PERI_D()					( RCC->RCC_AHB2ENR &= ~(1 << 6) )
/* Disable clock for GPIOH */
#define DISABLE_GPIOH_PERI_D()					( RCC->RCC_AHB2ENR &= ~(1 << 7) )

/* Disable clock for I2C 1*/
#define DISABLE_I2C1_PERI_D()					( RCC->RCC_APB1ENR1 &= ~(1 << 21) )
/* Disable clock for I2C 2*/
#define DISABLE_I2C2_PERI_D()					( RCC->RCC_APB1ENR1 &= ~(1 << 22) )
/* Disable clock for I2C 3*/
#define DISABLE_I2C3_PERI_D()					( RCC->RCC_APB1ENR1 &= ~(1 << 23) )

/* Disable clock for SPI 1*/
#define DISABLE_SPI1_PERI_D() 					( RCC->RCC_APB2ENR &= ~(1 << 12) )
/* Disable clock for SPI 2*/
#define DISABLE_SPI2_PERI_D() 					( RCC->RCC_APB1ENR1 &= ~(1 << 14) )
/* Disable clock for SPI 3*/
#define DISABLE_SPI3_PERI_D() 					( RCC->RCC_APB1ENR1 &= ~(1 << 15) )

/* Disable clock for USART 1*/
#define DISABLE_USART1_PERI_D() 				( RCC->RCC_APB2ENR &= ~(1 << 14) )
/* Disable clock for LPUART 1*/
#define DISABLE_LPUART1_PERI_D()				( RCC->RCC_APB1ENR2)&= ~(1 << 0) )
/* Disable clock for USART 2*/
#define DISABLE_USART2_PERI_D() 				( RCC->RCC_APB1ENR1 &= ~(1 << 17) )
/* Disable clock for USART 3*/
#define DISABLE_USART3_PERI_D() 				( RCC->RCC_APB1ENR1 &= ~(1 << 18) )
/* Disable clock for UART 4*/
#define DISABLE_UART2_PERI_D() 					( RCC->RCC_APB1ENR1 &= ~(1 << 19) )
/* Disable clock for USART 5*/
#define DISABLE_UART5_PERI_D() 					( RCC->RCC_APB1ENR1 &= ~(1 << 20) )

/* Disable clock for EXTI */
/* TODO: Add Macro*/
/* Disable clock for SYSCFG */
#define DISABLE_SYSCFG_PERI_D() 				( RCC->RCC_APB2ENR &= ~(1 << 0) )

#endif /* DRIVERS_INCLUDES_STM32L476XX_H_ */
