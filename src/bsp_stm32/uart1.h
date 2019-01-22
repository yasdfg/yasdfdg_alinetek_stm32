/*
 * uart1.h
 *
 *  Created on: 2016年3月10日
 *      Author: yzhuaer
 */

#ifndef STM32F103C8_SOURCE_APP_INC_UART1_H_
#define STM32F103C8_SOURCE_APP_INC_UART1_H_

#include "lh_typedef.h"

void uart1_init(U32 bound);
void uart1_send_str (char *pstr);
void uart1_send_len(U8 *pstr, U16 len);

#endif /* STM32F103C8_SOURCE_APP_INC_UART1_H_ */
