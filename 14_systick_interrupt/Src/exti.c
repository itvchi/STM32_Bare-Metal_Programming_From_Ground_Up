#include "exti.h"
#include "stm32f4xx.h"
#include "rcc.h"
#include "gpio.h"

void pushButton_init()
{
	/* Enable clock for GPIOA */
	set_ahb1_periph_clock(RCC_AHB1ENR_GPIOAEN);

	/* Configure PA0 as input */
	set_pin_mode(GPIOA, (1<<BTN), GPIO_INPUT_MODE);

	/* Enable clock for SYSCFG module */
	set_apb2_periph_clock(RCC_APB2ENR_SYSCFGEN);

	/* Clear port selection for EXTI0 - register is cleared at reset */
	/* Select PORTA for EXTI0 */
	SET_BIT(SYSCFG->EXTICR[0], SYSCFG_EXTICR1_EXTI0_PA);

	/* Unmask EXTI0 */
	SET_BIT(EXTI->IMR, EXTI_IMR_IM0);

	/* Select rising edge trigger */
	SET_BIT(EXTI->FTSR, EXTI_FTSR_TR0);

	/* Enable EXTI0 in NVIC */
	NVIC_EnableIRQ(EXTI0_IRQn);
}

