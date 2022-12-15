/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "device.h"
#include "gpio_if.h"
#include "dip_switch.h"
#include "command_decoder.h"
#include "led.h"
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
uint8_t uart_pc;
device this_device;
potenciometro pot;
transmisor_receptor_red t_r_red;
mode_types device_mode;
uint8_t uart_red;
static uint8_t cont_tim = 0;

led this_led;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

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

	/*pines de switches*/
	t_gpio_pin user_switch1_pin = {SW1_GPIO_Port, SW1_Pin};
	t_gpio_if switch_1;
	t_gpio_pin user_switch2_pin = {SW2_GPIO_Port, SW2_Pin};
	t_gpio_if switch_2;
	t_gpio_pin user_switch3_pin = {SW3_GPIO_Port, SW3_Pin};
	t_gpio_if switch_3;
	t_gpio_pin user_switch4_pin = {SW4_GPIO_Port, SW4_Pin};
	t_gpio_if switch_4;

	/*Device*/
	//device this_device;

	/*Dip Switch*/
	dip_switch this_dip;

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
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */



  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);			// inicializacion pwm'
  led_init(&this_led, &htim1);

  HAL_UART_Receive_IT(&huart2, &uart_pc, 1);		// inicializacion interrupciones UART2
  HAL_UART_Receive_IT(&huart1, &uart_red, 1);		// inicializacion interrupciones UART1

  gpio_if_init(&switch_1, ACTIVE_HIGH, &user_switch1_pin, GPIO_IF_INPUT);
  if (gpio_if_open(&switch_1) != GPIO_IF_SUCCESS)
    {
      Error_Handler();
    }
  gpio_if_init(&switch_2, ACTIVE_HIGH, &user_switch2_pin, GPIO_IF_INPUT);
  if (gpio_if_open(&switch_2) != GPIO_IF_SUCCESS)
    {
      Error_Handler();
    }
  gpio_if_init(&switch_3, ACTIVE_HIGH, &user_switch3_pin, GPIO_IF_INPUT);
  if (gpio_if_open(&switch_3) != GPIO_IF_SUCCESS)
    {
      Error_Handler();
    }
  gpio_if_init(&switch_4, ACTIVE_HIGH, &user_switch4_pin, GPIO_IF_INPUT);
  if (gpio_if_open(&switch_4) != GPIO_IF_SUCCESS)
    {
      Error_Handler();
    }

  HAL_ADC_Init(&hadc1);


  trans_recep_init(&t_r_red, &huart1);

  dip_switch_ports_init(&this_dip, &switch_1, &switch_2, &switch_3, &switch_4);
  int dip_value = get_dip_value(&this_dip);
  device_if_init(&this_device, dip_value);

  led_set(&this_led, 1960);

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

// rutina de interrupcion por UART
uint8_t dato_1;
uint8_t dato_2;

void HAL_UART_RxCpltCallback (UART_HandleTypeDef *huart)
{
	static uint8_t cont = 1;
	device_mode = this_device.modo;


	// Modo MASTER
	if(huart->Instance == USART2)
	{
		if (cont == 1)
		{
			dato_1 = uart_pc;
			cont = 2;
		}
		else if (cont == 2)
		{
			dato_2 = uart_pc;
			cont = 1;
			if (device_mode == MASTER)
			{
				int command = decode_pc_command(&this_device, dato_1, dato_2);
			}
		}
	}

	// Modo SLAVE
	if(huart->Instance == USART1)
	{
		if (device_mode == MASTER)
		{
			HAL_UART_Transmit(&huart2, &uart_red, 1, 100);
			HAL_TIM_Base_Stop_IT(&htim2);
		}
		else
		{
			if (cont == 1)
			{
				dato_1 = uart_red;
				cont = 2;
			}
			else if (cont == 2)
			{
				dato_2 = uart_red;
				cont = 1;
				if (device_mode == SLAVE)
				{
					int command = decode_red_command(&this_device, dato_1, dato_2);
				}
			}
		}
	}

	HAL_UART_Receive_IT(&huart2, &uart_pc, 1);
	HAL_UART_Receive_IT(&huart1, &uart_red, 1);
}


/*void HAL_UART_TxCpltCallback (UART_HandleTypeDef *huart)
{
	HAL_UART_Transmit_IT(&huart1, &uart_red, 1);
}*/



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (cont_tim == 1) {
		HAL_UART_Transmit(&huart2, '1', 1, 100);
		HAL_TIM_Base_Stop_IT(&htim2);
	}
	else
	{
		cont_tim = 1;
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
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
