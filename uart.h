#ifndef UART_H
#define UART_H

#include "pico/stdlib.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    uart_inst_t *uart;
    uint baudrate;
    uint tx_pin;
    uint rx_pin;
} UART_t;

UART_t init_uart(uart_inst_t *uart, int baudrate, int gpio_tx, int gpio_rx);
void print(uart_inst_t *uart, const char *format, ...);


#endif