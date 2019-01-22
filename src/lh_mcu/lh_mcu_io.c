/*
 * lh_mcu_io.c
 *
 *  Created on: 2019-01-06 13:46
 *      Author: yzhuar(598092672@QQ.com)
 *
 */

#include "lh_mcu.h"



//typedef struct {
//	U8 *key_port;     // 二值端口
//	U8 *adc_port;     // 数值端口
//	U8 *adc_port;     // 通讯端口
//	U8 *adc_port;     // 中断端口
//
//
//    U8 key_num;       // 按键个数
//
//    U8 tri_t;        // 输出连按之前的寄存数，
//    U8 out_tri_t;    // 输出单击，多连按的值。例如：1为单按、2为二连按、3为三连按、以此递推
//}lh_key1_t;

/********************************************************************
 * 描述：
 ********************************************************************/
U8 *lh_mcu_key_hook(void){
	static U8 lh_mcu_key_input[1+4];
	lh_mcu_key_input[0]=4;
	lh_mcu_key_input[1]=KEY0;
	lh_mcu_key_input[2]=KEY1;
	lh_mcu_key_input[3]=KEY2;
	lh_mcu_key_input[4]=!KEY3;
	return lh_mcu_key_input;
}
const U8 systemLedDat0[]={0,255};// 指示灯灭
const U8 systemLedDat1[]={1,255};// 指示灯亮
const U8 systemLedDat2[]={// 指示灯1秒慢闪
	1,100,
	0,100,
	1,254,
};
const U8 systemLedDat3[]={// 指示灯0.2秒快闪
	1,20,
	0,20,
	1,254,
};
const U8 systemLedDat4[]={// 指示灯0.3亮后灭
	1,5,
	0,255,
};
static void baud_rate_delay(void){ // 波特率115200的bit延时是8.68us
	U8 i;                          // 1ms只能发送14.4个字节
	for(i=0;i<99;i++){} // stm32f103 在ram中跑的延时8.6us
//	for(i=0;i<85;i++){} // stm32f103 在rom中跑的延时8.72us
}
static void VirtualCOM_ByteSend(u8 val) {
	u8 i = 0;
	LED1=0;	//起始位
	baud_rate_delay();
	for (i = 0; i < 8; i++){	//8位数据位
		if (val & 0x01)
			LED1=1;
		else
			LED1=0;
		baud_rate_delay();
		val >>= 1;
	}
	LED1=1;	//停止位
	baud_rate_delay();
}
/********************************************************************
 * 描述：
 ********************************************************************/
U8 *lh_mcu_led_hook(void){
	static U8 lh_mcu_led_output[1+3];
	lh_mcu_led_output[0]=3;
	LED0=!lh_mcu_led_output[1];
	BEEP=lh_mcu_led_output[2];
	if(lh_mcu_led_output[3])
	VirtualCOM_ByteSend(lh_mcu_led_output[3]);
	return lh_mcu_led_output;
}







































