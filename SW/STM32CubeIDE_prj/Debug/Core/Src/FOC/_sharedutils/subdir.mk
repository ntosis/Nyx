################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/FOC/_sharedutils/const_params.c \
../Core/Src/FOC/_sharedutils/div_s16s32.c \
../Core/Src/FOC/_sharedutils/div_s32_convergent.c \
../Core/Src/FOC/_sharedutils/div_s32_floor.c \
../Core/Src/FOC/_sharedutils/look1_is16lu32n16tu16_binlcse.c \
../Core/Src/FOC/_sharedutils/mul_ssu32_loSR.c \
../Core/Src/FOC/_sharedutils/mul_ssu32_loSR_sat.c \
../Core/Src/FOC/_sharedutils/mul_wide_su32.c \
../Core/Src/FOC/_sharedutils/rtGetInf.c \
../Core/Src/FOC/_sharedutils/rtGetNaN.c \
../Core/Src/FOC/_sharedutils/rt_atan2f_snf.c \
../Core/Src/FOC/_sharedutils/rt_atan2f_snf_cordic6.c \
../Core/Src/FOC/_sharedutils/rt_nonfinite.c \
../Core/Src/FOC/_sharedutils/rt_zcfcn.c 

OBJS += \
./Core/Src/FOC/_sharedutils/const_params.o \
./Core/Src/FOC/_sharedutils/div_s16s32.o \
./Core/Src/FOC/_sharedutils/div_s32_convergent.o \
./Core/Src/FOC/_sharedutils/div_s32_floor.o \
./Core/Src/FOC/_sharedutils/look1_is16lu32n16tu16_binlcse.o \
./Core/Src/FOC/_sharedutils/mul_ssu32_loSR.o \
./Core/Src/FOC/_sharedutils/mul_ssu32_loSR_sat.o \
./Core/Src/FOC/_sharedutils/mul_wide_su32.o \
./Core/Src/FOC/_sharedutils/rtGetInf.o \
./Core/Src/FOC/_sharedutils/rtGetNaN.o \
./Core/Src/FOC/_sharedutils/rt_atan2f_snf.o \
./Core/Src/FOC/_sharedutils/rt_atan2f_snf_cordic6.o \
./Core/Src/FOC/_sharedutils/rt_nonfinite.o \
./Core/Src/FOC/_sharedutils/rt_zcfcn.o 

C_DEPS += \
./Core/Src/FOC/_sharedutils/const_params.d \
./Core/Src/FOC/_sharedutils/div_s16s32.d \
./Core/Src/FOC/_sharedutils/div_s32_convergent.d \
./Core/Src/FOC/_sharedutils/div_s32_floor.d \
./Core/Src/FOC/_sharedutils/look1_is16lu32n16tu16_binlcse.d \
./Core/Src/FOC/_sharedutils/mul_ssu32_loSR.d \
./Core/Src/FOC/_sharedutils/mul_ssu32_loSR_sat.d \
./Core/Src/FOC/_sharedutils/mul_wide_su32.d \
./Core/Src/FOC/_sharedutils/rtGetInf.d \
./Core/Src/FOC/_sharedutils/rtGetNaN.d \
./Core/Src/FOC/_sharedutils/rt_atan2f_snf.d \
./Core/Src/FOC/_sharedutils/rt_atan2f_snf_cordic6.d \
./Core/Src/FOC/_sharedutils/rt_nonfinite.d \
./Core/Src/FOC/_sharedutils/rt_zcfcn.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/FOC/_sharedutils/%.o: ../Core/Src/FOC/_sharedutils/%.c Core/Src/FOC/_sharedutils/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/ADCRawToIab" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/DRV8304" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/FOC" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/FOC/_sharedutils" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/Interface" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/PWMtoAngle" -I"/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/SafetyChecks" -I/home/unix/MyCODE/GitProjects/Nyx/Nyx/SW/STM32CubeIDE_prj/Core/Inc/CalcSpinSpeednDir -Og -ffunction-sections -fdata-sections -Wall -Wextra -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

