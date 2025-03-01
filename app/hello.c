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
#include <stdint.h>

int main(void) {
    platform_init(PLATFORM_CLOCK_MAX);
    platform_sync();
    size_t i = 0;

    uint64_t t = platform_cpu_cyclecount();
    i++;
    t = platform_cpu_cyclecount() - t;
    printf("Hello world %u %u.\n", (uint32_t)(t >> 32), (uint32_t)t);
    return 0;
}
