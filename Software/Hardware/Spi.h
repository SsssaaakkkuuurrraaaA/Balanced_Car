#ifndef __SPI_H
#define __SPI_H

#include "stm32f10x.h"                  // Device header

#define SPI_SS     GPIO_Pin_0
#define SPI_SCK    GPIO_Pin_1
#define SPI_MOSI   GPIO_Pin_2
#define SPI_MISO   GPIO_Pin_3

void SPI_W_SS(uint8_t BitValue);
void SPI_W_SCK(uint8_t BitValue);
void SPI_W_MOSI(uint8_t BitValue);
uint8_t SPI_R_MISO(void);

void Spi_Init(void);

void Spi_Start(void);
void Spi_Stop(void);

uint8_t Spi_Receive(uint8_t Data);

#endif
