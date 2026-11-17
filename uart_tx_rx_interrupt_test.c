//uart_tx_rx_interrupt_test.c
#include "uart.h"
#include "delay.h"
#include <LPC21xx.h>

extern u32 flag;
s8 t='A';
main()
{
	UART_Init();
	while(1)
	{
		U0THR=t;
		while(flag==0);
		flag=0;
		delay_ms(100);
	}
}
