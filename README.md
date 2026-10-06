# Project Name

Baremetal-runtime-memory-layout-viewer

## Project
The main purpose of this project is to able to print the run time memory layout (.data - start and end,.bss- start and end,heap - start and end, stack - start and end and flash memory - start an dend and also the const value in the flash memory).
Register-level peripheral drivers(gpio and uart) for the STM32F446RE written with  CMSIS.

### Target Hardware
	
- MCU:	STM32F446RE
- Board:	NUCLEO-F446RE
- Toolchain:	STM32CubeIDE

#### Feature

  - GPIO driver using CMSIS for configuring the parameter.
  - USART2 was configured for data logging.
  - parameter _sdata,_edata,_sidata,_sbss,_ebss,_flash_size,_ram_size,_stext, _etext,_end,*__sbrk_heap_end,_estack from linker descriptor are used.
  - values can be verified from the .map generated while compilation.

##### Project Structure
```text
├── Inc/           # Header files (gpio.h,usart.h)
├── Src/           # Source files (gpio.c,usart.c, main.c)
├── Startup/       # Startup assembly file
├── STM32F446RETX_FLASH.ld   # Linker script (Flash)
├── STM32F446RETX_RAM.ld     # Linker script (RAM)
├── .project / .cproject     # STM32CubeIDE project files
└── .gitignore
```
###### Usage API

## GPIO:
```c
void gpio_init(char port,uint8_t pin,uint8_t mode)
bool gpio_read_data(char port,uint8_t pin);
void gpio_set_pin(char port, uint8_t pin, bool val);
void gpio_set_bssr(char port, uint8_t pin);
void gpio_reset_bssr(char port, uint8_t pin);
void gpio_set_af(char port,uint8_t pin,uint8_t af_num);
```
## USART:
```c
void usart2_init(void);
uint8_t usart2_read(void);
void usart2_write(uint8_t val);
void print_string(char *ptr);
void usart2_brr(uint32_t perip_clk,uint32_t baudrate);
```
**NOTE:**
- Clock source is determined from the Block Diagram in the Datasheet DS10693 Rev 11.
- Alternate function is also determined from the Data sheet DS10693 Rev 11.
- Nucleo board pin for the in build USART2  is determined from the Nucleo - f446re schematic MB1136.
- parameters( _sdata,_edata,_sidata,_sbss,_ebss,_flash_size,_ram_size,_stext, _etext,_end,*__sbrk_heap_end,_estack) from the flash linked descriptor for printing thr various memory runtime layout.
