#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

void adc1_init();
void adc1_interrupt_init();
uint32_t adc_get_data();

#endif /* ADC_H_ */
