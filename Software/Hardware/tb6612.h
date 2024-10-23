#ifndef __TB6612_H
#define __TB6612_H

#include "stm32f10x.h"                  // Device header
#include "Mathematics.h"

#include "Delay.h"
#include "Tim.h"

typedef enum{
	Motor_Go = 0,
	Motor_Back = 1,
	Motor_Stop = 2,
}Motor_State;

#define	Motor_AIN1  GPIO_Pin_4
#define	Motor_AIN2  GPIO_Pin_5

#define	Motor_BIN1  GPIO_Pin_6
#define	Motor_BIN2  GPIO_Pin_7

void MotorA_Init(void);
void MotorB_Init(void);

void TB6612_Init(void);

void Motor1(Motor_State State);
void Motor2(Motor_State State);

void Motor_SetPWM1(int PWM);
void Motor_SetPWM2(int PWM);

void Motor_SetPWM(int PWM1, int PWM2);

#endif
