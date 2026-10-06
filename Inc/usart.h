/*
 * usart.h
 *
 *  Created on: Oct 4, 2026
 *      Author: Admin
 */

#ifndef USART_H_
#define USART_H_

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "stm32f446xx.h"

/**
 * @brief usart2 initialization.
 */
void usart2_init(void);

/**
 * @brief read one byte data from the usart2.
 */

uint8_t usart2_read(void);

/**
 * @brief write one byte in usart2.
 */

void usart2_write(uint8_t val);

/**
 * @brief Transmit a null-terminated string over USART2, one character at a time.
 */

void print_string(char *ptr);

/**
 * @brief set the baud rate for the usart.
 */

void usart2_brr(uint32_t perip_clk,uint32_t baudrate);
#endif /* USART_H_ */
