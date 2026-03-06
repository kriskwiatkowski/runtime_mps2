/* MPS2 CMSIS Library - Device Header Selection
*
* Copyright (c) 2006-2018 ARM Limited
* SPDX-License-Identifier: BSD-3-Clause
*
* This header selects the appropriate device header based on the
* MPS2 platform configuration (AN385, AN386, AN500, AN521, etc.)
*/

#ifndef MPS2_DEVICE_H
#define MPS2_DEVICE_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(MPS2_AN521)
/* Cortex-M33 based platform (AN521) 
 * We include the CMSDK_CM4.h for peripheral definitions, but override the core
 */

/* Define IRQn_Type before including core - required by core_cm33.h */
typedef enum IRQn {
    /* -------------------  Cortex-M33 Processor Exceptions Numbers  ------------------- */
    NonMaskableInt_IRQn   = -14, /*  2 Non Maskable Interrupt          */
    HardFault_IRQn        = -13, /*  3 HardFault Interrupt             */
    MemoryManagement_IRQn = -12, /*  4 Memory Management Interrupt     */
    BusFault_IRQn         = -11, /*  5 Bus Fault Interrupt             */
    UsageFault_IRQn       = -10, /*  6 Usage Fault Interrupt           */
    SecureFault_IRQn      = -9,  /*  7 Secure Fault Interrupt          */
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
    PORT0_ALL_IRQn = 6, /*!< Port 0 combined Interrupt                         */
    PORT1_ALL_IRQn = 7, /*!< Port 1 combined Interrupt                         */
    TIMER0_IRQn = 8, /*!< TIMER 0 Interrupt                                 */
    TIMER1_IRQn = 9, /*!< TIMER 1 Interrupt                                 */
    DUALTIMER_IRQn = 10, /*!< Dual Timer Interrupt                              */
    SPI_IRQn     = 11, /*!< SPI Interrupt                                     */
    UARTOVF_IRQn = 12, /*!< UART 0,1,2 Overflow Interrupt                     */
    ETHERNET_IRQn = 13, /*!< Ethernet Interrupt                                */
    I2S_IRQn = 14, /*!< I2S Interrupt                                     */
    TSC_IRQn = 15, /*!< Touch Screen Interrupt                            */
    PORT2_ALL_IRQn = 16, /*!< Port 2 combined Interrupt                         */
    PORT3_ALL_IRQn = 17, /*!< Port 3 combined Interrupt                         */
    UARTRX3_IRQn = 18, /*!< UART 3 RX Interrupt                               */
    UARTTX3_IRQn = 19, /*!< UART 3 TX Interrupt                               */
    UARTRX4_IRQn = 20, /*!< UART 4 RX Interrupt                               */
    UARTTX4_IRQn = 21, /*!< UART 4 TX Interrupt                               */
    ADCSPI_IRQn  = 22, /*!< SHIELD ADC SPI Interrupt                          */
    SHIELDSPI_IRQn = 23, /*!< SHIELD SPI Combined Interrupt                     */
    PORT0_0_IRQn = 24, /*!<  GPIO Port 0 pin 0 Interrupt                      */
    PORT0_1_IRQn = 25, /*!<  GPIO Port 0 pin 1 Interrupt                      */
    PORT0_2_IRQn = 26, /*!<  GPIO Port 0 pin 2 Interrupt                      */
    PORT0_3_IRQn = 27, /*!<  GPIO Port 0 pin 3 Interrupt                      */
    PORT0_4_IRQn = 28, /*!<  GPIO Port 0 pin 4 Interrupt                      */
    PORT0_5_IRQn = 29, /*!<  GPIO Port 0 pin 5 Interrupt                      */
    PORT0_6_IRQn = 30, /*!<  GPIO Port 0 pin 6 Interrupt                      */
    PORT0_7_IRQn = 31, /*!<  GPIO Port 0 pin 7 Interrupt                      */
} IRQn_Type;

/* First define the core configuration before including CMSDK header */
#define __CM33_REV                0x0000U   /* Core revision r0p0 */
#define __SAUREGION_PRESENT       0U        /* SAU regions not present */
#define __MPU_PRESENT             1U        /* MPU present */
#define __VTOR_PRESENT            1U        /* VTOR present */
#define __NVIC_PRIO_BITS          3U        /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0U        /* Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             0U        /* no FPU present */
#define __DSP_PRESENT             0U        /* no DSP extension present */

/* Include M33 core before CMSDK peripheral definitions */
#include "core_cm33.h"

/* Now include peripheral definitions - we'll skip the core include in CMSDK_CM4.h */
#define CMSDK_CM4_H_CORE_INCLUDED
#define CMSDK_CM4_H_IRQN_INCLUDED

/* Prevent redefinition warnings for config already set above */
#define __CM4_REV 0x0000
#undef __NVIC_PRIO_BITS
#define __NVIC_PRIO_BITS 3
#undef __Vendor_SysTickConfig
#define __Vendor_SysTickConfig 0
#undef __MPU_PRESENT  
#define __MPU_PRESENT 1
#undef __FPU_PRESENT
#define __FPU_PRESENT 0

/* Include everything from CMSDK but the core and IRQn */
#include "CMSDK_CM4.h"

/* AN521 UART0 is at 0x40200000, not at the default CMSDK_APB_BASE+0x4000 */
#undef CMSDK_UART0_BASE
#undef CMSDK_UART0
#define CMSDK_UART0_BASE 0x40200000UL
#define CMSDK_UART0      ((CMSDK_UART_TypeDef *)CMSDK_UART0_BASE)

#else
/* All other platforms use CMSDK_CM4.h (compatible with M3, M4, M7) */
#include "CMSDK_CM4.h"

#endif

#ifdef __cplusplus
}
#endif

#endif /* MPS2_DEVICE_H */
