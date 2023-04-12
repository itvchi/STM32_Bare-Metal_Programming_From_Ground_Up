#ifndef UART_H_
#define UART_H_

#include "stm32f4xx.h"
#include <stdint.h>

void uart_write(USART_TypeDef *USARTx, uint8_t data);
void usart1_tx_init();

#endif /* UART_H_ */
