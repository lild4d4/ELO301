/*
 * command_decoder.c
 *
 *  Created on: Dec 5, 2022
 *      Author: Grupo8
 */

#include "stdint.h"
#include <stdlib.h>
#include "command_decoder.h"
#include "device.h"
#include "usart.h"
#include "adc.h"
#include "tim.h"

/*- COMANDOS ---------------------------------------------------------*/
#define READ_POT 1;
#define WRITE_LED 2;

extern uint8_t uart_red;
extern transmisor_receptor_red t_r_red;
uint8_t counter;

int decode_pc_command(device *dev, uint8_t command_1, uint8_t command_2)
{

	if(dev->modo==SLAVE)
	{
		return -1;
	}
	else
	{


		send(&t_r_red, &command_1, &command_2);
		//HAL_UART_Transmit(&huart1, &command_1, 1, 1000);
		//HAL_UART_Transmit(&huart1, &command_2, 1, 1000);

		//HAL_UART_Receive(&huart1, &uart_red, 1, 5000);
 		HAL_TIM_Base_Start_IT(&htim2);

		return 0;
	}
}

int decode_red_command(device *dev, uint8_t red_command_1, uint8_t red_command_2)
{
	if(dev->modo==MASTER)
	{
		HAL_UART_Transmit(&huart1, &red_command_1, 1, 1000);
		HAL_UART_Transmit(&huart1, &red_command_2, 1, 1000);
	}
	else
	{
		// chequear si es el ID correcto
		if( (0b00001111 & red_command_1) == dev->id )
		{
			if(red_command_1>>7 == 0 )
			{
				potenciometro pot;
				potenciometro_init(&pot, &hadc1);
				uint8_t adc_val = potenciometro_get_value(&pot);

				HAL_UART_Transmit(&huart1, &adc_val, 1, 1000);

			}
			else
			{
				uint16_t dc_pwm = (float)red_command_2/127 * 1960;
				__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, dc_pwm);
				HAL_UART_Transmit(&huart1, &dc_pwm, 1, 1000);

			}
		}
		else
		{
			return 0;
		}
	}
}



/* https://visualgdb.com/tutorials/arm/stm32/timers/hal/ */



/* 		HAL_TIM_Base_Start_IT(&htim2);

		while (counter < 20)
		{
			if ()
			{
				//
				break;
			}

			if (__HAL_TIM_GET_FLAG(&htim2, TIM_FLAG_UPDATE) == SET)
			{
				__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);
				counter++;
			}

		}
		HAL_TIM_Base_Stop_IT(&htim2);
*/
