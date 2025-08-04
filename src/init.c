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
#include "uart.h"

void SysTick_Handler(void);

/// ############################
/// Internal implementation
/// ############################

static void setup_fpu(void) {
#if defined(MPS2_ENABLE_FPU)
    // Enable the FPU
    SCB->CPACR |= ((3UL << 10 * 2) | /* set CP10 Full Access */
                   (3UL << 11 * 2)); /* set CP11 Full Access */
#endif
}

volatile unsigned long long stm32_sys_tick_overflowcnt = 0;

static void systick_setup(void) {
    // Enable SysTick Timer
    SysTick->LOAD = 0xFFFFFFu;
    NVIC_SetPriority(SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL);
    NVIC_EnableIRQ(SysTick_IRQn);
    SysTick->VAL  = 0UL;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;
}

/******************************************************************************
 *
 * CPU cycle count
 *
 *****************************************************************************/

// Used for counting cycles
void SysTick_Handler(void) { ++stm32_sys_tick_overflowcnt; }
static inline uint64_t systick_get_value(void) { return SysTick->VAL; }

/******************************************************************************
 *
 * I/O
 *
 *****************************************************************************/
void _putchar(char character) { uart_putc(uart_get_port(), character); }

static volatile unsigned long long overflowcnt = 0;

/// ############################
/// External API
/// ############################

int platform_init(platform_op_mode_t a) {
    (void)a;
    setup_fpu();
    uart_init(uart_get_port());
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

/* End of BSS is where the heap starts (defined in the linker script) */
extern char end;
static char* heap_end = &end;

uint64_t platform_mps2_stack_size(void) {
    register char* cur_stack;
    __asm__ volatile("mov %0, sp" : "=r"(cur_stack));
    return cur_stack - heap_end;
}

int platform_io_is_readable(void) { return uart_is_readable(uart_get_port()); }

int platform_io_is_writable(void) { return uart_is_writable(uart_get_port()); }

int platform_io_write(const char* buf, int len) {
    int i, w;
    if (len <= 0) {
        return 0;  // Nothing to write
    }

    for (w = 0, i = 0; i < len; ++i) {
        uart_putc(uart_get_port(), buf[i]);
        ++w;
    }

    return w;
}

int platform_io_read(char* buf, int len) {
    int i, r;

    if (len <= 0) {
        return 0;  // Nothing to read
    }

    for (r = 0, i = 0; i < len; ++i) {
        buf[i] = uart_getc(uart_get_port());
        ++r;
    }
    return r;
}
