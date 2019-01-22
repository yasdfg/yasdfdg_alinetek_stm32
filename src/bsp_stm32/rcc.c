/*
 * rcc.c
 *
 *  Created on: 2016年3月12日
 *      Author: yzhuaer
 */

#include "bsp_init.h"
#include "stm32f10x.h"
#include "stm32f10x_conf.h"

void rcc_configurator(void)
{
	RCC_DeInit(); // 将外设 RCC 寄存器重设为缺省值

	RCC_HSICmd(ENABLE);
	while(RCC_GetFlagStatus(RCC_FLAG_HSIRDY)== RESET);//等待HSI就绪

//	RCC_HSEConfig(RCC_HSE_ON); // 设置外部高速晶振（ HSE）

	RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_9); // 设置 PLL 时钟源及倍频系数


	RCC_HCLKConfig(RCC_SYSCLK_Div1); // 设置 AHB 时钟（ HCLK）
	RCC_PCLK1Config(RCC_HCLK_Div2); // 设置低速 AHB 时钟（ PCLK1）
	RCC_PCLK2Config(RCC_HCLK_Div1); // 设置高速 AHB 时钟（ PCLK2）

//	RCC_USBCLKConfig(RCC_PCLK2_Div6); // 设置 USB 时钟（ USBCLK）
//	RCC_ADCCLKConfig(RCC_PCLK2_Div8); // 设置 ADC 时钟（ ADCCLK）

//	RCC_LSEConfig(); // 设置外部低速晶振（ LSE）
//	RCC_LSICmd(); // 使能或者失能内部低速晶振（ LSI）

//	RCC_RTCCLKConfig(); // 设置 RTC 时钟（ RTCCLK）
//	RCC_RTCCLKCmd(); // 使能或者失能 RTC 时钟

//	RCC_ITConfig(); // 使能或者失能指定的 RCC 中断

	RCC_PLLCmd(ENABLE); // 使能 PLL
	while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET); // 检查指定的 RCC 标志位设置与否
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK); // 设置系统时钟（ SYSCLK）

}

///********************************************************************************
//*函数名:   RCC_Configuration()
//*输入参数：无
//*输出参数：无
//*返回值：  无
//*功能描述：
//*说明：
//*******************************************************************************/
//void RCC_Configuration(void)
//{
//	ErrorStatus HSEStartUpStatus;

//	//系统时钟控制器复位
//	RCC_DeInit();

//	//打开外部晶振
//	RCC_HSEConfig(RCC_HSE_ON);

//	//等待外部晶振稳定
//	HSEStartUpStatus = RCC_WaitForHSEStartUp();

//	if(HSEStartUpStatus == SUCCESS)
//	{
//		// HCLK = SYSCLK
//		RCC_HCLKConfig(RCC_SYSCLK_Div1);

//		// PCLK2 = HCLK
//		RCC_PCLK2Config(RCC_HCLK_Div1);

//		// PCLK1 = HCLK/2
//		RCC_PCLK1Config(RCC_HCLK_Div2);
//		// ADCCLK = PCLK2/4
//		RCC_ADCCLKConfig(RCC_PCLK2_Div8);
//		// Flash 2 wait state
//		FLASH_SetLatency(FLASH_Latency_2);
//		// Enable Prefetch Buffer
//		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);

//		// PLLCLK = 8MHz * 9 = 72 MHz
//		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);

//		// Enable PLL
//		RCC_PLLCmd(ENABLE);

//		//等待PLL稳定
//		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
//		{
//		}

//		//选择PLL时钟为系统时钟源
//		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

//		//等待系统时钟源切换完成
//		while(RCC_GetSYSCLKSource() != 0x08)
//		{
//		}
//	}
//	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);//使能DMA1时钟
//	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);//使能DMA1时钟
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);//使能ADC1时钟
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
//	// Enable GPIOB, GPIOF and AFIO clocks
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |
//	                       RCC_APB2Periph_GPIOB |
//						   RCC_APB2Periph_GPIOC |
//						   RCC_APB2Periph_AFIO, ENABLE);
//	//ADC_Config();
//}

/********************************************************************************************************
*  Function: Derive_MCU_Init
********************************************************************************************************/
//void rcc_configurator(void)
//{
//    //--------------------------- CLK INIT, HSE PLL ----------------------------
////    ErrorStatus HSEStartUpStatus;
//    //RCC reset
//    RCC_DeInit();
////		//Enable HSE
////		RCC_HSEConfig(RCC_HSE_ON);
////		do
////		{
////				// TODO: enter the block content here
////				//Wait HSE is ready
////				HSEStartUpStatus = RCC_WaitForHSEStartUp();
////		}
////		//If HSE start fail, wail and wail.
////		while(HSEStartUpStatus == ERROR);
//
//    //4.Set AHB Clock
//    RCC_HCLKConfig(RCC_SYSCLK_Div1);
//
//    //HSE25M PLL-> 48M
//    //RCC_PLLConfig(RCC_PLLSource_PREDIV1, RCC_PLLMul_6);
//    //RCC_PLLConfig(RCC_PLLSource_PREDIV1, RCC_PLLMul_2);
//    RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_4);
//    RCC_PLLCmd(ENABLE);
//
//    //9
//    while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
//    //Select PLL as system clock source
//    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
//
//    //11
//    while(RCC_GetSYSCLKSource() != 0x08);
//
//    //----------------------------- CLOSE HSI ---------------------------
//    //if the flash spi is not used, should be alown to run.
//    //RCC_HSICmd(DISABLE);
//
//    //--------------------------- OPEN GPIO CLK -------------------------
////    RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);
////    RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOB, ENABLE);
////    RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOC, ENABLE);
////    RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOF,ENABLE);
//
//    //--------------------------- OPEN DMA CLK -------------------------
//    //RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);        /* use for adc model */
//
//    //---------------------------- INT CONFIG ---------------------------
//    //2-level interrupt
//    //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//
//    //---------------------------- JTAG CONFIG ---------------------------
//    //JTAG/SWD disable
//    //GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
//    //GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);
//}

































