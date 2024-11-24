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
#include <stddef.h>

#include "CMSDK_CM4.h"

/// ############################
/// Internal implementation
/// ############################

volatile unsigned long long stm32_sys_tick_overflowcnt = 0;

static void usart_setup(int baud) {}

static void systick_setup(void) {}

static void set_clock(platform_op_mode_t a) {}

static void setup_rng(void) {}

/******************************************************************************
 *
 * I/O
 *
 *****************************************************************************/
void _putchar(char character) {
    do {
    } while (CMSDK_UART0->STATE & CMSDK_UART_STATE_TXBF_Msk);
    CMSDK_UART0->DATA = (int)character & 0xFFu;
}

static volatile unsigned long long overflowcnt = 0;

/// ############################
/// External API
/// ############################

int platform_init(platform_op_mode_t a) {
    // wait for the first systick overflow
    // improves reliability of the benchmarking scripts since it makes it much
    // less likely that the host will miss the start of the output
    return 0;
}

void platform_set_attr(const struct platform_attr_t* a) {
    // We don't support switching frequency. This is suppose to be used
    // for unit-testing, not benchmarking.
    (void)a;
    set_clock(PLATFORM_CLOCK_MAX);
}

uint64_t platform_cpu_cyclecount(void) {
#if 0
    while (true) {
        unsigned long long before = stm32_sys_tick_overflowcnt;
        unsigned long long result =
            (before + 1) * 16777216llu - systick_get_value();
        if (stm32_sys_tick_overflowcnt == before) {
            return result;
        }
    }
#endif
    return 0;
}
