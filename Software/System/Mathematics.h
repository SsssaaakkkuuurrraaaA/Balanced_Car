#ifndef __MATHEMATICS_H
#define __MATHEMATICS_H

#include "stm32f10x.h"                  // Device header

#include "math.h"

#include "stdlib.h"

#define PI  3.1415926535

#define Math_e  2.718281828

void int_SetPositive_Value(int* Value);
void float_SetPositive_Value(float* Value);
void double_SetPositive_Value(double* Value);

void int_Turn_Sign(int* Value);
void float_Turn_Sign(float* Value);
void double_Turn_Sign(double* Value);

void int_Swap_Value(int* Value1, int* Value2);
void uint8_t_Swap_Value(uint8_t* Value1, uint8_t* Value2);
void uint16_t_Swap_Value(uint16_t* Value1, uint16_t* Value2);
void uint32_t_Swap_Value(uint32_t* Value1, uint32_t* Value2);
void float_Swap_Value(float* Value1, float* Value2);
void double_Swap_Value(double* Value1, double* Value2);

uint8_t int_Sign_PositiveCheck(int Number);
uint8_t float_Sign_PositiveCheck(float Number);
uint8_t double_Sign_PositiveCheck(double Number);

uint8_t int_Sign_TowValue_Check(int Num1, int Num2);
uint8_t float_Sign_TowValue_Check(float Num1, float Num2);
uint8_t double_Sign_TowValue_Check(double Num1, double Num2);

#endif
