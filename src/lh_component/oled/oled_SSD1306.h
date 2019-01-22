/*
 * oled_SSD1306.h
 *
 *  Created on: 2019-01-05 14:13
 *      Author: yzhuar(598092672@QQ.com)
 *
 */
#ifndef SRC_LH_COMPONENT_OLED_OLED_SSD1306_H_
#define SRC_LH_COMPONENT_OLED_OLED_SSD1306_H_

#include "lh_component.h"

//OLED控制用函数
void oled_ssd1306_init(void);
void oled_ssd1306_display_on(void);
void oled_ssd1306_display_off(void);
void oled_ssd1306_refresh_gram(void);
void oled_ssd1306_clear(void);

void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);
void OLED_ShowString(u8 x,u8 y,const u8 *p);

#endif /* SRC_LH_COMPONENT_OLED_OLED_SSD1306_H_ */
