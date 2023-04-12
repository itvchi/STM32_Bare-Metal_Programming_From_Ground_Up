#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

void adc1_init();
void adc_start_conversion();
uint32_t adc_get_data();

#endif /* ADC_H_ */
