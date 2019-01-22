/*
 * lh_component.h
 *
 *  Created on: 2018-11-29 03:08
 *      Author: yzhuar(598092672@QQ.com)
 *
 */
#ifndef LH_COMPONENT_LH_COMPONENT_H_
#define LH_COMPONENT_LH_COMPONENT_H_

#include "lh_interface.h"

#include "lh_systemDelay.h"
#include "lh_systemLed.h"
#include "intel_8080_gpio.h"

#include "oled_SSD1306.h"
#include "lh_systemKey.h"
#include "lh_delog.h"

#define lh_delay_ms(nms) os_dly_wait(nms)
#define lh_delay_us(nus) os_dly_wait(nus)
#define lh_osDelay_ms(nms) os_dly_wait(nms)
#define lh_osDelay_us(nus) os_dly_wait(nus)

#endif /* LH_COMPONENT_LH_COMPONENT_H_ */
