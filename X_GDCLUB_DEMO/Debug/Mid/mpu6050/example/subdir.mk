################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mid/mpu6050/example/driver_mpu6050_basic.c \
../Mid/mpu6050/example/driver_mpu6050_dmp.c \
../Mid/mpu6050/example/driver_mpu6050_fifo.c 

OBJS += \
./Mid/mpu6050/example/driver_mpu6050_basic.o \
./Mid/mpu6050/example/driver_mpu6050_dmp.o \
./Mid/mpu6050/example/driver_mpu6050_fifo.o 

C_DEPS += \
./Mid/mpu6050/example/driver_mpu6050_basic.d \
./Mid/mpu6050/example/driver_mpu6050_dmp.d \
./Mid/mpu6050/example/driver_mpu6050_fifo.d 


# Each subdirectory must supply rules for building sources it contributes
Mid/mpu6050/example/%.o Mid/mpu6050/example/%.su: ../Mid/mpu6050/example/%.c Mid/mpu6050/example/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -D__TARGET_FPU_VFP -DUSE_DMP -DUSE_HAL_DRIVER -DEMPL -DARM_MATH_CM4 -DSTM32F411xE -DEMPL_TARGET_STM32F4 -DMPL_LOG_NDEBUG=1 -DMPU6050 -DDEBUG -c -I../Core/Inc -I../Mid/mpu6050/example -I../Mid/mpu6050/interface -I../Mid/mpu6050/src -I../Mid/dmp -I../Mid/vofa -I../Mid/e2prom -I../Mid -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Mid-2f-mpu6050-2f-example

clean-Mid-2f-mpu6050-2f-example:
	-$(RM) ./Mid/mpu6050/example/driver_mpu6050_basic.d ./Mid/mpu6050/example/driver_mpu6050_basic.o ./Mid/mpu6050/example/driver_mpu6050_basic.su ./Mid/mpu6050/example/driver_mpu6050_dmp.d ./Mid/mpu6050/example/driver_mpu6050_dmp.o ./Mid/mpu6050/example/driver_mpu6050_dmp.su ./Mid/mpu6050/example/driver_mpu6050_fifo.d ./Mid/mpu6050/example/driver_mpu6050_fifo.o ./Mid/mpu6050/example/driver_mpu6050_fifo.su

.PHONY: clean-Mid-2f-mpu6050-2f-example

