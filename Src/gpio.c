/*
 * gpio.c
 *
 *  Created on: Oct 4, 2026
 *      Author: Admin
 */


#include "gpio.h"
/**
 * definition of RCC AHB1 enable location of each GPIO port.
 */
#define AHB1_GPIOA_EN (1U << 0)
#define AHB1_GPIOB_EN (1U << 1)
#define AHB1_GPIOC_EN (1U << 2)
#define AHB1_GPIOD_EN (1U << 3)
#define AHB1_GPIOE_EN (1U << 4)
#define AHB1_GPIOF_EN (1U << 5)
#define AHB1_GPIOG_EN (1U << 6)
#define AHB1_GPIOH_EN (1U << 7)

/**
 * @brief gpio init a particular portx and pin y with a mode specified.
 */

void gpio_init(char port,uint8_t pin,uint8_t mode){
	switch(port) {
	case 'A':
		RCC->AHB1ENR &= ~AHB1_GPIOA_EN;
		RCC->AHB1ENR |=  AHB1_GPIOA_EN;
		GPIOA->MODER |= (mode << (pin*2));
		break;
	case 'B' :
		RCC->AHB1ENR &= ~AHB1_GPIOB_EN;
		RCC->AHB1ENR |=  AHB1_GPIOB_EN;
		GPIOB->MODER |= (mode << (pin*2));
		break;
	case 'C' :
		RCC->AHB1ENR &= ~AHB1_GPIOC_EN;
		RCC->AHB1ENR |=  AHB1_GPIOC_EN;
		GPIOC->MODER |= (mode << (pin*2));
		break;
	case 'D':
		RCC->AHB1ENR &= ~AHB1_GPIOD_EN;
		RCC->AHB1ENR |=  AHB1_GPIOD_EN;
		GPIOD->MODER |= (mode << (pin*2));
		break;
	case 'E':
		RCC->AHB1ENR &= ~AHB1_GPIOE_EN;
		RCC->AHB1ENR |=  AHB1_GPIOE_EN;
		GPIOE->MODER |= (mode << (pin*2));
		break;
	case 'F':
		RCC->AHB1ENR &= ~AHB1_GPIOF_EN;
		RCC->AHB1ENR |=  AHB1_GPIOF_EN;
		GPIOF->MODER |= (mode << (pin*2));
		break;
	case 'G':
		RCC->AHB1ENR &= ~AHB1_GPIOG_EN;
		RCC->AHB1ENR |=  AHB1_GPIOG_EN;
		GPIOG->MODER |= (mode << (pin*2));
		break;
	case 'H':
		RCC->AHB1ENR &= ~AHB1_GPIOH_EN;
		RCC->AHB1ENR |=  AHB1_GPIOH_EN;
		GPIOH->MODER |= (mode << (pin*2));
		break;
	}
}

/**
 * @brief read the GPIO pin data.
 */

bool gpio_read_data(char port,uint8_t pin){
	bool read_val = false;
	switch(port){
	case 'A':
		read_val = (GPIOA->IDR & (1U << pin));
		break;
	case 'B':
			read_val = (GPIOB->IDR & (1U << pin));
			break;
	case 'C':
			read_val = (GPIOC->IDR & (1U << pin));
			break;
	case 'D':
			read_val = (GPIOD->IDR & (1U << pin));
			break;
	case 'E':
			read_val = (GPIOE->IDR & (1U << pin));
			break;
	case 'F':
			read_val = (GPIOF->IDR & (1U << pin));
			break;
	case 'G':
			read_val = (GPIOG->IDR & (1U << pin));
			break;
	case 'H':
			read_val = (GPIOH->IDR & (1U << pin));
			break;

	}
	return 	read_val;
}

/**
 * @brief set a particular pin y of a port x with a value specified.
 */

void gpio_set_pin(char port, uint8_t pin, bool val){
	uint32_t mask = (1U << pin);
	switch(port){
		case 'A':
			if (val) GPIOA->ODR |= mask;
			else     GPIOA->ODR &= ~mask;
			break;
		case 'B':
		     if (val) GPIOB->ODR |= mask;
			else     GPIOB ->ODR &= ~mask;
			break;
		case 'C':
			if (val) GPIOC->ODR |= mask;
			else     GPIOC->ODR &= ~mask;
				break;
		case 'D':
			if (val) GPIOD->ODR |= mask;
			else     GPIOD->ODR &= ~mask;
			break;
		case 'E':
			if (val) GPIOE->ODR |= mask;
			else     GPIOE->ODR &= ~mask;
			break;
		case 'F':
			if (val) GPIOF->ODR |= mask;
			else     GPIOF->ODR &= ~mask;
			break;
		case 'G':
			if (val) GPIOG->ODR |= mask;
			else     GPIOG->ODR &= ~mask;
			break;
		case 'H':
			if (val) GPIOH->ODR |= mask;
			else     GPIOH->ODR &= ~mask;
			break;
		}
}

/**
 * @brief set a particular port x pin y using BSSR register
 */
void gpio_set_bssr(char port, uint8_t pin){
	uint32_t mask = (1U << pin);
	switch(port){
	case 'A':
		GPIOA->BSRR |= mask;
		break;
	case 'B':
		GPIOB->BSRR  |= mask;
		break;
	case 'C':
		GPIOC->BSRR  |= mask;
		break;
	case 'D':
		GPIOD->BSRR  |= mask;
		break;
	case 'E':
		GPIOE->BSRR  |= mask;
		break;
	case 'F':
		GPIOF->BSRR  |= mask;
		break;
	case 'G':
		GPIOG->BSRR  |= mask;
		break;
	case 'H':
		GPIOH->BSRR  |= mask;
		break;
	}
}


/**
 * @brief reset a particular port x pin y using BSSR register
 */

void gpio_reset_bssr(char port, uint8_t pin){
	uint32_t mask = (1U << (pin+16));
		switch(port){
			case 'A':
				GPIOA->BSRR |= mask;
				break;
			case 'B':
				GPIOB->BSRR  |= mask;
				break;
			case 'C':
				GPIOC->BSRR  |= mask;
				break;
			case 'D':
				GPIOD->BSRR  |= mask;
				break;
			case 'E':
				GPIOE->BSRR  |= mask;
				break;
			case 'F':
				GPIOF->BSRR  |= mask;
				break;
			case 'G':
				GPIOG->BSRR  |= mask;
				break;
			case 'H':
				GPIOH->BSRR  |= mask;
				break;
			}
}

/**
 * @brief set the AF for tha application based on datasheet to a particular portx and pin y.
 */

void gpio_set_af(char port,uint8_t pin,uint8_t af_num){
	uint8_t shift = (pin <= 7) ? (pin * 4) : ((pin - 8) * 4);
	uint32_t mask = (0xFU << shift);
	 uint8_t reg_index = (pin <= 7) ? 0 : 1;

	switch(port){
	case 'A':
		GPIOA->AFR[reg_index] &= ~mask;
		GPIOA->AFR[reg_index] |= ((uint32_t)af_num << shift);
		break;
	case 'B':
		GPIOB->AFR[reg_index] &= ~mask;
		GPIOB->AFR[reg_index] |= ((uint32_t)af_num << shift);
		break;
	case 'C':
		GPIOC->AFR[reg_index] &= ~mask;
		GPIOC->AFR[reg_index] |= ((uint32_t)af_num << shift);
		break;
	case 'D':
		GPIOD->AFR[reg_index] &= ~mask;
		GPIOD->AFR[reg_index] |= ((uint32_t)af_num << shift);
		break;
	case 'E':
		GPIOE->AFR[reg_index] &= ~mask;
		GPIOE->AFR[reg_index] |= ((uint32_t)af_num << shift);
		break;
	case 'F':
		GPIOF->AFR[reg_index] &= ~mask;
		GPIOF->AFR[reg_index] |= ((uint32_t)af_num << shift);
		break;
	case 'G':
		GPIOG->AFR[reg_index] &= ~mask;
		GPIOG->AFR[reg_index] |= ((uint32_t)af_num << shift);
		break;
	case 'H':
		GPIOH->AFR[reg_index] &= ~mask;
		GPIOH->AFR[reg_index] |= ((uint32_t)af_num << shift);
		break;
	}
}
