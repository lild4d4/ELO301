/*
 * command_decoder.c
 *
 *  Created on: Dec 5, 2022
 *      Author: Grupo8
 */

#include "stdint.h"
#include <stdlib.h>
#include "command_decoder.h"
#include "device.h"
#include "usart.h"

/*- COMANDOS ---------------------------------------------------------*/
#define READ_POT 1;
#define WRITE_LED 2;

int decode_pc_command(device *dev, uint8_t command_1, uint8_t command_2)
{
	if(dev->modo==SLAVE)
	{
		return -1;
	}
	else
	{
		HAL_UART_Transmit_IT(&huart1, &command_1, 1);
		HAL_UART_Transmit_IT(&huart1, &command_2, 1);
		return 0;
	}
}

int decode_red_command(device *dev, int red_command_1, int red_command_2)
{
	if(dev->modo==MASTER)
	{
		return -1;
	}
	else
	{
		if( (0b00001111) & (red_command_1 == dev->id) )
		{
			if(red_command_2==0)
			{
				//read pot
			}
			else
			{
				//write led
			}
		}
		else
		{
			return 0;
		}
	}
}
