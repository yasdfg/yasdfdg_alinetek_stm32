/*
 * lh_typedef.h
 *
 *  Created on: 2018-07-18 15:02
 *      Author: yzhuar(598092672@QQ.com)
 *
 */
#ifndef SRC_BUSINESS_SYSTEM_TYPEDEF_H_
#define SRC_BUSINESS_SYSTEM_TYPEDEF_H_

#define KEIL51 0

	typedef unsigned char  u8;
	typedef unsigned short u16;
	typedef unsigned int   u32;


#if KEIL51

	typedef unsigned char  U8;
	typedef unsigned short U16;
	typedef unsigned int   U32;
	typedef   signed char  S8;
	typedef   signed short S16;
	typedef   signed int   S32;

	typedef volatile unsigned char  U8reg;
	typedef volatile unsigned short U16reg;
	typedef volatile unsigned int   U32reg;
	typedef volatile   signed char  S8reg;
	typedef volatile   signed short S16reg;
	typedef volatile   signed int   S32reg;

	typedef long long          S64;
	typedef unsigned long long U64;
	typedef float              F32;
	typedef double             F64;

#endif
#include "RTL.h"


#define countof(n)  (sizeof(n)/sizeof(n[0])) // 计算数组中元素个数

#include <assert.h>	// 诊断	         仅包含assert宏。可以在程序中使用该宏来诊断程序状态（例如某个变量是否为0等），若检查失败，程序终止。
#include <ctype.h>	// 字符处理	     包含判断字符类型及大小写转换的函数。
#include <errno.h>	// 错误监测	     提供了errno。可以在调用特定库函数后检测errno的值以判断调用过程中是否有错误发生。
#include <float.h>	// 浮点数特性	     提供了描述浮点数特性的宏。
#include <limits.h>	// 整型特性	     提供了描述整数类型和字符类型特性的宏。
#include <locale.h>	// 本地化	         提供了一些支持程序国际化的函数。
#include <math.h>	// 数学计算	     提供了大量用以数学计算的函数。
#include <setjmp.h>	// 非本地跳转	     提供了用于绕过正常的函数返回机制，从一个函数跳转到另一个正在活动的函数的setjmp和longjmp函数。
#include <signal.h>	// 信号处理	     提供了包括中断和运行时错误在内的异常情况处理函数。
#include <stdarg.h>	// 不定参数	     提供了支持函数处理不变个数的参数的工具。
#include <stddef.h>	// 常用定义	     提供了常用的类型和宏。
#include <stdio.h>	// 输入输出	     提供了大量输入输出函数。
#include <stdlib.h>	// 常用实用函数    提供了大量实用的函数。
#include <string.h>	// 字符串处理	     提供了大量字符串处理函数。
#include <time.h>	// 日期和时间      提供了获取、操纵和处理日期的函数。

#endif /* SRC_BUSINESS_SYSTEM_TYPEDEF_H_ */
























