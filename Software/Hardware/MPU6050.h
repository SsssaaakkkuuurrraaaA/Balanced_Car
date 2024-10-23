#ifndef __MPU6050_H
#define __MPU6050_H

#include "stm32f10x.h"                  // Device header

#include "Delay.h"

#include "MPU6050_I2C.h"

#include "MPU6050_Reg.h"

#define MPU6050_ADDRESS  0xD0		// MPU6050的I2C从机地址

#define MPU6050_OUT_Freq  1000

#define GyroScope1  188
#define GyroScope2  98
#define GyroScope3  42
#define GyroScope4  20
#define GyroScope5  10
#define GyroScope6  5

#define Sample_Freq_Max  1000
#define Sample_Freq_Min  4

#define GyroRate  100

void MPU6050_WriteByte(uint8_t RegAddress, uint8_t Data);
void MPU6050_WriteBytes(uint8_t RegAddress, uint8_t* Data, uint8_t Size);

void MPU6050_ReadByte(uint8_t RegAddress, uint8_t* Data);
void MPU6050_ReadBytes(uint8_t RegAddress, uint8_t* Data, uint8_t Size);

void MPU6050_GetID(uint8_t* ID);

void MPU6050_Set_DLPF_CFG(uint16_t Rate);

void MPU6050_SetGyroRate(uint16_t Rate);

void MPU6050_Init(void);

void MPU6050_GetACC_Data(int16_t *AccX, int16_t *AccY, int16_t *AccZ);
void MPU6050_GetGYRO_Data(int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ);

#endif
