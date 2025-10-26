#ifndef MBED_CMSIS_NVIC_H
#define MBED_CMSIS_NVIC_H

#include "memory_zones.h"

#define NVIC_NUM_VECTORS (16 + 48)
#define NVIC_RAM_VECTOR_ADDRESS ZBT_SRAM2_START  // Location of vectors in RAM

/*
 * Size of the whole vector table in bytes. Each vector is on 32 bits.
 */
#define NVIC_VECTORS_SIZE (NVIC_NUM_VECTORS * 4)

#endif
