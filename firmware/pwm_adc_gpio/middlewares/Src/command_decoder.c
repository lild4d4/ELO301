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
#include "led.h"

/*- COMANDOS ---------------------------------------------------------*/

#define READ_POT	0
#define WRITE_LED	1

extern uint8_t uart_red;
extern transmisor_receptor_red t_r_red;
extern led this_led;
extern potenciometro pot;
uint8_t counter;

void decode_pc_command(device *dev, uint8_t command_1, uint8_t command_2)
{
	if(dev->modo==SLAVE)
	{
		// nada
	}
	else
	{
		// Enviar comandos del PC a la red
		send(&t_r_red, &command_1, &command_2);

		// Activa el timer del timeout (5 segundos)
 		HAL_TIM_Base_Start_IT(&htim2);
	}
}

void decode_red_command(device *dev, uint8_t red_command_1, uint8_t red_command_2)
{
	if(dev->modo==MASTER)
	{
		// Si por alguna razón el MASTER recibe estos comandos, los reenvía a la red
		send(&t_r_red, &red_command_1, &red_command_2);
	}
	else
	{
		/* Chequear si es el ID correcto:
		 * "red_command_1" contiene el ID del dispositivo en los 4 bits menos significativos
		 */
		if( (0b00001111 & red_command_1) == dev->id )
		{
			int instruccion = red_command_1>>7;

			// Leer valor del potenciómetro
			if(instruccion == READ_POT)
			{
				uint8_t adc_val = potenciometro_get_value(&pot);

				// Retornar valor potenciómetro por UART hacia la red
				int cero = 0x00;
				send(&t_r_red, &cero, &adc_val);
			}

			// Setear brillo de LED
			else if (instruccion == WRITE_LED)
			{
				uint16_t dc_pwm = (float)red_command_2/127 * 1960;
				led_set(&this_led, dc_pwm);

				// Retornar xFF xFF por UART hacia la red (interpretado como un OK)
				int response = 0xFF;
				send(&t_r_red, &response, &response);
			}
		}
		else
		{
			// nada
		}
	}
}


// Timer que controla la ventana de espera de respuesta de la red

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	/* Variable usada para arreglar un bug donde la -primera- vez que se activan las
	 * interrupciones de timer, ocurre una interrupción inmediatamente. */
	static uint8_t cont_tim = 0;

	if (cont_tim == 1) {
		// Enviar '1' al computador cuando ocurre timeout después de 5 segundos (no hay respuesta de la red)
		HAL_UART_Transmit(&huart2, &cont_tim, 1, 100);
		HAL_TIM_Base_Stop_IT(&htim2);
	}
	else
	{
		cont_tim = 1;
	}
}


/* https://visualgdb.com/tutorials/arm/stm32/timers/hal/ */
