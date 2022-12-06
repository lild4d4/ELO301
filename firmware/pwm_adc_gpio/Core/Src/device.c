/*
 * device.c
 *
 *  Created on: Dec 5, 2022
 *      Author: Grupo8
 */

#include <stdlib.h>
#include "device.h"

void device_if_init( device *device_gc, mode_types set_mode, int set_id)
{
	device_gc->modo = set_mode;
	device_gc->id = set_id;
}
