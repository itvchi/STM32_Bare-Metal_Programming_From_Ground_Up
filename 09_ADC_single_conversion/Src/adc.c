#include "adc.h"
#include "rcc.h"
#include "gpio.h"
#include "stm32f4xx.h"

/* ADCIN8 pin is at PB0 - alternate function  */
#define ADC_CH						8
#define ADCIN8_PIN					(1U<<0)

void adc1_init()
{
	/* Enable clock for analog input pin port */
	set_ahb1_periph_clock(RCC_AHB1ENR_GPIOBEN);

	/* Configure analog input pin mode */
	set_pin_mode(GPIOB, ADCIN8_PIN, GPIO_ANALOG_MODE);

	/* Enable clock for ADC module */
	set_apb2_periph_clock(RCC_APB2ENR_ADC1EN);

	/* Configure ADC module - single conversion mode */
	CLEAR_BIT(ADC1->CR2, ADC_CR2_CONT);

	/* Configure sequencer length to 1 - SQR1_L = 0 */
	CLEAR_BIT(ADC1->SQR1, ADC_SQR1_L_Msk);

	/* Set ADC channel in sequencer */
	MODIFY_REG(ADC1->SQR3, ADC_SQR3_SQ1, ADC_CH<<ADC_SQR3_SQ1_Pos);

	/* Enable ADC module */
	SET_BIT(ADC1->CR2, ADC_CR2_ADON);
}

void adc_start_conversion()
{
	/* Start conversion */
		SET_BIT(ADC1->CR2, ADC_CR2_SWSTART);
}

uint32_t adc_get_data()
{
	/* Wait for end of conversion flag */
	while(!(ADC1->SR & ADC_SR_EOC_Msk));

	/* Read result - 12 bit default */
	return (ADC1->DR & 0xFFF);
}
