/*
 * lh_systemLed.h
 *
 *  Created on: 2018-09-13 11:34
 *      Author: yzhuar(598092672@QQ.com)
 *
 */
#ifndef LHWORKS_LH_COMPONENT_SYSTEMLED_LH_SYSTEMLED_H_
#define LHWORKS_LH_COMPONENT_SYSTEMLED_LH_SYSTEMLED_H_

#include "../lh_component.h"

extern const U8 systemLed0[];// 指示灯灭
extern const U8 systemLed1[];// 指示灯亮
extern const U8 systemLed2[];
extern const U8 systemLed3[];
extern const U8 systemLed4[];

void lh_systemLed_rest(U8 outId);
void lh_systemLed_set(U8 outId,const U8 *queue);
U8 lh_systemLed_getState(U8 outId);
void lh_systemLed_polling(void);
// 附加功能
U8 *lh_systemLed_uart(const char *logDat,U8 len);

#endif /* LHWORKS_LH_COMPONENT_SYSTEMLED_LH_SYSTEMLED_H_ */

































