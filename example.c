#include "uart.h"

#define UART_ID uart1
#define Baudrate 115200
#define TX 4
#define RX 5

int main()
{
    stdio_init_all();
    init_uart(UART_ID, Baudrate, TX, RX);

    int i = 0;
    while (1)
    {
        print(uart1, "Hello, world! %d\n\r", i);
        i++;
        sleep_ms(1000);
    }

    return 0;
}
