#include "timer.h"
#include "stm32f4xx.h"
#include "rcc.h"

void timer1_1hz_init()
{
	/* Enable clock for TIM1 */
	set_apb2_periph_clock(RCC_APB2ENR_TIM1EN);

	/* Set the prescaler */
	TIM1->PSC = 1600-1; //divide clock by 1600 (timer clock is now 10kHz)

	/* Set the auto-reload value */
	TIM1->ARR = 10000-1; //timer counts 10k values -> Update Event every 10kHz/10000 = 1Hz
}

void timer1_delay()
{
	/* Enable timer */
	TIM1->CR1 = TIM_CR1_CEN;

	/* Wait for Update Event flag is set */
	while(!(TIM1->SR & TIM_SR_UIF));

	/* Clear UIF flag */
	CLEAR_BIT(TIM1->SR, TIM_SR_UIF);
}
