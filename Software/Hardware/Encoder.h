#ifndef __ENCODER_H
#define __ENCODER_H

#include "stm32f10x.h"                  // Device header

#include "Tim.h"

void Encoder_Init(void);

int Encoder_TIM3_Get(void);
int Encoder_TIM1_Get(void);

#endif
