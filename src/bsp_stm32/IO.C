/*
 * IO.C
 *
 *  Created on: 2017年11月27日
 *      Author: yzhuar
 */

#include "bsp_init.h"
#include "stm32f10x.h"
#include "stm32f10x_conf.h"

void KEY_Init(void) //IO初始化
{
 	GPIO_InitTypeDef GPIO_InitStructure;
	//初始化KEY0-->GPIOA.13,KEY1-->GPIOA.15  上拉输入
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);//使能PORTA,PORTE时钟

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;//PE2~4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOE2,3,4

	//初始化 WK_UP-->GPIOA.0	  下拉输入
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0设置成输入，默认下拉
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.0

}
void BEEP_Init(void)
{

 GPIO_InitTypeDef  GPIO_InitStructure;

 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能GPIOB端口时钟

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				 //BEEP-->PB.8 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);	 //根据参数初始化GPIOB.8



 GPIO_ResetBits(GPIOB,GPIO_Pin_8);//输出0，关闭蜂鸣器输出

}
//初始化SSD1306
void OLED_Init(void)
{

 	GPIO_InitTypeDef  GPIO_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOG, ENABLE);	 //使能PC,D,G端口时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_6;	 //PD3,PD6推挽输出
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度50MHz
 	GPIO_Init(GPIOD, &GPIO_InitStructure);	  //初始化GPIOD3,6
 	GPIO_SetBits(GPIOD,GPIO_Pin_3|GPIO_Pin_6);	//PD3,PD6 输出高



 	GPIO_InitStructure.GPIO_Pin =0xFF; //PC0~7 OUT推挽输出
 	GPIO_Init(GPIOC, &GPIO_InitStructure);
 	GPIO_SetBits(GPIOC,0xFF); //PC0~7输出高

 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;				 //PG13,14,15 OUT推挽输出
 	GPIO_Init(GPIOG, &GPIO_InitStructure);
 	GPIO_SetBits(GPIOG,GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);						 //PG13,14,15 OUT  输出高
}
/*******************************************************
 * 功能：
 ******************************************************/
void IO_Init(void) {


	 GPIO_InitTypeDef  GPIO_InitStructure;
	 KEY_Init();
	 BEEP_Init();
	 OLED_Init();
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE, ENABLE);	 //Ê¹ÄÜPB,PE¶Ë¿ÚÊ±ÖÓ

	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 //LED0-->PB.5 红色灯
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //
	 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //
	 GPIO_SetBits(GPIOB,GPIO_Pin_5);						 //

	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	    		 //LED1-->PE.5 绿色灯
	 GPIO_Init(GPIOE, &GPIO_InitStructure);	  				 //
	 GPIO_SetBits(GPIOE,GPIO_Pin_5); 						 //

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 //PB0 推挽输出 LCD背光
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}































