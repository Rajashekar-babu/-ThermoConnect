//eint0_virq0_eint1_virq1_test.c
#include <LPC21xx.h>
#include "types.h"
#define EINT0_VIC_CHNO 14
#define EINT0_STATUS_LED 16 //@p1.16
#define EINT0_PIN_FUNC   0x0000000C

#define EINT1_VIC_CHNO 15
#define EINT1_STATUS_LED 17 //@p1.17
#define EINT1_PIN_FUNC   0x000000C0

void eint0_isr(void) __irq;
void eint1_isr(void) __irq;

u32 gCount;

main()
{
	//Cfg p0.1,p0.3 as EINT0,EINT1 input pins
	PINSEL0&=~((3<<(1*2))|(3<<(3*2)));
	PINSEL0|=EINT0_PIN_FUNC|
	         EINT1_PIN_FUNC;
	//cfg VIC
	//let eint0,eint1 be irq type
	//default all are anyway irq type
	//VICIntSelect=0;
	//enable eint0,eint1 via vic
	VICIntEnable=1<<EINT0_VIC_CHNO|
	             1<<EINT1_VIC_CHNO;
	
	//cfg eint0 as v.irq with priority 0
	VICVectCntl0=(1<<5)|EINT0_VIC_CHNO;
	//load isr addr into irq slot 0
	VICVectAddr0=(u32 ) eint0_isr;
	
	//cfg eint1 as v.irq with priority 1
	VICVectCntl1=(1<<5)|EINT1_VIC_CHNO;
	//load isr addr into irq slot 1
	VICVectAddr1=(u32 ) eint1_isr;
	
	//cfg External Interrupt Peripheral(EIP)
	//enable EINT0,EINT1 ,all are default enabled
	//EXTINT=0;
	//cfg eint0,eint1 as edge triggered,
	EXTMODE=(1<<1)|(1<<0);
	//cfg eint0,eint1 for falling edge trigger
	//default all are falling edge
	//EXTPOLAR=0;
	
	//cfg EINT0,EINT1 status leds pins as gpio out
	IODIR1|=(1<<EINT0_STATUS_LED)|
	        (1<<EINT1_STATUS_LED);
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

void eint1_isr(void) __irq
{
	//isr activity to be executed
	IOPIN1^=1<<EINT1_STATUS_LED;
	//clear eint1 status in vic
	VICVectAddr=0;
	//clear eint1 status in EIP
	EXTINT=1<<1;
}
