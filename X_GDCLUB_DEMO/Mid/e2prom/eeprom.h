/*
 * eeprom.h
 *
 *  Created on: Oct 18, 2022
 *      Author: 42426
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#include "stm32f4xx_hal.h"

#define M24C32_ADDR_WRITE 0xA0
#define M24C32_ADDR_READ  0xA1

extern uint8_t i2c_tx_data[10];
extern uint8_t i2c_rx_data[10];


HAL_StatusTypeDef EEPROM_Init(void);
HAL_StatusTypeDef EEPROM_RandomRead(I2C_HandleTypeDef *hi2c, uint16_t DevAddress,\
		                            uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef EEPROM_ReadMemory(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress,\
		                            uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef EEPROM_WirteMemory(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress,\
		                            uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);
void eeprom_test(void);

#endif /* EEPROM_H_ */
