/*
 * transmisor_receptor_red.c
 *
 *  Created on: Dec 10, 2022
 *      Author: makcr
 */


#include "transmisor_receptor_red.h"


void trans_recep_init( transmisor_receptor_red *t_r_red, UART_HandleTypeDef *uart)
{
	t_r_red->puerto_uart = *uart;
	// ENABLE del transceptor desactivado por defecto
	HAL_GPIO_WritePin(GPIOA, EN_Pin, 0);
}

void send(transmisor_receptor_red *t_r_red, uint8_t *command_1, uint8_t *command_2)
{
	// Activar el ENABLE del transceptor
	HAL_GPIO_WritePin(GPIOA, EN_Pin, 1);

	// Enviar datos a la red
	HAL_UART_Transmit(&(t_r_red->puerto_uart), command_1, 1, 1000);
	HAL_UART_Transmit(&(t_r_red->puerto_uart), command_2, 1, 1000);

	// Desactivar el ENABLE del transceptor
	HAL_GPIO_WritePin(GPIOA, EN_Pin, 0);
}
