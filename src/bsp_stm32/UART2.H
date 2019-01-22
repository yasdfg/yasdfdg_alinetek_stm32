/*
 * UART2.H
 *
 *  Created on: 2017年11月27日
 *      Author: yzhuar
 */

#ifndef STM32F10X_UART2_H_
#define STM32F10X_UART2_H_

#include "lh_typedef.h"

void uart2_init(U32 bound);
void uart2_open_it(void);
void uart2_close_it(void);
void uart2_send_str(const char *pstr);
void uart2_send_len(U8 *pstr, U16 numbyte);

#endif /* STM32F10X_UART2_H_ */
