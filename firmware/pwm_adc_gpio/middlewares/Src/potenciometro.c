/*
 * potenciometro.c
 *
 *  Created on: 10 dic 2022
 *      Author: danie
 */

#include "potenciometro.h"

void potenciometro_init(potenciometro *pot, ADC_HandleTypeDef *hadc1)
{
	pot->adc_port = *hadc1;
}

uint8_t potenciometro_get_value(potenciometro *pot)
{
	HAL_ADC_Start(&(pot->adc_port));
	HAL_ADC_PollForConversion(&(pot->adc_port), 100);

	// Convierte el valor ADC a un valor entre 0 y 100 (a modo de porcentaje)
	uint8_t adc_val = ( (double) HAL_ADC_GetValue(&(pot->adc_port)) ) /3815 * 100;
	return adc_val;
}
