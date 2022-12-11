/*
 * transmisor_receptor_red.h
 *
 *  Created on: Dec 10, 2022
 *      Author: makcr
 */

#ifndef INC_TRANSMISOR_RECEPTOR_RED_H_
#define INC_TRANSMISOR_RECEPTOR_RED_H_

#include "usart.h"

typedef struct
{
	UART_HandleTypeDef puerto_uart;
} transmisor_receptor_red;

void trans_recep_init( transmisor_receptor_red *t_r_red, UART_HandleTypeDef *uart);

void send(transmisor_receptor_red *t_r_red, uint8_t *command_1, uint8_t *command_2);

#endif /* INC_TRANSMISOR_RECEPTOR_RED_H_ */
