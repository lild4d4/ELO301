/**
 * @file    dip_switch.h
 *
 *  Created on: Dec 5, 2022
 *      Author: danie
 */

#ifndef SRC_DIP_SWITCH_H_
#define SRC_DIP_SWITCH_H_

#include "gpio_if.h"

/*- PRIVATE_Definitions ------------------------------------------------------*/

/*- PRIVATE_Types ------------------------------------------------------------*/

typedef struct
{
	t_gpio_if *sw_1;
	t_gpio_if *sw_2;
	t_gpio_if *sw_3;
	t_gpio_if *sw_4;
} dip_switch;

/*- PUBLIC_API ---------------------------------------------------------------*/

/**
 * @brief Inicializa el DIP switch asignando los pins GPIO
 * @param dip Estructura que contiene los datos del DIP switch
 * @param gpio_1 Pin para el primer switch
 * @param gpio_2 Pin para el segundo switch
 * @param gpio_3 Pin para el tercer switch
 * @param gpio_4 Pin para el cuarto switch
 */
void dip_switch_ports_init(dip_switch *dip, t_gpio_if *gpio_1, t_gpio_if *gpio_2, t_gpio_if *gpio_3, t_gpio_if *gpio_4);

/**
 * @brief Convierte el valor binario del DIP switch a un número decimal
 * @param dip Estructura que contiene los datos del DIP switch
 * @return val Valor en decimal del DIP switch
 */
int get_dip_value(dip_switch *dip);
#endif /* SRC_DIP_SWITCH_H_ */
