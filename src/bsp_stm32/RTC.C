/*
 * RTC.C
 *
 *  Created on: 2016年4月21日
 *      Author: yzhuaer
 */

#include "bsp_init.h"
#include "stm32f10x.h"
#include "stm32f10x_conf.h"

U8 Year;
U8 Month;
U8 Day;
U8 Hour;
U8 Minute;
U8 Second;

U8 RTC_AWU_FLAG;

U16 break_tc;

/*******************************************************************************
* 描述：
*******************************************************************************/
void RTC_init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE); // 启用PWR和BKP的时钟（from APB1）
	PWR_BackupAccessCmd(ENABLE);                                             // 后备域解锁

	{
		EXTI_InitTypeDef EXTI_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;

	    EXTI_InitStructure.EXTI_Line = EXTI_Line17;
	    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	    EXTI_Init(&EXTI_InitStructure);

	    NVIC_InitStructure.NVIC_IRQChannel = RTC_IRQn;
	    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	    NVIC_Init(&NVIC_InitStructure);
	}

	if (BKP_ReadBackupRegister(BKP_DR1) != 0xA8A5)
	{
		BKP_DeInit();                                                            // 备份寄存器模块复位

		RCC_LSEConfig(RCC_LSE_ON);                                               // 外部32.768K其哟偶那个

		while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)                      // 等待稳定
		{
//			DelayMS(1);
			if(++break_tc>=5000)
			{
				break;
			}
		}
		if(break_tc<5000)
		{
			RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);                                  // RTC时钟源配置成LSE（外部32.768K）
			RCC_RTCCLKCmd(ENABLE);                                                   // RTC开启

			RTC_EnterConfigMode();                                                   // 进入配置模式

			RTC_WaitForSynchro();                                                    // 开启后需要等待APB1时钟与RTC时钟同步，才能读写寄存器
			RTC_WaitForLastTask();                                                   // 读写寄存器前，要确定上一个操作已经结束

			RTC_SetPrescaler(32767);                                                 // 设置RTC分频器，使RTC时钟为1Hz。RTC period = RTCCLK/RTC_PR= (32.768 KHz)/(32767+1)。
			RTC_WaitForLastTask();                                                   // 等待寄存器写入完成

//			RTC_ITConfig(RTC_IT_SEC, ENABLE);                                      // 使能秒中断
//			RTC_WaitForLastTask();                                                 // 等待写入完成

			RTC_ITConfig(RTC_IT_ALR, ENABLE);                                      // 使能秒中断
			RTC_WaitForLastTask();                                                 // 等待写入完成

			RTC_ExitConfigMode();

			BKP_WriteBackupRegister(BKP_DR1, 0xA8A5);

//			software_version[11]='1';
		}
	}

}


void RTC_IRQHandler(void){

	/* RTC_IT_OW溢出中断
	 * RTC_IT_ALR闹钟中断
	 * RTC_IT_SEC秒中断
	 */

	if (RTC_GetITStatus(RTC_IT_SEC) != RESET) {
		RTC_ClearITPendingBit (RTC_IT_SEC);
	}

	if (RTC_GetITStatus(RTC_IT_ALR) != RESET) {
		RTC_ClearITPendingBit (RTC_IT_ALR);
	}

}

void RTCAlarm_IRQHandler(void)
{
	EXTI_ClearITPendingBit(EXTI_Line17); // SYS.wake_id|=1<<17;
}


/********************************************************************
** 描述：更新时间日期到时后备区。
********************************************************************/
void saveTimer_to_rtc(void)
{
	if(break_tc<5000)
	{
		PWR_BackupAccessCmd(ENABLE); // 后备域解锁

		BKP_WriteBackupRegister(BKP_DR2, Year);
		BKP_WriteBackupRegister(BKP_DR3, Month);
		BKP_WriteBackupRegister(BKP_DR4, Day);
		BKP_WriteBackupRegister(BKP_DR5, Hour);
		BKP_WriteBackupRegister(BKP_DR6, Minute);
		BKP_WriteBackupRegister(BKP_DR7, Second);

		RTC_SetCounter(0);
		RTC_WaitForLastTask(); // 等待写入完成

		RTC_SetAlarm(60*60);   // 一个小时后自动唤醒60*60
		RTC_WaitForLastTask(); // 等待写入完成

		EXTI_ClearITPendingBit(EXTI_Line17);
	}
}

/********************************************************************
** 描述：从后备区中更新时间日期。
********************************************************************/
void getTimer_from_rtc(void)
{
//	U32 rtc_S;
//
//	PWR_BackupAccessCmd(ENABLE); // 后备域解锁
//
//	Year = BKP_ReadBackupRegister(BKP_DR2);
//	Month = BKP_ReadBackupRegister(BKP_DR3);
//	Day = BKP_ReadBackupRegister(BKP_DR4);
//	Hour = BKP_ReadBackupRegister(BKP_DR5);
//	Minute = BKP_ReadBackupRegister(BKP_DR6);
//	Second = BKP_ReadBackupRegister(BKP_DR7);
//
//	rtc_S = RTC_GetCounter();

}


















































