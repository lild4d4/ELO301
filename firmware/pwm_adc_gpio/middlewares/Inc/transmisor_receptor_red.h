/**
 * @file    transmisor_receptor_red.h
 *
 *  Created on: Dec 10, 2022
 *      Author: makcr
 */

#ifndef INC_TRANSMISOR_RECEPTOR_RED_H_
#define INC_TRANSMISOR_RECEPTOR_RED_H_

#include "usart.h"

/*- PRIVATE_Definitions ------------------------------------------------------*/

/*- PRIVATE_Types ------------------------------------------------------------*/

typedef struct
{
	UART_HandleTypeDef puerto_uart;
} transmisor_receptor_red;

/*- PUBLIC_API ---------------------------------------------------------------*/

/**
 * @brief Inicializa el transmisor-receptor UART
 * @param t_r_red Estructura de datos de la UART
 * @param uart Handler del UART
 */
void trans_recep_init( transmisor_receptor_red *t_r_red, UART_HandleTypeDef *uart);

/**
 * @brief Envía datos por UART
 * @param t_r_red Estructura de datos de la UART
 * @param command_1 Primer comando a enviar
 * @param command_2 Segundo comando a enviar
 */
void send(transmisor_receptor_red *t_r_red, uint8_t *command_1, uint8_t *command_2);

#endif /* INC_TRANSMISOR_RECEPTOR_RED_H_ */
