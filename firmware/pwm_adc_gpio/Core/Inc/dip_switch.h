/*
 * dip_switch.h
 *
 *  Created on: Dec 5, 2022
 *      Author: danie
 */

#ifndef SRC_DIP_SWITCH_H_
#define SRC_DIP_SWITCH_H_

#include "gpio_if.h"

typedef struct
{
	t_gpio_if *sw_1;
	t_gpio_if *sw_2;
	t_gpio_if *sw_3;
	t_gpio_if *sw_4;
} dip_switch;

/*- PUBLIC_API ---------------------------------------------------------------*/

/**
 * @brief Init device configuration
 * @param gpio_if Pointer to gpio_if data structure
 * @param active Pin active mode
 * @param pin Pointer to pin data structure
 * @param initial_state State of the pin after init
 */
void dip_switch_ports_init(dip_switch *dip, t_gpio_if *gpio_1, t_gpio_if *gpio_2, t_gpio_if *gpio_3, t_gpio_if *gpio_4);
int get_dip_value(dip_switch *dip);
#endif /* SRC_DIP_SWITCH_H_ */
