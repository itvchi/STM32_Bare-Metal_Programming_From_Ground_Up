/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f4xx.h"
#include <stdio.h>
#include "led.h"
#include "timer.h"
#include "exti.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/* Include CMSIS first */
/* Define MCU */

void EXTI0_IRQHandler()
{
	/* Clear pending interrupt, by setting its bit ro 1 */
	SET_BIT(EXTI->PR, EXTI_PR_PR0);

	led_toggle(LED2);
}

void TIM1_UP_TIM10_IRQHandler()
{
	/* Check if interrupt is pending */
	if(TIM1->SR & TIM_SR_UIF)
	{
		/* Clear update interrupt flag */
		CLEAR_BIT(TIM1->SR, TIM_SR_UIF);

		/* Do something */
		led_toggle(LED1);
	}
}

int main(void)
{
	user_led_init();
	timer1_1hz_interrupt_init();
	pushButton_init();

    /* Loop forever */
	for(;;)
	{
	}
}
