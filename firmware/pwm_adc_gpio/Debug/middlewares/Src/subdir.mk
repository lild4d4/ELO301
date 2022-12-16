################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../middlewares/Src/command_decoder.c \
../middlewares/Src/device.c \
../middlewares/Src/dip_switch.c \
../middlewares/Src/led.c \
../middlewares/Src/potenciometro.c \
../middlewares/Src/transmisor_receptor_red.c 

OBJS += \
./middlewares/Src/command_decoder.o \
./middlewares/Src/device.o \
./middlewares/Src/dip_switch.o \
./middlewares/Src/led.o \
./middlewares/Src/potenciometro.o \
./middlewares/Src/transmisor_receptor_red.o 

C_DEPS += \
./middlewares/Src/command_decoder.d \
./middlewares/Src/device.d \
./middlewares/Src/dip_switch.d \
./middlewares/Src/led.d \
./middlewares/Src/potenciometro.d \
./middlewares/Src/transmisor_receptor_red.d 


# Each subdirectory must supply rules for building sources it contributes
middlewares/Src/%.o middlewares/Src/%.su: ../middlewares/Src/%.c middlewares/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L452xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../middlewares/Src -I../middlewares/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-middlewares-2f-Src

clean-middlewares-2f-Src:
	-$(RM) ./middlewares/Src/command_decoder.d ./middlewares/Src/command_decoder.o ./middlewares/Src/command_decoder.su ./middlewares/Src/device.d ./middlewares/Src/device.o ./middlewares/Src/device.su ./middlewares/Src/dip_switch.d ./middlewares/Src/dip_switch.o ./middlewares/Src/dip_switch.su ./middlewares/Src/led.d ./middlewares/Src/led.o ./middlewares/Src/led.su ./middlewares/Src/potenciometro.d ./middlewares/Src/potenciometro.o ./middlewares/Src/potenciometro.su ./middlewares/Src/transmisor_receptor_red.d ./middlewares/Src/transmisor_receptor_red.o ./middlewares/Src/transmisor_receptor_red.su

.PHONY: clean-middlewares-2f-Src

