/*
 * potenciometro.h
 *
 *  Created on: 10 dic 2022
 *      Author: danie
 */

#ifndef INC_POTENCIOMETRO_H_
#define INC_POTENCIOMETRO_H_

#include "usart.h"

typedef struct
{
	int valor;
	ADC_HandleTypeDef adc_port;
} potenciometro;

void potenciometro_init(potenciometro *pot, ADC_HandleTypeDef *hadc1);

uint8_t potenciometro_get_value(potenciometro *pot);

#endif /* INC_POTENCIOMETRO_H_ */
