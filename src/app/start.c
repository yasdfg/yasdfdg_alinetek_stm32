/*
 * systemLed_process.c
 *
 *  Created on: 2019-01-03 17:06
 *      Author: yzhuar(598092672@QQ.com)
 *
 */

#include "includeAll.H"

typedef void* (*lh_stateMacFun_t)(void);

static U8 funId;
static U8 funIdOut[12];
void* start1(void){
	if(funStateMac_mark){funStateMac_mark=0;
		POINT_COLOR=BLACK;
		LCD_Clear(RED);
	}
	if(lh_systemKey_Single(2)==5){ // 左
		lh_systemLed_rest(1);
		lh_systemLed_set(1,systemLedDat4);
		return lh_stateMac_getBeforeState((lh_SMN_abt)funStateMac);
	}
	return start1;
}
const lh_stateMacFun_t stateMacFunList[]={
	start,start1,
};

/********************************************************************
 * 描述：
 ********************************************************************/
static void showFunId(void){
	sprintf((char*)funIdOut,"funId: %04X",funId);
	LCD_ShowString(30,110,200,16,16,funIdOut);
}
/********************************************************************
 * 描述：
 * 输入：
 * 输出：
 ********************************************************************/
void* start(void){
	if(funStateMac_mark){funStateMac_mark=0;
		POINT_COLOR=RED;
		LCD_Clear(BLACK);
		LCD_ShowString(30,50,200,16,16,"WarShip STM32 ^_^");
		LCD_ShowString(30,70,200,16,16,"TFTLCD TEST");
		LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
		showFunId();
		LCD_ShowString(30,130,200,16,16,"2012/9/5");
	}
	if(lh_systemKey_Single(3)==5){ // 上
		funId++;
		lh_systemLed_rest(1);
		lh_systemLed_set(1,systemLedDat4);
		showFunId();
	}
	if(lh_systemKey_Single(1)==5){ // 下
		funId--;
		lh_systemLed_rest(1);
		lh_systemLed_set(1,systemLedDat4);
		showFunId();
	}
	if(lh_systemKey_Single(2)==5){ // 左
		lh_systemLed_rest(1);lh_systemLed_rest(2);
		lh_systemLed_set(1,systemLedDat4);
	}
	if(lh_systemKey_Single(0)==5){ // 右 进入下一个功能
		lh_systemLed_rest(1);
		lh_systemLed_set(1,systemLedDat4);
		if(funId<countof(stateMacFunList)){
			return stateMacFunList[funId];
		}
	}
	return start;
}

