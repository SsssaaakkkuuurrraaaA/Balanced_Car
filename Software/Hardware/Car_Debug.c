#include "Car_Debug.h"

void UART_Debug_Go(void)
{
	if(UART_RxTXTFlag == 1 && strcmp(UART_RxPacket, "Go\r\n") == 0)		
	{							
		Motor_SetPWM(100, 100);
		Car_PID();
		
		Delay_s(10);
		Motor_SetPWM(0, 0);
	
		UART_RxTXTFlag = 0;			
	}
}

void UART_Debug_Back(void)
{
	if(UART_RxTXTFlag == 1 && strcmp(UART_RxPacket, "Back\r\n") == 0)		
	{							
		Motor_SetPWM(-100, -100);
		Car_PID();
		
		Delay_s(10);
		Motor_SetPWM(0, 0);
	
		UART_RxTXTFlag = 0;			
	}
}

void UART_Debug_TurnLeft(void)
{
	if(UART_RxTXTFlag == 1 && strcmp(UART_RxPacket, "TurnLeft\r\n") == 0)		
	{							

	
		UART_RxTXTFlag = 0;			
	}
}

void UART_Debug_TurnRight(void)
{
	if(UART_RxTXTFlag == 1 && strcmp(UART_RxPacket, "TurnRight\r\n") == 0)		
	{							

	
		UART_RxTXTFlag = 0;			
	}
}

void Debug_Go(void)
{
	Motor_SetPWM(100, 100);
	Car_PID();
	
	Delay_s(10);
	Motor_SetPWM(0, 0);
}

void Debug_Back(void)
{
	Motor_SetPWM(-100, -100);
	Car_PID();
	
	Delay_s(10);
	Motor_SetPWM(0, 0);
}

void Debug_TurnLeft(void)
{
	
	
	Delay_s(10);
	Motor_SetPWM(0, 0);
}

void Debug_TurnRight(void)
{
	
	
	Delay_s(10);
	Motor_SetPWM(0, 0);
}
