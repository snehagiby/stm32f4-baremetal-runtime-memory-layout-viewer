
#include <stdint.h>
#include "usart.h"
#include "gpio.h"
#include <stdlib.h>

extern uint32_t _sdata;    //.data start address
extern uint32_t _edata;    //.data end address
extern uint32_t  _sidata;    //flash address where intial value of .data stored

extern uint32_t _sbss;	   //.bss start address
extern uint32_t _ebss;      //.bss end address

extern uint32_t _flash_size; // added new variable for flash size
extern uint32_t _ram_size;
extern uint32_t _stext;     //start address where text stored in Flash
extern uint32_t _etext;		//end address where text/code ends in Flsh

extern uint32_t _end;       //heap start address
extern uint8_t *__sbrk_heap_end; //heap end address
extern uint32_t _estack;   //stack start address
char buf[80];

int main(void)
{
	usart2_init();
	uint8_t *ptr = malloc(10);
	//.data memory layout
	sprintf(buf, "\r\nThe start and end of .data is 0x%08X, 0x%08X\r\n",
	        (unsigned int)&_sdata, (unsigned int)&_edata);
	print_string(buf);
	sprintf(buf,"\r\n The address in FLASH where the initial value of .data stored  0x%08X",(unsigned int)&_sidata);
	print_string(buf);

	//.bss memory layout
	sprintf(buf, "\r\nThe end of code is 0x%08X\r\n",
		        (unsigned int)&_etext);
	print_string(buf);
	sprintf(buf, "\r\nThe start and end of .bss is 0x%08X, 0x%08X\r\n",
		        (unsigned int)&_sbss, (unsigned int)&_ebss);
	print_string(buf);

	//flash and RAM size
	sprintf(buf, "\r\nThe size of FLASH and RAM is 0x%08X, 0x%08X \r\n",
			        (unsigned int)&_flash_size, (unsigned int)&_ram_size);
	print_string(buf);
	sprintf(buf, "\r\nThe start and end address of code in flash 0x%08X, 0x%08X\r\n",
			(unsigned int)&_stext, (unsigned int)&_etext);
	print_string(buf);

	//stack start and end address
	sprintf(buf, "\r\nThe stack start and end address 0x%08X , 0x%08X\r\n",
					        (unsigned int)&_estack , (unsigned int)__get_MSP());
	print_string(buf);

	//Heap start and end address
	sprintf(buf, "\r\nThe heap start address 0x%08X, 0x%08X \r\n",
						        (unsigned int)&_end ,(unsigned int)__sbrk_heap_end);
	print_string(buf);


    /* Loop forever */
	for(;;);
}
