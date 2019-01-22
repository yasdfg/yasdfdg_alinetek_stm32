/*
 * +.C
 *
 *  Created on: 2016年3月10日
 *      Author: yzhuaer
 */
#include "lh_interface.h"
#include "bsp_init.h"

/**************************************************************
 ** 描述：在72MHz中，定时1ms
 **************************************************************/
void SysTick_Init(void) {
//	SysTick_Config(9000/2);
//	SysTick_CLKSourceConfig (SysTick_CLKSource_HCLK_Div8); // 设置 SysTick 时钟源
//	SysTick_SetReload(ENABLE); // 设置 SysTick 重装载值
//	SysTick_CounterCmd(ENABLE); // 使能或者失能 SysTick 计数器
//	SysTick_ITConfig(ENABLE); // 使能或者失能 SysTick 中断
}


//void SysTick_Handler(void){
//	lessos32_tick_dev();	//smg6_process();
//	lessos32_trigTask(0);
//}































