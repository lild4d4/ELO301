/*
 * led.h
 *
 *  Created on: Dec 12, 2022
 *      Author: danie
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "tim.h"

typedef struct{
	TIM_HandleTypeDef htim;
}led;

void led_init(led *this_led, TIM_HandleTypeDef *htim);
void led_set(led *this_led, float value);

#endif /* INC_LED_H_ */
