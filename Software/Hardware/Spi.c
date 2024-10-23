#include "Spi.h"

void SPI_W_SS(uint8_t BitValue)
{
	GPIO_WriteBit(GPIOA, SPI_SS, (BitAction)BitValue);
}

void SPI_W_SCK(uint8_t BitValue)
{
	GPIO_WriteBit(GPIOA, SPI_SCK, (BitAction)BitValue);
}

void SPI_W_MOSI(uint8_t BitValue)
{
	GPIO_WriteBit(GPIOA, SPI_MOSI, (BitAction)BitValue);
}

uint8_t SPI_R_MISO(void)
{
	return GPIO_ReadInputDataBit(GPIOA, SPI_MISO);
}

void Spi_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = SPI_SCK | SPI_SS | SPI_MISO;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = SPI_MOSI;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	SPI_W_SS(1);
	SPI_W_SCK(0);
}

void Spi_Start(void)
{
	SPI_W_SS(0);
}

void Spi_Stop(void)
{
	SPI_W_SS(1);
}

uint8_t Spi_Receive(uint8_t Data)
{
	uint16_t i;
	
	uint8_t Receive_Data = 0x00;
	
	for (i = 0; i < 8; i++)
	{
		SPI_W_MOSI(Receive_Data & (0x80 >> i));
		SPI_W_SCK(1);
		
		if(SPI_R_MISO() == 1)
		{
			Receive_Data |= (0x80 >> i);
		}
		
		SPI_W_SCK(0);
	}
	
	return Receive_Data;
}
