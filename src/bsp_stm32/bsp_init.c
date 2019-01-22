/*
 * bsp_init.c
 *
 *  Created on: 2018-08-02 15:46
 *      Author: yzhuar(598092672@QQ.com)
 *
 */

#include "bsp_init.h"
#include "stm32f10x.h"
#include "stm32f10x_conf.h"

/********************************************************************
 * 鎻忚堪锛�
 * 杈撳叆锛�
 * 杈撳嚭锛�
 ********************************************************************/
void bsp_init(void){

	U32 thei;
	for(thei=0;thei<3000000;thei++){}

//	rcc_configurator(); // 瀹氫箟鏃堕挓

	//另外强烈推荐用户将 Cortex-M3 内核的 STM32F103 和 Cortex-M4 内核的 STM32F407 的
	//NVIC 优先级分组设置为 4,即：NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);这样中断
	//优先级的管理将非常方便。
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

	IO_Init(); //
	fsmc_init();
//	stm32f10x_spi1_init();
//	stm32f10x_spi2_init();
	uart1_init(9600);
//	uart2_init(9600);
	SysTick_Init();

}






























