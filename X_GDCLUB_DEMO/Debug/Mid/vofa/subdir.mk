################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mid/vofa/VOFA.c 

OBJS += \
./Mid/vofa/VOFA.o 

C_DEPS += \
./Mid/vofa/VOFA.d 


# Each subdirectory must supply rules for building sources it contributes
Mid/vofa/%.o Mid/vofa/%.su: ../Mid/vofa/%.c Mid/vofa/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -D__TARGET_FPU_VFP -DUSE_DMP -DUSE_HAL_DRIVER -DEMPL -DARM_MATH_CM4 -DSTM32F411xE -DEMPL_TARGET_STM32F4 -DMPL_LOG_NDEBUG=1 -DMPU6050 -DDEBUG -c -I../Core/Inc -I../Mid/mpu6050/example -I../Mid/mpu6050/interface -I../Mid/mpu6050/src -I../Mid/dmp -I../Mid/vofa -I../Mid/e2prom -I../Mid -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Mid-2f-vofa

clean-Mid-2f-vofa:
	-$(RM) ./Mid/vofa/VOFA.d ./Mid/vofa/VOFA.o ./Mid/vofa/VOFA.su

.PHONY: clean-Mid-2f-vofa

