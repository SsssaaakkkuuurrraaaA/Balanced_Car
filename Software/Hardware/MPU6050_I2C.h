#ifndef __MPU6050_I2C_H
#define __MPU6050_I2C_H

#include "stm32f10x.h"                  // Device header

#include "MPU6050_Reg.h"

#include "Delay.h"

#define GPIO_MPU6050_SCL  GPIOB
#define GPIO_MPU6050_SDA  GPIOB

#define Pin_MPU6050_SCL  GPIO_Pin_10
#define Pin_MPU6050_SDA  GPIO_Pin_11

void MPU6050_I2C_Init(void);

void MPU6050_I2C_Start(void);
void MPU6050_I2C_Stop(void);

void MPU6050_I2C_SendByte(uint8_t Byte);
uint8_t MPU6050_I2C_ReceiveByte(void);

void MPU6050_I2C_SendAck(uint8_t AckBit);
uint8_t MPU6050_I2C_ReceiveAck(void);

#endif
