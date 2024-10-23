#include "PID.h"

// 直立环控制 
int PID_Balance(float Kp, float Kd, float Kalman_Angle, float Balance_Angle, short gy)
{
	float Bias_Angle = 0.0f;
	
	Bias_Angle = Kalman_Angle - Balance_Angle;
	
	return Kp * Bias_Angle + Kd * gy;
}

// 速度环控制 
int PID_Velocity(float Kp, float Ki, int Encoder_A, int Encoder_B)
{
	int Bias_Velocity = 0;
	
	static int Least_Velocity = 0; 
	static int Last_Velocity = 0;  

	Bias_Velocity = (Encoder_A + Encoder_B) - Encoder_Bias_Val;

	Bias_Velocity = Bias_Velocity_K * Last_Velocity + (1 - Bias_Velocity_K) * Bias_Velocity;

	Last_Velocity = Bias_Velocity;
	
	Least_Velocity += Bias_Velocity;
	
	if(Least_Velocity > Least_Velocity_Max)
	{
		Least_Velocity = Least_Velocity_Max;
	}
	
	else if(Least_Velocity < Least_Velocity_Mix)
	{
		Least_Velocity = Least_Velocity_Mix;
	}
	
	return Kp * Bias_Velocity + Ki * Least_Velocity;
}

// 转向环控制
int PID_Turn(float Kp,short gz)
{
	return Kp * (gz - COM_gz_Val);
}
