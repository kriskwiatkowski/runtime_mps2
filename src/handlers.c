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
 *
 */

#include <errno.h>
#include <platform/platform.h>
#include <platform/printf.h>
#include <stddef.h>

#include "CMSDK_CM4.h"

// Set clock to 25MHz (default on MPS2)
#ifndef MPS2_SYSTEM_CLOCK
#define MPS2_SYSTEM_CLOCK 25000000UL
#endif

#ifdef MPS2_BAUD
#undef MPS2_BAUD
#endif
#define MPS2_BAUD 38400UL

/******************************************************************************
 *
 * Platform initialization.
 *
 *****************************************************************************/
void SystemInit(void);

void SystemInit(void) {
    // Enable the FPU
    SCB->CPACR |= ((3UL << 10 * 2) | /* set CP10 Full Access */
                   (3UL << 11 * 2)); /* set CP11 Full Access */

    // Enable UART
    CMSDK_GPIO0->ALTFUNCSET |= 1u;
    CMSDK_GPIO0->ALTFUNCSET |= 2u;
    CMSDK_UART0->BAUDDIV    = MPS2_SYSTEM_CLOCK / MPS2_BAUD;
    CMSDK_UART0->CTRL       |= 1 << CMSDK_UART_CTRL_RXEN_Pos;
    CMSDK_UART0->CTRL       |= 1 << CMSDK_UART_CTRL_TXEN_Pos;

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
 * Handlers for semiconfig (for running in QEMU)
 *
 *****************************************************************************/
#if !defined(NO_SEMIHOSTING_EXIT)
/* Semihosting is a mechanism for ARM targets to communicate input/output
 * requests from application code to a host computer running a debugger.
 * This mechanism could be used, for example, to allow functions in the C
 * library, such as printf() and scanf(), to use the screen and keyboard
 * of the host rather than having a screen and keyboard on the target system.
 *
 * For more details see DUI0058.pdf, chapter 5.
 *
 * Coppied from
 * https://github.com/rust-embedded/cortex-m-semihosting/blob/e776ba5cec80088c8eda4f38fe20be2b32797414/src/debug.rs#L29
 */
enum {
    kBranchThroughZero   = 0x20000,
    kUndefinedInstr      = 0x20001,
    kSoftwareInterrupt   = 0x20002,
    kPrefetchAbort       = 0x20003,
    kDataAbort           = 0x20004,
    kAddressException    = 0x20005,
    kIRQ                 = 0x20006,
    kFIQ                 = 0x20007,
    kBreakPoint          = 0x20020,
    kWatchPoint          = 0x20021,
    kStepComplete        = 0x20022,
    kRunTimeErrorUnknown = 0x20023,
    kInternalError       = 0x20024,
    kUserInterruption    = 0x20025,
    kApplicationExit     = 0x20026,
    kStackOverflow       = 0x20027,
    kDivisionByZero      = 0x20028,
    kOSSpecific          = 0x20029,
};
// Do a system call towards QEMU or the debugger.
static uint32_t semihosting_syscall(const uint32_t arg) {
    uint32_t nr = 0x18;  // Exeption reporting
    __asm__ volatile(
        "mov r0, %[nr]\n"
        "mov r1, %[arg]\n"
        "bkpt 0xAB\n"
        "mov %[nr], r0\n"
        : [nr] "+r"(nr)
        : [arg] "r"(arg)
        : "0", "1");
    return nr;
}

// Signals to QEMU program exit.
static void __attribute__((destructor)) semihosting_exit(void) {
    semihosting_syscall(kApplicationExit);
}

// Declare functions to avoid reporting errors caused by "-Wmissing-prototypes"
extern void NMI_Handler(void);
extern void HardFault_Handler(void);
extern void MemManage_Handler(void);
extern void BusFault_Handler(void);
extern void UsageFault_Handler(void);
extern void SVC_Handler(void);
extern void DebugMon_Handler(void);
extern void PendSV_Handler(void);
extern void Default_Handler(void);

void NMI_Handler(void) {
    printf("NMI_Handler\n");
    semihosting_syscall(kRunTimeErrorUnknown);
}

void HardFault_Handler(void) {
    printf("HardFault_Handler\n");
    semihosting_syscall(kRunTimeErrorUnknown);
}

void MemManage_Handler(void) {
    printf("MemManage_Handler\n");
    semihosting_syscall(kRunTimeErrorUnknown);
}

void BusFault_Handler(void) {
    printf("BusFault_Handler\n");
    semihosting_syscall(kRunTimeErrorUnknown);
}

void UsageFault_Handler(void) {
    printf("UsageFault_Handler\n");
    semihosting_syscall(kRunTimeErrorUnknown);
}

void SVC_Handler(void) {
    printf("SVC_Handler\n");
    semihosting_syscall(kApplicationExit);
}

void DebugMon_Handler(void) {
    printf("DebugMon_Handler\n");
    semihosting_syscall(kApplicationExit);
}

void PendSV_Handler(void) {
    printf("PendSV_Handler\n");
    semihosting_syscall(kApplicationExit);
}

/******************************************************************************
 *
 * CPU cycle count
 *
 *****************************************************************************/

// Used for counting cycles
static volatile unsigned long long overflowcnt = 0;
static inline void SysTick_Handler(void) { ++overflowcnt; }
static inline uint64_t systick_get_value(void) { return SysTick->VAL; }

void Default_Handler(void) { semihosting_syscall(kApplicationExit); }

#endif /* !defined(NO_SEMIHOSTING_EXIT) */
