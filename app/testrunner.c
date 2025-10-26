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
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

int CUNIT_run(void);

int epcc_printf(const char* format, ...) {
    va_list va;
    va_start(va, format);
    const int ret = vprintf(format, va);
    va_end(va);
    return 0;
}

int main(void) {
    platform_init(PLATFORM_CLOCK_MAX);
    platform_sync();

    printf("Hello world \n");
    int ret = CUNIT_run();
    printf("Result %d\n", ret);

    return 0;
}
