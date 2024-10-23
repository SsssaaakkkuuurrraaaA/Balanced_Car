#include "MPU6050.h"

void MPU6050_WriteByte(uint8_t RegAddress, uint8_t Data)
{
	MPU6050_I2C_Start();
	MPU6050_I2C_SendByte(MPU6050_ADDRESS);
	MPU6050_I2C_ReceiveAck();
	MPU6050_I2C_SendByte(RegAddress);
	MPU6050_I2C_ReceiveAck();
	MPU6050_I2C_SendByte(Data);
	MPU6050_I2C_ReceiveAck();
	MPU6050_I2C_Stop();
}

void MPU6050_WriteBytes(uint8_t RegAddress, uint8_t* Data, uint8_t Size)
{
	uint8_t i;
	
	MPU6050_I2C_Start();
	MPU6050_I2C_SendByte(MPU6050_ADDRESS);
	MPU6050_I2C_ReceiveAck();
	MPU6050_I2C_SendByte(RegAddress);
	MPU6050_I2C_ReceiveAck();
	
	for(i = 0; i < Size; i++)
	{
		MPU6050_I2C_SendByte(Data[i]);
		MPU6050_I2C_ReceiveAck();
	}

	MPU6050_I2C_Stop();
}

void MPU6050_ReadByte(uint8_t RegAddress, uint8_t* Data)
{
	MPU6050_I2C_Start();
	MPU6050_I2C_SendByte(MPU6050_ADDRESS);
	MPU6050_I2C_ReceiveAck();
	MPU6050_I2C_SendByte(RegAddress);
	MPU6050_I2C_ReceiveAck();
	
	MPU6050_I2C_Start();
	MPU6050_I2C_SendByte(MPU6050_ADDRESS | 0x01);
	MPU6050_I2C_ReceiveAck();
	*Data = MPU6050_I2C_ReceiveByte();
	MPU6050_I2C_SendAck(1);
	MPU6050_I2C_Stop();
}

void MPU6050_ReadBytes(uint8_t RegAddress, uint8_t* Data, uint8_t Size)
{
	uint8_t i;
	
	MPU6050_I2C_Start();
	MPU6050_I2C_SendByte(MPU6050_ADDRESS);
	MPU6050_I2C_ReceiveAck();
	MPU6050_I2C_SendByte(RegAddress);
	MPU6050_I2C_ReceiveAck();
	
	MPU6050_I2C_Start();
	MPU6050_I2C_SendByte(MPU6050_ADDRESS | 0x01);
	
	for(i = 0; i < Size; i++)
	{
		if (i < Size - 1) 
        {
			MPU6050_I2C_SendAck(1);
        }
		
		else 
        {
			MPU6050_I2C_SendAck(0);
		}
		
		Data[i] = MPU6050_I2C_ReceiveByte();
	}
	
	MPU6050_I2C_Stop();
}

void MPU6050_GetID(uint8_t* ID)
{
	MPU6050_ReadByte(MPU_DEVICE_ID_REG, ID);
}

void MPU6050_Set_DLPF_CFG(uint16_t Rate)
{
	uint16_t cfg;
	
	Rate /= 2;
	
	if(Rate > GyroScope1)
	{
		cfg = 1;
	}
	
	else if(Rate > GyroScope2)
	{
		cfg = 2;
	}
	
	else if(Rate > GyroScope3)
	{
		cfg = 3;
	}
	
	else if(Rate > GyroScope4)
	{
		cfg = 4;
	}
	
	else if(Rate > GyroScope5)
	{
		cfg = 5;
	}
	
	else
	{
		cfg = 6;
	}
	
	MPU6050_WriteByte(MPU_CFG_REG, (cfg << 0));
}

// 采样频率 = 陀螺仪输出频率 / (1 + 分频值)
// 分频值 = （陀螺仪输出频率 / 采样频率） - 1
void MPU6050_SetGyroRate(uint16_t Rate)
{
	uint16_t Sample_Div = 0;
	
	// 限幅
	if(Rate < Sample_Freq_Min)
	{
		Rate = Sample_Freq_Min;
	}
	
	if(Rate > Sample_Freq_Max)
	{
		Rate = Sample_Freq_Max;
	}
	
	Sample_Div = MPU6050_OUT_Freq / Rate - 1;
	MPU6050_WriteByte(MPU_SAMPLE_RATE_REG, Sample_Div);
	
	MPU6050_Set_DLPF_CFG(Rate);  // 根据采样率设置低通滤波器
}

void MPU6050_Init(void)
{
	uint8_t Device_ID;
	
	MPU6050_I2C_Init();
	
	MPU6050_WriteByte(MPU_PWR_MGMT1_REG, 0x80);
	Delay_ms(300);
	MPU6050_WriteByte(MPU_PWR_MGMT1_REG, 0X00);
	
	MPU6050_WriteByte(MPU_GYRO_CFG_REG, 0x18);
	
	MPU6050_WriteByte(MPU_ACCEL_CFG_REG, 0x18);
	
	MPU6050_WriteByte(MPU_INT_EN_REG, 0x00);
	MPU6050_WriteByte(MPU_USER_CTRL_REG, 0x00);
	MPU6050_WriteByte(MPU_FIFO_EN_REG, 0x00);
	
	MPU6050_ReadByte(MPU_DEVICE_ID_REG, &Device_ID);
	if(Device_ID == MPU_IIC_ADDR)
	{
		MPU6050_WriteByte(MPU_PWR_MGMT1_REG, 0x01);
		
		MPU6050_SetGyroRate(GyroRate);  // 设置陀螺仪采样率，低通滤波
	
		MPU6050_WriteByte(MPU_PWR_MGMT2_REG, 0x00);
	}
}

void MPU6050_GetACC_Data(int16_t *AccX, int16_t *AccY, int16_t *AccZ) 
{
	uint8_t DataH, DataL;
	
	MPU6050_ReadByte(MPU_ACCEL_XOUTH_REG, &DataH);
	MPU6050_ReadByte(MPU_ACCEL_XOUTL_REG, &DataL);
	*AccX = (DataH << 8) | DataL;
	
	MPU6050_ReadByte(MPU_ACCEL_YOUTH_REG, &DataH);
	MPU6050_ReadByte(MPU_ACCEL_YOUTL_REG, &DataL);
	*AccY = (DataH << 8) | DataL;
	
	MPU6050_ReadByte(MPU_ACCEL_ZOUTH_REG, &DataH);
	MPU6050_ReadByte(MPU_ACCEL_ZOUTL_REG, &DataL);
	*AccZ = (DataH << 8) | DataL;
}

void MPU6050_GetGYRO_Data(int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ)
{
	uint8_t DataH, DataL;
	
	MPU6050_ReadByte(MPU_GYRO_XOUTH_REG, &DataH);
	MPU6050_ReadByte(MPU_GYRO_XOUTL_REG, &DataL);
	*GyroX = (DataH << 8) | DataL;
	
	MPU6050_ReadByte(MPU_GYRO_YOUTH_REG, &DataH);
	MPU6050_ReadByte(MPU_GYRO_YOUTL_REG, &DataL);
	*GyroY = (DataH << 8) | DataL;
	
	MPU6050_ReadByte(MPU_GYRO_ZOUTH_REG, &DataH);
	MPU6050_ReadByte(MPU_GYRO_ZOUTL_REG, &DataL);
	*GyroZ = (DataH << 8) | DataL;
}
