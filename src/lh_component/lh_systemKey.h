/*
 * lh_systemKey.h
 *
 *  Created on: 2018-12-25 18:52
 *      Author: yzhuar(598092672@QQ.com)
 *
 */
#ifndef LH_COMPONENT_SYSTEMKEY_LH_SYSTEMKEY_H_
#define LH_COMPONENT_SYSTEMKEY_LH_SYSTEMKEY_H_

#include "../lh_component.h"

U16 lh_systemKey_Single(U8 keyId);
U8 lh_systemKey_multi(U8 keyId,U8 num);
U8 lh_systemKey_long(U8 keyId,U16 time);
U8 lh_systemKey_pulse(U8 keyId,U16 time1,U16 time2);

void lh_systemKey_polling(void);

#endif /* LH_COMPONENT_SYSTEMKEY_LH_SYSTEMKEY_H_ */
