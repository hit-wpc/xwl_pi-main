################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mid/dmp/data_builder.c \
../Mid/dmp/eMPL_outputs.c \
../Mid/dmp/hal_outputs.c \
../Mid/dmp/inv_mpu.c \
../Mid/dmp/inv_mpu_dmp_motion_driver.c \
../Mid/dmp/log_stm32.c \
../Mid/dmp/message_layer.c \
../Mid/dmp/ml_math_func.c \
../Mid/dmp/mlmath.c \
../Mid/dmp/mpl.c \
../Mid/dmp/mpu6050.c \
../Mid/dmp/results_holder.c \
../Mid/dmp/start_manager.c \
../Mid/dmp/storage_manager.c 

OBJS += \
./Mid/dmp/data_builder.o \
./Mid/dmp/eMPL_outputs.o \
./Mid/dmp/hal_outputs.o \
./Mid/dmp/inv_mpu.o \
./Mid/dmp/inv_mpu_dmp_motion_driver.o \
./Mid/dmp/log_stm32.o \
./Mid/dmp/message_layer.o \
./Mid/dmp/ml_math_func.o \
./Mid/dmp/mlmath.o \
./Mid/dmp/mpl.o \
./Mid/dmp/mpu6050.o \
./Mid/dmp/results_holder.o \
./Mid/dmp/start_manager.o \
./Mid/dmp/storage_manager.o 

C_DEPS += \
./Mid/dmp/data_builder.d \
./Mid/dmp/eMPL_outputs.d \
./Mid/dmp/hal_outputs.d \
./Mid/dmp/inv_mpu.d \
./Mid/dmp/inv_mpu_dmp_motion_driver.d \
./Mid/dmp/log_stm32.d \
./Mid/dmp/message_layer.d \
./Mid/dmp/ml_math_func.d \
./Mid/dmp/mlmath.d \
./Mid/dmp/mpl.d \
./Mid/dmp/mpu6050.d \
./Mid/dmp/results_holder.d \
./Mid/dmp/start_manager.d \
./Mid/dmp/storage_manager.d 


# Each subdirectory must supply rules for building sources it contributes
Mid/dmp/%.o Mid/dmp/%.su: ../Mid/dmp/%.c Mid/dmp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -D__TARGET_FPU_VFP -DUSE_DMP -DUSE_HAL_DRIVER -DEMPL -DARM_MATH_CM4 -DSTM32F411xE -DEMPL_TARGET_STM32F4 -DMPL_LOG_NDEBUG=1 -DMPU6050 -DDEBUG -c -I../Core/Inc -I../Mid/mpu6050/example -I../Mid/mpu6050/interface -I../Mid/mpu6050/src -I../Mid/dmp -I../Mid/vofa -I../Mid/e2prom -I../Mid -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Mid-2f-dmp

clean-Mid-2f-dmp:
	-$(RM) ./Mid/dmp/data_builder.d ./Mid/dmp/data_builder.o ./Mid/dmp/data_builder.su ./Mid/dmp/eMPL_outputs.d ./Mid/dmp/eMPL_outputs.o ./Mid/dmp/eMPL_outputs.su ./Mid/dmp/hal_outputs.d ./Mid/dmp/hal_outputs.o ./Mid/dmp/hal_outputs.su ./Mid/dmp/inv_mpu.d ./Mid/dmp/inv_mpu.o ./Mid/dmp/inv_mpu.su ./Mid/dmp/inv_mpu_dmp_motion_driver.d ./Mid/dmp/inv_mpu_dmp_motion_driver.o ./Mid/dmp/inv_mpu_dmp_motion_driver.su ./Mid/dmp/log_stm32.d ./Mid/dmp/log_stm32.o ./Mid/dmp/log_stm32.su ./Mid/dmp/message_layer.d ./Mid/dmp/message_layer.o ./Mid/dmp/message_layer.su ./Mid/dmp/ml_math_func.d ./Mid/dmp/ml_math_func.o ./Mid/dmp/ml_math_func.su ./Mid/dmp/mlmath.d ./Mid/dmp/mlmath.o ./Mid/dmp/mlmath.su ./Mid/dmp/mpl.d ./Mid/dmp/mpl.o ./Mid/dmp/mpl.su ./Mid/dmp/mpu6050.d ./Mid/dmp/mpu6050.o ./Mid/dmp/mpu6050.su ./Mid/dmp/results_holder.d ./Mid/dmp/results_holder.o ./Mid/dmp/results_holder.su ./Mid/dmp/start_manager.d ./Mid/dmp/start_manager.o ./Mid/dmp/start_manager.su ./Mid/dmp/storage_manager.d ./Mid/dmp/storage_manager.o ./Mid/dmp/storage_manager.su

.PHONY: clean-Mid-2f-dmp

