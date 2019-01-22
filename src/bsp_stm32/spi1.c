/*
 * spi1.c
 *
 *  Created on: 2018年11月5日
 *      Author: Administrator
 */


#include "bsp_init.h"
#include "stm32f10x.h"
#include "stm32f10x_conf.h"

/********************************************************************
 * 描述：
 * 输入：
 * 输出：
 ********************************************************************/
void stm32f10x_spi1_init(void){

	GPIO_InitTypeDef 		GPIO_InitStructure;
	SPI_InitTypeDef  		SPI_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);

	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_7;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	//GPIO_PinRemapConfig(GPIO_FullRemap_TIM1,ENABLE);
	//----------------------------------------------------------------
	//
	SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Tx;//单线发送方式
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;//主 SPI
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;//SPI发送接收8或者16位帧结构
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;//SPI_CPOL_High=模式3，时钟空闲为高 //SPI_CPOL_Low=模式0，时钟空闲为低
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;//第一个或者第二个跳变沿数据被采样
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;//NSS 信号由软件控制
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;//预分频 256
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_LSB;//数据从高位开始发送SPI_FirstBit_MSB
	SPI_InitStructure.SPI_CRCPolynomial = 7;//CRC 值计算的多项式
	SPI_Init(SPI1,&SPI_InitStructure);//根据指定的参数初始化外设 SPIx 寄存器
	//SPI_I2S_DMACmd(SPI2,SPI_I2S_DMAReq_Tx,ENABLE);
	SPI_Cmd(SPI1,ENABLE);
}

void stm32f10x_spi1_sendByte(U8 data){
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE)==RESET);
	SPI_I2S_SendData(SPI1,data);
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_BSY)==SET);
}

void stm32f10x_spi1_sendLen(U8 *data,U8 len){
	U8 i;
	for(i=0;i<len;i++){
		while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE)==RESET);
		SPI_I2S_SendData(SPI1,*data);
		data++;
		while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_BSY)==SET);
	}
}













