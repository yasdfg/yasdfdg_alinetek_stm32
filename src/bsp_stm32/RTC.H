/*
 * RTC.H
 *
 *  Created on: 2016年4月21日
 *      Author: yzhuaer
 */

#ifndef STM32F103C8_SOURCE_APP_INC_RTC_H_
#define STM32F103C8_SOURCE_APP_INC_RTC_H_

extern U8 Year;
extern U8 Month;
extern U8 Day;
extern U8 Hour;
extern U8 Minute;
extern U8 Second;

extern U8 RTC_AWU_FLAG;

void RTC_init(void);
void saveTimer_to_rtc(void);
void getTimer_from_rtc(void);
void RealTime_Runing(void);

#endif /* STM32F103C8_SOURCE_APP_INC_RTC_H_ */
