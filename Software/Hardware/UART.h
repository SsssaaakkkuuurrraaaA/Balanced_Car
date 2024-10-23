#ifndef __UART_H
#define __UART_H

#include "stm32f10x.h"                  // Device header

#include "stdio.h"
#include "string.h"
#include "stdarg.h"

#include "Delay.h"

#include "OLED.h"

#include "tb6612.h"

#include "Car.h"

extern char UART_RxPacket[];
extern uint8_t UART_RxTXTFlag;

void UART_Init(void);
void UART_SendByte(uint8_t Byte);
void UART_SendArray(uint8_t *Array, uint16_t Length);
void UART_SendString(char *String);
void UART_SendNumber(uint32_t Number, uint8_t Length);
void UART_Printf(char *format, ...);

/*
void UART_SendTXT(void);
*/

uint8_t UART_GetRxFlag(void);
uint8_t UART_GetRxData(void);

#endif
