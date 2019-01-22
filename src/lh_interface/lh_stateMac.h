/*
 * stateMac_Process.h
 *
 *  Created on: 20180109
 *      Author: yzhuar
 */

#ifndef USER_STATUSMLISTSTRU_H_
#define USER_STATUSMLISTSTRU_H_

#include "lh_interface.h"

typedef struct lh_stateMacNature_t * lh_SMN_abt;

U8 lh_getStateMac_natureSize(void);
lh_SMN_abt lh_newStateMac_for_heap(void);
void  lh_stateMac_init(lh_SMN_abt SM,void* (*firstState)(void));
void  lh_freeStateMac_for_heap(lh_SMN_abt SM);
U8    lh_stateMac_Process(lh_SMN_abt SM);
void *lh_stateMac_getBeforeState(lh_SMN_abt SM);

#endif /* USER_STATUSMLISTSTRU_H_ */















