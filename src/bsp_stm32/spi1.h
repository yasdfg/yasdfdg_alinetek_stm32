/*
 * spi1.h
 *
 *  Created on: 2018年11月5日
 *      Author: Administrator
 */

#ifndef RTX_STM32F103C8_USER_APP_STM32F10X_BSP_SPI1_H_
#define RTX_STM32F103C8_USER_APP_STM32F10X_BSP_SPI1_H_

#include "lh_typedef.h"

extern void stm32f10x_spi1_init(void);
extern void stm32f10x_spi1_sendByte(U8 data);
extern void stm32f10x_spi1_sendLen(U8 *data,U8 len);

#endif /* RTX_STM32F103C8_USER_APP_STM32F10X_BSP_SPI1_H_ */
