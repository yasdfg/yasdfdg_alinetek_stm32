/*
 * lh_delog.c
 *
 *  Created on: 2019-01-07 18:01
 *      Author: yzhuar(598092672@QQ.com)
 *
 */

#include "lh_delog.h"
#ifdef lh_DELOG_EN

#include "includeALL.H"

static void baud_rate_delay(void){ // 波特率115200的bit延时是8.68us
	U8 i;                          // 1ms只能发送14.4个字节
	for(i=0;i<99;i++){} // stm32f103 在ram中跑的延时8.6us
//	for(i=0;i<85;i++){} // stm32f103 在rom中跑的延时8.72us
}
static void VirtualCOM_ByteSend(u8 val) {
	u8 i = 0;
	PAout(9)=0;	//起始位
	baud_rate_delay();
	for (i = 0; i < 8; i++){	//8位数据位
		if (val & 0x01)
			PAout(9)=1;
		else
			PAout(9)=0;
		baud_rate_delay();
		val >>= 1;
	}
	PAout(9)=1;	//停止位
	baud_rate_delay();
}

/********************************************************************
 * 描述：
 * 输入：
 * 输出：
 ********************************************************************/
void lh_delog_print(const char *logDat) {
	while (*logDat != 0) {
		VirtualCOM_ByteSend(*logDat);
		logDat++;
	}
}
#endif

















