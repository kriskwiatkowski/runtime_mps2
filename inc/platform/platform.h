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

#ifndef MPS2_PLATFORM_H_
#define MPS2_PLATFORM_H_

#include <stddef.h>
#include <stdint.h>

// Platform attributes
typedef enum {
    PLATFORM_CLOCK_MAX,
    //!< Sets the clock to max possible value
    PLATFORM_CLOCK_USERSPACE
    //!< Sets the CPU clock to 24Mhz (used for benchmarking)
} platform_op_mode_t;

/**
 * @brief Initializes whole STM32 platform.
 * @retval Always 0.
 */
int platform_init(platform_op_mode_t a);

// Structure for passign platform attributes
struct platform_attr_t {
    uint32_t attr[4];
    size_t n;
};

// Set platform attribute.
void platform_set_attr(const struct platform_attr_t *a);

// Returns current number of cycles on a clock.
uint64_t platform_cpu_cyclecount(void);

// Get random number from TRNG
int platform_get_random(void *out, unsigned len);

// Improves benchmark results
void platform_sync(void);

uint64_t platform_mps2_stack_size(void);

/**
 * Check if the serial peripheral is readable.
 *
 * @brief This is a non-blocking call, checking if the peripheral is readable.
 * @returns 1 when I/O is readable, 0 when not readable, negative value on error.
 */
int platform_io_is_readable(void);

/**
 * Check if the serial peripheral is writable
 *
 * @brief This is a non-blocking call, checking if the peripheral is writable.
 * @returns 1 when I/O is writable, 0 when not writable, negative value on error.
 */
int platform_io_is_writable(void);

/**
 * Write a string.
 *
 * @brief This is a blocking call, waiting for I/O to be writable.
 *
 * @param[out] buf Buffer to store the string to be written.
 * @param[in] len Length of the buffer to write.
 *
 * @returns Number of bytes written to I/O, or -1 on error.
 */
int platform_io_write(const char *buf, int len);

/**
 * Read a string.
 *
 * @brief This is a blocking call, waiting for a string of bytes from I/O.
 *
 * @param[out] buf Buffer to store the read string.
 * @param[in] len Length of the buffer to read.
 *
 * @returns Number of bytes read from I/O, or -1 on error.
 */
int platform_io_read(char *buf, int len);

#endif  // MPS2_PLATFORM_H_
