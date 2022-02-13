################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/FOC/ConstParams.c \
../Core/Src/FOC/MotorControlLibNEWFixedP_FULL19b.c \
../Core/Src/FOC/MotorControlLibNEWFixedP_FULL19b_data.c \
../Core/Src/FOC/ReadMotorAngle.c 

OBJS += \
./Core/Src/FOC/ConstParams.o \
./Core/Src/FOC/MotorControlLibNEWFixedP_FULL19b.o \
./Core/Src/FOC/MotorControlLibNEWFixedP_FULL19b_data.o \
./Core/Src/FOC/ReadMotorAngle.o 

C_DEPS += \
./Core/Src/FOC/ConstParams.d \
./Core/Src/FOC/MotorControlLibNEWFixedP_FULL19b.d \
./Core/Src/FOC/MotorControlLibNEWFixedP_FULL19b_data.d \
./Core/Src/FOC/ReadMotorAngle.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/FOC/%.o: ../Core/Src/FOC/%.c Core/Src/FOC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/ADCRawToIab" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/DRV8304" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/FOC" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/FOC/_sharedutils" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/Interface" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/PWMtoAngle" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/SafetyChecks" -I/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/CalcSpinSpeednDir -Og -ffunction-sections -fdata-sections -Wall -Wextra -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

