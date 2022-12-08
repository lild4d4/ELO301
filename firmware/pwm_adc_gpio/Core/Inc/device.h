/*
 * device.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Grupo8
 */

#ifndef DEVICE_H_
#define DEVICE_H_

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
 * @brief Init device configuration
 * @param gpio_if Pointer to gpio_if data structure
 * @param active Pin active mode
 * @param pin Pointer to pin data structure
 * @param initial_state State of the pin after init
 */
void device_if_init( device *device_gc, int set_id);

#endif /* DEVICE_H_ */
