#include "main.h"

int main(void)
{
	// 初始化
	OLED_Init();
	
	UART_Init();
	
	TB6612_Init();
	
	Encoder_Init();
		
	MPU6050_Init();
	
	while (1)
	{		
		Car_GetAngle();

		Car_PID();

		/*
		// 测试编码器
		OLED_ShowNum(1, 1, Encoder_TIM1_Get(), 5);
		OLED_ShowNum(2, 1, Encoder_TIM3_Get(), 5);
		*/
		
		/*
		// 测试串口
		UART_SendTXT();
		*/
		
		/*
		// 测试电机
		Motor_SetPWM1(5000);
		Motor_SetPWM2(5000);
		*/
		
		/*
		// 测试加速度、角度、卡尔曼滤波返回值
		Car_GetAngle();
		*/
	}
}
