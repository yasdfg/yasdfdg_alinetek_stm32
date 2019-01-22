/*
 * uart1.c
 *
 *  Created on: 2016年3月9日
 *      Author: yzhuaer
 */

#include "bsp_init.h"
#include "stm32f10x.h"
#include "stm32f10x_conf.h"

/*****************************************************************************
** 描述：
*****************************************************************************/
void uart1_init(U32 bound)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	//① GPIO、串口时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);
	//②串口复位
	USART_DeInit(USART1);
	//③GPIO 端口模式设置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; // USART1_TX PA.9
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; // 复用推挽输出
	GPIO_Init(GPIOA, &GPIO_InitStructure); // 初始化 PA9
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; // USART1_RX  PA.10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; // 浮空输入
	GPIO_Init(GPIOA, &GPIO_InitStructure); // 初始化 PA10
	//④串口参数初始化
	USART_InitStructure.USART_BaudRate = bound; // 一般设置为 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; // 字长为 8 位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1; // 一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No; // 无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // 无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; // 收发模式
	USART_Init(USART1, &USART_InitStructure); // 根据指定的参数初始化串口
	//⑤初始化 NVIC
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;	// 抢占优先级 3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3; // 子优先级 3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; // IRQ 通道使能
	NVIC_Init(&NVIC_InitStructure); // 根据指定的参数初始化 VIC 寄存器
	//⑤开启中断
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);	//开启中断
	//⑥使能串口
	USART_Cmd(USART1, ENABLE); // 使能串口
}

/*****************************************************************************
** 描述：
*****************************************************************************/
void  uart1_send_str (char *pstr)
{
    while (*pstr != 0){
        while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
        USART_SendData(USART1, *(pstr++));
    }
}

/*****************************************************************************
 ** 描述：
 *****************************************************************************/
void uart1_send_len(U8 *pstr, U16 len) {

	U16 tihs_i;

	for(tihs_i=0;tihs_i<len;tihs_i++){

		while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
			;
		USART_SendData(USART1, *(pstr++));

	}

}

/*****************************************************************************
** 描述：串口1中断服务程序
*****************************************************************************/
void USART1_IRQHandler(void){

	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
		//while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET){}
		USART1->DR++;
		USART_SendData(USART1,'1');
	}
}






































