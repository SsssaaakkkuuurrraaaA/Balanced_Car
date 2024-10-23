#ifndef __TIM_H
#define __TIM_H

#include "stm32f10x.h"                  // Device header

#define Driver_PWMA  GPIO_Pin_2
#define Driver_PWMB  GPIO_Pin_1

#define Encoder1_A  GPIO_Pin_6
#define Encoder1_B  GPIO_Pin_7

#define Encoder2_A  GPIO_Pin_8
#define Encoder2_B  GPIO_Pin_11

#define TIM_Motor_ARR  (7200 - 1)
#define TIM_Motor_PSC  (1 - 1)

#define TIM_Encoder_ARR  (65536 - 1)
#define TIM_Encoder_PSC  (1 - 1)

void TIM2_Init(void);

void PWM_SetCompare2(uint16_t Compare);
void PWM_SetCompare3(uint16_t Compare);

void Encoder1_TIM_Init(void);
void Encoder2_TIM_Init(void);

#endif
