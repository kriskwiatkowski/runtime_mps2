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

#ifndef __LIB_H__
#define __LIB_H__

#ifndef MPS2_SYSTEM_CLOCK
#if defined(MPS2_AN500)
// Set clock to 600MHz
#define MPS2_SYSTEM_CLOCK 60000000UL
#else
// Set clock to 25MhZ (default on MPS2)
#define MPS2_SYSTEM_CLOCK 25000000UL
#endif
#endif

struct uart_t {
    CMSDK_UART_TypeDef *uart;
    int index;
};

#endif  // __LIB_H__
