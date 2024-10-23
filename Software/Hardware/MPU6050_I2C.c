#include "MPU6050_I2C.h"

void MPU6050_I2C_W_SCL(uint8_t BitValue)
{
	GPIO_WriteBit(GPIO_MPU6050_SCL, Pin_MPU6050_SCL, (BitAction)BitValue);
	Delay_us(10);
}

void MPU6050_I2C_W_SDA(uint8_t BitValue)
{
	GPIO_WriteBit(GPIO_MPU6050_SDA, Pin_MPU6050_SDA, (BitAction)BitValue);
	Delay_us(10);
}

uint8_t MPU6050_I2C_R_SDA(void)
{
	uint8_t BitValue;
	BitValue = GPIO_ReadInputDataBit(GPIO_MPU6050_SDA, Pin_MPU6050_SDA);
	Delay_us(10);
	return BitValue;
}

void MPU6050_I2C_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Pin = Pin_MPU6050_SCL | Pin_MPU6050_SDA;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB, Pin_MPU6050_SCL | Pin_MPU6050_SDA);
}

void MPU6050_I2C_Start(void)
{
	MPU6050_I2C_W_SDA(1);
	MPU6050_I2C_W_SCL(1);
	MPU6050_I2C_W_SDA(0);
	MPU6050_I2C_W_SCL(0);
}

void MPU6050_I2C_Stop(void)
{
	MPU6050_I2C_W_SDA(0);
	MPU6050_I2C_W_SCL(1);
	MPU6050_I2C_W_SDA(1);
}

void MPU6050_I2C_SendByte(uint8_t Byte)
{
	uint8_t i;
	for (i = 0; i < 8; i ++)
	{
		MPU6050_I2C_W_SDA(Byte & (0x80 >> i));
		MPU6050_I2C_W_SCL(1);
		MPU6050_I2C_W_SCL(0);
	}
}

uint8_t MPU6050_I2C_ReceiveByte(void)
{
	uint8_t i, Byte = 0x00;
	MPU6050_I2C_W_SDA(1);
	for (i = 0; i < 8; i ++)
	{
		MPU6050_I2C_W_SCL(1);
		if (MPU6050_I2C_R_SDA() == 1){Byte |= (0x80 >> i);}
		MPU6050_I2C_W_SCL(0);
	}
	return Byte;
}

void MPU6050_I2C_SendAck(uint8_t AckBit)
{
	MPU6050_I2C_W_SDA(AckBit);
	MPU6050_I2C_W_SCL(1);
	MPU6050_I2C_W_SCL(0);
}

uint8_t MPU6050_I2C_ReceiveAck(void)
{
	uint8_t AckBit;
	MPU6050_I2C_W_SDA(1);
	MPU6050_I2C_W_SCL(1);
	AckBit = MPU6050_I2C_R_SDA();
	MPU6050_I2C_W_SCL(0);
	return AckBit;
}
