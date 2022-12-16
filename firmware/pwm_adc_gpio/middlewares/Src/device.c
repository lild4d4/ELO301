/*
 * device.c
 *
 *  Created on: Dec 5, 2022
 *      Author: Grupo8
 */

#include <stdlib.h>
#include "device.h"

void device_if_init( device *device_gc, int set_id)
{
	if(set_id==0)
	{
		device_gc->modo = MASTER;
	}
	else
	{
		device_gc->modo = SLAVE;
	}
	device_gc->id = set_id;
}
