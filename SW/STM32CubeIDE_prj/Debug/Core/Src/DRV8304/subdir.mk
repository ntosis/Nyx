################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/DRV8304/drv8304.c 

OBJS += \
./Core/Src/DRV8304/drv8304.o 

C_DEPS += \
./Core/Src/DRV8304/drv8304.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/DRV8304/%.o: ../Core/Src/DRV8304/%.c Core/Src/DRV8304/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Core/Inc/ADCRawToIab -I../Core/Inc/DRV8304 -I../Core/Inc/FOC -I../Core/Inc/FOC/_sharedutils -I../Core/Inc/Interface -I../Core/Inc/PWMtoAngle -I../Core/Inc/SafetyChecks -I../Core/Inc/CalcSpinSpeednDir -Og -ffunction-sections -fdata-sections -Wall -Wextra -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

