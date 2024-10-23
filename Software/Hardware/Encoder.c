#include "Encoder.h"

void Encoder_Init(void)
{
	Encoder1_TIM_Init();
	Encoder2_TIM_Init();
}

int Encoder_TIM3_Get(void)
{
	int Encoder_Count = 0;
	
	Encoder_Count = TIM_GetCounter(TIM3);
	
	TIM_SetCounter(TIM3, 0);
	
	return Encoder_Count;
}

int Encoder_TIM1_Get(void)
{
	int Encoder_Count = 0;
	
	Encoder_Count = TIM_GetCounter(TIM1);
	
	TIM_SetCounter(TIM1, 0);
	
	return Encoder_Count;
}
