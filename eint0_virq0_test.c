//eint0_virq0_test.c
#include <LPC21xx.h>
#include "types.h"

#define EINT0_VIC_CHNO 14
#define EINT0_STATUS_LED 16 //@p1.16
#define EINT0_PIN_FUNC   0x0000000C
void eint0_isr(void) __irq;
u32 gCount;

main()
{
	//Cfg p0.1 as EINT0 input
	PINSEL0&=~(3<<(1*2));
	PINSEL0|=EINT0_PIN_FUNC;
	//cfg VIC
	//let eint0 be irq type
	//default all are anyway irq type
	//VICIntSelect=0;
	//enable eint0 via vic
	VICIntEnable=1<<EINT0_VIC_CHNO;
	//cfg eint0 as v.irq with priority 0
	VICVectCntl0=(1<<5)|EINT0_VIC_CHNO;
	//load isr addr into irq slot 0
	VICVectAddr0=(u32 ) eint0_isr;
	
	//cfg External Interrupt Peripheral(EIP)
	//enable EINT0 ,all are default enabled
	//EXTINT=0;
	//cfg eint0 as edge triggered,
	EXTMODE=1<<0;
	//cfg eint0 for falling edge trigger
	//default all are falling edge
	//EXTPOLAR=0;
	
	//cfg EINT0 status led pin as gpio out
	IODIR1|=1<<EINT0_STATUS_LED;
	while(1)
	{
		gCount++;
	}
}

void eint0_isr(void) __irq
{
	//isr activity to be executed
	IOPIN1^=1<<EINT0_STATUS_LED;
	//clear eint0 status in vic
	VICVectAddr=0;
	//clear eint0 status in EIP
	EXTINT=1<<0;
}
