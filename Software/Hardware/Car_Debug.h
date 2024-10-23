#ifndef __Car_Debug_H
#define __Car_Debug_H

#include "stm32f10x.h"                  // Device header

#include "Mathematics.h"

#include "Delay.h"

#include "UART.h"

#include "tb6612.h"

#include "Mpu6050.h"

#include "Car.h"

void UART_Debug_Go(void);
void UART_Debug_Back(void);
void UART_Debug_TurnLeft(void);
void UART_Debug_TurnRight(void);

void Debug_Go(void);
void Debug_Back(void);
void Debug_TurnLeft(void);
void Debug_TurnRight(void);

#endif
