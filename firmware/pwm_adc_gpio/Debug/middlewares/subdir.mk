################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../middlewares/command_decoder.c 

OBJS += \
./middlewares/command_decoder.o 

C_DEPS += \
./middlewares/command_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
middlewares/%.o middlewares/%.su: ../middlewares/%.c middlewares/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L452xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-middlewares

clean-middlewares:
	-$(RM) ./middlewares/command_decoder.d ./middlewares/command_decoder.o ./middlewares/command_decoder.su

.PHONY: clean-middlewares

