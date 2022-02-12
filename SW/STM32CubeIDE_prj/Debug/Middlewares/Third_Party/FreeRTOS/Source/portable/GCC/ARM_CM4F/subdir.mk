################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.o: ../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.c Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/ADCRawToIab" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/DRV8304" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/FOC" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/FOC/_sharedutils" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/Interface" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/PWMtoAngle" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/SafetyChecks" -Og -ffunction-sections -fdata-sections -Wall -Wextra -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

