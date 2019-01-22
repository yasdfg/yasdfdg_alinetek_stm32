/*
 * main.c
 *
 *  Created on: 2019-01-03 14:19
 *      Author: yzhuar(598092672@QQ.com)
 *
 */

#include "includeAll.h"

U8 funStateMac[12];  // 功能状态机
U8 funStateMac_mark=1; // 功能状态机，状态改变标记


//任务栈空间必须 8 字节对齐，可以将任务栈数组定义成 uint64_t 类型即可。
static U64 AppTaskStartStk[512/8]; /* 任务栈 */
static U64 AppTaskLcdEvt[256/8]; /* 任务栈 */
static U64 AppTaskLcdStk[256/8]; /* 任务栈 */
static U64 AppTaskLEDStk[256/8]; /* 任务栈 */

/* 任务句柄 */
OS_TID HandleTaskEvt=NULL;
OS_TID HandleTaskLcd=NULL;
OS_TID HandleTaskLED=NULL;

__task void AppTaskStart(void);



__task void AppTaskEvt(void);
__task void AppTaskLcd(void);
__task void AppTaskLED(void);
/*
*********************************************************************************************************
* 函 数 名: main
* 功能说明: 标准 c 程序入口。
* 形 参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
int main(void) {
	#ifdef Dbg_RAM
	NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0);
	#endif

	{static U32 memPool[(200+3)/4];
	lh_memPool_init((U8*)memPool,sizeof(memPool));}

	/* 初始化外设 */
	bsp_init();
	/* 创建启动任务 */
	os_sys_init_user(AppTaskStart,                /* 任务函数 */
						2,                        /* 任务优先级 */
						&AppTaskStartStk,         /* 任务栈 */
						sizeof(AppTaskStartStk)); /* 任务栈大小，单位字节数 */
	// 大家使用的简单工程里面不能有 SysTick，PendSV 和 SVC 三个系统中断的使用，因为 RTX 系统要使用这三个中断。
	//PendSV是可悬起异常
	while(1){}
}
/*
*********************************************************************************************************
* 函 数 名: AppTaskStart
* 功能说明: 启动任务，也就是最高优先级任务。
* 形 参: 无
* 返 回 值: 无
* 优 先 级: 2
*********************************************************************************************************
*/
__task void AppTaskStart(void) {


	HandleTaskLED = os_tsk_create_user(AppTaskLED,              /* 任务函数 */
										1,                      /* 任务优先级 */
										&AppTaskLEDStk,         /* 任务栈 */
										sizeof(AppTaskLEDStk)); /* 任务栈大小，单位字节数 */
	HandleTaskLcd = os_tsk_create_user(AppTaskLcd,              /* 任务函数 */
										2,                      /* 任务优先级 */
										&AppTaskLcdStk,         /* 任务栈 */
										sizeof(AppTaskLcdStk)); /* 任务栈大小，单位字节数 */
	HandleTaskEvt = os_tsk_create_user(AppTaskEvt,              /* 任务函数 */
										3,                      /* 任务优先级 */
										&AppTaskLcdEvt,         /* 任务栈 */
										sizeof(AppTaskLcdEvt)); /* 任务栈大小，单位字节数 */


	while (1) {

		os_dly_wait(500);
	}
}
/****************************************************
 * 描述：
 * 优 先 级: 2。
 * 参数：
 * 返回：
 * 修改：
****************************************************/
__task void AppTaskEvt(void) {

	while (1) {
		os_dly_wait(500);
	}
}
/****************************************************
 * 描述：
 * 优 先 级: 2。
 * 参数：
 * 返回：
 * 修改：
****************************************************/

__task void AppTaskLcd(void) {

	lh_stateMac_init((lh_SMN_abt)funStateMac,start);

	LCD_Init();

	while (1) {
		if(lh_stateMac_Process((lh_SMN_abt)funStateMac)){
			funStateMac_mark=1;
		}
		os_dly_wait(10);
	}
}
/****************************************************
 * 描述：系统信号灯和按键扫描任务，优先给最低，当信号灯不正常时，说明程序不正常。
 * 优 先 级: 1。对于 RTX 操作系统来说，优先级参数中数值越小优先级越低，也就是说
 *        空闲任务的优先级是最低的，因为它的优先级数值是 0
 * 参数：
 * 返回：
 * 修改：
****************************************************/
__task void AppTaskLED(void) {

	lh_systemLed_rest(0);

//	os_itv_set(10); // 绝对周期事件10ms
//	os_itv_wait();

	while (1) {
//		static U16 index;
//		index=lh_memPool_getUsedSize();
//		if(index){}
		lh_systemLed_set(0,systemLedDat3); // 系统信号灯快闪
		lh_systemLed_set(2,lh_systemLed_uart("1234567890",10)); // 系统信号灯快闪
//		if(lh_systemLed_getState(2)){
//			lh_systemLed_rest(2);
//		}
		//- 按键
		lh_systemKey_polling();
		//- 系统灯- 蜂鸣器
		lh_systemLed_polling();
		os_dly_wait(10);
	}
}







































