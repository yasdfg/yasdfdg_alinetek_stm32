/*
 * UART2.C
 *
 *  Created on: 2017年11月27日
 *      Author: yzhuar
 */
#include "includeALL.h"
#include "bsp_init.h"
#include "stm32f10x.h"
#include "stm32f10x_conf.h"

/*****************************************************************************
** 描述：
*****************************************************************************/
void uart2_init(U32 bound)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	//① GPIO、串口时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	//②串口复位
	USART_DeInit(USART2);
	//③GPIO 端口模式设置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; // USART1_TX PA.2
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; // 复用推挽输出
	GPIO_Init(GPIOA, &GPIO_InitStructure); // 初始化 PA2
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3; // USART1_RX  PA.3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; // 浮空输入
	GPIO_Init(GPIOA, &GPIO_InitStructure); // 初始化 PA3
	//④串口参数初始化
	USART_InitStructure.USART_BaudRate = bound; // 一般设置为 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; // 字长为 8 位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1; // 一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No; // 无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // 无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; // 收发模式
	USART_Init(USART2, &USART_InitStructure); // 根据指定的参数初始化串口
	//⑤初始化 NVIC
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;	// 抢占优先级 3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3; // 子优先级 3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; // IRQ 通道使能
	NVIC_Init(&NVIC_InitStructure); // 根据指定的参数初始化 VIC 寄存器
	//⑤开启中断
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); //开启接收中断
//	USART_ITConfig(USART2, USART_IT_TXE, ENABLE); //开启发送中断
	//⑥使能串口
	USART_Cmd(USART2, ENABLE); // 使能串口
}
void uart2_open_it(void){
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); //开启接收中断
}
void uart2_close_it(void){
	USART_ITConfig(USART2, USART_IT_RXNE, DISABLE); //开启接收中断
}
/*****************************************************************************
 ** 描述：
 *****************************************************************************/
void uart2_send_str(const char *pstr) {
	while (*pstr != 0) {
		while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET)
			;
		USART_SendData(USART2, *(pstr++));
	}
}

/*****************************************************************************
 ** 描述：
 *****************************************************************************/
void uart2_send_len(U8 *pstr, U16 numbyte) {

	U16 tihs_i;

	for(tihs_i=0;tihs_i<numbyte;tihs_i++){

		while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET)
			;
		USART_SendData(USART2, *(pstr++));

	}

}

/*****************************************************************************
 ** 描述：串口2中断服务程序
 *****************************************************************************/
void USART2_IRQHandler(void) {

	if ((USART2->SR & USART_FLAG_RXNE) == USART_FLAG_RXNE) {
//		commBus_uartRead((U8) USART2->DR);
	}
//	if (USART_GetITStatus(USART2, USART_IT_RXNE) != RESET) {
//
//		lh_debugUart_recvByte(USART_ReceiveData(USART2));
//
//	}
}






























