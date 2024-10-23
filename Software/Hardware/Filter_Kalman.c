#include "Filter_Kalman.h"

float FilterKalman_Angle_Value;

float Filter_Kalman_Angle;  	// 角度
float Filter_Kalman_Q_Bias;  	// 偏置
float Filter_Kalman_PP[2][2] = { {1, 0}, {0, 1} };  // 协方差矩阵

float Filter_Kalman_Q_Angle = 0.001;  // 过程噪声协方差
float Filter_Kalman_Q_Gyro = 0.003;   // 过程噪声协方差
float Filter_Kalman_R_Angle = 0.5;    // 测量噪声协方差
float Filter_Kalman_dt = 0.005;       // 时间步长

float Filter_Kalman_Angle_dot;        // 角速度
float Filter_Kalman_Pdot[4];          // 协方差矩阵微分
float Filter_Kalman_PCt_0, Filter_Kalman_PCt_1, Filter_Kalman_E;  // 卡尔曼增益相关变量
float Filter_Kalman_K_0, Filter_Kalman_K_1;         // 卡尔曼增益
float Filter_Kalman_Angle_Err;  // 测量误差

float Filter_Kalman(float Acc_Angle, float Gyro)
{
    // 预测
    Filter_Kalman_Angle += (Gyro - Filter_Kalman_Q_Bias) * Filter_Kalman_dt;  // 先验估计
    Filter_Kalman_Pdot[0] = Filter_Kalman_Q_Angle - Filter_Kalman_PP[0][1] - Filter_Kalman_PP[1][0];
    Filter_Kalman_Pdot[1] = -Filter_Kalman_PP[1][1];
    Filter_Kalman_Pdot[2] = -Filter_Kalman_PP[1][1];
    Filter_Kalman_Pdot[3] = Filter_Kalman_Q_Gyro;
    
    Filter_Kalman_PP[0][0] += Filter_Kalman_Pdot[0] * Filter_Kalman_dt;
    Filter_Kalman_PP[0][1] += Filter_Kalman_Pdot[1] * Filter_Kalman_dt;
    Filter_Kalman_PP[1][0] += Filter_Kalman_Pdot[2] * Filter_Kalman_dt;
    Filter_Kalman_PP[1][1] += Filter_Kalman_Pdot[3] * Filter_Kalman_dt;
    
    // 更新
    Filter_Kalman_Angle_Err = Acc_Angle - Filter_Kalman_Angle;  
    Filter_Kalman_PCt_0 = Filter_Kalman_PP[0][0];
    Filter_Kalman_PCt_1 = Filter_Kalman_PP[1][0];
    Filter_Kalman_E = Filter_Kalman_R_Angle + Filter_Kalman_PCt_0;
    
    Filter_Kalman_K_0 = Filter_Kalman_PCt_0 / Filter_Kalman_E;
    Filter_Kalman_K_1 = Filter_Kalman_PCt_1 / Filter_Kalman_E;
    
    Filter_Kalman_PP[0][0] -= Filter_Kalman_K_0 * Filter_Kalman_PCt_0;
    Filter_Kalman_PP[0][1] -= Filter_Kalman_K_0 * Filter_Kalman_PP[0][1];
    Filter_Kalman_PP[1][0] -= Filter_Kalman_K_1 * Filter_Kalman_PCt_0;
    Filter_Kalman_PP[1][1] -= Filter_Kalman_K_1 * Filter_Kalman_PP[0][1];
    
    Filter_Kalman_Angle += Filter_Kalman_K_0 * Filter_Kalman_Angle_Err;  // 更新角度估计
    Filter_Kalman_Q_Bias += Filter_Kalman_K_1 * Filter_Kalman_Angle_Err; // 更新偏置估计
    
    Filter_Kalman_Angle_dot = Gyro - Filter_Kalman_Q_Bias;  // 角速度估计
	
	FilterKalman_Angle_Value = Filter_Kalman_Angle;
	
	return FilterKalman_Angle_Value;
}
