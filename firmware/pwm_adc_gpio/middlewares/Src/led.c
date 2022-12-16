/*
 * led.c
 *
 *  Created on: Dec 12, 2022
 *      Author: danie
 */

#include "led.h"

void led_init(led *this_led, TIM_HandleTypeDef *htim)
{
	this_led->htim = *htim;
	// Inicialización timer que controla el PWM
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

void led_set(led *this_led, float value)
{
	__HAL_TIM_SET_COMPARE(&(this_led->htim), TIM_CHANNEL_1, value);
}
