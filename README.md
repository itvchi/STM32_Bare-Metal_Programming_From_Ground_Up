Examples from course STM32 Bare-Metal Programming From Ground Up
Tested on STM32F429 Discovery board

Content list:
1. GPIO module
    01_gpio - PG13 and PG14 led toggle using ODR register
    02_gpio_bsrr - PG13 and PG14 led toggle using BSRR register
    03_gpio_input - led toggle speed based on PA0 button state

2. USART module
    04_uart_tx - data transmit in polling mode
    05_uart_printf - transmit data using pintf function over UART
    06_uart_modular - divided project into submodules
    07_uart_rx - data receive and transmit in poling mode with received char interpreting (change state of leds)

3. ADC module
    08_ADC_continuous_conversion - one channel continuous conversion mode
    09_ADC_single_conversion - one channel single conversion mode (polling)