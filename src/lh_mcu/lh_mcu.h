/*
 * lh_mcu.h
 *
 *  Created on: 2019-01-06 13:51
 *      Author: yzhuar(598092672@QQ.com)
 *
 */
#ifndef SRC_LH_MCU_LH_MCU_H_
#define SRC_LH_MCU_LH_MCU_H_

#include "lh_interface.h"
#include "bsp_init.h"

U8 *lh_mcu_key_hook(void);
extern const U8 systemLedDat0[];
extern const U8 systemLedDat1[];
extern const U8 systemLedDat2[];
extern const U8 systemLedDat3[];
extern const U8 systemLedDat4[];
U8 *lh_mcu_led_hook(void);

#endif /* SRC_LH_MCU_LH_MCU_H_ */
