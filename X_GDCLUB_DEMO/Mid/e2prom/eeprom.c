/*
 * eeprom.c
 *
 *  Created on: Oct 18, 2022
 *      Author: 42426
 */
#include "eeprom.h"
#include "i2c.h"

uint8_t i2c_tx_data[10] = {
		0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09
};
uint8_t i2c_rx_data[10] = {
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

HAL_StatusTypeDef EEPROM_Init(void)
{
	return SUCCESS;
}

HAL_StatusTypeDef EEPROM_RandomRead(I2C_HandleTypeDef *hi2c, uint16_t DevAddress,\
		                            uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
	HAL_StatusTypeDef error_status;
	error_status = HAL_I2C_Master_Transmit(hi2c, DevAddress, pData, Size, Timeout);
	return error_status;
}

HAL_StatusTypeDef EEPROM_ReadMemory(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress,\
		                            uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
	HAL_StatusTypeDef error_status;
	error_status = HAL_I2C_Mem_Read(hi2c, DevAddress, MemAddress, MemAddSize, pData, Size, Timeout);
	return error_status;
}

HAL_StatusTypeDef EEPROM_WirteMemory(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress,\
		                             uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
	HAL_StatusTypeDef error_status;
	error_status = HAL_I2C_Mem_Write(hi2c, DevAddress, MemAddress, MemAddSize, pData, Size, Timeout);
	return error_status;
}

void eeprom_test(void)
{
	  HAL_StatusTypeDef status;
	  status = EEPROM_WirteMemory(&hi2c1, M24C32_ADDR_WRITE, 0x0000,I2C_MEMADD_SIZE_16BIT,i2c_tx_data,10,1000);
	  HAL_Delay(500);
	  status = EEPROM_ReadMemory(&hi2c1,M24C32_ADDR_READ, 0x0000,I2C_MEMADD_SIZE_16BIT,i2c_rx_data,10,1000);
	  HAL_Delay(500);
}
