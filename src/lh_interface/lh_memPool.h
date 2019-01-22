/*
 * lh_memPool.h
 *
 *  Created on: 2019-01-06 16:29
 *      Author: yzhuar(598092672@QQ.com)
 *
 */
#ifndef LH_INTERFACE_MEMORYMAG_LH_MEMPOOL_H_
#define LH_INTERFACE_MEMORYMAG_LH_MEMPOOL_H_

#include "lh_interface.h"

void lh_memPool_init(U8 *memPoolAddr,U16 size);
U16 lh_memPool_getUsedSize(void);
U8 *lh_memPool_getSpace(U16 size);

#endif /* LH_INTERFACE_MEMORYMAG_LH_MEMPOOL_H_ */
