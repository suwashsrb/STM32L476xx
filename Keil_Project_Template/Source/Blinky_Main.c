
#include "stm32l476.h"

void delay(unsigned dly)
{
    while(dly--);
}
int main()
{
    // Turn on GPIOB and GPIOE
    RCC_AHB2ENR |= BIT1 + BIT4;
    GPIOB_MODER |= BIT4;
    GPIOB_MODER &= ~BIT5;
    GPIOE_MODER |= BIT16;
    GPIOE_MODER &= ~BIT17;
    while(1)
    {
        GPIOB_ODR |= BIT2;  // Turn on red led
        GPIOE_ODR &= ~BIT8; // Turn off green led
        delay(200000);
        GPIOB_ODR &= ~BIT2; // Turn off red led
        GPIOE_ODR |= BIT8;  // Turn on green led
        delay(200000);
    }

}
