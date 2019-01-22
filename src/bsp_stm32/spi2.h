/*
 * spi2.h
 *
 *  Created on: 2018-08-07 15:30
 *      Author: yzhuar(598092672@QQ.com)
 *
 */
#ifndef USER_APP_STM32F10X_BSP_SPI2_H_
#define USER_APP_STM32F10X_BSP_SPI2_H_

#include "lh_typedef.h"

extern void stm32f10x_spi2_init(void);
extern void stm32f10x_spi2_sendByte(U8 data);
extern void stm32f10x_spi2_sendLen(U8 *data,U8 len);

extern U8 SPIWriteByte(U8 Byte);
extern U8 SPIReadByte(U8 TxData);

#endif /* USER_APP_STM32F10X_BSP_SPI2_H_ */
