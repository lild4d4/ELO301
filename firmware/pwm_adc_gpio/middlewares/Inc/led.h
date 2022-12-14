/**
 * @file    led.h
 *
 *  Created on: Dec 12, 2022
 *      Author: danie
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "tim.h"

typedef struct{
	TIM_HandleTypeDef htim;
} led;

/*- PRIVATE_Definitions ------------------------------------------------------*/

/*- PRIVATE_Types ------------------------------------------------------------*/

/*- PUBLIC_API ---------------------------------------------------------------*/

/**
 * @brief Inicializa el LED que recibirá la señal PWM
 * @param this_led Estructura de datos del LED
 * @param htim Handler del timer PWM que se le asignará al LED
 */
void led_init(led *this_led, TIM_HandleTypeDef *htim);

/**
 * @brief Setea el ciclo de trabajo (DC) de la PWM del LED
 * @param this_led Estructura de datos del LED
 * @param value Valor del DC de la PWM (0 a 100)
 */
void led_set(led *this_led, float value);

#endif /* INC_LED_H_ */
