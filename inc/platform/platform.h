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
