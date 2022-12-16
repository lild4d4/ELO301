/**
 * @file    potenciometro.h
 *
 *  Created on: 10 dic 2022
 *      Author: danie
 */

#ifndef INC_POTENCIOMETRO_H_
#define INC_POTENCIOMETRO_H_

#include "usart.h"

/*- PRIVATE_Definitions ------------------------------------------------------*/

/*- PRIVATE_Types ------------------------------------------------------------*/

typedef struct
{
	int valor;
	ADC_HandleTypeDef adc_port;
} potenciometro;

/*- PUBLIC_API ---------------------------------------------------------------*/

/**
 * @brief Inicializa el potenciómetro
 * @param pot Estructura de datos del potenciómetro
 * @param hadc1 Handler del ADC1
 */
void potenciometro_init(potenciometro *pot, ADC_HandleTypeDef *hadc1);

/**
 * @brief Obtiene el valor del potenciómetro
 * @param pot Estructura de datos del potenciómetro
 */
uint8_t potenciometro_get_value(potenciometro *pot);

#endif /* INC_POTENCIOMETRO_H_ */
