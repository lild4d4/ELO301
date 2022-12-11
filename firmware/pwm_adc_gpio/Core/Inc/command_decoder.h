/*
 * command_decoder.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Grupo8
 */

#ifndef COMMAND_DECODER_H_
#define COMMAND_DECODER_H_

#include "stdint.h"
#include "device.h"
#include "potenciometro.h"

int decode_pc_command(device *dev, uint8_t pc_command_1, uint8_t pc_command_2);
int decode_red_command(device *dev, uint8_t red_command_1, uint8_t red_command_2);

#endif /* COMMAND_DECODER_H_ */
