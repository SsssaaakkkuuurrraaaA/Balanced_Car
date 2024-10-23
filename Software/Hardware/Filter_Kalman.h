#ifndef __FILTER_KALMAN_H
#define __FILTER_KALMAN_H

#include "stm32f10x.h"                  // Device header

#include "Mathematics.h"

float Filter_Kalman(float Acc_Angle, float Gyro);

#endif
