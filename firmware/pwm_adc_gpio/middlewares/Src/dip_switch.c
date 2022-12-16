/*
 * dip_switch.c
 *
 *  Created on: Dec 5, 2022
 *      Author: Grupo8
 */

#include "dip_switch.h"
#include "gpio_if.h"


void dip_switch_ports_init(dip_switch *dip, t_gpio_if *gpio_1, t_gpio_if *gpio_2, t_gpio_if *gpio_3, t_gpio_if *gpio_4)
{
	dip->sw_1 = gpio_1;
	dip->sw_2 = gpio_2;
	dip->sw_3 = gpio_3;
	dip->sw_4 = gpio_4;
}

int get_dip_value(dip_switch *dip)
{
	int val=0;
	if(gpio_if_get(dip->sw_1)==GPIO_IF_SET)
	{
		val = val + 1;
	}
	if(gpio_if_get(dip->sw_2)==GPIO_IF_SET)
	{
		val = val + 2;
	}
	if(gpio_if_get(dip->sw_3)==GPIO_IF_SET)
	{
		val = val + 4;
	}
	if(gpio_if_get(dip->sw_4)==GPIO_IF_SET)
	{
		val = val + 8;
	}
	return val;
}
