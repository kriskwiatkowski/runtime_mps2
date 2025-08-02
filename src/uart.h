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

#ifndef __UART_H__
#define __UART_H__

#include <errno.h>
#include <platform/platform.h>
#include <platform/printf.h>
#include <stdbool.h>
#include <stddef.h>

// Forward declaration of the uart_t structure
struct uart_t;

/**
 * @brief Initialize the serial peripheral. It sets the default parameters for the serial
 * peripheral.
 *
 * @param obj The serial object
 */
void uart_init(struct uart_t *obj);

/**
 * @brief Get the UART port object.
 *
 * @return Pointer to the UART port object.
 */
struct uart_t *uart_get_port(void);

/**
 * @brief Configure the baud rate.
 *
 * @param obj      The serial object
 * @param baudrate The baud rate to be configured
 * @return True if the baud rate was set, false if the baud rate is too low.
 */
bool uart_set_baud(struct uart_t *obj, unsigned long baudrate);

/**
 * @brief Send a character.
 *
 * @param obj The serial object
 * @param c   The character to be sent
 */
void uart_putc(struct uart_t *obj, int c);

/**
 * @brief Get character. This is a blocking call, waiting for a character.
 *
 * @param obj The serial object
 * @return Received character
 */
char uart_getc(struct uart_t *obj);

/**
 * @brief Check if the serial peripheral is readable.
 *
 * @param obj The serial object
 * @return Non-zero value if a character can be read, 0 if nothing to read.
 */
bool uart_is_readable(struct uart_t *obj);

/**
 * @brief Check if the serial peripheral is writable.
 *
 * @param obj The serial object
 * @return Non-zero value if a character can be written, 0 otherwise.
 */
bool uart_is_writable(struct uart_t *obj);

/**
 * @brief Clear the serial peripheral.
 *
 * @param obj The serial object
 */
void uart_clear(struct uart_t *obj);

#endif  // __UART_H__
