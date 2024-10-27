#include "Car.h"

float Filter_Kalman_Angle_Value;

Car_Parameter Parameter_Val;

float Acc_Angle;
float Gyro_Y;

float Balance_Kp = 80.0;		//-720.0;
float Balance_Kd = 0;		//0.72;
float Balance_Angle = 1.0;	//-1.0;

float Velocity_Kp = 0;		//170.0;
float Velocity_Ki = 0;	    //0.85;

float Turn_Kp = 0;			//0.5;

int Encoder1 = 0;
int Encoder2 = 0;

void Car_GetAngle(void)
{
	MPU6050_GetACC_Data(&Parameter_Val.AccX, &Parameter_Val.AccY, &Parameter_Val.AccZ);
	MPU6050_GetGYRO_Data(&Parameter_Val.GyroX, &Parameter_Val.GyroY, &Parameter_Val.GyroZ);

	// 统一符号
	Acc_Angle = Get_Acc_Angle(Parameter_Val.AccX, Parameter_Val.AccZ);
	Gyro_Y = Get_Gyro(Parameter_Val.GyroY);  
	
	if(float_Sign_TowValue_Check(Acc_Angle, Gyro_Y) == 0)
	{
		float_Turn_Sign(&Gyro_Y);
	}
	
	Filter_Kalman_Angle_Value = Filter_Kalman(Acc_Angle, Gyro_Y);
	
	// OLED_ShowSignFloatNum(1, 1, Acc_Angle, 1);
	// OLED_ShowSignFloatNum(2, 1, Gyro_Y, 1);
	// OLED_ShowSignFloatNum(3, 1, Filter_Kalman_Angle_Value, 1);
}

void Car_PID(void)
{
	int Balance_Out = 0;
	int Velocity_Out = 0;
	int Turn_Out = 0;
	int PWM1 = 0, PWM2 = 0;

	Encoder1 = Encoder_TIM3_Get();
	Encoder2 = Encoder_TIM1_Get();

	/* 1.直立环控制 */
	Balance_Out = PID_Balance(Balance_Kp, Balance_Kd, Filter_Kalman_Angle_Value, Balance_Angle, Parameter_Val.GyroY);
	
	/* 2.速度环控制 */
	Velocity_Out = PID_Velocity(Velocity_Kp, Velocity_Ki, Encoder1, Encoder2);
	
	/* 3.转向环控制 */
	Turn_Out = PID_Turn(Turn_Kp, Parameter_Val.GyroZ);
	
	/* 4.叠加PID结果，作用到电机上 */
	PWM1 = Balance_Out + Velocity_Out + Turn_Out;
	PWM2 = Balance_Out + Velocity_Out - Turn_Out;
	
	Motor_SetPWM1(PWM1);
	Motor_SetPWM2(PWM2);
}

