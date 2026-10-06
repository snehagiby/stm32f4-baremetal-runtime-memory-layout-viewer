/*
 * usart.c
 *
 *  Created on: Oct 4, 2026
 *      Author: Admin
 */

#include "usart.h"
#include "gpio.h"

/**
 * defined parameter for the intialization.
 */
#define USARTx_CR1_UE   (1U << 13)
#define USARTx_CR1_TE	(1U << 3)
#define USARTx_CR1_RE	(1U << 2)

#define USARTx_SR_TXE	(1U << 7)
#define USARTx_SR_RXNE   (1U << 5)

#define RCC_APB1_USART2 (1U << 17)

/**
 * define parameter for the baud rate setting.
 */
#define USART_BAUDRATE 115200
#define SYSCLK		   16000000   //16MHz
#define USART_PERI_CLOCK	SYSCLK

/**
 * @brief set the baud rate for the usart.
 */

void usart2_brr(uint32_t perip_clk,uint32_t baudrate){
	USART2->BRR = (perip_clk + baudrate/2)/baudrate;
}

/**
 * @brief usart2 initialization.
 */

void usart2_init(void){
	//clock intialized
	RCC ->APB1ENR &= ~RCC_APB1_USART2;
	RCC->APB1ENR |= RCC_APB1_USART2;
	//GPIO af set
	gpio_init('A',2,GPIO_AF_MODE);
	gpio_init('A',3,GPIO_AF_MODE);
	gpio_set_af('A',2,7);
	gpio_set_af('A',3,7);

	usart2_brr(USART_PERI_CLOCK,USART_BAUDRATE);

	USART2->CR1 |= USARTx_CR1_UE;
	USART2->CR1 |= USARTx_CR1_TE;
	USART2->CR1 |= USARTx_CR1_RE;

}

/**
 * @brief read one byte data from the usart2.
 */

uint8_t usart2_read(void){
	while(!(USART2->SR & USARTx_SR_RXNE));
	return USART2->DR;
}

/**
 * @brief write one byte in usart2.
 */

void usart2_write(uint8_t val){
	while(!(USART2->SR & USARTx_SR_TXE));
	USART2->DR = val;
}

/**
 * @brief Transmit a null-terminated string over USART2, one character at a time.
 */

void print_string(char *ptr){
	while(*ptr){
		usart2_write(*ptr);
		ptr++;
	}
}
