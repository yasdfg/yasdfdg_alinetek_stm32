/*
 * IO.H
 *
 *  Created on: 2017年11月27日
 *      Author: yzhuar
 */

#ifndef STM32F10X_IO_H_
#define STM32F10X_IO_H_

#define LED0 PBout(5)
#define LED1 PEout(5)

#define KEY0 PEin(4)   	//PE4
#define KEY1 PEin(3)	//PE3
#define KEY2 PEin(2)	//PE2
#define KEY3 PAin(0)	//PA0  WK_UP

#define BEEP PBout(8)

void IO_Init(void);

#endif /* STM32F10X_IO_H_ */
