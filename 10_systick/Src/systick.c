#include "systick.h"
#include "stm32f4xx.h"

void SysTick_DelayMS(uint32_t delay)
{
	/* Reload the number of clocks per millisecond */
	SysTick->LOAD = 16000; //(16000/16000000 = 0.001s)

	/* Clear the Current Value register */
	SysTick->VAL = 0;

	/* Select clock source and enable SysTick */
	SET_BIT(SysTick->CTRL, SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk);

	/* Wait 'delay' times for SysTick overflow */
	for(uint32_t i = 0; i<delay; i++)
		while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));

	/* Disable SysTick */
	CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_ENABLE_Msk);
}
