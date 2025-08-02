/*
 * Copyright (C) Kris Kwiatkowski, Among Bytes LTD
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#include "uart.h"

#include <stdbool.h>

#include "CMSDK_CM4.h"
#include "core_cm4.h"
#include "lib.h"
#include "uart.h"

// Global UART object
struct uart_t k_uart;

void uart_init(struct uart_t *obj) {
    // We use UART_0 only
    obj->index = 0;
    obj->uart  = (CMSDK_UART_TypeDef *)CMSDK_UART0;

    obj->uart->CTRL = 0x00;  // Disable UART when changing configuration
    obj->uart->CTRL |= 1 << CMSDK_UART_CTRL_RXEN_Pos;  // RX enable
    obj->uart->CTRL |= 1 << CMSDK_UART_CTRL_TXEN_Pos;  // TX enable

    // Set the GPIO pins for UART
    CMSDK_GPIO0->ALTFUNCSET |= 1u;
    CMSDK_GPIO0->ALTFUNCSET |= 2u;

    // set default baud rate and format
    (void)uart_set_baud(obj, 115200UL);
}

struct uart_t *uart_get_port(void) { return &k_uart; }

bool uart_set_baud(struct uart_t *obj, unsigned long baudrate) {
    /*
    * The MPS2 has a simple divider to control the baud rate.
    * The formula is:
    * Baudrate = PCLK / Baud Rate
    * Example:
    *   PCLK = 25 Mhz, baud rate = 9600
    *   so for a desired baud rate : 25000000 / 9600 = 2604
    */
    int b = MPS2_SYSTEM_CLOCK / baudrate;

    if (b >= 16) {
        // Check minimum baud rate
        return false;
    }

    obj->uart->BAUDDIV = b;
    return true;
}

void uart_putc(struct uart_t *obj, int c) {
    while (!uart_is_writable(obj)) {
        // Wait until the transmit buffer is not full
    }
    obj->uart->DATA = (int)c & 0xFFu;
}

char uart_getc(struct uart_t *obj) {
    while (!uart_is_readable(obj)) {
        // Wait until the receive buffer is not empty
    }
    return (obj->uart->DATA & 0xFFu);
}

bool uart_is_readable(struct uart_t *obj) {
    /* CMSDK_UART_STATE_RXBF_Msk is set when RXBF buffer is full. The
     * buffer size in our case is equal to 1 byte */
    return (obj->uart->STATE & CMSDK_UART_STATE_RXBF_Msk) != 0;
}

bool uart_is_writable(struct uart_t *obj) {
    /* CMSDK_UART_STATE_TXBF_Msk is set when TXBF buffer is empty. We only
     * write to the buffer when it is empty. */
    return (obj->uart->STATE & CMSDK_UART_STATE_TXBF_Msk) == 0;
}

void uart_clear(struct uart_t *obj) {
    // Clear the TX buffer
    while (!uart_is_writable(obj)) {
        // Wait until the transmit buffer is empty
    }
    obj->uart->DATA = 0;  // Clear the TX buffer
}
