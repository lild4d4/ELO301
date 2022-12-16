/**
 * @file    command_decoder.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Grupo8
 */

#ifndef COMMAND_DECODER_H_
#define COMMAND_DECODER_H_

#include "stdint.h"
#include "device.h"
#include "potenciometro.h"
#include "transmisor_receptor_red.h"

/*- PRIVATE_Definitions ------------------------------------------------------*/

/*- PRIVATE_Types ------------------------------------------------------------*/

/*- PUBLIC_API ---------------------------------------------------------------*/

/**
 * @brief Decodifica el comando que recibe el dispositivo MASTER desde el PC.
 * @param dev Dispositivo que recibe el comando del PC
 * @param pc_command_1 Primera mitad del comando recibido
 * @param pc_command_2 Segunda mitad del comando recibido
 */
void decode_pc_command(device *dev, uint8_t pc_command_1, uint8_t pc_command_2);

/**
 * @brief Decodifica el comando que recibe el dispositivo SLAVE desde la red.
 * @param dev Dispositivo que recibe el comando de la red
 * @param red_command_1 Primera mitad del comando recibido
 * @param red_command_2 Segunda mitad del comando recibido
 */
void decode_red_command(device *dev, uint8_t red_command_1, uint8_t red_command_2);

#endif /* COMMAND_DECODER_H_ */
