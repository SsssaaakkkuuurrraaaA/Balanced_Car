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
