#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f4xx.h"
#include <stdint.h>

void set_pin_mode(GPIO_TypeDef *GPIOx, uint32_t pin, uint32_t mode);

#endif /* GPIO_H_ */
