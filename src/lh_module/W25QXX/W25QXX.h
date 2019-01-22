/*
 * W25QXX.h
 *
 *  Created on: 2019-01-12 16:27
 *      Author: yzhuar(598092672@QQ.com)
 *
 */
#ifndef SRC_LH_MODULE_W25QXX_W25QXX_H_
#define SRC_LH_MODULE_W25QXX_W25QXX_H_

#ifdef __cplusplus
extern "C" {
#endif

//W25X系列/Q系列芯片列表
//W25Q80 ID  0XEF13
//W25Q16 ID  0XEF14
//W25Q32 ID  0XEF15
//W25Q32 ID  0XEF16
#define W25Q80 	0XEF13
#define W25Q16 	0XEF14
#define W25Q32 	0XEF15
#define W25Q64 	0XEF16

extern u16 SPI_FLASH_TYPE;//定义我们使用的flash芯片型号

#define	SPI_FLASH_CS PBout(12)  //选中FLASH

////////////////////////////////////////////////////////////////////////////

//指令表
#define W25X_WriteEnable		0x06
#define W25X_WriteDisable		0x04
#define W25X_ReadStatusReg		0x05
#define W25X_WriteStatusReg		0x01
#define W25X_ReadData			0x03
#define W25X_FastReadData		0x0B
#define W25X_FastReadDual		0x3B
#define W25X_PageProgram		0x02
#define W25X_BlockErase			0xD8
#define W25X_SectorErase		0x20
#define W25X_ChipErase			0xC7
#define W25X_PowerDown			0xB9
#define W25X_ReleasePowerDown	0xAB
#define W25X_DeviceID			0xAB
#define W25X_ManufactDeviceID	0x90
#define W25X_JedecDeviceID		0x9F

void W25QXX_init(void);
U16  W25QXX_readId(void);  	    //读取FLASH ID
u8	 W25QXX_readSR(void);        //读取状态寄存器
void W25QXX_writeSR(U8 sr);  	//写状态寄存器
void W25QXX_writeEnable(void);  //写使能
void W25QXX_writeDisable(void);	//写保护

void W25QXX_eraseChip(void);    	  //整片擦除
void W25QXX_eraseSector(u32 Dst_Addr);//扇区擦除
void W25QXX_waitBusy(void);           //等待空闲
void W25QXX_powerDown(void);           //进入掉电模式
void W25QXX_wakeup(void);			  //唤醒

void W25QXX_read(u8* pBuffer,u32 ReadAddr,u16 NumByteToRead);   //读取flash
void W25QXX_Write_NoCheck(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite);
void W25QXX_write(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite);//写入flash


#ifdef __cplusplus
}
#endif

#endif /* SRC_LH_MODULE_W25QXX_W25QXX_H_ */
