#ifndef __PID_H
#define __PID_H

#include "stm32f10x.h"                  // Device header

#define Least_Velocity_Max  1000
#define Least_Velocity_Mix  -1000

#define Encoder_Bias_Val  0
#define Bias_Velocity_K  0.8

#define COM_gz_Val  0

int PID_Balance(float Kp, float Kd, float Kalman_Angle, float Balance_Angle, short gy);

int PID_Velocity(float Kp, float Ki, int Encoder_A, int Encoder_B);

int PID_Turn(float Kp,short gz);

#endif
