/*
 * lh_systemDelay.c
 *
 *  Created on: 2019-01-05 16:22
 *      Author: yzhuar(598092672@QQ.com)
 *
 */

#include "includeALL.H"

/********************************************************************
 * 描述：
 * 输入：
 * 输出：
 ********************************************************************/
void lh_systemDelay_ms(U16 nms){
	//arm_m3在72MHz下的延时
	U16 i,j;
	for(i=0;i<nms;i++){
		for(j=0;j<7980;j++){

		}
	}
}
/********************************************************************
 * 描述：
 * 输入：
 * 输出：
 ********************************************************************/
void lh_systemDelay_us(U16 nus){
	//arm_m3在72MHz下的延时
	U16 i,j;
	for(i=0;i<nus;i++){
		j=6;
		do{
		}while(j--);
	}
}




































