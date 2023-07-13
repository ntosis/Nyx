################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Interface/InterfaceBswApp.c \
../Core/Src/Interface/convertSingleTo12bit.c \
../Core/Src/Interface/convertSingleTo12bit_data.c 

OBJS += \
./Core/Src/Interface/InterfaceBswApp.o \
./Core/Src/Interface/convertSingleTo12bit.o \
./Core/Src/Interface/convertSingleTo12bit_data.o 

C_DEPS += \
./Core/Src/Interface/InterfaceBswApp.d \
./Core/Src/Interface/convertSingleTo12bit.d \
./Core/Src/Interface/convertSingleTo12bit_data.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Interface/%.o: ../Core/Src/Interface/%.c Core/Src/Interface/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Core/Inc/ADCRawToIab -I../Core/Inc/DRV8304 -I../Core/Inc/FOC -I../Core/Inc/FOC/_sharedutils -I../Core/Inc/Interface -I../Core/Inc/PWMtoAngle -I../Core/Inc/SafetyChecks -I../Core/Inc/CalcSpinSpeednDir -Og -ffunction-sections -fdata-sections -Wall -Wextra -ffile-prefix-map=/home/runner/work/Nyx/Nyx/SW/STM32CubeIDE_prj=. -Werror-implicit-function-declaration -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

