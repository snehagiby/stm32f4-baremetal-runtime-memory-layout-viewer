/*
 * gpio.h
 *
 *  Created on: Oct 4, 2026
 *      Author: Admin
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "stm32f446xx.h"

#define GPIO_INPUT_MODE 	0x00
#define GPIO_OUTPUT_MODE 	0x01
#define GPIO_AF_MODE 		0x02
#define GPIO_ANALOG_MODE 	0x03

/**
 * @brief gpio init a particular portx and pin y with a mode specified.
 */
void gpio_init(char port,uint8_t pin,uint8_t mode);
/**
 * @brief read the GPIO pin data.
 */
bool gpio_read_data(char port,uint8_t pin);
/**
 * @brief set a particular pin y of a port x with a value specified.
 */
void gpio_set_pin(char port, uint8_t pin, bool val);
/**
 * @brief set a particular port x pin y using BSSR register
 */
void gpio_set_bssr(char port, uint8_t pin);
/**
 * @brief reset a particular port x pin y using BSSR register
 */
void gpio_reset_bssr(char port, uint8_t pin);
/**
 * @brief set the AF for tha application based on datasheet to a particular portx and pin y.
 */
void gpio_set_af(char port,uint8_t pin,uint8_t af_num);
#endif /* GPIO_H_ */
