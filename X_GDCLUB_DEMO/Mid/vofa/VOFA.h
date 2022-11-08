/*
 * VOFA.h
 *
 *  Created on: Aug 20, 2021
 *      Author: 42426
 */
#include "stm32f4xx_hal.h"
#include "stdio.h"
#include "usart.h"
#include "string.h"

typedef enum{
	FLOAT = 0,
	UINT8,
	UINT16,
	UINT32,
}DATA_TYPE;
enum ImgFormat {
    Format_Invalid,
    Format_Mono,
    Format_MonoLSB,
    Format_Indexed8,
    Format_RGB32,
    Format_ARGB32,
    Format_ARGB32_Premultiplied,
    Format_RGB16,
    Format_ARGB8565_Premultiplied,
    Format_RGB666,
    Format_ARGB6666_Premultiplied,
    Format_RGB555,
    Format_ARGB8555_Premultiplied,
    Format_RGB888,
    Format_RGB444,
    Format_ARGB4444_Premultiplied,
    Format_RGBX8888,
    Format_RGBA8888,
    Format_RGBA8888_Premultiplied,
    Format_BGR30,
    Format_A2BGR30_Premultiplied,
    Format_RGB30,
    Format_A2RGB30_Premultiplied,
    Format_Alpha8,
    Format_Grayscale8,

    // 以下格式发送时，IMG_WIDTH和IMG_HEIGHT不需要强制指定，设置为-1即可
    Format_BMP,
    Format_GIF,
    Format_JPG,
    Format_PNG,
    Format_PBM,
    Format_PGM,
    Format_PPM,
    Format_XBM,
    Format_XPM,
    Format_SVG,
};

extern float spwm_data[100];

void USART_VOFA_FIREWATER_INITDATA_TRANS(uint16_t data);
void USART_VOFA_FIREWATER_FLOATDATA_TRANS(float data);
void USART_VOFA_FIREWATER_INITBUF_TRANS(uint16_t *data,uint16_t data_size);
void USART_VOFA_FIREWATER_FLOATBUF_TRANS(float *data,uint16_t data_size);
void USART_VOFA_JUSTFLOAT_FLOATDATA_TRANS(float data);
void USART_VOFA_JUSTFLOAT_FLOATBUF_TRANS(float *data,uint16_t data_size);

