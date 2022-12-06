/*
 * command_decoder.c
 *
 *  Created on: Dec 5, 2022
 *      Author: Grupo8
 */

#include <stdlib.h>
#include "command_decoder.h"
#include "device.h"

/*- COMANDOS ---------------------------------------------------------*/
#define READ_POT 1;
#define WRITE_LED 2;

int decode_pc_command(device *dev, int pc_command)
{
	if(dev->modo==SLAVE)
	{
		return -1;
	}
	else
	{
		return pc_command;
	}
}

int decode_red_command(device *dev, int red_command)
{
	if(dev->modo==MASTER)
	{
		return -1;
	}
	else
	{
		if(0b1111 & red_command==dev->id)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
