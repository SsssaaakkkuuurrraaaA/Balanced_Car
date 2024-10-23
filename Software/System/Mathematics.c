#include "Mathematics.h"

void int_SetPositive_Value(int* Value)
{
	if((*Value) < 0)
	{
		(*Value) = -(*Value);
	}
}

void float_SetPositive_Value(float* Value)
{
	if((*Value) < 0)
	{
		(*Value) = -(*Value);
	}
}

void double_SetPositive_Value(double* Value)
{
	if((*Value) < 0)
	{
		(*Value) = -(*Value);
	}
}

void int_Turn_Sign(int* Value)
{
	(*Value) = -(*Value);
}

void float_Turn_Sign(float* Value)
{
	(*Value) = -(*Value);
}

void double_Turn_Sign(double* Value)
{
	(*Value) = -(*Value);
}

void int_Swap_Value(int* Value1, int* Value2)
{
	int Temp;
	Temp = (*Value1);
	(*Value1) = (*Value2);
	(*Value2) = Temp;
}

void uint8_t_Swap_Value(uint8_t* Value1, uint8_t* Value2)
{
	uint8_t Temp;
	Temp = (*Value1);
	(*Value1) = (*Value2);
	(*Value2) = Temp;
}

void uint16_t_Swap_Value(uint16_t* Value1, uint16_t* Value2)
{
	uint16_t Temp;
	Temp = (*Value1);
	(*Value1) = (*Value2);
	(*Value2) = Temp;
}

void uint32_t_Swap_Value(uint32_t* Value1, uint32_t* Value2)
{
	uint32_t Temp;
	Temp = (*Value1);
	(*Value1) = (*Value2);
	(*Value2) = Temp;
}

void float_Swap_Value(float* Value1, float* Value2)
{
	float Temp;
	Temp = (*Value1);
	(*Value1) = (*Value2);
	(*Value2) = Temp;
}

void double_Swap_Value(double* Value1, double* Value2)
{
	double Temp;
	Temp = (*Value1);
	(*Value1) = (*Value2);
	(*Value2) = Temp;
}

uint8_t int_Sign_PositiveCheck(int Number)
{
	if(Number == abs(Number))
	{
		return 1;
	}
	
	return 0;
}

uint8_t float_Sign_PositiveCheck(float Number)
{
	if(Number == fabs(Number))
	{
		return 1;
	}
	
	return 0;
}

uint8_t double_Sign_PositiveCheck(double Number)
{
	if(Number == fabs(Number))
	{
		return 1;
	}
	
	return 0;
}

uint8_t int_Sign_TowValue_Check(int Num1, int Num2)
{
	if(int_Sign_PositiveCheck(Num1) == int_Sign_PositiveCheck(Num2))
	{
		return 1;
	}
	
	return 0;
}

uint8_t float_Sign_TowValue_Check(float Num1, float Num2)
{
	if(float_Sign_PositiveCheck(Num1) == float_Sign_PositiveCheck(Num2))
	{
		return 1;
	}
	
	return 0;
}

uint8_t double_Sign_TowValue_Check(double Num1, double Num2)
{
	if(double_Sign_PositiveCheck(Num1) == double_Sign_PositiveCheck(Num2))
	{
		return 1;
	}
	
	return 0;
}
