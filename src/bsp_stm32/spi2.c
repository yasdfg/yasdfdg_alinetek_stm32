/*
 * spi2.c
 *
 *  Created on: 2018-08-02 17:58
 *      Author: yzhuar(598092672@QQ.com)
 *
 */

#include "bsp_init.h"
#include "stm32f10x.h"
#include "stm32f10x_conf.h"

/********************************************************************
 * 描述：
 * 输入：
 * 输出：
 ********************************************************************/
void stm32f10x_spi2_init(void){

	GPIO_InitTypeDef 		GPIO_InitStructure;
	SPI_InitTypeDef  		SPI_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);

	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_15;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	//GPIO_PinRemapConfig(GPIO_FullRemap_TIM1,ENABLE);
	//----------------------------------------------------------------
	//
	SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Tx;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;   //SPI_NSS_Hard
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;//SPI_BaudRatePrescaler_256;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	//SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_Init(SPI2,&SPI_InitStructure);
	//SPI_I2S_DMACmd(SPI2,SPI_I2S_DMAReq_Tx,ENABLE);
	SPI_Cmd(SPI2,ENABLE);
}

void stm32f10x_spi2_sendByte(U8 data){
	while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_TXE)==RESET);
	SPI_I2S_SendData(SPI2,data);
	while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_BSY)==SET);
}

void stm32f10x_spi2_sendLen(U8 *data,U8 len){
	U8 i;
	for(i=0;i<len;i++){
		while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_TXE)==RESET);
		SPI_I2S_SendData(SPI2,*data);
		data++;
		while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_BSY)==SET);
	}
}

////U8 SPIWriteByte(U8 Byte){
////	while((SPI2->SR&0X02)==0);      // 等待发送区空
////	SPI2->DR=Byte;                  // 发送一个byte
//////	while((SPI2->SR&0X01)==0);      // 等待接收完一个byte
//////	return SPI2->DR;                // 返回收到的数据
////}

// //SPIx 读写一个字节
// //TxData:要写入的字节
// //返回值:读取到的字节
//U8 SPIReadByte(U8 TxData)
//{
//     u8 retry=0;
//     while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET) //检查指定的SPI标志位设置与否:发送缓存空标志位
//     {
//         retry++;
//         if(retry>200)return 0;
//     }
//     SPI_I2S_SendData(SPI2, TxData); //通过外设SPIx发送一个数据
//     retry=0;

//     while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET) //检查指定的SPI标志位设置与否:接受缓存非空标志位
//     {
//         retry++;
//         if(retry>200)return 0;
//     }
//     return SPI_I2S_ReceiveData(SPI2); //返回通过SPIx最近接收的数据
//}


//void SPI2_Init(void)
//{
// 	GPIO_InitTypeDef GPIO_InitStructure;
//  	SPI_InitTypeDef  SPI_InitStructure;

//	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );//PORTB时钟使能
//	RCC_APB1PeriphClockCmd(	RCC_APB1Periph_SPI2,  ENABLE );//SPI2时钟使能

//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //PB13/14/15复用推挽输出
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOB

// 	GPIO_SetBits(GPIOB,GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);  //PB13/14/15上拉

//	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //设置SPI单向或者双向的数据模式:SPI设置为双线双向全双工
//	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		//设置SPI工作模式:设置为主SPI
//	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;		//设置SPI的数据大小:SPI发送接收8位帧结构
//	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;		//串行同步时钟的空闲状态为高电平
//	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;	//串行同步时钟的第二个跳变沿（上升或下降）数据被采样
//	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		//NSS信号由硬件（NSS管脚）还是软件（使用SSI位）管理:内部NSS信号有SSI位控制
//	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;		//定义波特率预分频的值:波特率预分频值为256
//	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	//指定数据传输从MSB位还是LSB位开始:数据传输从MSB位开始
//	SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRC值计算的多项式
//	SPI_Init(SPI2, &SPI_InitStructure);  //根据SPI_InitStruct中指定的参数初始化外设SPIx寄存器

//	SPI_Cmd(SPI2, ENABLE); //使能SPI外设

//	SPI2_ReadWriteByte(0xff);//启动传输


//}
////SPI 速度设置函数
////SpeedSet:
////SPI_BaudRatePrescaler_2   2分频
////SPI_BaudRatePrescaler_8   8分频
////SPI_BaudRatePrescaler_16  16分频
////SPI_BaudRatePrescaler_256 256分频
//void SPI2_SetSpeed(u8 SPI_BaudRatePrescaler){
//  	assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_BaudRatePrescaler));
//	SPI2->CR1&=0XFFC7;
//	SPI2->CR1|=SPI_BaudRatePrescaler;	//设置SPI2速度
//	SPI_Cmd(SPI2,ENABLE);

//}

////SPIx 读写一个字节
////TxData:要写入的字节
////返回值:读取到的字节
//u8 SPI2_ReadWriteByte(u8 TxData)
//{
//	u8 retry=0;
//	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET){ //检查指定的SPI标志位设置与否:发送缓存空标志位
//		retry++;
//		if(retry>200)return 0;
//	}
//	SPI_I2S_SendData(SPI2, TxData); //通过外设SPIx发送一个数据
//	retry=0;

//	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET) //检查指定的SPI标志位设置与否:接受缓存非空标志位
//		{
//		retry++;
//		if(retry>200)return 0;
//		}
//	return SPI_I2S_ReceiveData(SPI2); //返回通过SPIx最近接收的数据
//}





























