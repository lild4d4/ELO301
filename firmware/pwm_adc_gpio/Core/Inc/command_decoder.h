/*
 * command_decoder.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Grupo8
 */

#ifndef COMMAND_DECODER_H_
#define COMMAND_DECODER_H_

#include "device.h"

int decode_pc_command(device *dev);
int decode_red_command(device *dev, int red_command);

#endif /* COMMAND_DECODER_H_ */
