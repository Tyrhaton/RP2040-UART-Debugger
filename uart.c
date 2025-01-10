#include "uart.h"

UART_t init_uart(uart_inst_t *uart, int baudrate, int gpio_tx, int gpio_rx)
{
    int actual_baudrate = uart_init(uart, baudrate);
    gpio_set_function(gpio_tx, GPIO_FUNC_UART);
    gpio_set_function(gpio_rx, GPIO_FUNC_UART);
    UART_t uart_t = {uart, actual_baudrate, gpio_tx, gpio_rx};

    return uart_t;
}

void print(uart_inst_t *uart, const char *format, ...) {
    va_list args;

    va_start(args, format);
    int required_size = vsnprintf(NULL, 0, format, args);
    va_end(args);

    if (required_size < 0) {
        perror("Formatting error during size calculation");
        return;
    }

    size_t buffer_size = (size_t)required_size + 1; 
    char *buffer = (char *)malloc(buffer_size);
    if (!buffer) {
        perror("Failed to allocate buffer");
        return;
    }

    va_start(args, format);
    vsnprintf(buffer, buffer_size, format, args);
    va_end(args);

    uart_puts(uart, buffer);
    printf("%s", buffer);

    free(buffer);
}
