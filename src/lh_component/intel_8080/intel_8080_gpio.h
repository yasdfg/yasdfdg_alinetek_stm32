/*
 * intel_8080_gpio.h
 *
 *  Created on: 2019-01-05 15:29
 *      Author: yzhuar(598092672@QQ.com)
 *
 */
#ifndef SRC_LH_COMPONENT_INTEL_8080_INTEL_8080_GPIO_H_
#define SRC_LH_COMPONENT_INTEL_8080_INTEL_8080_GPIO_H_

#include "lh_component.h"

void intel_8080_gpio_rest(void);
void intel_8080_gpio_wr_byte(U8 cmd,U8 dat);

#endif /* SRC_LH_COMPONENT_INTEL_8080_INTEL_8080_GPIO_H_ */
