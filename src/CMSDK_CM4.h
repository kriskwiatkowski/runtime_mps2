/* MPS2 CMSIS Library
*
* Copyright (c) 2006-2018 ARM Limited
* SPDX-License-Identifier: BSD-3-Clause
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice,
* this list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following disclaimer in the documentation
* and/or other materials provided with the distribution.
*
* 3. Neither the name of the copyright holder nor the names of its contributors
* may be used to endorse or promote products derived from this software without
* specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************
* @file     CMSDK_CM4.h
* @brief    CMSIS Cortex-M4 Core Peripheral Access Layer Header File for
*           Device CMSDK_CM4
*
*******************************************************************************/

#ifndef CMSDK_CM4_H
#define CMSDK_CM4_H

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum IRQn {
    /* -------------------  Cortex-M3 Processor Exceptions Numbers  ------------------- */
    NonMaskableInt_IRQn   = -14, /*  2 Non Maskable Interrupt          */
    HardFault_IRQn        = -13, /*  3 HardFault Interrupt             */
    MemoryManagement_IRQn = -12, /*  4 Memory Management Interrupt     */
    BusFault_IRQn         = -11, /*  5 Bus Fault Interrupt             */
    UsageFault_IRQn       = -10, /*  6 Usage Fault Interrupt           */
    SVCall_IRQn           = -5,  /* 11 SV Call Interrupt               */
    DebugMonitor_IRQn     = -4,  /* 12 Debug Monitor Interrupt         */
    PendSV_IRQn           = -2,  /* 14 Pend SV Interrupt               */
    SysTick_IRQn          = -1,  /* 15 System Tick Interrupt           */

    /******  CMSDK Specific Interrupt Numbers *********************************************************/
    UARTRX0_IRQn = 0, /*!< UART 0 RX Interrupt                               */
    UARTTX0_IRQn = 1, /*!< UART 0 TX Interrupt                               */
    UARTRX1_IRQn = 2, /*!< UART 1 RX Interrupt                               */
    UARTTX1_IRQn = 3, /*!< UART 1 TX Interrupt                               */
    UARTRX2_IRQn = 4, /*!< UART 2 RX Interrupt                               */
    UARTTX2_IRQn = 5, /*!< UART 2 TX Interrupt                               */
    PORT0_ALL_IRQn =
        6, /*!< Port 0 combined Interrupt                         */
    PORT1_ALL_IRQn =
        7,           /*!< Port 1 combined Interrupt                         */
    TIMER0_IRQn = 8, /*!< TIMER 0 Interrupt                                 */
    TIMER1_IRQn = 9, /*!< TIMER 1 Interrupt                                 */
    DUALTIMER_IRQn =
        10,            /*!< Dual Timer Interrupt                              */
    SPI_IRQn     = 11, /*!< SPI Interrupt                                     */
    UARTOVF_IRQn = 12, /*!< UART 0,1,2 Overflow Interrupt                     */
    ETHERNET_IRQn =
        13,        /*!< Ethernet Interrupt                                */
    I2S_IRQn = 14, /*!< I2S Interrupt                                     */
    TSC_IRQn = 15, /*!< Touch Screen Interrupt                            */
    PORT2_ALL_IRQn =
        16, /*!< Port 2 combined Interrupt                         */
    PORT3_ALL_IRQn =
        17,            /*!< Port 3 combined Interrupt                         */
    UARTRX3_IRQn = 18, /*!< UART 3 RX Interrupt                               */
    UARTTX3_IRQn = 19, /*!< UART 3 TX Interrupt                               */
    UARTRX4_IRQn = 20, /*!< UART 4 RX Interrupt                               */
    UARTTX4_IRQn = 21, /*!< UART 4 TX Interrupt                               */
    ADCSPI_IRQn  = 22, /*!< SHIELD ADC SPI Interrupt                          */
    SHIELDSPI_IRQn =
        23,            /*!< SHIELD SPI Combined Interrupt                     */
    PORT0_0_IRQn = 24, /*!<  GPIO Port 0 pin 0 Interrupt                      */
    PORT0_1_IRQn = 25, /*!<  GPIO Port 0 pin 1 Interrupt                      */
    PORT0_2_IRQn = 26, /*!<  GPIO Port 0 pin 2 Interrupt                      */
    PORT0_3_IRQn = 27, /*!<  GPIO Port 0 pin 3 Interrupt                      */
    PORT0_4_IRQn = 28, /*!<  GPIO Port 0 pin 4 Interrupt                      */
    PORT0_5_IRQn = 29, /*!<  GPIO Port 0 pin 5 Interrupt                      */
    PORT0_6_IRQn = 30, /*!<  GPIO Port 0 pin 6 Interrupt                      */
    PORT0_7_IRQn = 31, /*!<  GPIO Port 0 pin 7 Interrupt                      */
} IRQn_Type;

/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M4 Processor and Core Peripherals */
#define __CM4_REV \
    0x0001 /*!< Core Revision r0p1                               */
#define __NVIC_PRIO_BITS \
    3 /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig \
    0                   /*!< Set to 1 if different SysTick Config is used     */
#define __MPU_PRESENT 1 /*!< MPU present or not                               */
#define __FPU_PRESENT 1 /*!< FPU present or not                               */

/*@}*/ /* end of group CMSDK_CM4_CMSIS */

#include "core_cm4.h" /* Cortex-M4 processor and core peripherals           */

/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/
/** @addtogroup CMSDK_CM4_Peripherals CMSDK_CM4 Peripherals
  CMSDK_CM4 Device Specific Peripheral registers structures
  @{
*/

#if defined(__CC_ARM)
#pragma anon_unions
#endif

/*------------- Universal Asynchronous Receiver Transmitter (UART) -----------*/
/** @addtogroup CMSDK_UART CMSDK Universal Asynchronous Receiver/Transmitter
  memory mapped structure for CMSDK_UART
  @{
*/
typedef struct {
    __IO uint32_t DATA;  /*!< Offset: 0x000 Data Register    (R/W) */
    __IO uint32_t STATE; /*!< Offset: 0x004 Status Register  (R/W) */
    __IO uint32_t CTRL;  /*!< Offset: 0x008 Control Register (R/W) */
    union {
        __I uint32_t
            INTSTATUS; /*!< Offset: 0x00C Interrupt Status Register (R/ ) */
        __O uint32_t
            INTCLEAR; /*!< Offset: 0x00C Interrupt Clear Register ( /W) */
    } INT;
    __IO uint32_t BAUDDIV; /*!< Offset: 0x010 Baudrate Divider Register (R/W) */

} CMSDK_UART_TypeDef;

/* CMSDK_UART DATA Register Definitions */

#define CMSDK_UART_DATA_Pos 0 /*!< CMSDK_UART_DATA_Pos: DATA Position */
#define CMSDK_UART_DATA_Msk \
    (0xFFul << CMSDK_UART_DATA_Pos) /*!< CMSDK_UART DATA: DATA Mask */

#define CMSDK_UART_STATE_RXOR_Pos 3 /*!< CMSDK_UART STATE: RXOR Position */
#define CMSDK_UART_STATE_RXOR_Msk \
    (0x1ul << CMSDK_UART_STATE_RXOR_Pos) /*!< CMSDK_UART STATE: RXOR Mask */

#define CMSDK_UART_STATE_TXOR_Pos 2 /*!< CMSDK_UART STATE: TXOR Position */
#define CMSDK_UART_STATE_TXOR_Msk \
    (0x1ul << CMSDK_UART_STATE_TXOR_Pos) /*!< CMSDK_UART STATE: TXOR Mask */

#define CMSDK_UART_STATE_RXBF_Pos 1 /*!< CMSDK_UART STATE: RXBF Position */
#define CMSDK_UART_STATE_RXBF_Msk \
    (0x1ul << CMSDK_UART_STATE_RXBF_Pos) /*!< CMSDK_UART STATE: RXBF Mask */

#define CMSDK_UART_STATE_TXBF_Pos 0 /*!< CMSDK_UART STATE: TXBF Position */
#define CMSDK_UART_STATE_TXBF_Msk \
    (0x1ul << CMSDK_UART_STATE_TXBF_Pos) /*!< CMSDK_UART STATE: TXBF Mask */

#define CMSDK_UART_CTRL_HSTM_Pos 6 /*!< CMSDK_UART CTRL: HSTM Position */
#define CMSDK_UART_CTRL_HSTM_Msk \
    (0x01ul << CMSDK_UART_CTRL_HSTM_Pos) /*!< CMSDK_UART CTRL: HSTM Mask */

#define CMSDK_UART_CTRL_RXORIRQEN_Pos \
    5 /*!< CMSDK_UART CTRL: RXORIRQEN Position */
#define CMSDK_UART_CTRL_RXORIRQEN_Msk \
    (0x01ul                           \
     << CMSDK_UART_CTRL_RXORIRQEN_Pos) /*!< CMSDK_UART CTRL: RXORIRQEN Mask */

#define CMSDK_UART_CTRL_TXORIRQEN_Pos \
    4 /*!< CMSDK_UART CTRL: TXORIRQEN Position */
#define CMSDK_UART_CTRL_TXORIRQEN_Msk \
    (0x01ul                           \
     << CMSDK_UART_CTRL_TXORIRQEN_Pos) /*!< CMSDK_UART CTRL: TXORIRQEN Mask */

#define CMSDK_UART_CTRL_RXIRQEN_Pos 3 /*!< CMSDK_UART CTRL: RXIRQEN Position */
#define CMSDK_UART_CTRL_RXIRQEN_Msk \
    (0x01ul                         \
     << CMSDK_UART_CTRL_RXIRQEN_Pos) /*!< CMSDK_UART CTRL: RXIRQEN Mask */

#define CMSDK_UART_CTRL_TXIRQEN_Pos 2 /*!< CMSDK_UART CTRL: TXIRQEN Position */
#define CMSDK_UART_CTRL_TXIRQEN_Msk \
    (0x01ul                         \
     << CMSDK_UART_CTRL_TXIRQEN_Pos) /*!< CMSDK_UART CTRL: TXIRQEN Mask */

#define CMSDK_UART_CTRL_RXEN_Pos 1 /*!< CMSDK_UART CTRL: RXEN Position */
#define CMSDK_UART_CTRL_RXEN_Msk \
    (0x01ul << CMSDK_UART_CTRL_RXEN_Pos) /*!< CMSDK_UART CTRL: RXEN Mask */

#define CMSDK_UART_CTRL_TXEN_Pos 0 /*!< CMSDK_UART CTRL: TXEN Position */
#define CMSDK_UART_CTRL_TXEN_Msk \
    (0x01ul << CMSDK_UART_CTRL_TXEN_Pos) /*!< CMSDK_UART CTRL: TXEN Mask */

#define CMSDK_UART_INTSTATUS_RXORIRQ_Pos \
    3 /*!< CMSDK_UART CTRL: RXORIRQ Position */
#define CMSDK_UART_CTRL_RXORIRQ_Msk \
    (0x01ul                         \
     << CMSDK_UART_INTSTATUS_RXORIRQ_Pos) /*!< CMSDK_UART CTRL: RXORIRQ Mask */

#define CMSDK_UART_CTRL_TXORIRQ_Pos 2 /*!< CMSDK_UART CTRL: TXORIRQ Position */
#define CMSDK_UART_CTRL_TXORIRQ_Msk \
    (0x01ul                         \
     << CMSDK_UART_CTRL_TXORIRQ_Pos) /*!< CMSDK_UART CTRL: TXORIRQ Mask */

#define CMSDK_UART_CTRL_RXIRQ_Pos 1 /*!< CMSDK_UART CTRL: RXIRQ Position */
#define CMSDK_UART_CTRL_RXIRQ_Msk \
    (0x01ul << CMSDK_UART_CTRL_RXIRQ_Pos) /*!< CMSDK_UART CTRL: RXIRQ Mask */

#define CMSDK_UART_CTRL_TXIRQ_Pos 0 /*!< CMSDK_UART CTRL: TXIRQ Position */
#define CMSDK_UART_CTRL_TXIRQ_Msk \
    (0x01ul << CMSDK_UART_CTRL_TXIRQ_Pos) /*!< CMSDK_UART CTRL: TXIRQ Mask */

#define CMSDK_UART_BAUDDIV_Pos 0 /*!< CMSDK_UART BAUDDIV: BAUDDIV Position */
#define CMSDK_UART_BAUDDIV_Msk \
    (0xFFFFFul                 \
     << CMSDK_UART_BAUDDIV_Pos) /*!< CMSDK_UART BAUDDIV: BAUDDIV Mask */

/*@}*/ /* end of group CMSDK_UART */

/*----------------------------- Timer (TIMER) -------------------------------*/
/** @addtogroup CMSDK_TIMER CMSDK Timer
  @{
*/
typedef struct {
    __IO uint32_t CTRL;   /*!< Offset: 0x000 Control Register (R/W) */
    __IO uint32_t VALUE;  /*!< Offset: 0x004 Current Value Register (R/W) */
    __IO uint32_t RELOAD; /*!< Offset: 0x008 Reload Value Register  (R/W) */
    union {
        __I uint32_t
            INTSTATUS; /*!< Offset: 0x00C Interrupt Status Register (R/ ) */
        __O uint32_t
            INTCLEAR; /*!< Offset: 0x00C Interrupt Clear Register ( /W) */
    } INT;

} CMSDK_TIMER_TypeDef;

/* CMSDK_TIMER CTRL Register Definitions */

#define CMSDK_TIMER_CTRL_IRQEN_Pos 3 /*!< CMSDK_TIMER CTRL: IRQEN Position */
#define CMSDK_TIMER_CTRL_IRQEN_Msk \
    (0x01ul << CMSDK_TIMER_CTRL_IRQEN_Pos) /*!< CMSDK_TIMER CTRL: IRQEN Mask */

#define CMSDK_TIMER_CTRL_SELEXTCLK_Pos \
    2 /*!< CMSDK_TIMER CTRL: SELEXTCLK Position */
#define CMSDK_TIMER_CTRL_SELEXTCLK_Msk \
    (0x01ul                            \
     << CMSDK_TIMER_CTRL_SELEXTCLK_Pos) /*!< CMSDK_TIMER CTRL: SELEXTCLK Mask */

#define CMSDK_TIMER_CTRL_SELEXTEN_Pos \
    1 /*!< CMSDK_TIMER CTRL: SELEXTEN Position */
#define CMSDK_TIMER_CTRL_SELEXTEN_Msk \
    (0x01ul                           \
     << CMSDK_TIMER_CTRL_SELEXTEN_Pos) /*!< CMSDK_TIMER CTRL: SELEXTEN Mask */

#define CMSDK_TIMER_CTRL_EN_Pos 0 /*!< CMSDK_TIMER CTRL: EN Position */
#define CMSDK_TIMER_CTRL_EN_Msk \
    (0x01ul << CMSDK_TIMER_CTRL_EN_Pos) /*!< CMSDK_TIMER CTRL: EN Mask */

#define CMSDK_TIMER_VAL_CURRENT_Pos \
    0 /*!< CMSDK_TIMER VALUE: CURRENT Position */
#define CMSDK_TIMER_VAL_CURRENT_Msk \
    (0xFFFFFFFFul                   \
     << CMSDK_TIMER_VAL_CURRENT_Pos) /*!< CMSDK_TIMER VALUE: CURRENT Mask */

#define CMSDK_TIMER_RELOAD_VAL_Pos 0 /*!< CMSDK_TIMER RELOAD: RELOAD Position */
#define CMSDK_TIMER_RELOAD_VAL_Msk \
    (0xFFFFFFFFul                  \
     << CMSDK_TIMER_RELOAD_VAL_Pos) /*!< CMSDK_TIMER RELOAD: RELOAD Mask */

#define CMSDK_TIMER_INTSTATUS_Pos \
    0 /*!< CMSDK_TIMER INTSTATUS: INTSTATUSPosition */
#define CMSDK_TIMER_INTSTATUS_Msk \
    (0x01ul                       \
     << CMSDK_TIMER_INTSTATUS_Pos) /*!< CMSDK_TIMER INTSTATUS: INTSTATUSMask */

#define CMSDK_TIMER_INTCLEAR_Pos \
    0 /*!< CMSDK_TIMER INTCLEAR: INTCLEAR Position */
#define CMSDK_TIMER_INTCLEAR_Msk \
    (0x01ul                      \
     << CMSDK_TIMER_INTCLEAR_Pos) /*!< CMSDK_TIMER INTCLEAR: INTCLEAR Mask */

/*@}*/ /* end of group CMSDK_TIMER */

/*------------- Timer (TIM) --------------------------------------------------*/
// <g> Timer (TIM)

/** @addtogroup CMSDK_DualTIMER CMSDK Dual Timer
  @{
*/

typedef struct {
    __IO uint32_t Timer1Load; /* Offset: 0x000 (R/W) Timer 1 Load */
    __I uint32_t
        Timer1Value; /* Offset: 0x004 (R/ ) Timer 1 Counter Current Value */
    __IO uint32_t Timer1Control; /* Offset: 0x008 (R/W) Timer 1 Control */
    /* <o.7> TimerEn: Timer Enable         */
    /* <o.6> TimerMode: Timer Mode         */
    /*   <0=> Freerunning-mode             */
    /*   <1=> Periodic mode                */
    /* <o.5> IntEnable: Interrupt Enable   */
    /* <o.2..3> TimerPre: Timer Prescale   */
    /*   <0=> / 1                          */
    /*   <1=> / 16                         */
    /*   <2=> / 256                        */
    /*   <3=> Undefined!                   */
    /* <o.1> TimerSize: Timer Size         */
    /*   <0=> 16-bit counter               */
    /*   <1=> 32-bit counter               */
    /* <o.0> OneShot: One-shoot mode       */
    /*   <0=> Wrapping mode                */
    /*   <1=> One-shot mode                */
    /* </h>                                */
    __O uint32_t Timer1IntClr; /* Offset: 0x00C ( /W) Timer 1 Interrupt Clear */
    __I uint32_t
        Timer1RIS; /* Offset: 0x010 (R/ ) Timer 1 Raw Interrupt Status */
    __I uint32_t
        Timer1MIS; /* Offset: 0x014 (R/ ) Timer 1 Masked Interrupt Status */
    __IO uint32_t
        Timer1BGLoad; /* Offset: 0x018 (R/W) Background Load Register */
    uint32_t RESERVED0;
    __IO uint32_t Timer2Load; /* Offset: 0x020 (R/W) Timer 2 Load */
    __I uint32_t
        Timer2Value; /* Offset: 0x024 (R/ ) Timer 2 Counter Current Value */
    __IO uint32_t Timer2Control; /* Offset: 0x028 (R/W) Timer 2 Control */
    /* <o.7> TimerEn: Timer Enable         */
    /* <o.6> TimerMode: Timer Mode         */
    /*   <0=> Freerunning-mode             */
    /*   <1=> Periodic mode                */
    /* <o.5> IntEnable: Interrupt Enable   */
    /* <o.2..3> TimerPre: Timer Prescale   */
    /*   <0=> / 1                          */
    /*   <1=> / 16                         */
    /*   <2=> / 256                        */
    /*   <3=> Undefined!                   */
    /* <o.1> TimerSize: Timer Size         */
    /*   <0=> 16-bit counter               */
    /*   <1=> 32-bit counter               */
    /* <o.0> OneShot: One-shoot mode       */
    /*   <0=> Wrapping mode                */
    /*   <1=> One-shot mode                */
    /* </h>                                */
    __O uint32_t Timer2IntClr; /* Offset: 0x02C ( /W) Timer 2 Interrupt Clear */
    __I uint32_t
        Timer2RIS; /* Offset: 0x030 (R/ ) Timer 2 Raw Interrupt Status */
    __I uint32_t
        Timer2MIS; /* Offset: 0x034 (R/ ) Timer 2 Masked Interrupt Status */
    __IO uint32_t
        Timer2BGLoad; /* Offset: 0x038 (R/W) Background Load Register */
    uint32_t RESERVED1[945];
    __IO uint32_t
        ITCR; /* Offset: 0xF00 (R/W) Integration Test Control Register */
    __O uint32_t
        ITOP; /* Offset: 0xF04 ( /W) Integration Test Output Set Register */
} CMSDK_DUALTIMER_BOTH_TypeDef;

#define CMSDK_DUALTIMER1_LOAD_Pos 0 /*!< CMSDK_DUALTIMER1 LOAD: LOAD Position */
#define CMSDK_DUALTIMER1_LOAD_Msk \
    (0xFFFFFFFFul                 \
     << CMSDK_DUALTIMER1_LOAD_Pos) /*!< CMSDK_DUALTIMER1 LOAD: LOAD Mask */

#define CMSDK_DUALTIMER1_VALUE_Pos \
    0 /*!< CMSDK_DUALTIMER1 VALUE: VALUE Position */
#define CMSDK_DUALTIMER1_VALUE_Msk \
    (0xFFFFFFFFul                  \
     << CMSDK_DUALTIMER1_VALUE_Pos) /*!< CMSDK_DUALTIMER1 VALUE: VALUE Mask */

#define CMSDK_DUALTIMER1_CTRL_EN_Pos \
    7 /*!< CMSDK_DUALTIMER1 CTRL_EN: CTRL Enable Position */
#define CMSDK_DUALTIMER1_CTRL_EN_Msk \
    (0x1ul                           \
     << CMSDK_DUALTIMER1_CTRL_EN_Pos) /*!< CMSDK_DUALTIMER1 CTRL_EN: CTRL Enable Mask */

#define CMSDK_DUALTIMER1_CTRL_MODE_Pos \
    6 /*!< CMSDK_DUALTIMER1 CTRL_MODE: CTRL MODE Position */
#define CMSDK_DUALTIMER1_CTRL_MODE_Msk \
    (0x1ul                             \
     << CMSDK_DUALTIMER1_CTRL_MODE_Pos) /*!< CMSDK_DUALTIMER1 CTRL_MODE: CTRL MODE Mask */

#define CMSDK_DUALTIMER1_CTRL_INTEN_Pos \
    5 /*!< CMSDK_DUALTIMER1 CTRL_INTEN: CTRL Int Enable Position */
#define CMSDK_DUALTIMER1_CTRL_INTEN_Msk \
    (0x1ul                              \
     << CMSDK_DUALTIMER1_CTRL_INTEN_Pos) /*!< CMSDK_DUALTIMER1 CTRL_INTEN: CTRL Int Enable Mask */

#define CMSDK_DUALTIMER1_CTRL_PRESCALE_Pos \
    2 /*!< CMSDK_DUALTIMER1 CTRL_PRESCALE: CTRL PRESCALE Position */
#define CMSDK_DUALTIMER1_CTRL_PRESCALE_Msk \
    (0x3ul                                 \
     << CMSDK_DUALTIMER1_CTRL_PRESCALE_Pos) /*!< CMSDK_DUALTIMER1 CTRL_PRESCALE: CTRL PRESCALE Mask */

#define CMSDK_DUALTIMER1_CTRL_SIZE_Pos \
    1 /*!< CMSDK_DUALTIMER1 CTRL_SIZE: CTRL SIZE Position */
#define CMSDK_DUALTIMER1_CTRL_SIZE_Msk \
    (0x1ul                             \
     << CMSDK_DUALTIMER1_CTRL_SIZE_Pos) /*!< CMSDK_DUALTIMER1 CTRL_SIZE: CTRL SIZE Mask */

#define CMSDK_DUALTIMER1_CTRL_ONESHOOT_Pos \
    0 /*!< CMSDK_DUALTIMER1 CTRL_ONESHOOT: CTRL ONESHOOT Position */
#define CMSDK_DUALTIMER1_CTRL_ONESHOOT_Msk \
    (0x1ul                                 \
     << CMSDK_DUALTIMER1_CTRL_ONESHOOT_Pos) /*!< CMSDK_DUALTIMER1 CTRL_ONESHOOT: CTRL ONESHOOT Mask */

#define CMSDK_DUALTIMER1_INTCLR_Pos \
    0 /*!< CMSDK_DUALTIMER1 INTCLR: INT Clear Position */
#define CMSDK_DUALTIMER1_INTCLR_Msk \
    (0x1ul                          \
     << CMSDK_DUALTIMER1_INTCLR_Pos) /*!< CMSDK_DUALTIMER1 INTCLR: INT Clear  Mask */

#define CMSDK_DUALTIMER1_RAWINTSTAT_Pos \
    0 /*!< CMSDK_DUALTIMER1 RAWINTSTAT: Raw Int Status Position */
#define CMSDK_DUALTIMER1_RAWINTSTAT_Msk \
    (0x1ul                              \
     << CMSDK_DUALTIMER1_RAWINTSTAT_Pos) /*!< CMSDK_DUALTIMER1 RAWINTSTAT: Raw Int Status Mask */

#define CMSDK_DUALTIMER1_MASKINTSTAT_Pos \
    0 /*!< CMSDK_DUALTIMER1 MASKINTSTAT: Mask Int Status Position */
#define CMSDK_DUALTIMER1_MASKINTSTAT_Msk \
    (0x1ul                               \
     << CMSDK_DUALTIMER1_MASKINTSTAT_Pos) /*!< CMSDK_DUALTIMER1 MASKINTSTAT: Mask Int Status Mask */

#define CMSDK_DUALTIMER1_BGLOAD_Pos \
    0 /*!< CMSDK_DUALTIMER1 BGLOAD: Background Load Position */
#define CMSDK_DUALTIMER1_BGLOAD_Msk \
    (0xFFFFFFFFul                   \
     << CMSDK_DUALTIMER1_BGLOAD_Pos) /*!< CMSDK_DUALTIMER1 BGLOAD: Background Load Mask */

#define CMSDK_DUALTIMER2_LOAD_Pos 0 /*!< CMSDK_DUALTIMER2 LOAD: LOAD Position */
#define CMSDK_DUALTIMER2_LOAD_Msk \
    (0xFFFFFFFFul                 \
     << CMSDK_DUALTIMER2_LOAD_Pos) /*!< CMSDK_DUALTIMER2 LOAD: LOAD Mask */

#define CMSDK_DUALTIMER2_VALUE_Pos \
    0 /*!< CMSDK_DUALTIMER2 VALUE: VALUE Position */
#define CMSDK_DUALTIMER2_VALUE_Msk \
    (0xFFFFFFFFul                  \
     << CMSDK_DUALTIMER2_VALUE_Pos) /*!< CMSDK_DUALTIMER2 VALUE: VALUE Mask */

#define CMSDK_DUALTIMER2_CTRL_EN_Pos \
    7 /*!< CMSDK_DUALTIMER2 CTRL_EN: CTRL Enable Position */
#define CMSDK_DUALTIMER2_CTRL_EN_Msk \
    (0x1ul                           \
     << CMSDK_DUALTIMER2_CTRL_EN_Pos) /*!< CMSDK_DUALTIMER2 CTRL_EN: CTRL Enable Mask */

#define CMSDK_DUALTIMER2_CTRL_MODE_Pos \
    6 /*!< CMSDK_DUALTIMER2 CTRL_MODE: CTRL MODE Position */
#define CMSDK_DUALTIMER2_CTRL_MODE_Msk \
    (0x1ul                             \
     << CMSDK_DUALTIMER2_CTRL_MODE_Pos) /*!< CMSDK_DUALTIMER2 CTRL_MODE: CTRL MODE Mask */

#define CMSDK_DUALTIMER2_CTRL_INTEN_Pos \
    5 /*!< CMSDK_DUALTIMER2 CTRL_INTEN: CTRL Int Enable Position */
#define CMSDK_DUALTIMER2_CTRL_INTEN_Msk \
    (0x1ul                              \
     << CMSDK_DUALTIMER2_CTRL_INTEN_Pos) /*!< CMSDK_DUALTIMER2 CTRL_INTEN: CTRL Int Enable Mask */

#define CMSDK_DUALTIMER2_CTRL_PRESCALE_Pos \
    2 /*!< CMSDK_DUALTIMER2 CTRL_PRESCALE: CTRL PRESCALE Position */
#define CMSDK_DUALTIMER2_CTRL_PRESCALE_Msk \
    (0x3ul                                 \
     << CMSDK_DUALTIMER2_CTRL_PRESCALE_Pos) /*!< CMSDK_DUALTIMER2 CTRL_PRESCALE: CTRL PRESCALE Mask */

#define CMSDK_DUALTIMER2_CTRL_SIZE_Pos \
    1 /*!< CMSDK_DUALTIMER2 CTRL_SIZE: CTRL SIZE Position */
#define CMSDK_DUALTIMER2_CTRL_SIZE_Msk \
    (0x1ul                             \
     << CMSDK_DUALTIMER2_CTRL_SIZE_Pos) /*!< CMSDK_DUALTIMER2 CTRL_SIZE: CTRL SIZE Mask */

#define CMSDK_DUALTIMER2_CTRL_ONESHOOT_Pos \
    0 /*!< CMSDK_DUALTIMER2 CTRL_ONESHOOT: CTRL ONESHOOT Position */
#define CMSDK_DUALTIMER2_CTRL_ONESHOOT_Msk \
    (0x1ul                                 \
     << CMSDK_DUALTIMER2_CTRL_ONESHOOT_Pos) /*!< CMSDK_DUALTIMER2 CTRL_ONESHOOT: CTRL ONESHOOT Mask */

#define CMSDK_DUALTIMER2_INTCLR_Pos \
    0 /*!< CMSDK_DUALTIMER2 INTCLR: INT Clear Position */
#define CMSDK_DUALTIMER2_INTCLR_Msk \
    (0x1ul                          \
     << CMSDK_DUALTIMER2_INTCLR_Pos) /*!< CMSDK_DUALTIMER2 INTCLR: INT Clear  Mask */

#define CMSDK_DUALTIMER2_RAWINTSTAT_Pos \
    0 /*!< CMSDK_DUALTIMER2 RAWINTSTAT: Raw Int Status Position */
#define CMSDK_DUALTIMER2_RAWINTSTAT_Msk \
    (0x1ul                              \
     << CMSDK_DUALTIMER2_RAWINTSTAT_Pos) /*!< CMSDK_DUALTIMER2 RAWINTSTAT: Raw Int Status Mask */

#define CMSDK_DUALTIMER2_MASKINTSTAT_Pos \
    0 /*!< CMSDK_DUALTIMER2 MASKINTSTAT: Mask Int Status Position */
#define CMSDK_DUALTIMER2_MASKINTSTAT_Msk \
    (0x1ul                               \
     << CMSDK_DUALTIMER2_MASKINTSTAT_Pos) /*!< CMSDK_DUALTIMER2 MASKINTSTAT: Mask Int Status Mask */

#define CMSDK_DUALTIMER2_BGLOAD_Pos \
    0 /*!< CMSDK_DUALTIMER2 BGLOAD: Background Load Position */
#define CMSDK_DUALTIMER2_BGLOAD_Msk \
    (0xFFFFFFFFul                   \
     << CMSDK_DUALTIMER2_BGLOAD_Pos) /*!< CMSDK_DUALTIMER2 BGLOAD: Background Load Mask */

typedef struct {
    __IO uint32_t TimerLoad; /* Offset: 0x000 (R/W) Timer Load */
    __I uint32_t
        TimerValue; /* Offset: 0x000 (R/W) Timer Counter Current Value */
    __IO uint32_t TimerControl; /* Offset: 0x000 (R/W) Timer Control */
    /* <o.7> TimerEn: Timer Enable         */
    /* <o.6> TimerMode: Timer Mode         */
    /*   <0=> Freerunning-mode             */
    /*   <1=> Periodic mode                */
    /* <o.5> IntEnable: Interrupt Enable   */
    /* <o.2..3> TimerPre: Timer Prescale   */
    /*   <0=> / 1                          */
    /*   <1=> / 16                         */
    /*   <2=> / 256                        */
    /*   <3=> Undefined!                   */
    /* <o.1> TimerSize: Timer Size         */
    /*   <0=> 16-bit counter               */
    /*   <1=> 32-bit counter               */
    /* <o.0> OneShot: One-shoot mode       */
    /*   <0=> Wrapping mode                */
    /*   <1=> One-shot mode                */
    /* </h>                                */
    __O uint32_t TimerIntClr; /* Offset: 0x000 (R/W) Timer Interrupt Clear */
    __I uint32_t TimerRIS; /* Offset: 0x000 (R/W) Timer Raw Interrupt Status */
    __I uint32_t
        TimerMIS; /* Offset: 0x000 (R/W) Timer Masked Interrupt Status */
    __IO uint32_t
        TimerBGLoad; /* Offset: 0x000 (R/W) Background Load Register */
} CMSDK_DUALTIMER_SINGLE_TypeDef;

#define CMSDK_DUALTIMER_LOAD_Pos 0 /*!< CMSDK_DUALTIMER LOAD: LOAD Position */
#define CMSDK_DUALTIMER_LOAD_Msk \
    (0xFFFFFFFFul                \
     << CMSDK_DUALTIMER_LOAD_Pos) /*!< CMSDK_DUALTIMER LOAD: LOAD Mask */

#define CMSDK_DUALTIMER_VALUE_Pos \
    0 /*!< CMSDK_DUALTIMER VALUE: VALUE Position */
#define CMSDK_DUALTIMER_VALUE_Msk \
    (0xFFFFFFFFul                 \
     << CMSDK_DUALTIMER_VALUE_Pos) /*!< CMSDK_DUALTIMER VALUE: VALUE Mask */

#define CMSDK_DUALTIMER_CTRL_EN_Pos \
    7 /*!< CMSDK_DUALTIMER CTRL_EN: CTRL Enable Position */
#define CMSDK_DUALTIMER_CTRL_EN_Msk \
    (0x1ul                          \
     << CMSDK_DUALTIMER_CTRL_EN_Pos) /*!< CMSDK_DUALTIMER CTRL_EN: CTRL Enable Mask */

#define CMSDK_DUALTIMER_CTRL_MODE_Pos \
    6 /*!< CMSDK_DUALTIMER CTRL_MODE: CTRL MODE Position */
#define CMSDK_DUALTIMER_CTRL_MODE_Msk \
    (0x1ul                            \
     << CMSDK_DUALTIMER_CTRL_MODE_Pos) /*!< CMSDK_DUALTIMER CTRL_MODE: CTRL MODE Mask */

#define CMSDK_DUALTIMER_CTRL_INTEN_Pos \
    5 /*!< CMSDK_DUALTIMER CTRL_INTEN: CTRL Int Enable Position */
#define CMSDK_DUALTIMER_CTRL_INTEN_Msk \
    (0x1ul                             \
     << CMSDK_DUALTIMER_CTRL_INTEN_Pos) /*!< CMSDK_DUALTIMER CTRL_INTEN: CTRL Int Enable Mask */

#define CMSDK_DUALTIMER_CTRL_PRESCALE_Pos \
    2 /*!< CMSDK_DUALTIMER CTRL_PRESCALE: CTRL PRESCALE Position */
#define CMSDK_DUALTIMER_CTRL_PRESCALE_Msk \
    (0x3ul                                \
     << CMSDK_DUALTIMER_CTRL_PRESCALE_Pos) /*!< CMSDK_DUALTIMER CTRL_PRESCALE: CTRL PRESCALE Mask */

#define CMSDK_DUALTIMER_CTRL_SIZE_Pos \
    1 /*!< CMSDK_DUALTIMER CTRL_SIZE: CTRL SIZE Position */
#define CMSDK_DUALTIMER_CTRL_SIZE_Msk \
    (0x1ul                            \
     << CMSDK_DUALTIMER_CTRL_SIZE_Pos) /*!< CMSDK_DUALTIMER CTRL_SIZE: CTRL SIZE Mask */

#define CMSDK_DUALTIMER_CTRL_ONESHOOT_Pos \
    0 /*!< CMSDK_DUALTIMER CTRL_ONESHOOT: CTRL ONESHOOT Position */
#define CMSDK_DUALTIMER_CTRL_ONESHOOT_Msk \
    (0x1ul                                \
     << CMSDK_DUALTIMER_CTRL_ONESHOOT_Pos) /*!< CMSDK_DUALTIMER CTRL_ONESHOOT: CTRL ONESHOOT Mask */

#define CMSDK_DUALTIMER_INTCLR_Pos \
    0 /*!< CMSDK_DUALTIMER INTCLR: INT Clear Position */
#define CMSDK_DUALTIMER_INTCLR_Msk \
    (0x1ul                         \
     << CMSDK_DUALTIMER_INTCLR_Pos) /*!< CMSDK_DUALTIMER INTCLR: INT Clear  Mask */

#define CMSDK_DUALTIMER_RAWINTSTAT_Pos \
    0 /*!< CMSDK_DUALTIMER RAWINTSTAT: Raw Int Status Position */
#define CMSDK_DUALTIMER_RAWINTSTAT_Msk \
    (0x1ul                             \
     << CMSDK_DUALTIMER_RAWINTSTAT_Pos) /*!< CMSDK_DUALTIMER RAWINTSTAT: Raw Int Status Mask */

#define CMSDK_DUALTIMER_MASKINTSTAT_Pos \
    0 /*!< CMSDK_DUALTIMER MASKINTSTAT: Mask Int Status Position */
#define CMSDK_DUALTIMER_MASKINTSTAT_Msk \
    (0x1ul                              \
     << CMSDK_DUALTIMER_MASKINTSTAT_Pos) /*!< CMSDK_DUALTIMER MASKINTSTAT: Mask Int Status Mask */

#define CMSDK_DUALTIMER_BGLOAD_Pos \
    0 /*!< CMSDK_DUALTIMER BGLOAD: Background Load Position */
#define CMSDK_DUALTIMER_BGLOAD_Msk \
    (0xFFFFFFFFul                  \
     << CMSDK_DUALTIMER_BGLOAD_Pos) /*!< CMSDK_DUALTIMER BGLOAD: Background Load Mask */

/*@}*/ /* end of group CMSDK_DualTIMER */

/*-------------------- General Purpose Input Output (GPIO) -------------------*/
/** @addtogroup CMSDK_GPIO CMSDK GPIO
  @{
*/
typedef struct {
    __IO uint32_t DATA;    /* Offset: 0x000 (R/W) DATA Register */
    __IO uint32_t DATAOUT; /* Offset: 0x004 (R/W) Data Output Latch Register */
    uint32_t RESERVED0[2];
    __IO uint32_t
        OUTENABLESET; /* Offset: 0x010 (R/W) Output Enable Set Register */
    __IO uint32_t
        OUTENABLECLR; /* Offset: 0x014 (R/W) Output Enable Clear Register */
    __IO uint32_t
        ALTFUNCSET; /* Offset: 0x018 (R/W) Alternate Function Set Register */
    __IO uint32_t
        ALTFUNCCLR; /* Offset: 0x01C (R/W) Alternate Function Clear Register */
    __IO uint32_t
        INTENSET; /* Offset: 0x020 (R/W) Interrupt Enable Set Register */
    __IO uint32_t
        INTENCLR; /* Offset: 0x024 (R/W) Interrupt Enable Clear Register */
    __IO uint32_t
        INTTYPESET; /* Offset: 0x028 (R/W) Interrupt Type Set Register */
    __IO uint32_t
        INTTYPECLR; /* Offset: 0x02C (R/W) Interrupt Type Clear Register */
    __IO uint32_t
        INTPOLSET; /* Offset: 0x030 (R/W) Interrupt Polarity Set Register */
    __IO uint32_t
        INTPOLCLR; /* Offset: 0x034 (R/W) Interrupt Polarity Clear Register */
    union {
        __I uint32_t
            INTSTATUS; /* Offset: 0x038 (R/ ) Interrupt Status Register */
        __O uint32_t
            INTCLEAR; /* Offset: 0x038 ( /W) Interrupt Clear Register */
    } INT;
    uint32_t RESERVED1[241];
    __IO uint32_t LB_MASKED
        [256]; /* Offset: 0x400 - 0x7FC Lower byte Masked Access Register (R/W) */
    __IO uint32_t UB_MASKED
        [256]; /* Offset: 0x800 - 0xBFC Upper byte Masked Access Register (R/W) */
} CMSDK_GPIO_TypeDef;

#define CMSDK_GPIO_DATA_Pos 0 /*!< CMSDK_GPIO DATA: DATA Position */
#define CMSDK_GPIO_DATA_Msk \
    (0xFFFFul << CMSDK_GPIO_DATA_Pos) /*!< CMSDK_GPIO DATA: DATA Mask */

#define CMSDK_GPIO_DATAOUT_Pos 0 /*!< CMSDK_GPIO DATAOUT: DATAOUT Position */
#define CMSDK_GPIO_DATAOUT_Msk \
    (0xFFFFul                  \
     << CMSDK_GPIO_DATAOUT_Pos) /*!< CMSDK_GPIO DATAOUT: DATAOUT Mask */

#define CMSDK_GPIO_OUTENSET_Pos 0 /*!< CMSDK_GPIO OUTEN: OUTEN Position */
#define CMSDK_GPIO_OUTENSET_Msk \
    (0xFFFFul << CMSDK_GPIO_OUTEN_Pos) /*!< CMSDK_GPIO OUTEN: OUTEN Mask */

#define CMSDK_GPIO_OUTENCLR_Pos 0 /*!< CMSDK_GPIO OUTEN: OUTEN Position */
#define CMSDK_GPIO_OUTENCLR_Msk \
    (0xFFFFul << CMSDK_GPIO_OUTEN_Pos) /*!< CMSDK_GPIO OUTEN: OUTEN Mask */

#define CMSDK_GPIO_ALTFUNCSET_Pos 0 /*!< CMSDK_GPIO ALTFUNC: ALTFUNC Position */
#define CMSDK_GPIO_ALTFUNCSET_Msk \
    (0xFFFFul                     \
     << CMSDK_GPIO_ALTFUNC_Pos) /*!< CMSDK_GPIO ALTFUNC: ALTFUNC Mask */

#define CMSDK_GPIO_ALTFUNCCLR_Pos 0 /*!< CMSDK_GPIO ALTFUNC: ALTFUNC Position */
#define CMSDK_GPIO_ALTFUNCCLR_Msk \
    (0xFFFFul                     \
     << CMSDK_GPIO_ALTFUNC_Pos) /*!< CMSDK_GPIO ALTFUNC: ALTFUNC Mask */

#define CMSDK_GPIO_INTENSET_Pos 0 /*!< CMSDK_GPIO INTEN: INTEN Position */
#define CMSDK_GPIO_INTENSET_Msk \
    (0xFFFFul << CMSDK_GPIO_INTEN_Pos) /*!< CMSDK_GPIO INTEN: INTEN Mask */

#define CMSDK_GPIO_INTENCLR_Pos 0 /*!< CMSDK_GPIO INTEN: INTEN Position */
#define CMSDK_GPIO_INTENCLR_Msk \
    (0xFFFFul << CMSDK_GPIO_INTEN_Pos) /*!< CMSDK_GPIO INTEN: INTEN Mask */

#define CMSDK_GPIO_INTTYPESET_Pos 0 /*!< CMSDK_GPIO INTTYPE: INTTYPE Position */
#define CMSDK_GPIO_INTTYPESET_Msk \
    (0xFFFFul                     \
     << CMSDK_GPIO_INTTYPE_Pos) /*!< CMSDK_GPIO INTTYPE: INTTYPE Mask */

#define CMSDK_GPIO_INTTYPECLR_Pos 0 /*!< CMSDK_GPIO INTTYPE: INTTYPE Position */
#define CMSDK_GPIO_INTTYPECLR_Msk \
    (0xFFFFul                     \
     << CMSDK_GPIO_INTTYPE_Pos) /*!< CMSDK_GPIO INTTYPE: INTTYPE Mask */

#define CMSDK_GPIO_INTPOLSET_Pos 0 /*!< CMSDK_GPIO INTPOL: INTPOL Position */
#define CMSDK_GPIO_INTPOLSET_Msk \
    (0xFFFFul << CMSDK_GPIO_INTPOL_Pos) /*!< CMSDK_GPIO INTPOL: INTPOL Mask */

#define CMSDK_GPIO_INTPOLCLR_Pos 0 /*!< CMSDK_GPIO INTPOL: INTPOL Position */
#define CMSDK_GPIO_INTPOLCLR_Msk \
    (0xFFFFul << CMSDK_GPIO_INTPOL_Pos) /*!< CMSDK_GPIO INTPOL: INTPOL Mask */

#define CMSDK_GPIO_INTSTATUS_Pos \
    0 /*!< CMSDK_GPIO INTSTATUS: INTSTATUS Position */
#define CMSDK_GPIO_INTSTATUS_Msk \
    (0xFFul                      \
     << CMSDK_GPIO_INTSTATUS_Pos) /*!< CMSDK_GPIO INTSTATUS: INTSTATUS Mask */

#define CMSDK_GPIO_INTCLEAR_Pos 0 /*!< CMSDK_GPIO INTCLEAR: INTCLEAR Position */
#define CMSDK_GPIO_INTCLEAR_Msk \
    (0xFFul                     \
     << CMSDK_GPIO_INTCLEAR_Pos) /*!< CMSDK_GPIO INTCLEAR: INTCLEAR Mask */

#define CMSDK_GPIO_MASKLOWBYTE_Pos \
    0 /*!< CMSDK_GPIO MASKLOWBYTE: MASKLOWBYTE Position */
#define CMSDK_GPIO_MASKLOWBYTE_Msk \
    (0x00FFul                      \
     << CMSDK_GPIO_MASKLOWBYTE_Pos) /*!< CMSDK_GPIO MASKLOWBYTE: MASKLOWBYTE Mask */

#define CMSDK_GPIO_MASKHIGHBYTE_Pos \
    0 /*!< CMSDK_GPIO MASKHIGHBYTE: MASKHIGHBYTE Position */
#define CMSDK_GPIO_MASKHIGHBYTE_Msk \
    (0xFF00ul                       \
     << CMSDK_GPIO_MASKHIGHBYTE_Pos) /*!< CMSDK_GPIO MASKHIGHBYTE: MASKHIGHBYTE Mask */

/*@}*/ /* end of group CMSDK_GPIO */

/*------------- System Control (SYSCON) --------------------------------------*/
/** @addtogroup CMSDK_SYSCON CMSDK System Control
  @{
*/
typedef struct {
    __IO uint32_t REMAP;   /* Offset: 0x000 (R/W) Remap Control Register */
    __IO uint32_t PMUCTRL; /* Offset: 0x004 (R/W) PMU Control Register */
    __IO uint32_t RESETOP; /* Offset: 0x008 (R/W) Reset Option Register */
    __IO uint32_t EMICTRL; /* Offset: 0x00C (R/W) EMI Control Register */
    __IO uint32_t RSTINFO; /* Offset: 0x010 (R/W) Reset Information Register */
} CMSDK_SYSCON_TypeDef;

#define CMSDK_SYSCON_REMAP_Pos 0
#define CMSDK_SYSCON_REMAP_Msk \
    (0x01ul                    \
     << CMSDK_SYSCON_REMAP_Pos) /*!< CMSDK_SYSCON MEME_CTRL: REMAP Mask */

#define CMSDK_SYSCON_PMUCTRL_EN_Pos 0
#define CMSDK_SYSCON_PMUCTRL_EN_Msk \
    (0x01ul                         \
     << CMSDK_SYSCON_PMUCTRL_EN_Pos) /*!< CMSDK_SYSCON PMUCTRL: PMUCTRL ENABLE Mask */

#define CMSDK_SYSCON_LOCKUPRST_RESETOP_Pos 0
#define CMSDK_SYSCON_LOCKUPRST_RESETOP_Msk \
    (0x01ul                                \
     << CMSDK_SYSCON_LOCKUPRST_RESETOP_Pos) /*!< CMSDK_SYSCON SYS_CTRL: LOCKUP RESET ENABLE Mask */

#define CMSDK_SYSCON_EMICTRL_SIZE_Pos 24
#define CMSDK_SYSCON_EMICTRL_SIZE_Msk \
    (0x00001ul                        \
     << CMSDK_SYSCON_EMICTRL_SIZE_Pos) /*!< CMSDK_SYSCON EMICTRL: SIZE Mask */

#define CMSDK_SYSCON_EMICTRL_TACYC_Pos 16
#define CMSDK_SYSCON_EMICTRL_TACYC_Msk \
    (0x00007ul                         \
     << CMSDK_SYSCON_EMICTRL_TACYC_Pos) /*!< CMSDK_SYSCON EMICTRL: TURNAROUNDCYCLE Mask */

#define CMSDK_SYSCON_EMICTRL_WCYC_Pos 8
#define CMSDK_SYSCON_EMICTRL_WCYC_Msk \
    (0x00003ul                        \
     << CMSDK_SYSCON_EMICTRL_WCYC_Pos) /*!< CMSDK_SYSCON EMICTRL: WRITECYCLE Mask */

#define CMSDK_SYSCON_EMICTRL_RCYC_Pos 0
#define CMSDK_SYSCON_EMICTRL_RCYC_Msk \
    (0x00007ul                        \
     << CMSDK_SYSCON_EMICTRL_RCYC_Pos) /*!< CMSDK_SYSCON EMICTRL: READCYCLE Mask */

#define CMSDK_SYSCON_RSTINFO_SYSRESETREQ_Pos 0
#define CMSDK_SYSCON_RSTINFO_SYSRESETREQ_Msk \
    (0x00001ul                               \
     << CMSDK_SYSCON_RSTINFO_SYSRESETREQ_Pos) /*!< CMSDK_SYSCON RSTINFO: SYSRESETREQ Mask */

#define CMSDK_SYSCON_RSTINFO_WDOGRESETREQ_Pos 1
#define CMSDK_SYSCON_RSTINFO_WDOGRESETREQ_Msk \
    (0x00001ul                                \
     << CMSDK_SYSCON_RSTINFO_WDOGRESETREQ_Pos) /*!< CMSDK_SYSCON RSTINFO: WDOGRESETREQ Mask */

#define CMSDK_SYSCON_RSTINFO_LOCKUPRESET_Pos 2
#define CMSDK_SYSCON_RSTINFO_LOCKUPRESET_Msk \
    (0x00001ul                               \
     << CMSDK_SYSCON_RSTINFO_LOCKUPRESET_Pos) /*!< CMSDK_SYSCON RSTINFO: LOCKUPRESET Mask */

/*@}*/ /* end of group CMSDK_SYSCON */

/*------------- PL230 uDMA (PL230) --------------------------------------*/
/** @addtogroup CMSDK_PL230 CMSDK uDMA controller
  @{
*/
typedef struct {
    __I uint32_t DMA_STATUS; /* Offset: 0x000 (R/W) DMA status Register */
    __O uint32_t DMA_CFG; /* Offset: 0x004 ( /W) DMA configuration Register */
    __IO uint32_t
        CTRL_BASE_PTR; /* Offset: 0x008 (R/W) Channel Control Data Base Pointer Register */
    __I uint32_t
        ALT_CTRL_BASE_PTR; /* Offset: 0x00C (R/ ) Channel Alternate Control Data Base Pointer Register */
    __I uint32_t
        DMA_WAITONREQ_STATUS; /* Offset: 0x010 (R/ ) Channel Wait On Request Status Register */
    __O uint32_t
        CHNL_SW_REQUEST; /* Offset: 0x014 ( /W) Channel Software Request Register */
    __IO uint32_t
        CHNL_USEBURST_SET; /* Offset: 0x018 (R/W) Channel UseBurst Set Register */
    __O uint32_t
        CHNL_USEBURST_CLR; /* Offset: 0x01C ( /W) Channel UseBurst Clear Register */
    __IO uint32_t
        CHNL_REQ_MASK_SET; /* Offset: 0x020 (R/W) Channel Request Mask Set Register */
    __O uint32_t
        CHNL_REQ_MASK_CLR; /* Offset: 0x024 ( /W) Channel Request Mask Clear Register */
    __IO uint32_t
        CHNL_ENABLE_SET; /* Offset: 0x028 (R/W) Channel Enable Set Register */
    __O uint32_t
        CHNL_ENABLE_CLR; /* Offset: 0x02C ( /W) Channel Enable Clear Register */
    __IO uint32_t
        CHNL_PRI_ALT_SET; /* Offset: 0x030 (R/W) Channel Primary-Alterante Set Register */
    __O uint32_t
        CHNL_PRI_ALT_CLR; /* Offset: 0x034 ( /W) Channel Primary-Alterante Clear Register */
    __IO uint32_t
        CHNL_PRIORITY_SET; /* Offset: 0x038 (R/W) Channel Priority Set Register */
    __O uint32_t
        CHNL_PRIORITY_CLR; /* Offset: 0x03C ( /W) Channel Priority Clear Register */
    uint32_t RESERVED0[3];
    __IO uint32_t ERR_CLR; /* Offset: 0x04C (R/W) Bus Error Clear Register   */

} CMSDK_PL230_TypeDef;

#define PL230_DMA_CHNL_BITS 0

#define CMSDK_PL230_DMA_STATUS_MSTREN_Pos \
    0 /*!< CMSDK_PL230 DMA STATUS: MSTREN Position */
#define CMSDK_PL230_DMA_STATUS_MSTREN_Msk \
    (0x00000001ul                         \
     << CMSDK_PL230_DMA_STATUS_MSTREN_Pos) /*!< CMSDK_PL230 DMA STATUS: MSTREN Mask */

#define CMSDK_PL230_DMA_STATUS_STATE_Pos \
    0 /*!< CMSDK_PL230 DMA STATUS: STATE Position */
#define CMSDK_PL230_DMA_STATUS_STATE_Msk \
    (0x0000000Ful                        \
     << CMSDK_PL230_DMA_STATUS_STATE_Pos) /*!< CMSDK_PL230 DMA STATUS: STATE Mask */

#define CMSDK_PL230_DMA_STATUS_CHNLS_MINUS1_Pos \
    0 /*!< CMSDK_PL230 DMA STATUS: CHNLS_MINUS1 Position */
#define CMSDK_PL230_DMA_STATUS_CHNLS_MINUS1_Msk \
    (0x0000001Ful                               \
     << CMSDK_PL230_DMA_STATUS_CHNLS_MINUS1_Pos) /*!< CMSDK_PL230 DMA STATUS: CHNLS_MINUS1 Mask */

#define CMSDK_PL230_DMA_STATUS_TEST_STATUS_Pos \
    0 /*!< CMSDK_PL230 DMA STATUS: TEST_STATUS Position */
#define CMSDK_PL230_DMA_STATUS_TEST_STATUS_Msk \
    (0x00000001ul                              \
     << CMSDK_PL230_DMA_STATUS_TEST_STATUS_Pos) /*!< CMSDK_PL230 DMA STATUS: TEST_STATUS Mask */

#define CMSDK_PL230_DMA_CFG_MSTREN_Pos \
    0 /*!< CMSDK_PL230 DMA CFG: MSTREN Position */
#define CMSDK_PL230_DMA_CFG_MSTREN_Msk \
    (0x00000001ul                      \
     << CMSDK_PL230_DMA_CFG_MSTREN_Pos) /*!< CMSDK_PL230 DMA CFG: MSTREN Mask */

#define CMSDK_PL230_DMA_CFG_CPCCACHE_Pos \
    2 /*!< CMSDK_PL230 DMA CFG: CPCCACHE Position */
#define CMSDK_PL230_DMA_CFG_CPCCACHE_Msk \
    (0x00000001ul                        \
     << CMSDK_PL230_DMA_CFG_CPCCACHE_Pos) /*!< CMSDK_PL230 DMA CFG: CPCCACHE Mask */

#define CMSDK_PL230_DMA_CFG_CPCBUF_Pos \
    1 /*!< CMSDK_PL230 DMA CFG: CPCBUF Position */
#define CMSDK_PL230_DMA_CFG_CPCBUF_Msk \
    (0x00000001ul                      \
     << CMSDK_PL230_DMA_CFG_CPCBUF_Pos) /*!< CMSDK_PL230 DMA CFG: CPCBUF Mask */

#define CMSDK_PL230_DMA_CFG_CPCPRIV_Pos \
    0 /*!< CMSDK_PL230 DMA CFG: CPCPRIV Position */
#define CMSDK_PL230_DMA_CFG_CPCPRIV_Msk \
    (0x00000001ul                       \
     << CMSDK_PL230_DMA_CFG_CPCPRIV_Pos) /*!< CMSDK_PL230 DMA CFG: CPCPRIV Mask */

#define CMSDK_PL230_CTRL_BASE_PTR_Pos \
    PL230_DMA_CHNL_BITS + 5 /*!< CMSDK_PL230 STATUS: BASE_PTR Position */
#define CMSDK_PL230_CTRL_BASE_PTR_Msk \
    (0x0FFFFFFFul                     \
     << CMSDK_PL230_CTRL_BASE_PTR_Pos) /*!< CMSDK_PL230 STATUS: BASE_PTR Mask */

#define CMSDK_PL230_ALT_CTRL_BASE_PTR_Pos \
    0 /*!< CMSDK_PL230 STATUS: MSTREN Position */
#define CMSDK_PL230_ALT_CTRL_BASE_PTR_Msk \
    (0xFFFFFFFFul                         \
     << CMSDK_PL230_ALT_CTRL_BASE_PTR_Pos) /*!< CMSDK_PL230 STATUS: MSTREN Mask */

#define CMSDK_PL230_DMA_WAITONREQ_STATUS_Pos \
    0 /*!< CMSDK_PL230 DMA_WAITONREQ_STATUS: DMA_WAITONREQ_STATUS Position */
#define CMSDK_PL230_DMA_WAITONREQ_STATUS_Msk \
    (0xFFFFFFFFul                            \
     << CMSDK_PL230_DMA_WAITONREQ_STATUS_Pos) /*!< CMSDK_PL230 DMA_WAITONREQ_STATUS: DMA_WAITONREQ_STATUS Mask */

#define CMSDK_PL230_CHNL_SW_REQUEST_Pos \
    0 /*!< CMSDK_PL230 CHNL_SW_REQUEST: CHNL_SW_REQUEST Position */
#define CMSDK_PL230_CHNL_SW_REQUEST_Msk \
    (0xFFFFFFFFul                       \
     << CMSDK_PL230_CHNL_SW_REQUEST_Pos) /*!< CMSDK_PL230 CHNL_SW_REQUEST: CHNL_SW_REQUEST Mask */

#define CMSDK_PL230_CHNL_USEBURST_SET_Pos \
    0 /*!< CMSDK_PL230 CHNL_USEBURST: SET Position */
#define CMSDK_PL230_CHNL_USEBURST_SET_Msk \
    (0xFFFFFFFFul                         \
     << CMSDK_PL230_CHNL_USEBURST_SET_Pos) /*!< CMSDK_PL230 CHNL_USEBURST: SET Mask */

#define CMSDK_PL230_CHNL_USEBURST_CLR_Pos \
    0 /*!< CMSDK_PL230 CHNL_USEBURST: CLR Position */
#define CMSDK_PL230_CHNL_USEBURST_CLR_Msk \
    (0xFFFFFFFFul                         \
     << CMSDK_PL230_CHNL_USEBURST_CLR_Pos) /*!< CMSDK_PL230 CHNL_USEBURST: CLR Mask */

#define CMSDK_PL230_CHNL_REQ_MASK_SET_Pos \
    0 /*!< CMSDK_PL230 CHNL_REQ_MASK: SET Position */
#define CMSDK_PL230_CHNL_REQ_MASK_SET_Msk \
    (0xFFFFFFFFul                         \
     << CMSDK_PL230_CHNL_REQ_MASK_SET_Pos) /*!< CMSDK_PL230 CHNL_REQ_MASK: SET Mask */

#define CMSDK_PL230_CHNL_REQ_MASK_CLR_Pos \
    0 /*!< CMSDK_PL230 CHNL_REQ_MASK: CLR Position */
#define CMSDK_PL230_CHNL_REQ_MASK_CLR_Msk \
    (0xFFFFFFFFul                         \
     << CMSDK_PL230_CHNL_REQ_MASK_CLR_Pos) /*!< CMSDK_PL230 CHNL_REQ_MASK: CLR Mask */

#define CMSDK_PL230_CHNL_ENABLE_SET_Pos \
    0 /*!< CMSDK_PL230 CHNL_ENABLE: SET Position */
#define CMSDK_PL230_CHNL_ENABLE_SET_Msk \
    (0xFFFFFFFFul                       \
     << CMSDK_PL230_CHNL_ENABLE_SET_Pos) /*!< CMSDK_PL230 CHNL_ENABLE: SET Mask */

#define CMSDK_PL230_CHNL_ENABLE_CLR_Pos \
    0 /*!< CMSDK_PL230 CHNL_ENABLE: CLR Position */
#define CMSDK_PL230_CHNL_ENABLE_CLR_Msk \
    (0xFFFFFFFFul                       \
     << CMSDK_PL230_CHNL_ENABLE_CLR_Pos) /*!< CMSDK_PL230 CHNL_ENABLE: CLR Mask */

#define CMSDK_PL230_CHNL_PRI_ALT_SET_Pos \
    0 /*!< CMSDK_PL230 CHNL_PRI_ALT: SET Position */
#define CMSDK_PL230_CHNL_PRI_ALT_SET_Msk \
    (0xFFFFFFFFul                        \
     << CMSDK_PL230_CHNL_PRI_ALT_SET_Pos) /*!< CMSDK_PL230 CHNL_PRI_ALT: SET Mask */

#define CMSDK_PL230_CHNL_PRI_ALT_CLR_Pos \
    0 /*!< CMSDK_PL230 CHNL_PRI_ALT: CLR Position */
#define CMSDK_PL230_CHNL_PRI_ALT_CLR_Msk \
    (0xFFFFFFFFul                        \
     << CMSDK_PL230_CHNL_PRI_ALT_CLR_Pos) /*!< CMSDK_PL230 CHNL_PRI_ALT: CLR Mask */

#define CMSDK_PL230_CHNL_PRIORITY_SET_Pos \
    0 /*!< CMSDK_PL230 CHNL_PRIORITY: SET Position */
#define CMSDK_PL230_CHNL_PRIORITY_SET_Msk \
    (0xFFFFFFFFul                         \
     << CMSDK_PL230_CHNL_PRIORITY_SET_Pos) /*!< CMSDK_PL230 CHNL_PRIORITY: SET Mask */

#define CMSDK_PL230_CHNL_PRIORITY_CLR_Pos \
    0 /*!< CMSDK_PL230 CHNL_PRIORITY: CLR Position */
#define CMSDK_PL230_CHNL_PRIORITY_CLR_Msk \
    (0xFFFFFFFFul                         \
     << CMSDK_PL230_CHNL_PRIORITY_CLR_Pos) /*!< CMSDK_PL230 CHNL_PRIORITY: CLR Mask */

#define CMSDK_PL230_ERR_CLR_Pos 0 /*!< CMSDK_PL230 ERR: CLR Position */
#define CMSDK_PL230_ERR_CLR_Msk \
    (0x00000001ul << CMSDK_PL230_ERR_CLR_Pos) /*!< CMSDK_PL230 ERR: CLR Mask */

/*@}*/ /* end of group CMSDK_PL230 */

/*------------- PrimeCell UART (PL110) --------------------------------------*/
/** @addtogroup CMSDK_PL110 CMSDK PrimeCell UART
  @{
*/

typedef struct {
    __IO uint32_t UARTDR;  // <h> Data
    //   <o.11>   OE: Overrun error <r>
    //   <o.10>   BE: Break error <r>
    //   <o.9>    PE: Parity error <r>
    //   <o.8>    FE: Framing error <r>
    //   <o.0..7> DATA: Received or Transmitting data (0..255)
    // </h>
    union {
        __I uint32_t UARTRSR;  // <h> Receive Status <r>
        //   <o.3>    OE: Overrun error <r>
        //   <o.2>    BE: Break error <r>
        //   <o.1>    PE: Parity error <r>
        //   <o.0>    FE: Framing error <r>
        // </h>
        __O uint32_t UARTECR;  // <h> Error Clear <w>
        //   <o.3>    OE: Overrun error <w>
        //   <o.2>    BE: Break error <w>
        //   <o.1>    PE: Parity error <w>
        //   <o.0>    FE: Framing error <w>
        // </h>
    } UART;
    uint32_t RESERVED0[4];
    __IO uint32_t UARTFR;  // <h> Flags <r>
    //   <o.8>    RI: Ring indicator <r>
    //   <o.7>    TXFE: Transmit FIFO empty <r>
    //   <o.6>    RXFF: Receive FIFO full <r>
    //   <o.5>    TXFF: Transmit FIFO full <r>
    //   <o.4>    RXFE: Receive FIFO empty <r>
    //   <o.3>    BUSY: UART busy <r>
    //   <o.2>    DCD: Data carrier detect <r>
    //   <o.1>    DSR: Data set ready <r>
    //   <o.0>    CTS: Clear to send <r>
    // </h>
    uint32_t RESERVED1;
    __IO uint32_t UARTILPR;  // <h> IrDA Low-power Counter
    //   <o.0..7> ILPDVSR: 8-bit low-power divisor value (0..255)
    // </h>
    __IO uint32_t UARTIBRD;  // <h> Integer Baud Rate
    //   <o.0..15> BAUD DIVINT: Integer baud rate divisor (0..65535)
    // </h>
    __IO uint32_t UARTFBRD;  // <h> Fractional Baud Rate
    //   <o.0..5> BAUD DIVFRAC: Fractional baud rate divisor (0..63)
    // </h>
    __IO uint32_t UARTLCR_H;  // <h> Line Control
    //   <o.8>    SPS: Stick parity select
    //   <o.5..6> WLEN: Word length
    //     <0=> 5 bits
    //     <1=> 6 bits
    //     <2=> 7 bits
    //     <3=> 8 bits
    //   <o.4>    FEN: Enable FIFOs
    //   <o.3>    STP2: Two stop bits select
    //   <o.2>    EPS: Even parity select
    //   <o.1>    PEN: Parity enable
    //   <o.0>    BRK: Send break
    // </h>
    __IO uint32_t UARTCR;  // <h> Control
    //   <o.15>   CTSEn: CTS hardware flow control enable
    //   <o.14>   RTSEn: RTS hardware flow control enable
    //   <o.13>   Out2: Complement of Out2 modem status output
    //   <o.12>   Out1: Complement of Out1 modem status output
    //   <o.11>   RTS: Request to send
    //   <o.10>   DTR: Data transmit ready
    //   <o.9>    RXE: Receive enable
    //   <o.8>    TXE: Transmit enable
    //   <o.7>    LBE: Loop-back enable
    //   <o.2>    SIRLP: IrDA SIR low power mode
    //   <o.1>    SIREN: SIR enable
    //   <o.0>    UARTEN: UART enable
    // </h>
    __IO uint32_t UARTIFLS;  // <h> Interrupt FIFO Level Select
    //   <o.3..5> RXIFLSEL: Receive interrupt FIFO level select
    //     <0=> >= 1/8 full
    //     <1=> >= 1/4 full
    //     <2=> >= 1/2 full
    //     <3=> >= 3/4 full
    //     <4=> >= 7/8 full
    //     <5=> reserved
    //     <6=> reserved
    //     <7=> reserved
    //   <o.0..2> TXIFLSEL: Transmit interrupt FIFO level select
    //     <0=> <= 1/8 full
    //     <1=> <= 1/4 full
    //     <2=> <= 1/2 full
    //     <3=> <= 3/4 full
    //     <4=> <= 7/8 full
    //     <5=> reserved
    //     <6=> reserved
    //     <7=> reserved
    // </h>
    __IO uint32_t UARTIMSC;  // <h> Interrupt Mask Set / Clear
    //   <o.10>   OEIM: Overrun error interrupt mask
    //   <o.9>    BEIM: Break error interrupt mask
    //   <o.8>    PEIM: Parity error interrupt mask
    //   <o.7>    FEIM: Framing error interrupt mask
    //   <o.6>    RTIM: Receive interrupt mask
    //   <o.5>    TXIM: Transmit interrupt mask
    //   <o.4>    RXIM: Receive interrupt mask
    //   <o.3>    DSRMIM: nUARTDSR modem interrupt mask
    //   <o.2>    DCDMIM: nUARTDCD modem interrupt mask
    //   <o.1>    CTSMIM: nUARTCTS modem interrupt mask
    //   <o.0>    RIMIM: nUARTRI modem interrupt mask
    // </h>
    __IO uint32_t UARTRIS;  // <h> Raw Interrupt Status <r>
    //   <o.10>   OERIS: Overrun error interrupt status <r>
    //   <o.9>    BERIS: Break error interrupt status <r>
    //   <o.8>    PERIS: Parity error interrupt status <r>
    //   <o.7>    FERIS: Framing error interrupt status <r>
    //   <o.6>    RTRIS: Receive timeout interrupt status <r>
    //   <o.5>    TXRIS: Transmit interrupt status <r>
    //   <o.4>    RXRIS: Receive interrupt status <r>
    //   <o.3>    DSRRMIS: nUARTDSR modem interrupt status <r>
    //   <o.2>    DCDRMIS: nUARTDCD modem interrupt status <r>
    //   <o.1>    CTSRMIS: nUARTCTS modem interrupt status <r>
    //   <o.0>    RIRMIS: nUARTRI modem interrupt status <r>
    // </h>
    __IO uint32_t UARTMIS;  // <h> Masked Interrupt Status <r>
    //   <o.10>   OEMIS: Overrun error masked interrupt status <r>
    //   <o.9>    BEMIS: Break error masked interrupt status <r>
    //   <o.8>    PEMIS: Parity error masked interrupt status <r>
    //   <o.7>    FEMIS: Framing error masked interrupt status <r>
    //   <o.6>    RTMIS: Receive timeout masked interrupt status <r>
    //   <o.5>    TXMIS: Transmit masked interrupt status <r>
    //   <o.4>    RXMIS: Receive masked interrupt status <r>
    //   <o.3>    DSRMMIS: nUARTDSR modem masked interrupt status <r>
    //   <o.2>    DCDMMIS: nUARTDCD modem masked interrupt status <r>
    //   <o.1>    CTSMMIS: nUARTCTS modem masked interrupt status <r>
    //   <o.0>    RIMMIS: nUARTRI modem masked interrupt status <r>
    // </h>
    __O uint32_t UARTICR;  // <h> Interrupt Clear <w>
    //   <o.10>   OEIC: Overrun error interrupt clear <w>
    //   <o.9>    BEIC: Break error interrupt clear <w>
    //   <o.8>    PEIC: Parity error interrupt clear <w>
    //   <o.7>    FEIC: Framing error interrupt clear <w>
    //   <o.6>    RTIC: Receive timeout interrupt clear <w>
    //   <o.5>    TXIC: Transmit interrupt clear <w>
    //   <o.4>    RXIC: Receive interrupt clear <w>
    //   <o.3>    DSRMIC: nUARTDSR modem interrupt clear <w>
    //   <o.2>    DCDMIC: nUARTDCD modem interrupt clear <w>
    //   <o.1>    CTSMIC: nUARTCTS modem interrupt clear <w>
    //   <o.0>    RIMIC: nUARTRI modem interrupt clear <w>
    // </h>
    __IO uint32_t UARTDMACR;  // <h> DMA Control
    //   <o.2>    DMAONERR: DMA on error
    //   <o.1>    TXDMAE: Transmit DMA enable
    //   <o.0>    RXDMAE: Receive DMA enable
    // </h>
} PL110_UART_TypeDef;

#define CMSDK_PL110_DATAOVRRUN_Pos \
    11 /*!< CMSDK_PL110 DATAOVRRUN: Data Overrun Position */
#define CMSDK_PL110_DATAOVRRUN_Msk \
    (0x1ul                         \
     << CMSDK_PL110_DATAOVRRUN_Pos) /*!< CMSDK_PL110 DATAOVRRUN: Data Overrun Mask */

#define CMSDK_PL110_DATABREAKERR_Pos \
    10 /*!< CMSDK_PL110 DATABREAKERR: Data Break Error Position */
#define CMSDK_PL110_DATABREAKERR_Msk \
    (0x1ul                           \
     << CMSDK_PL110_DATABREAKERR_Pos) /*!< CMSDK_PL110 DATABREAKERR: Data Break Error Mask */

#define CMSDK_PL110_DATAPARITYERR_Pos \
    9 /*!< CMSDK_PL110 DATAPARITYERR: Data Parity Error Position */
#define CMSDK_PL110_DATAPARITYERR_Msk \
    (0x1ul                            \
     << CMSDK_PL110_DATAPARITYERR_Pos) /*!< CMSDK_PL110 DATAPARITYERR: Data Parity Error Mask */

#define CMSDK_PL110_DATAFRAMEERR_Pos \
    8 /*!< CMSDK_PL110 DATAFRAMEERR: Data Frame Error Position */
#define CMSDK_PL110_DATAFRAMEERR_Msk \
    (0x1ul                           \
     << CMSDK_PL110_DATAFRAMEERR_Pos) /*!< CMSDK_PL110 DATAFRAMEERR: Data Frame Error Mask */

#define CMSDK_PL110_RECOVRRUN_Pos \
    3 /*!< CMSDK_PL110 RECOVRRUN: Receive Overrun Position */
#define CMSDK_PL110_RECOVRRUN_Msk \
    (0x1ul                        \
     << CMSDK_PL110_RECOVRRUN_Pos) /*!< CMSDK_PL110 RECOVRRUN: Receive Overrun Mask */

#define CMSDK_PL110_RECBREAKERR_Pos \
    2 /*!< CMSDK_PL110 RECBREAKERR: Receive Break Error Position */
#define CMSDK_PL110_RECBREAKERR_Msk \
    (0x1ul                          \
     << CMSDK_PL110_RECBREAKERR_Pos) /*!< CMSDK_PL110 RECBREAKERR: Receive Break Error Mask */

#define CMSDK_PL110_RECPARITYERR_Pos \
    1 /*!< CMSDK_PL110 RECPARITYERR: Receive Parity Error Position */
#define CMSDK_PL110_RECPARITYERR_Msk \
    (0x1ul                           \
     << CMSDK_PL110_RECPARITYERR_Pos) /*!< CMSDK_PL110 RECPARITYERR: Receive Parity Error Mask */

#define CMSDK_PL110_RECFRAMEERR_Pos \
    0 /*!< CMSDK_PL110 RECFRAMEERR: Receive Frame Error Position */
#define CMSDK_PL110_RECFRAMEERR_Msk \
    (0x1ul                          \
     << CMSDK_PL110_RECFRAMEERR_Pos) /*!< CMSDK_PL110 RECFRAMEERR: Receive Frame Error Mask */

#define CMSDK_PL110_ERRCLROVRRUN_Pos \
    3 /*!< CMSDK_PL110 ERRCLROVRRUN: Clear Overrun Position */
#define CMSDK_PL110_ERRCLROVRRUN_Msk \
    (0x1ul                           \
     << CMSDK_PL110_ERRCLROVRRUN_Pos) /*!< CMSDK_PL110 ERRCLROVRRUN: Clear Overrun Mask */

#define CMSDK_PL110_ERRCLRBREAKERR_Pos \
    2 /*!< CMSDK_PL110 ERRCLRBREAKERR: Clear Break Error Position */
#define CMSDK_PL110_ERRCLRBREAKERR_Msk \
    (0x1ul                             \
     << CMSDK_PL110_ERRCLRBREAKERR_Pos) /*!< CMSDK_PL110 ERRCLRBREAKERR: Clear Break Error Mask */

#define CMSDK_PL110_ERRCLRPARITYERR_Pos \
    1 /*!< CMSDK_PL110 ERRCLRPARITYERR: Clear Parity Error Position */
#define CMSDK_PL110_ERRCLRPARITYERR_Msk \
    (0x1ul                              \
     << CMSDK_PL110_ERRCLRPARITYERR_Pos) /*!< CMSDK_PL110 ERRCLRPARITYERR: Clear Parity Error Mask */

#define CMSDK_PL110_ERRCLRFRAMEERR_Pos \
    0 /*!< CMSDK_PL110 ERRCLRFRAMEERR: Clear Frame Error Position */
#define CMSDK_PL110_ERRCLRFRAMEERR_Msk \
    (0x1ul                             \
     << CMSDK_PL110_ERRCLRFRAMEERR_Pos) /*!< CMSDK_PL110 ERRCLRFRAMEERR: Clear Frame Error Mask */

#define CMSDK_PL110_FLAG_RINGIND_Pos \
    8 /*!< CMSDK_PL110 FLAG_RINGIND: Ring Indicator Position */
#define CMSDK_PL110_FLAG_RINGIND_Msk \
    (0x1ul                           \
     << CMSDK_PL110_FLAG_RINGIND_Pos) /*!< CMSDK_PL110 FLAG_RINGIND: Ring Indicator Mask */

#define CMSDK_PL110_FLAG_TXFEMPTY_Pos \
    7 /*!< CMSDK_PL110 FLAG_TXFEMPTY: Transmit FIFO Empty Position */
#define CMSDK_PL110_FLAG_TXFEMPTY_Msk \
    (0x1ul                            \
     << CMSDK_PL110_FLAG_TXFEMPTY_Pos) /*!< CMSDK_PL110 FLAG_TXFEMPTY: Transmit FIFO Empty Mask */

#define CMSDK_PL110_FLAG_RXFFULL_Pos \
    6 /*!< CMSDK_PL110 FLAG_RXFFULL: Receive FIFO Full Position */
#define CMSDK_PL110_FLAG_RXFFULL_Msk \
    (0x1ul                           \
     << CMSDK_PL110_FLAG_RXFFULL_Pos) /*!< CMSDK_PL110 FLAG_RXFFULL: Receive FIFO Full Mask */

#define CMSDK_PL110_FLAG_TXFFULL_Pos \
    5 /*!< CMSDK_PL110 FLAG_TXFFULL: Transmit FIFO Full Position */
#define CMSDK_PL110_FLAG_TXFFULL_Msk \
    (0x1ul                           \
     << CMSDK_PL110_FLAG_TXFFULL_Pos) /*!< CMSDK_PL110 FLAG_TXFFULL: Transmit FIFO Full Mask */

#define CMSDK_PL110_FLAG_RXFEMPTY_Pos \
    4 /*!< CMSDK_PL110 FLAG_RXFEMPTY: Receive FIFO Empty Position */
#define CMSDK_PL110_FLAG_RXFEMPTY_Msk \
    (0x1ul                            \
     << CMSDK_PL110_FLAG_RXFEMPTY_Pos) /*!< CMSDK_PL110 FLAG_RXFEMPTY: Receive FIFO Empty Mask */

#define CMSDK_PL110_FLAG_UARTBUSY_Pos \
    3 /*!< CMSDK_PL110 FLAG_UARTBUSY: UART Busy Position */
#define CMSDK_PL110_FLAG_UARTBUSY_Msk \
    (0x1ul                            \
     << CMSDK_PL110_FLAG_UARTBUSY_Pos) /*!< CMSDK_PL110 FLAG_UARTBUSY: UART Busy Mask */

#define CMSDK_PL110_FLAG_CARRIERDETECT_Pos \
    2 /*!< CMSDK_PL110 FLAG_CARRIERDETECT: Carrier Detect Position */
#define CMSDK_PL110_FLAG_CARRIERDETECT_Msk \
    (0x1ul                                 \
     << CMSDK_PL110_FLAG_CARRIERDETECT_Pos) /*!< CMSDK_PL110 FLAG_CARRIERDETECT: Carrier Detect Mask */

#define CMSDK_PL110_FLAG_DATASETREADY_Pos \
    1 /*!< CMSDK_PL110 FLAG_DATASETREADY: Data Set Ready Position */
#define CMSDK_PL110_FLAG_DATASETREADY_Msk \
    (0x1ul                                \
     << CMSDK_PL110_FLAG_DATASETREADY_Pos) /*!< CMSDK_PL110 FLAG_DATASETREADY: Data Set Ready Mask */

#define CMSDK_PL110_FLAG_CLR2SEND_Pos \
    0 /*!< CMSDK_PL110 FLAG_CLR2SEND: Clear To Send Position */
#define CMSDK_PL110_FLAG_CLR2SEND_Msk \
    (0x1ul                            \
     << CMSDK_PL110_FLAG_CLR2SEND_Pos) /*!< CMSDK_PL110 FLAG_CLR2SEND: Clear To Send Mask */

#define CMSDK_PL110_IRDALOWPOWERCOUNT_Pos \
    0 /*!< CMSDK_PL110 IRDALOWPOWERCOUNT: IrDA 8-bit low-power divisor value Position */
#define CMSDK_PL110_IRDALOWPOWERCOUNT_Msk \
    (0xFFul                               \
     << CMSDK_PL110_IRDALOWPOWERCOUNT_Pos) /*!< CMSDK_PL110 IRDALOWPOWERCOUNT: IrDA 8-bit low-power divisor value Mask */

#define CMSDK_PL110_INTDIVIDER_Pos \
    0 /*!< CMSDK_PL110 INTDIVIDER: Integer Divider Position */
#define CMSDK_PL110_INTDIVIDER_Msk \
    (0xFFFFul                      \
     << CMSDK_PL110_INTDIVIDER_Pos) /*!< CMSDK_PL110 INTDIVIDER: Integer Divider Mask */

#define CMSDK_PL110_FRACTDIVIDER_Pos \
    0 /*!< CMSDK_PL110 FRACTDIVIDER: Fractional Divider Position */
#define CMSDK_PL110_FRACTDIVIDER_Msk \
    (0x3Ful                          \
     << CMSDK_PL110_FRACTDIVIDER_Pos) /*!< CMSDK_PL110 FRACTDIVIDER: Fractional Divider Mask */

#define CMSDK_PL110_STICKPARITYSEL_Pos \
    8 /*!< CMSDK_PL110 STICKPARITYSEL: Stick parity select Position */
#define CMSDK_PL110_STICKPARITYSEL_Msk \
    (0x1ul                             \
     << CMSDK_PL110_STICKPARITYSEL_Pos) /*!< CMSDK_PL110 STICKPARITYSEL: Stick parity select Mask */

#define CMSDK_PL110_WORDLEN_Pos \
    5 /*!< CMSDK_PL110 WORDLEN: Word Length Select Position */
#define CMSDK_PL110_WORDLEN_Msk \
    (0x3ul                      \
     << CMSDK_PL110_WORDLEN_Pos) /*!< CMSDK_PL110 WORDLEN: Word Length Select Mask */

#define CMSDK_PL110_ENFIFOS_Pos \
    4 /*!< CMSDK_PL110 ENFIFOS: Enable FIFOs Position */
#define CMSDK_PL110_ENFIFOS_Msk \
    (0x1ul                      \
     << CMSDK_PL110_ENFIFOS_Pos) /*!< CMSDK_PL110 ENFIFOS: Enable FIFOs Mask */

#define CMSDK_PL110_2STOPBITS_Pos \
    3 /*!< CMSDK_PL110 2STOPBITS: Two Stop Bits Select Position */
#define CMSDK_PL110_2STOPBITS_Msk \
    (0x1ul                        \
     << CMSDK_PL110_2STOPBITS_Pos) /*!< CMSDK_PL110 2STOPBITS: Two Stop Bits Select Mask */

#define CMSDK_PL110_EVENPARITY_Pos \
    2 /*!< CMSDK_PL110 EVENPARITY: Even Parity Select Position */
#define CMSDK_PL110_EVENPARITY_Msk \
    (0x1ul                         \
     << CMSDK_PL110_EVENPARITY_Pos) /*!< CMSDK_PL110 EVENPARITY: Even Parity Select Mask */

#define CMSDK_PL110_PARITYEN_Pos \
    1 /*!< CMSDK_PL110 PARITYEN: Parity Enable Position */
#define CMSDK_PL110_PARITYEN_Msk \
    (0x1ul                       \
     << CMSDK_PL110_PARITYEN_Pos) /*!< CMSDK_PL110 PARITYEN: Parity Enable Mask */

#define CMSDK_PL110_SENDBREAK_Pos \
    0 /*!< CMSDK_PL110 SENDBREAK: Send Break Position */
#define CMSDK_PL110_SENDBREAK_Msk \
    (0x1ul                        \
     << CMSDK_PL110_SENDBREAK_Pos) /*!< CMSDK_PL110 SENDBREAK: Send Break Mask */

#define CMSDK_PL110_CTS_FLOWCTRL_Pos \
    15 /*!< CMSDK_PL110 CTS_FLOWCTRL: Enable CTS Flow Control Position */
#define CMSDK_PL110_CTS_FLOWCTRL_Msk \
    (0x1ul                           \
     << CMSDK_PL110_CTS_FLOWCTRL_Pos) /*!< CMSDK_PL110 CTS_FLOWCTRL: Enable CTS Flow Control Mask */

#define CMSDK_PL110_RTS_FLOWCTRL_Pos \
    14 /*!< CMSDK_PL110 RTS_FLOWCTRL: Enable RTS Flow Control Position */
#define CMSDK_PL110_RTS_FLOWCTRL_Msk \
    (0x1ul                           \
     << CMSDK_PL110_RTS_FLOWCTRL_Pos) /*!< CMSDK_PL110 RTS_FLOWCTRL: Enable RTS Flow Control Mask */

#define CMSDK_PL110_OUT2_Pos \
    13 /*!< CMSDK_PL110 OUT2: Complement of Out2 modem status output Position */
#define CMSDK_PL110_OUT2_Msk \
    (0x1ul                   \
     << CMSDK_PL110_OUT2_Pos) /*!< CMSDK_PL110 OUT2: Complement of Out2 modem status output Mask */

#define CMSDK_PL110_OUT1_Pos \
    12 /*!< CMSDK_PL110 OUT1: Complement of Out1 modem status output Position */
#define CMSDK_PL110_OUT1_Msk \
    (0x1ul                   \
     << CMSDK_PL110_OUT1_Pos) /*!< CMSDK_PL110 OUT1: Complement of Out1 modem status output Mask */

#define CMSDK_PL110_REQ2SEND_Pos \
    11 /*!< CMSDK_PL110 REQ2SEND: Request To Send Position */
#define CMSDK_PL110_REQ2SEND_Msk \
    (0x1ul                       \
     << CMSDK_PL110_REQ2SEND_Pos) /*!< CMSDK_PL110 REQ2SEND: Request To Send Mask */

#define CMSDK_PL110_DATATRANSREADY_Pos \
    10 /*!< CMSDK_PL110 DATATRANSREADY: Transmit Ready Position */
#define CMSDK_PL110_DATATRANSREADY_Msk \
    (0x1ul                             \
     << CMSDK_PL110_DATATRANSREADY_Pos) /*!< CMSDK_PL110 DATATRANSREADY: Transmit Ready Mask */

#define CMSDK_PL110_RXEN_Pos 9 /*!< CMSDK_PL110 RXEN: Receive Enable Position */
#define CMSDK_PL110_RXEN_Msk \
    (0x1ul                   \
     << CMSDK_PL110_RXEN_Pos) /*!< CMSDK_PL110 RXEN: Receive Enable Mask */

#define CMSDK_PL110_TXEN_Pos \
    8 /*!< CMSDK_PL110 TXEN: Transmit Enable Position */
#define CMSDK_PL110_TXEN_Msk \
    (0x1ul                   \
     << CMSDK_PL110_TXEN_Pos) /*!< CMSDK_PL110 TXEN: Transmit Enable Mask */

#define CMSDK_PL110_LOOPBACKEN_Pos \
    7 /*!< CMSDK_PL110 LOOPBACKEN: Loopback Enable Position */
#define CMSDK_PL110_LOOPBACKEN_Msk \
    (0x1ul                         \
     << CMSDK_PL110_LOOPBACKEN_Pos) /*!< CMSDK_PL110 LOOPBACKEN: Loopback Enable Mask */

#define CMSDK_PL110_IRDASIRLPM_Pos \
    2 /*!< CMSDK_PL110 IRDASIRLPM: IRDA SIR Low Power Position */
#define CMSDK_PL110_IRDASIRLPM_Msk \
    (0x1ul                         \
     << CMSDK_PL110_IRDASIRLPM_Pos) /*!< CMSDK_PL110 IRDASIRLPM: IRDA SIR Low Power Mask */

#define CMSDK_PL110_SIREN_Pos 1 /*!< CMSDK_PL110 SIREN: SIR Enable Position */
#define CMSDK_PL110_SIREN_Msk \
    (0x1ul << CMSDK_PL110_SIREN_Pos) /*!< CMSDK_PL110 SIREN: SIR Enable Mask */

#define CMSDK_PL110_UARTEN_Pos \
    0 /*!< CMSDK_PL110 UARTEN: UART Enable Position */
#define CMSDK_PL110_UARTEN_Msk \
    (0x1ul                     \
     << CMSDK_PL110_UARTEN_Pos) /*!< CMSDK_PL110 UARTEN: UART Enable Mask */

#define CMSDK_PL110_RECINTFIFOLEVEL_Pos \
    3 /*!< CMSDK_PL110 RECINTFIFOLEVEL: Set Receive Int FIFO Level Position */
#define CMSDK_PL110_RECINTFIFOLEVEL_Msk \
    (0x7ul                              \
     << CMSDK_PL110_RECINTFIFOLEVEL_Pos) /*!< CMSDK_PL110 RECINTFIFOLEVEL: Set Receive Int FIFO Level Mask */

#define CMSDK_PL110_TRANSINTFIFOLEVEL_Pos \
    0 /*!< CMSDK_PL110 TRANSINTFIFOLEVEL: Set Transmit Int FIFO Level Position */
#define CMSDK_PL110_TRANSINTFIFOLEVEL_Msk \
    (0x7ul                                \
     << CMSDK_PL110_TRANSINTFIFOLEVEL_Pos) /*!< CMSDK_PL110 TRANSINTFIFOLEVEL: Set Transmit Int FIFO Level Mask */

#define CMSDK_PL110_SETMASK_OVRRUNERRINT_Pos \
    10 /*!< CMSDK_PL110 SETMASK_OVRRUNERRINT: Set Overrun Error Int Mask Position */
#define CMSDK_PL110_SETMASK_OVRRUNERRINT_Msk \
    (0x1ul                                   \
     << CMSDK_PL110_SETMASK_OVRRUNERRINT_Pos) /*!< CMSDK_PL110 SETMASK_OVRRUNERRINT: Set Overrun Error Int Mask Mask */

#define CMSDK_PL110_SETMASK_BREAKERRINT_Pos \
    9 /*!< CMSDK_PL110 SETMASK_BREAKERRINT: Set Break Error Int Mask Position */
#define CMSDK_PL110_SETMASK_BREAKERRINT_Msk \
    (0x1ul                                  \
     << CMSDK_PL110_SETMASK_BREAKERRINT_Pos) /*!< CMSDK_PL110 SETMASK_BREAKERRINT: Set Break Error Int Mask Mask */

#define CMSDK_PL110_SETMASK_PARITYERRINT_Pos \
    8 /*!< CMSDK_PL110 SETMASK_PARITYERRINT: Set Parity Error Int Mask Position */
#define CMSDK_PL110_SETMASK_PARITYERRINT_Msk \
    (0x1ul                                   \
     << CMSDK_PL110_SETMASK_PARITYERRINT_Pos) /*!< CMSDK_PL110 SETMASK_PARITYERRINT: Set Parity Error Int Mask Mask */

#define CMSDK_PL110_SETMASK_FRAMEERRINT_Pos \
    7 /*!< CMSDK_PL110 SETMASK_FRAMEERRINT: Set Frame Error Int Mask Position */
#define CMSDK_PL110_SETMASK_FRAMEERRINT_Msk \
    (0x1ul                                  \
     << CMSDK_PL110_SETMASK_FRAMEERRINT_Pos) /*!< CMSDK_PL110 SETMASK_FRAMEERRINT: Set Frame Error Int Mask Mask */

#define CMSDK_PL110_SETMASK_RECTRANSINT_Pos \
    6 /*!< CMSDK_PL110 SETMASK_RECTRANSINT: Set Transmit Receive Comb Int Mask Position */
#define CMSDK_PL110_SETMASK_RECTRANSINT_Msk \
    (0x1ul                                  \
     << CMSDK_PL110_SETMASK_RECTRANSINT_Pos) /*!< CMSDK_PL110 SETMASK_RECTRANSINT: Set Transmit Receive Comb Int Mask Mask */

#define CMSDK_PL110_SETMASK_TRANSINT_Pos \
    5 /*!< CMSDK_PL110 SETMASK_TRANSINT: Set Transmit Int Mask Position */
#define CMSDK_PL110_SETMASK_TRANSINT_Msk \
    (0x1ul                               \
     << CMSDK_PL110_SETMASK_TRANSINT_Pos) /*!< CMSDK_PL110 SETMASK_TRANSINT: Set Transmit Int Mask Mask */

#define CMSDK_PL110_SETMASK_RECINT_Pos \
    4 /*!< CMSDK_PL110 SETMASK_RECINT: Set Receive Int Mask Position */
#define CMSDK_PL110_SETMASK_RECINT_Msk \
    (0x1ul                             \
     << CMSDK_PL110_SETMASK_RECINT_Pos) /*!< CMSDK_PL110 SETMASK_RECINT: Set Receive Int Mask Mask */

#define CMSDK_PL110_SETMASK_UART_DSRMODINT_Pos \
    3 /*!< CMSDK_PL110 SETMASK_UART_DSRMODINT: Set Data Set Ready Modem Int Mask Position */
#define CMSDK_PL110_SETMASK_UART_DSRMODINT_Msk \
    (0x1ul                                     \
     << CMSDK_PL110_SETMASK_UARTD_SRMODINT_Pos) /*!< CMSDK_PL110 SETMASK_UART_DSRMODINT: Set Data Set Ready Modem Int Mask Mask */

#define CMSDK_PL110_SETMASK_UART_DCDMODINT_Pos \
    2 /*!< CMSDK_PL110 SETMASK_UART_DCDMODINT: Set Data Carrier Detect Modem Int Mask Position */
#define CMSDK_PL110_SETMASK_UART_DCDMODINT_Msk \
    (0x1ul                                     \
     << CMSDK_PL110_SETMASK_UART_DCDMODINT_Pos) /*!< CMSDK_PL110 SETMASK_UART_DCDMODINT: Set Data Carrier Detect Modem Int Mask Mask */

#define CMSDK_PL110_SETMASK_UART_CTSMODINT_Pos \
    1 /*!< CMSDK_PL110 SETMASK_UART_CTSMODINT: Set Clear To Send Modem Int Mask Position */
#define CMSDK_PL110_SETMASK_UART_CTSMODINT_Msk \
    (0x1ul                                     \
     << CMSDK_PL110_SETMASK_UART_CTSMODINT_Pos) /*!< CMSDK_PL110 SETMASK_UART_CTSMODINT: Set Clear To Send Modem Int Mask Mask */

#define CMSDK_PL110_SETMASK_UART_RIMODINT_Pos \
    0 /*!< CMSDK_PL110 SETMASK_UART_RIMODINT: Set nUARTRI Modem Int Mask Position */
#define CMSDK_PL110_SETMASK_UART_RIMODINT_Msk \
    (0x1ul                                    \
     << CMSDK_PL110_SETMASK_UART_RIMODINT_Pos) /*!< CMSDK_PL110 SETMASK_UART_RIMODINT: Set nUARTRI Modem Int Mask Mask */

#define CMSDK_PL110_RAWINTSTAT_OVRRUNERRINT_Pos \
    10 /*!< CMSDK_PL110 RAWINTSTAT_OVRRUNERRINT: Raw Overrun Error Int Status Mask Position */
#define CMSDK_PL110_RAWINTSTAT_OVRRUNERRINT_Msk \
    (0x1ul                                      \
     << CMSDK_PL110_RAWINTSTAT_OVRRUNERRINT_Pos) /*!< CMSDK_PL110 RAWINTSTAT_OVRRUNERRINT: Raw Overrun Error Int Status  Mask */

#define CMSDK_PL110_RAWINTSTAT_BREAKERRINT_Pos \
    9 /*!< CMSDK_PL110 RAWINTSTAT_BREAKERRINT: Raw Break Error Int Status Mask Position */
#define CMSDK_PL110_RAWINTSTAT_BREAKERRINT_Msk \
    (0x1ul                                     \
     << CMSDK_PL110_RAWINTSTAT_BREAKERRINT_Pos) /*!< CMSDK_PL110 RAWINTSTAT_BREAKERRINT: Raw Break Error Int Status  Mask */

#define CMSDK_PL110_RAWINTSTAT_PARITYERRINT_Pos \
    8 /*!< CMSDK_PL110 RAWINTSTAT_PARITYERRINT: Raw Parity Error Int Status Mask Position */
#define CMSDK_PL110_RAWINTSTAT_PARITYERRINT_Msk \
    (0x1ul                                      \
     << CMSDK_PL110_RAWINTSTAT_PARITYERRINT_Pos) /*!< CMSDK_PL110 RAWINTSTAT_PARITYERRINT: Raw Parity Error Int Status  Mask */

#define CMSDK_PL110_RAWINTSTAT_FRAMEERRINT_Pos \
    7 /*!< CMSDK_PL110 RAWINTSTAT_FRAMEERRINT: Raw Frame Error Int Status Mask Position */
#define CMSDK_PL110_RAWINTSTAT_FRAMEERRINT_Msk \
    (0x1ul                                     \
     << CMSDK_PL110_RAWINTSTAT_FRAMEERRINT_Pos) /*!< CMSDK_PL110 RAWINTSTAT_FRAMEERRINT: Raw Frame Error Int Status Mask */

#define CMSDK_PL110_RAWINTSTAT_RECTRANSINT_Pos \
    6 /*!< CMSDK_PL110 RAWINTSTAT_RECTRANSINT: Raw Transmit Receive Comb Int Status Position */
#define CMSDK_PL110_RAWINTSTAT_RECTRANSINT_Msk \
    (0x1ul                                     \
     << CMSDK_PL110_RAWINTSTAT_RECTRANSINT_Pos) /*!< CMSDK_PL110 RAWINTSTAT_RECTRANSINT: Raw Transmit Receive Comb Int Status Mask */

#define CMSDK_PL110_RAWINTSTAT_TRANSINT_Pos \
    5 /*!< CMSDK_PL110 RAWINTSTAT_TRANSINT: Raw Transmit Int Status Position */
#define CMSDK_PL110_RAWINTSTAT_TRANSINT_Msk \
    (0x1ul                                  \
     << CMSDK_PL110_RAWINTSTAT_TRANSINT_Pos) /*!< CMSDK_PL110 RAWINTSTAT_TRANSINT: Raw Transmit Int Status Mask */

#define CMSDK_PL110_RAWINTSTAT_RECINT_Pos \
    4 /*!< CMSDK_PL110 RAWINTSTAT_RECINT: Raw Receive Int Status Position */
#define CMSDK_PL110_RAWINTSTAT_RECINT_Msk \
    (0x1ul                                \
     << CMSDK_PL110_RAWINTSTAT_RECINT_Pos) /*!< CMSDK_PL110 RAWINTSTAT_RECINT: Raw Receive Int Status Mask */

#define CMSDK_PL110_RAWINTSTAT_UART_DSRMODINT_Pos \
    3 /*!< CMSDK_PL110 RAWINTSTAT_UART_DSRMODINT: Raw Data Set Ready Int Status Position */
#define CMSDK_PL110_RAWINTSTAT_UART_DSRMODINT_Msk \
    (0x1ul                                        \
     << CMSDK_PL110_RAWINTSTAT_UARTD_SRMODINT_Pos) /*!< CMSDK_PL110 RAWINTSTAT_UARTD_SRMODINT: Raw Data Set Ready Int Status Mask */

#define CMSDK_PL110_RAWINTSTAT_UART_DCDMODINT_Pos \
    2 /*!< CMSDK_PL110 RAWINTSTAT_UART_DCDMODINT: Raw Data Carrier Detect Int Status Position */
#define CMSDK_PL110_RAWINTSTAT_UART_DCDMODINT_Msk \
    (0x1ul                                        \
     << CMSDK_PL110_RAWINTSTAT_UART_DCDMODINT_Pos) /*!< CMSDK_PL110 RAWINTSTAT_UART_DCDMODINT: Raw Data Carrier Detect Int Status Mask */

#define CMSDK_PL110_RAWINTSTAT_UART_CTSMODINT_Pos \
    1 /*!< CMSDK_PL110 RAWINTSTAT_UART_CTSMODINT: Raw Clear To Send Int Status Position */
#define CMSDK_PL110_RAWINTSTAT_UART_CTSMODINT_Msk \
    (0x1ul                                        \
     << CMSDK_PL110_RAWINTSTAT_UART_CTSMODINT_Pos) /*!< CMSDK_PL110 RAWINTSTAT_UART_CTSMODINT: Raw Clear To Send Int Status Mask */

#define CMSDK_PL110_RAWINTSTAT_UART_RIMODINT_Pos \
    0 /*!< CMSDK_PL110 RAWINTSTAT_UART_RIMODINT: Raw nUARTRI Modem Int Status Position */
#define CMSDK_PL110_RAWINTSTAT_UART_RIMODINT_Msk \
    (0x1ul                                       \
     << CMSDK_PL110_RAWINTSTAT_UART_RIMODINT_Pos) /*!< CMSDK_PL110 RAWINTSTAT_UART_RIMODINT: Raw nUARTRI Modem Int Status Mask */

#define CMSDK_PL110_MSKINTSTAT_OVRRUNERRINT_Pos \
    10 /*!< CMSDK_PL110 MSKINTSTAT_OVRRUNERRINT: Masked Overrun Error Int Status Position */
#define CMSDK_PL110_MSKINTSTAT_OVRRUNERRINT_Msk \
    (0x1ul                                      \
     << CMSDK_PL110_MSKINTSTAT_OVRRUNERRINT_Pos) /*!< CMSDK_PL110 MSKINTSTAT_OVRRUNERRINT: Masked Overrun Error Int Status Mask */

#define CMSDK_PL110_MSKINTSTAT_BREAKERRINT_Pos \
    9 /*!< CMSDK_PL110 MSKINTSTAT_BREAKERRINT: Masked Break Error Int Status Position */
#define CMSDK_PL110_MSKINTSTAT_BREAKERRINT_Msk \
    (0x1ul                                     \
     << CMSDK_PL110_MSKINTSTAT_BREAKERRINT_Pos) /*!< CMSDK_PL110 MSKINTSTAT_BREAKERRINT: Masked Break Error Int Status Mask */

#define CMSDK_PL110_MSKINTSTAT_PARITYERRINT_Pos \
    8 /*!< CMSDK_PL110 MSKINTSTAT_PARITYERRINT: Masked Parity Error Int Status Position */
#define CMSDK_PL110_MSKINTSTAT_PARITYERRINT_Msk \
    (0x1ul                                      \
     << CMSDK_PL110_MSKINTSTAT_PARITYERRINT_Pos) /*!< CMSDK_PL110 MSKINTSTAT_PARITYERRINT: Masked Parity Error Int Status Mask */

#define CMSDK_PL110_MSKINTSTAT_FRAMEERRINT_Pos \
    7 /*!< CMSDK_PL110 MSKINTSTAT_FRAMEERRINT: Masked Frame Error Int Status Position */
#define CMSDK_PL110_MSKINTSTAT_FRAMEERRINT_Msk \
    (0x1ul                                     \
     << CMSDK_PL110_MSKINTSTAT_FRAMEERRINT_Pos) /*!< CMSDK_PL110 MSKINTSTAT_FRAMEERRINT: Masked Frame Error Int Status Mask */

#define CMSDK_PL110_MSKINTSTAT_RECTRANSINT_Pos \
    6 /*!< CMSDK_PL110 MSKINTSTAT_RECTRANSINT: Masked Transmit Receive Comb Int Status Position */
#define CMSDK_PL110_MSKINTSTAT_RECTRANSINT_Msk \
    (0x1ul                                     \
     << CMSDK_PL110_MSKINTSTAT_RECTRANSINT_Pos) /*!< CMSDK_PL110 MSKINTSTAT_RECTRANSINT: Masked Transmit Receive Comb Int Status Mask */

#define CMSDK_PL110_MSKINTSTAT_TRANSINT_Pos \
    5 /*!< CMSDK_PL110 MSKINTSTAT_TRANSINT: Masked Transmit Int Status Position */
#define CMSDK_PL110_MSKINTSTAT_TRANSINT_Msk \
    (0x1ul                                  \
     << CMSDK_PL110_MSKINTSTAT_TRANSINT_Pos) /*!< CMSDK_PL110 MSKINTSTAT_TRANSINT: Masked Transmit Int Status Mask */

#define CMSDK_PL110_MSKINTSTAT_RECINT_Pos \
    4 /*!< CMSDK_PL110 MSKINTSTAT_RECINT: Masked Receive Int Status Position */
#define CMSDK_PL110_MSKINTSTAT_RECINT_Msk \
    (0x1ul                                \
     << CMSDK_PL110_MSKINTSTAT_RECINT_Pos) /*!< CMSDK_PL110 MSKINTSTAT_RECINT: Masked Receive Int Status Mask */

#define CMSDK_PL110_MSKINTSTAT_UART_DSRMODINT_Pos \
    3 /*!< CMSDK_PL110 MSKINTSTAT_UART_DSRMODINT: Masked Data Set Ready Int Status Position */
#define CMSDK_PL110_MSKINTSTAT_UART_DSRMODINT_Msk \
    (0x1ul                                        \
     << CMSDK_PL110_MSKINTSTAT_UARTD_SRMODINT_Pos) /*!< CMSDK_PL110 MSKINTSTAT_UART_DSRMODINT: Masked Data Set Ready Int Status Mask */

#define CMSDK_PL110_MSKINTSTAT_UART_DCDMODINT_Pos \
    2 /*!< CMSDK_PL110 MSKINTSTAT_UART_DCDMODINT: Masked Data Carrier Detect Int Status Position */
#define CMSDK_PL110_MSKINTSTAT_UART_DCDMODINT_Msk \
    (0x1ul                                        \
     << CMSDK_PL110_MSKINTSTAT_UART_DCDMODINT_Pos) /*!< CMSDK_PL110 MSKINTSTAT_UART_DCDMODINT: Masked Data Carrier Detect Int Status Mask */

#define CMSDK_PL110_MSKINTSTAT_UART_CTSMODINT_Pos \
    1 /*!< CMSDK_PL110 MSKINTSTAT_UART_CTSMODINT: Masked Clear To Send Int Status Position */
#define CMSDK_PL110_MSKINTSTAT_UART_CTSMODINT_Msk \
    (0x1ul                                        \
     << CMSDK_PL110_MSKINTSTAT_UART_CTSMODINT_Pos) /*!< CMSDK_PL110 MSKINTSTAT_UART_CTSMODINT: Masked Clear To Send Int Status Mask */

#define CMSDK_PL110_MSKINTSTAT_UART_RIMODINT_Pos \
    0 /*!< CMSDK_PL110 MSKINTSTAT_UART_RIMODINT: Masked nUARTRI Modem Int Status Position */
#define CMSDK_PL110_MSKINTSTAT_UART_RIMODINT_Msk \
    (0x1ul                                       \
     << CMSDK_PL110_MSKINTSTAT_UART_RIMODINT_Pos) /*!< CMSDK_PL110 MSKINTSTAT_UART_RIMODINT: Masked nUARTRI Modem Int Status Mask */

#define CMSDK_PL110_INTCLR_OVRRUNERRINT_Pos \
    10 /*!< CMSDK_PL110 INTCLR_OVRRUNERRINT: Clear Overrun Error Int Position */
#define CMSDK_PL110_INTCLR_OVRRUNERRINT_Msk \
    (0x1ul                                  \
     << CMSDK_PL110_INTCLR_OVRRUNERRINT_Pos) /*!< CMSDK_PL110 INTCLR_OVRRUNERRINT: Clear Overrun Error Int Mask */

#define CMSDK_PL110_INTCLR_BREAKERRINT_Pos \
    9 /*!< CMSDK_PL110 INTCLR_BREAKERRINT: Clear Break Error Int Position */
#define CMSDK_PL110_INTCLR_BREAKERRINT_Msk \
    (0x1ul                                 \
     << CMSDK_PL110_INTCLR_BREAKERRINT_Pos) /*!< CMSDK_PL110 INTCLR_BREAKERRINT: Clear Break Error Int Mask */

#define CMSDK_PL110_INTCLR_PARITYERRINT_Pos \
    8 /*!< CMSDK_PL110 INTCLR_PARITYERRINT: Clear Parity Error Int Position */
#define CMSDK_PL110_INTCLR_PARITYERRINT_Msk \
    (0x1ul                                  \
     << CMSDK_PL110_INTCLR_PARITYERRINT_Pos) /*!< CMSDK_PL110 INTCLR_PARITYERRINT: Clear Parity Error Int Mask */

#define CMSDK_PL110_INTCLR_FRAMEERRINT_Pos \
    7 /*!< CMSDK_PL110 INTCLR_FRAMEERRINT: Clear Frame Error Int Position */
#define CMSDK_PL110_INTCLR_FRAMEERRINT_Msk \
    (0x1ul                                 \
     << CMSDK_PL110_INTCLR_FRAMEERRINT_Pos) /*!< CMSDK_PL110 INTCLR_FRAMEERRINT: Clear Frame Error Int Mask */

#define CMSDK_PL110_INTCLR_RECTRANSINT_Pos \
    6 /*!< CMSDK_PL110 INTCLR_RECTRANSINT: Clear Receive Transmit Comb Int Position */
#define CMSDK_PL110_INTCLR_RECTRANSINT_Msk \
    (0x1ul                                 \
     << CMSDK_PL110_INTCLR_RECTRANSINT_Pos) /*!< CMSDK_PL110 INTCLR_RECTRANSINT: Clear Receive Transmit Comb Int Mask */

#define CMSDK_PL110_INTCLR_TRANSINT_Pos \
    5 /*!< CMSDK_PL110 INTCLR_TRANSINT: Clear Transmit Int Position */
#define CMSDK_PL110_INTCLR_TRANSINT_Msk \
    (0x1ul                              \
     << CMSDK_PL110_INTCLR_TRANSINT_Pos) /*!< CMSDK_PL110 INTCLR_TRANSINT: Clear Transmit Int Mask */

#define CMSDK_PL110_INTCLR_RECINT_Pos \
    4 /*!< CMSDK_PL110 INTCLR_RECINT: Clear Receive Int Position */
#define CMSDK_PL110_INTCLR_RECINT_Msk \
    (0x1ul                            \
     << CMSDK_PL110_INTCLR_RECINT_Pos) /*!< CMSDK_PL110 INTCLR_RECINT: Clear Receive Int Mask */

#define CMSDK_PL110_INTCLR_UART_DSRMODINT_Pos \
    3 /*!< CMSDK_PL110 INTCLR_UART_DSRMODINT: Clear Data Carrier Detect Int Position */
#define CMSDK_PL110_INTCLR_UART_DSRMODINT_Msk \
    (0x1ul                                    \
     << CMSDK_PL110_INTCLR_UARTD_SRMODINT_Pos) /*!< CMSDK_PL110 INTCLR_UARTD_SRMODINT: Clear Data Carrier Detect Int Mask */

#define CMSDK_PL110_INTCLR_UART_DCDMODINT_Pos \
    2 /*!< CMSDK_PL110 INTCLR_UART_DCDMODINT: Clear Data Set Ready Int Position */
#define CMSDK_PL110_INTCLR_UART_DCDMODINT_Msk \
    (0x1ul                                    \
     << CMSDK_PL110_INTCLR_UART_DCDMODINT_Pos) /*!< CMSDK_PL110 INTCLR_UART_DCDMODINT: Clear Data Set Ready Int Mask */

#define CMSDK_PL110_INTCLR_UART_CTSMODINT_Pos \
    1 /*!< CMSDK_PL110 INTCLR_UART_CTSMODINT: Clear Clear To Sent Int Position */
#define CMSDK_PL110_INTCLR_UART_CTSMODINT_Msk \
    (0x1ul                                    \
     << CMSDK_PL110_INTCLR_UART_CTSMODINT_Pos) /*!< CMSDK_PL110 INTCLR_UART_CTSMODINT: Clear Clear To Sent Int Mask */

#define CMSDK_PL110_INTCLR_UART_RIMODINT_Pos \
    0 /*!< CMSDK_PL110 INTCLR_UART_RIMODINT: Clear nUARTRI Modem Int Position */
#define CMSDK_PL110_INTCLR_UART_RIMODINT_Msk \
    (0x1ul                                   \
     << CMSDK_PL110_INTCLR_UART_RIMODINT_Pos) /*!< CMSDK_PL110 INTCLR_UART_RIMODINT: Clear nUARTRI Modem Int Mask */

#define CMSDK_PL110_DMA_ERR_Pos \
    2 /*!< CMSDK_PL110 DMA_ERR: DMA Error Position */
#define CMSDK_PL110_DMA_ERR_Msk \
    (0x1ul                      \
     << CMSDK_PL110_DMA_ERR_Pos) /*!< CMSDK_PL110 DMA_ERR: DMA Error Mask */

#define CMSDK_PL110_DMA_TRANS_EN_Pos \
    1 /*!< CMSDK_PL110 DMA_TRANS_EN: DMA Transmit Error Position */
#define CMSDK_PL110_DMA_TRANS_EN_Msk \
    (0x1ul                           \
     << CMSDK_PL110_DMA_TRANS_EN_Pos) /*!< CMSDK_PL110 DMA_TRANS_EN: DMA Transmit Error Mask */

#define CMSDK_PL110_DMA_REC_EN_Pos \
    0 /*!< CMSDK_PL110 DMA_REC_EN: DMA Receive Error Position */
#define CMSDK_PL110_DMA_REC_EN_Msk \
    (0x1ul                         \
     << CMSDK_PL110_DMA_REC_EN_Pos) /*!< CMSDK_PL110 DMA_REC_EN: DMA Receive Error Mask */

/*@}*/ /* end of group  CMSDK_PL110 */

/*------------------- Watchdog ----------------------------------------------*/
/** @addtogroup CMSDK_Watchdog CMSDK Watchdog
  @{
*/
typedef struct {
    __IO uint32_t LOAD; /* Offset: 0x000 (R/W) Watchdog Load Register */
    __I uint32_t VALUE; /* Offset: 0x004 (R/ ) Watchdog Value Register */
    __IO uint32_t CTRL; /* Offset: 0x008 (R/W) Watchdog Control Register */
    /*    <o.1>    RESEN: Reset enable               */
    /*    <o.0>    INTEN: Interrupt enable           */
    /*    </h>                                       */
    __O uint32_t
        INTCLR; /* Offset: 0x00C ( /W) Watchdog Clear Interrupt Register */
    __I uint32_t
        RAWINTSTAT; /* Offset: 0x010 (R/ ) Watchdog Raw Interrupt Status Register */
    __I uint32_t
        MASKINTSTAT; /* Offset: 0x014 (R/ ) Watchdog Interrupt Status Register */
    uint32_t RESERVED0[762];
    __IO uint32_t LOCK; /* Offset: 0xC00 (R/W) Watchdog Lock Register */
    uint32_t RESERVED1[191];
    __IO uint32_t
        ITCR; /* Offset: 0xF00 (R/W) Watchdog Integration Test Control Register */
    __O uint32_t
        ITOP; /* Offset: 0xF04 ( /W) Watchdog Integration Test Output Set Register */
} CMSDK_WATCHDOG_TypeDef;

#define CMSDK_Watchdog_LOAD_Pos 0 /*!< CMSDK_Watchdog LOAD: LOAD Position */
#define CMSDK_Watchdog_LOAD_Msk \
    (0xFFFFFFFFul               \
     << CMSDK_Watchdog_LOAD_Pos) /*!< CMSDK_Watchdog LOAD: LOAD Mask */

#define CMSDK_Watchdog_VALUE_Pos 0 /*!< CMSDK_Watchdog VALUE: VALUE Position */
#define CMSDK_Watchdog_VALUE_Msk \
    (0xFFFFFFFFul                \
     << CMSDK_Watchdog_VALUE_Pos) /*!< CMSDK_Watchdog VALUE: VALUE Mask */

#define CMSDK_Watchdog_CTRL_RESEN_Pos \
    1 /*!< CMSDK_Watchdog CTRL_RESEN: Enable Reset Output Position */
#define CMSDK_Watchdog_CTRL_RESEN_Msk \
    (0x1ul                            \
     << CMSDK_Watchdog_CTRL_RESEN_Pos) /*!< CMSDK_Watchdog CTRL_RESEN: Enable Reset Output Mask */

#define CMSDK_Watchdog_CTRL_INTEN_Pos \
    0 /*!< CMSDK_Watchdog CTRL_INTEN: Int Enable Position */
#define CMSDK_Watchdog_CTRL_INTEN_Msk \
    (0x1ul                            \
     << CMSDK_Watchdog_CTRL_INTEN_Pos) /*!< CMSDK_Watchdog CTRL_INTEN: Int Enable Mask */

#define CMSDK_Watchdog_INTCLR_Pos \
    0 /*!< CMSDK_Watchdog INTCLR: Int Clear Position */
#define CMSDK_Watchdog_INTCLR_Msk \
    (0x1ul                        \
     << CMSDK_Watchdog_INTCLR_Pos) /*!< CMSDK_Watchdog INTCLR: Int Clear Mask */

#define CMSDK_Watchdog_RAWINTSTAT_Pos \
    0 /*!< CMSDK_Watchdog RAWINTSTAT: Raw Int Status Position */
#define CMSDK_Watchdog_RAWINTSTAT_Msk \
    (0x1ul                            \
     << CMSDK_Watchdog_RAWINTSTAT_Pos) /*!< CMSDK_Watchdog RAWINTSTAT: Raw Int Status Mask */

#define CMSDK_Watchdog_MASKINTSTAT_Pos \
    0 /*!< CMSDK_Watchdog MASKINTSTAT: Mask Int Status Position */
#define CMSDK_Watchdog_MASKINTSTAT_Msk \
    (0x1ul                             \
     << CMSDK_Watchdog_MASKINTSTAT_Pos) /*!< CMSDK_Watchdog MASKINTSTAT: Mask Int Status Mask */

#define CMSDK_Watchdog_LOCK_Pos 0 /*!< CMSDK_Watchdog LOCK: LOCK Position */
#define CMSDK_Watchdog_LOCK_Msk \
    (0x1ul << CMSDK_Watchdog_LOCK_Pos) /*!< CMSDK_Watchdog LOCK: LOCK Mask */

#define CMSDK_Watchdog_INTEGTESTEN_Pos \
    0 /*!< CMSDK_Watchdog INTEGTESTEN: Integration Test Enable Position */
#define CMSDK_Watchdog_INTEGTESTEN_Msk \
    (0x1ul                             \
     << CMSDK_Watchdog_INTEGTESTEN_Pos) /*!< CMSDK_Watchdog INTEGTESTEN: Integration Test Enable Mask */

#define CMSDK_Watchdog_INTEGTESTOUTSET_Pos \
    1 /*!< CMSDK_Watchdog INTEGTESTOUTSET: Integration Test Output Set Position */
#define CMSDK_Watchdog_INTEGTESTOUTSET_Msk \
    (0x1ul                                 \
     << CMSDK_Watchdog_INTEGTESTOUTSET_Pos) /*!< CMSDK_Watchdog INTEGTESTOUTSET: Integration Test Output Set Mask */

/*@}*/ /* end of group  CMSDK_Watchdog */

/*------------------- PrimeCell APB GPIO --------------------------------------*/
/** @addtogroup CMSDK_PL061 CMSDK APB GPIO
  @{
*/
typedef struct {
    __IO uint32_t DATA[256];
    __IO uint32_t DIR;
    __IO uint32_t INTSENSE;
    __IO uint32_t INTBOTHEDGE;
    __IO uint32_t INTEVENT;
    __IO uint32_t INTMASK;
    __O uint32_t RAWINTSTAT;
    __O uint32_t MASKINTSTAT;
    __I uint32_t INTCLR;
    __IO uint32_t MODECTRL;

} APBGPIO_TypeDef;

#define CMSDK_PL061_DATA_Pos 0 /*!< CMSDK_PL061 DATA: DATA Position */
#define CMSDK_PL061_DATA_Msk \
    (0xFFFFFFFFul << CMSDK_PL061_LOAD_Pos) /*!< CMSDK_PL061 DATA: DATA Mask */

#define CMSDK_PL061_DIR_Pos 0 /*!< CMSDK_PL061 DIR: Data Direction Position */
#define CMSDK_PL061_DIR_Msk \
    (0x1ul << CMSDK_PL061_DIR_Pos) /*!< CMSDK_PL061 DIR: Data Direction  Mask */

#define CMSDK_PL061_INTSENSE_Pos \
    0 /*!< CMSDK_PL061 INTSENSE: INT SENSE Position */
#define CMSDK_PL061_INTSENSE_Msk \
    (0x1ul                       \
     << CMSDK_PL061_INTSENSE_Pos) /*!< CMSDK_PL061 INTSENSE: INT SENSE Mask */

#define CMSDK_PL061_INTBOTHEDGE_Pos \
    0 /*!< CMSDK_PL061 INTBOTHEDGE: INT BOTH EDGE Position */
#define CMSDK_PL061_INTBOTHEDGE_Msk \
    (0x1ul                          \
     << CMSDK_PL061_INTBOTHEDGE_Pos) /*!< CMSDK_PL061 INTBOTHEDGE: INT BOTH EDGE Mask */

#define CMSDK_PL061_INTEVENT_Pos \
    0 /*!< CMSDK_PL061 INTEVENT: INT EVENT Position */
#define CMSDK_PL061_INTEVENT_Msk \
    (0x1ul                       \
     << CMSDK_PL061_INTEVENT_Pos) /*!< CMSDK_PL061 INTEVENT: INT EVENT Mask */

#define CMSDK_PL061_INTMASK_Pos 0 /*!< CMSDK_PL061 INTMASK: INT MASK Position */
#define CMSDK_PL061_INTMASK_Msk \
    (0x1ul                      \
     << CMSDK_PL061_INTMASK_Pos) /*!< CMSDK_PL061 INTMASK: INT MASK Mask */

#define CMSDK_PL061_RAWINTSTAT_Pos \
    0 /*!< CMSDK_PL061 RAWINTSTAT: Raw Int Status Position */
#define CMSDK_PL061_RAWINTSTAT_Msk \
    (0x1ul                         \
     << CMSDK_PL061_RAWINTSTAT_Pos) /*!< CMSDK_PL061 RAWINTSTAT: Raw Int Status Mask */

#define CMSDK_PL061_MASKINTSTAT_Pos \
    0 /*!< CMSDK_PL061 MASKINTSTAT: Mask Int Status Position */
#define CMSDK_PL061_MASKINTSTAT_Msk \
    (0x1ul                          \
     << CMSDK_PL061_MASKINTSTAT_Pos) /*!< CMSDK_PL061 MASKINTSTAT: Mask Int Status Mask */

#define CMSDK_PL061_INTCLR_Pos 0 /*!< CMSDK_PL061 INTCLR: Int Clear Position */
#define CMSDK_PL061_INTCLR_Msk \
    (0x1ul << CMSDK_PL061_INTCLR_Pos) /*!< CMSDK_PL061 INTCLR: Int Clear Mask */

#define CMSDK_PL061_MODECTRL_HWEN_Pos \
    0 /*!< CMSDK_PL061 MODECTRL_HWEN: Mode Control Hardware Enable Position */
#define CMSDK_PL061_MODECTRL_HWEN_Msk \
    (0x1ul                            \
     << CMSDK_PL061_MODECTRL_HWEN_Pos) /*!< CMSDK_PL061 MODECTRL_HWEN: Mode Control Hardware Enable Mask */

/*@}*/ /* end of group  CMSDK_PL061 */

#if defined(__CC_ARM)
#pragma no_anon_unions
#endif

/*@}*/ /* end of group CMSDK_CM4_Peripherals */

/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/** @addtogroup CMSDK_CM4_MemoryMap CMSDK_CM4 Memory Mapping
  @{
*/

/* Peripheral and SRAM base address */
#define CMSDK_FLASH_BASE (0x00000000UL)  /*!< (FLASH     ) Base Address */
#define CMSDK_SRAM_BASE (0x20000000UL)   /*!< (SRAM      ) Base Address */
#define CMSDK_PERIPH_BASE (0x40000000UL) /*!< (Peripheral) Base Address */

/* Base addresses                                                             */
#define CMSDK_RAM_BASE (0x20000000UL)
#define CMSDK_APB_BASE (0x40000000UL)
#define CMSDK_AHB_BASE (0x40010000UL)

/* APB peripherals                                                           */
#define CMSDK_TIMER0_BASE (CMSDK_APB_BASE + 0x0000UL)
#define CMSDK_TIMER1_BASE (CMSDK_APB_BASE + 0x1000UL)
#define CMSDK_DUALTIMER_BASE (CMSDK_APB_BASE + 0x2000UL)
#define CMSDK_DUALTIMER_1_BASE (CMSDK_DUALTIMER_BASE)
#define CMSDK_DUALTIMER_2_BASE (CMSDK_DUALTIMER_BASE + 0x20UL)
#define CMSDK_UART0_BASE (CMSDK_APB_BASE + 0x4000UL)
#define CMSDK_UART1_BASE (CMSDK_APB_BASE + 0x5000UL)
#define CMSDK_UART2_BASE (CMSDK_APB_BASE + 0x6000UL)
#define CMSDK_UART3_BASE (CMSDK_APB_BASE + 0x7000UL)
#define CMSDK_WATCHDOG_BASE (CMSDK_APB_BASE + 0x8000UL)
#define CMSDK_UART4_BASE (CMSDK_APB_BASE + 0x9000UL)
#define CMSDK_PL230_BASE (CMSDK_APB_BASE + 0xF000UL)

/* AHB peripherals                                                           */
#define CMSDK_GPIO0_BASE (CMSDK_AHB_BASE + 0x0000UL)
#define CMSDK_GPIO1_BASE (CMSDK_AHB_BASE + 0x1000UL)
#define CMSDK_GPIO2_BASE (CMSDK_AHB_BASE + 0x2000UL)
#define CMSDK_GPIO3_BASE (CMSDK_AHB_BASE + 0x3000UL)
#define CMSDK_SYSCTRL_BASE (CMSDK_AHB_BASE + 0xF000UL)
/*@}*/ /* end of group CMSDK_CM4_MemoryMap */

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
/** @addtogroup CMSDK_CM4_PeripheralDecl CMSDK_CM4 Peripheral Declaration
  @{
*/

#define CMSDK_UART0 ((CMSDK_UART_TypeDef *)CMSDK_UART0_BASE)
#define CMSDK_UART1 ((CMSDK_UART_TypeDef *)CMSDK_UART1_BASE)
#define CMSDK_UART2 ((CMSDK_UART_TypeDef *)CMSDK_UART2_BASE)
#define CMSDK_UART3 ((CMSDK_UART_TypeDef *)CMSDK_UART3_BASE)
#define CMSDK_UART4 ((CMSDK_UART_TypeDef *)CMSDK_UART4_BASE)
#define CMSDK_TIMER0 ((CMSDK_TIMER_TypeDef *)CMSDK_TIMER0_BASE)
#define CMSDK_TIMER1 ((CMSDK_TIMER_TypeDef *)CMSDK_TIMER1_BASE)
#define CMSDK_DUALTIMER ((CMSDK_DUALTIMER_BOTH_TypeDef *)CMSDK_DUALTIMER_BASE)
#define CMSDK_DUALTIMER1 \
    ((CMSDK_DUALTIMER_SINGLE_TypeDef *)CMSDK_DUALTIMER_1_BASE)
#define CMSDK_DUALTIMER2 \
    ((CMSDK_DUALTIMER_SINGLE_TypeDef *)CMSDK_DUALTIMER_2_BASE)
#define CMSDK_WATCHDOG ((CMSDK_WATCHDOG_TypeDef *)CMSDK_WATCHDOG_BASE)
#define CMSDK_DMA ((CMSDK_PL230_TypeDef *)CMSDK_PL230_BASE)
#define CMSDK_GPIO0 ((CMSDK_GPIO_TypeDef *)CMSDK_GPIO0_BASE)
#define CMSDK_GPIO1 ((CMSDK_GPIO_TypeDef *)CMSDK_GPIO1_BASE)
#define CMSDK_GPIO2 ((CMSDK_GPIO_TypeDef *)CMSDK_GPIO2_BASE)
#define CMSDK_GPIO3 ((CMSDK_GPIO_TypeDef *)CMSDK_GPIO3_BASE)
#define CMSDK_SYSCON ((CMSDK_SYSCON_TypeDef *)CMSDK_SYSCTRL_BASE)
/*@}*/ /* end of group CMSDK_CM4_PeripheralDecl */

/*@}*/ /* end of group CMSDK_CM4_Definitions */

#ifdef __cplusplus
}
#endif

#endif /* CMSDK_CM4_H */
