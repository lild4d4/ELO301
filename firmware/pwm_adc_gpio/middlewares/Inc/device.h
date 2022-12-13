/**
 * @file    device.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Grupo8
 */

#ifndef DEVICE_H_
#define DEVICE_H_

/*- PRIVATE_Definitions ------------------------------------------------------*/

/*- PRIVATE_Types ------------------------------------------------------------*/
/**
 *
 */
typedef enum
{
  MASTER,
  SLAVE,
} mode_types;

typedef struct
{
	mode_types modo;
    int id;
} device;

/*- PUBLIC_API ---------------------------------------------------------------*/

/**
 * @brief Inicializa el dispositivo en modo MASTER o SLAVE dependiendo del valor del DIP Switch
 * @param device_gc Dispositivo a inicializar
 * @param set_id ID que se le asigna al dispositivo
 */
void device_if_init( device *device_gc, int set_id);

#endif /* DEVICE_H_ */
