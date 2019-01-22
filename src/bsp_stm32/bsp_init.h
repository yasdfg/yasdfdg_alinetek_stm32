/*
 * bsp_int.h
 *
 *  Created on: 2018-08-02 16:10
 *      Author: yzhuar(598092672@QQ.com)
 *
 */
#ifndef USER_APP_STM32F10X_BSP_BSP_INT_H_
#define USER_APP_STM32F10X_BSP_BSP_INT_H_

/*
 * λ������,ʵ��51���Ƶ�GPIO���ƹ���
** ����ʵ��˼��,�ο�<<CM3Ȩ��ָ��>>������(87ҳ~92ҳ).
** ����ʵ��˼��,�ο�<<CM3Ȩ��ָ��>>������(87ҳ~92ҳ).
** IO�ڲ����궨��
*/
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum))
//IO�ڵ�ַӳ��
#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C
#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08
//IO�ڲ���,ֻ�Ե�һ��IO��!
//ȷ��n��ֵС��16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //���
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //����

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //���
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //����

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //���
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //����

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //���
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //����

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //���
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //����

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //���
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //����

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //���
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //����

#include "stm32f10x.h"
#include "SysTick.H"
#include "IO.H"
#include "rcc.h"
#include "stm32_flash.h"
#include "spi1.h"
#include "spi2.h"
#include "uart1.h"
#include "UART2.H"
#include "fsmc.h"

extern void bsp_init(void);

/*- System_LED_Init -----------------------------------------------------------------*/
#define  SDK_LED_H()         do{PCout(13)=1;}while(0)
#define  SDK_LED_L()         do{PCout(13)=0;}while(0)
//- mfrc522_spi -------------------------------------------------------------
//#define  MFRC522_RESTL()         do{PBout(9)=1;}while(0)
//#define  MFRC522_RESTH()         do{PBout(9)=0;}while(0)// 复位脚
//
//#define  MFRC522_MISO()          PBin(7)// 主入从出
//
//#define  MFRC522_MOSIL()         do{PBout(6)=1;}while(0)
//#define  MFRC522_MOSIH()         do{PBout(6)=0;}while(0)// 主出从入
//
//#define  MFRC522_CLKL()         do{PBout(5)=1;}while(0)
//#define  MFRC522_CLKH()         do{PBout(5)=0;}while(0)// 时钟
//
//#define  MFRC522_CSL()         do{PBout(4)=1;}while(0)
//#define  MFRC522_CSH()         do{PBout(4)=0;}while(0)// 片选

/*- LCD -----------------------------------------------------------------*/
#define  LCD_RES_H()     do{PBout(2)=1;}while(0)    // LCD����λ��
#define  LCD_RES_L()     do{PBout(2)=0;}while(0)
#define  LCD_CS_H()     do{PBout(12)=1;}while(0)    // LCD����λ��
#define  LCD_CS_L()     do{PBout(12)=0;}while(0)
#define  LCD_CMD_H()     do{PBout(14)=1;}while(0)   // LCD��������ѡ��
#define  LCD_CMD_L()     do{PBout(14)=0;}while(0)
#define  LCD_BACK_H()    do{PAout(11)=1;}while(0)   // LCD������
#define  LCD_BACK_L()    do{PAout(11)=0;}while(0)

/*- ������LED����ŷ��������� -----------------------------------------------------------------*/
//#define  KEY_1()   PBin(5)
//#define  KEY_2()   PAin(6)
//#define  KEY_3()   PBin(0)
//#define  KEY_4()   PAin(9)
//#define  KEY_TEST() PAin(15)
//
//#define  LED_1()   PAout(5)
//#define  LED_2()   PAout(7)
//#define  LED_3()   PBout(1)
//#define  LED_4()   PAout(10)
//
//#define  RELAY_1()   PBout(9)
//#define  RELAY_2()   PBout(8)
//#define  RELAY_3()   PBout(7)
//#define  RELAY_4()   PBout(6)
//
//#define  FLOW_C_1()   PAout(0)
//#define  FLOW_C_2()   PAout(1)
//#define  FLOW_C_3()   PAout(3)
//#define  FLOW_C_4()   PAout(4)

/*- ������ -----------------------------------------------------------------*/
#define  BUZZER_EN()   PAout(8)=1
#define  BUZZER_DI()   PAout(8)=0

/*- ����оƬ -----------------------------------------------------------------*/
#define  VOICE_H()   PBout(4)=1
#define  VOICE_L()   PBout(4)=0

/*- �����ź� -----------------------------------------------------------------*/
#define  HEAT_FLAG() PBin(3)

#endif /* USER_APP_STM32F10X_BSP_BSP_INT_H_ */


































