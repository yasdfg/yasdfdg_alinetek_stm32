/*
 * intel_8080_gpio.c
 *
 *  Created on: 2019-01-05 15:28
 *      Author: yzhuar(598092672@QQ.com)
 *
 */

#include "includeAll.H"

/*
 * 8080 并行接口的发明者是 INTEL
 * 该总线也被广泛应用于各类液晶显示器
 *
 * CS： OLED 片选信号。
 * WR：向 OLED 写入数据。
 * RD：从 OLED 读取数据。
 * D[7： 0]： 8 位双向数据线。
 * RST(RES)：硬复位 OLED。
 * DC：命令/数据标志（0，读写命令； 1，读写数据）。
 */
// 硬件复位信号
#define INTEL_8080_RST_CLR() do{PGout(15)=0;}while(0)
#define INTEL_8080_RST_SET() do{PGout(15)=1;}while(0)
// 片选信号
#define INTEL_8080_CS_CLR()  do{PDout(6)=0;}while(0)
#define INTEL_8080_CS_SET()  do{PDout(6)=1;}while(0)
// 写信号
#define INTEL_8080_WR_CLR() do{PGout(14)=0;}while(0)
#define INTEL_8080_WR_SET() do{PGout(14)=1;}while(0)
// 读信号
#define INTEL_8080_RD_CLR() do{PGout(13)=0;}while(0)
#define INTEL_8080_RD_SET() do{PGout(13)=1;}while(0)
// 命令与数据信号： 0表示命令;1表示数据;
#define INTEL_8080_CD_CLR() do{PDout(3)=0;}while(0)
#define INTEL_8080_CD_SET() do{PDout(3)=1;}while(0)
// 数据
#define INTEL_8080_DATAOUT(dat) do{  \
	GPIO_Write(GPIOC,dat);            \
}while(0)
//	U16 pc;                          \
//	pc=GPIO_ReadOutputData(GPIOC);   \
//	pc=(pc&0xff00)|dat;              \
#define INTEL_8080_DATAIN() {return 0;}

void intel_8080_gpio_rest(void){
	INTEL_8080_RST_CLR();
	lh_systemDelay_ms(500);
	INTEL_8080_RST_SET();
}

//向SSD1306写入一个字节。
//dat:要写入的数据/命令
//cmd:数据/命令标志 0,表示命令;1,表示数据;
void intel_8080_gpio_wr_byte(U8 cmd,U8 dat){
	INTEL_8080_DATAOUT(dat);
	if(cmd)
		INTEL_8080_CD_SET();
	else
		INTEL_8080_CD_CLR();

	INTEL_8080_CS_CLR();
		INTEL_8080_WR_CLR();
		INTEL_8080_WR_SET(); // 上升沿发送数据
	INTEL_8080_CS_SET();

	INTEL_8080_CD_SET();
}

