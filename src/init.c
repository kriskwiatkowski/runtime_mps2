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

// Set clock to 25MHz (default on MPS2)
#ifndef MPS2_SYSTEM_CLOCK
#define MPS2_SYSTEM_CLOCK 25000000UL
#endif

/// ############################
/// Internal implementation
/// ############################

static void setup_fpu(void) {
    // Enable the FPU
    SCB->CPACR |= ((3UL << 10 * 2) | /* set CP10 Full Access */
                   (3UL << 11 * 2)); /* set CP11 Full Access */
}

volatile unsigned long long stm32_sys_tick_overflowcnt = 0;

static void usart_setup(unsigned long baud) {
    // Enable UART
    CMSDK_GPIO0->ALTFUNCSET |= 1u;
    CMSDK_GPIO0->ALTFUNCSET |= 2u;
    CMSDK_UART0->BAUDDIV    = MPS2_SYSTEM_CLOCK / baud;
    CMSDK_UART0->CTRL       |= 1 << CMSDK_UART_CTRL_RXEN_Pos;
    CMSDK_UART0->CTRL       |= 1 << CMSDK_UART_CTRL_TXEN_Pos;
}

static void systick_setup(void) {
    // Enable SysTick Timer
    SysTick->LOAD = 0xFFFFFFu;
    NVIC_SetPriority(SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL);
    NVIC_EnableIRQ(SysTick_IRQn);
    SysTick->VAL  = 0UL;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;
}

static void setup_rng(void) {}

/******************************************************************************
 *
 * CPU cycle count
 *
 *****************************************************************************/

// Used for counting cycles
void systick_handler(void) { ++stm32_sys_tick_overflowcnt; }
static inline uint64_t systick_get_value(void) { return SysTick->VAL; }

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
    (void)a;
    setup_fpu();
    usart_setup(115200UL);
    systick_setup();
    // wait for the first systick overflow
    // improves reliability of the benchmarking scripts since it makes it much
    // less likely that the host will miss the start of the output
    return 0;
}

void platform_set_attr(const struct platform_attr_t* a) {
    // We don't support switching frequency. This is suppose to be used
    // for unit-testing, not benchmarking.
    (void)a;
}

uint64_t platform_cpu_cyclecount(void) {
    while (1) {
        unsigned long long before = stm32_sys_tick_overflowcnt;
        unsigned long long result =
            (before + 1) * 16777216llu - systick_get_value();
        if (stm32_sys_tick_overflowcnt == before) {
            return result;
        }
    }
}

void platform_sync(void) {
    // wait for the first systick overflow
    unsigned long long old = stm32_sys_tick_overflowcnt;
    while (old == stm32_sys_tick_overflowcnt) {};
}
