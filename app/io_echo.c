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

#include <platform/platform.h>
#include <platform/printf.h>
#include <platform/uart.h>
#include <stddef.h>
#include <stdint.h>

int main(void) {
    platform_init(PLATFORM_CLOCK_MAX);
    platform_sync();
    size_t i = 0;
    char c;

    printf("Type something:\n");

    while (1) {
        c = uart_getc(uart_get_port());
        printf("GOT: ");
        uart_putc(uart_get_port(), c);
        printf("\n");
        if (c == 'q') {
            break;
        }
    }
    uart_clear(uart_get_port());
    return 0;
}
