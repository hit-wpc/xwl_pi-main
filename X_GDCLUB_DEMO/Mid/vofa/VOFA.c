/*
 * VOFA.c
 *
 *  Created on: Aug 20, 2021
 *      Author: 42426
 */

#include "VOFA.h"

float spwm_data[100] = { 1600, 1650, 1700, 1749, 1798, 1847, 1894, 1940, 1985,
		2028, 2070, 2109, 2147, 2183, 2216, 2247, 2275, 2301, 2323, 2343, 2360,
		2374, 2385, 2393, 2398, 2400, 2398, 2393, 2385, 2374, 2360, 2343, 2323,
		2301, 2275, 2247, 2216, 2183, 2147, 2109, 2070, 2028, 1985, 1940, 1894,
		1847, 1798, 1749, 1700, 1650, 1600, 1549, 1499, 1450, 1401, 1352, 1305,
		1259, 1214, 1171, 1129, 1090, 1052, 1016, 983, 952, 924, 898, 876, 856,
		839, 825, 814, 806, 801, 800, 801, 806, 814, 825, 839, 856, 876, 898,
		924, 952, 983, 1016, 1052, 1090, 1129, 1171, 1214, 1259, 1305, 1352,
		1401, 1450, 1499, 1549 };

void USART_VOFA_FIREWATER_INITDATA_TRANS(uint16_t data)
{
	printf("%d\r\n",data);
}

void USART_VOFA_FIREWATER_FLOATDATA_TRANS(float data)
{
	printf("%f\r\n",data);
}

void USART_VOFA_FIREWATER_INITBUF_TRANS(uint16_t *data,uint16_t data_size)
{
	uint16_t var = 0;
	for (var = 0; var < data_size; var++)
	{
		printf("%d\r\n",data[var]);
		USART_VOFA_FIREWATER_INITDATA_TRANS(data[var]);
	}
}

void USART_VOFA_FIREWATER_FLOATBUF_TRANS(float *data,uint16_t data_size)
{
	uint16_t var = 0;
	for (var = 0; var < data_size; var++)
	{
		printf("%f\r\n",data[var]);
		USART_VOFA_FIREWATER_FLOATDATA_TRANS(data[var]);
	}
}

void USART_VOFA_JUSTFLOAT_FLOATDATA_TRANS(float data)
{
	uint8_t data_tmp[4] = {0};
	uint8_t tail[4] ={0x00,0x00,0x80,0x7f};
	memcpy(data_tmp, (uint8_t *)&data, sizeof(data));
	HAL_UART_Transmit(&huart6, (uint8_t*) data_tmp, sizeof(data), 0xffff);
	//HAL_UART_Transmit(&huart6, (uint8_t*) tail, 4, 0xffff);
}

void USART_VOFA_JUSTFLOAT_FLOATBUF_TRANS(float *data,uint16_t data_size)
{
	uint16_t var = 0;
	uint8_t data_tmp[4] = {0};
	uint8_t tail[4] ={0x00,0x00,0x80,0x7f};
	for (var = 0; var < data_size; var++)
	{
		memcpy(data_tmp,(uint8_t *)&data[var], sizeof(data[var]));
		HAL_UART_Transmit(&huart6, (uint8_t*) data_tmp, sizeof(data[var]),
				0xffff);
		HAL_UART_Transmit(&huart6, (uint8_t*) tail, 4, 0xffff);
	}
}
