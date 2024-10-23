#ifndef __CAR_H
#define __CAR_H

#include "stm32f10x.h"                  // Device header

#include "Mathematics.h"

#include "Delay.h"

#include "Filter_Kalman.h"

#include "PID.h"

#include "OLED.h"

#include "MPU6050.h"

#include "tb6612.h"

#include "Encoder.h"

#define Get_Acc_Angle(ACC1, ACC2)  (atan2(ACC1, ACC2) * 100 / PI)
#define Get_Gyro(Gyro)  Gyro / (65536 / 4000)

typedef struct{
	int16_t AccX;
	int16_t AccY; 
	int16_t AccZ; 
	int16_t GyroX;
	int16_t GyroY;
	int16_t GyroZ;
}Car_Parameter;

void Car_GetAngle(void);
void Car_PID(void);

#endif
