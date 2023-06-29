#include "led.h"
#include "rcc.h"
#include "gpio.h"
#include"stm32f4xx.h"

void user_led_init()
{
	/* Enable clock for port G */
	set_ahb1_periph_clock(RCC_AHB1ENR_GPIOGEN);

	/* Configure led pins as outputs */
	set_pin_mode(GPIOG, (1<<LED1), GPIO_OUTPUT_MODE);
	set_pin_mode(GPIOG, (1<<LED2), GPIO_OUTPUT_MODE);
}

void led_on(uint32_t led)
{
	GPIOG->BSRR = (1<<led);
}

void led_off(uint32_t led)
{
	GPIOG->BSRR = (1<<(led + 16));
}

void led_toggle(uint32_t led)
{
	GPIOG->ODR ^= (1<<led);
}
