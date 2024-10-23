#include "tb6612.h"

// PWMA——A2  AIN1——A4  AIN2——A5
// PWMB——A1  BIN1——B6  BIN2——B7

void MotorA_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = Motor_AIN1 | Motor_AIN2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void MotorB_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = Motor_BIN1 | Motor_BIN2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void TB6612_Init(void)
{
	TIM2_Init();

	MotorA_Init();
	MotorB_Init();
}

void Motor1(Motor_State State)
{
	switch(State)
	{
		// AIN1——0  AIN2——1
		case Motor_Go:
		{
			GPIO_ResetBits(GPIOA, Motor_AIN1);
			GPIO_SetBits(GPIOA, Motor_AIN2);	
			break;
		}
		
		// AIN1——1  AIN2——0
		case Motor_Back:
		{
			GPIO_SetBits(GPIOA, Motor_AIN1);
			GPIO_ResetBits(GPIOA, Motor_AIN2);
			break;
		}
		
		// AIN1——1  AIN2——1
		case Motor_Stop:
		{
			GPIO_SetBits(GPIOA, Motor_AIN1);
			GPIO_SetBits(GPIOA, Motor_AIN2);
			break;
		}
	}
}

void Motor2(Motor_State State)
{
	switch(State)
	{
		// BIN1——0  BIN2——1
		case Motor_Go:
		{
			GPIO_ResetBits(GPIOB, Motor_BIN2);
			GPIO_SetBits(GPIOB, Motor_BIN1);	
			break;
		}
		
		// BIN1——1  BIN2——0
		case Motor_Back:
		{
			GPIO_SetBits(GPIOB, Motor_BIN2);
			GPIO_ResetBits(GPIOB, Motor_BIN1);
			break;
		}
		
		// BIN1——1  BIN2——1
		case Motor_Stop:
		{
			GPIO_SetBits(GPIOB, Motor_BIN1);
			GPIO_SetBits(GPIOB, Motor_BIN2);
			break;
		}
	}
}

void Motor_SetPWM1(int PWM)
{
	if(PWM > 0)
	{
		Motor1(Motor_Go);
	}
	
	else if(PWM < 0)
	{
		Motor1(Motor_Back);
		int_SetPositive_Value(&PWM);
	}
	
	else
	{
		Motor1(Motor_Stop);
	}
	
	PWM_SetCompare3(PWM);
}

void Motor_SetPWM2(int PWM)
{
	if(PWM > 0)
	{
		Motor2(Motor_Go);
	}
	
	else if(PWM < 0)
	{
		Motor2(Motor_Back);
		int_SetPositive_Value(&PWM);
	}
	
	else
	{
		Motor2(Motor_Stop);
	}
	
	PWM_SetCompare2(PWM);
}

void Motor_SetPWM(int PWM1, int PWM2)
{
	Motor_SetPWM1(PWM1);
	Motor_SetPWM2(PWM2);
}
