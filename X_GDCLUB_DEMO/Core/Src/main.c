/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "driver_mpu6050_basic.h"
#include "driver_mpu6050_dmp.h"
//#include "mpu6050.h"
#include "eeprom.h"
#include "VOFA.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint32_t i;
uint32_t times;
uint32_t cnt;
uint16_t len;
uint8_t (*g_gpio_irq)(void) = NULL;
static int16_t gs_accel_raw[128][3];
static int16_t gs_gyro_raw[128][3];
static float gs_gyro_dps[128][3];
static int32_t gs_quat[128][4];
static float gs_pitch[128];
static float gs_roll[128];
static float gs_yaw[128];
static int32_t gs_quat[128][4];
static float gs_pitch[128];
static float gs_roll[128];
static float gs_yaw[128];
mpu6050_address_t addr;
//float yaw = 0.0f;
//float roll = 0.0f;
//float pitch = 0.0f;
//long temperature = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
static void a_receive_callback(uint8_t type);
static void a_dmp_tap_callback(uint8_t count, uint8_t direction);
static void a_dmp_orient_callback(uint8_t orientation);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM2_Init();
  MX_I2C1_Init();
  MX_USART6_UART_Init();
  /* USER CODE BEGIN 2 */
	//mpu6050_init();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

	uint8_t tail[4] = { 0x00, 0x00, 0x80, 0x7f };
  while (1)
  {

		/****usart idle test*****/
//		if (rx_tc_flag == 1)  //接收完成标志
//				{
//			HAL_UART_Transmit_DMA(&huart6, rx_buffer, rx_len);
//			memset(rx_buffer, 0, rx_len);
//			rx_len = 0;
//			rx_tc_flag = 0;
//		}
//		 HAL_UART_Receive_DMA(&huart6, rx_buffer,
//		 RX_BUFFER_SIZE_MAX);

    /* USER CODE END WHILE */
		/* USER CODE BEGIN 3 */
		/****MPU6050 VOFA+ test*****/
//		MPU6050_Get_Euler_Temputer(&pitch, &roll, &yaw, &temperature);
//		USART_VOFA_JUSTFLOAT_FLOATDATA_TRANS(pitch);
//		USART_VOFA_JUSTFLOAT_FLOATDATA_TRANS(roll);
//		USART_VOFA_JUSTFLOAT_FLOATDATA_TRANS(yaw);
//		HAL_UART_Transmit(&huart6, (uint8_t*) tail, 4, 0xffff);


  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE BEGIN 4 */
#ifdef __GNUC__

#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)

#define GETCHAR_PROTOTYPE int __io_getchar(FILE *f)

#else

#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)

#define GETCHAR_PROTOTYPE int fgetc(FILE *f)

#endif /* __GNUC__ */

PUTCHAR_PROTOTYPE

{

	HAL_UART_Transmit(&huart6, (uint8_t*) &ch, 1, 0xFFFF);

	return ch;

}

static void a_receive_callback(uint8_t type) {
	switch (type) {
	case MPU6050_INTERRUPT_MOTION: {
		mpu6050_interface_debug_print("mpu6050: irq motion.\n");

		break;
	}
	case MPU6050_INTERRUPT_FIFO_OVERFLOW: {
		mpu6050_interface_debug_print("mpu6050: irq fifo overflow.\n");

		break;
	}
	case MPU6050_INTERRUPT_I2C_MAST: {
		mpu6050_interface_debug_print("mpu6050: irq i2c master.\n");

		break;
	}
	case MPU6050_INTERRUPT_DMP: {
		mpu6050_interface_debug_print("mpu6050: irq dmp\n");

		break;
	}
	case MPU6050_INTERRUPT_DATA_READY: {
		mpu6050_interface_debug_print("mpu6050: irq data ready\n");

		break;
	}
	default: {
		mpu6050_interface_debug_print("mpu6050: irq unknown code.\n");

		break;
	}
	}
}

static void a_dmp_tap_callback(uint8_t count, uint8_t direction) {
	switch (direction) {
	case MPU6050_DMP_TAP_X_UP: {
		mpu6050_interface_debug_print("mpu6050: tap irq x up with %d.\n",
				count);

		break;
	}
	case MPU6050_DMP_TAP_X_DOWN: {
		mpu6050_interface_debug_print("mpu6050: tap irq x down with %d.\n",
				count);

		break;
	}
	case MPU6050_DMP_TAP_Y_UP: {
		mpu6050_interface_debug_print("mpu6050: tap irq y up with %d.\n",
				count);

		break;
	}
	case MPU6050_DMP_TAP_Y_DOWN: {
		mpu6050_interface_debug_print("mpu6050: tap irq y down with %d.\n",
				count);

		break;
	}
	case MPU6050_DMP_TAP_Z_UP: {
		mpu6050_interface_debug_print("mpu6050: tap irq z up with %d.\n",
				count);

		break;
	}
	case MPU6050_DMP_TAP_Z_DOWN: {
		mpu6050_interface_debug_print("mpu6050: tap irq z down with %d.\n",
				count);

		break;
	}
	default: {
		mpu6050_interface_debug_print("mpu6050: tap irq unknown code.\n");

		break;
	}
	}
}

static void a_dmp_orient_callback(uint8_t orientation) {
	switch (orientation) {
	case MPU6050_DMP_ORIENT_PORTRAIT: {
		mpu6050_interface_debug_print("mpu6050: orient irq portrait.\n");

		break;
	}
	case MPU6050_DMP_ORIENT_LANDSCAPE: {
		mpu6050_interface_debug_print("mpu6050: orient irq landscape.\n");

		break;
	}
	case MPU6050_DMP_ORIENT_REVERSE_PORTRAIT: {
		mpu6050_interface_debug_print(
				"mpu6050: orient irq reverse portrait.\n");

		break;
	}
	case MPU6050_DMP_ORIENT_REVERSE_LANDSCAPE: {
		mpu6050_interface_debug_print(
				"mpu6050: orient irq reverse landscape.\n");

		break;
	}
	default: {
		mpu6050_interface_debug_print("mpu6050: orient irq unknown code.\n");

		break;
	}
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
