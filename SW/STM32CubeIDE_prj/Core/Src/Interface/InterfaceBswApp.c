/*
 * InterfaceBswApp.c
 *
 *  Created on: Jan 15, 2021
 *      Author: unix
 */

#include "InterfaceBswApp.h"
#include "tim.h"

uint32_t pwm_set_a_m=0;
uint32_t pwm_set_b_m=0;
uint32_t pwm_set_c_m=0;
uint8_t countInteruptsinOut=0;
uint8_t StepFunctionisStillRunning=0;
volatile uint32_t clocksNeededOfMAtlabFunc = 0;
volatile uint8_t NfaultState=0;
volatile uint8_t NfaultStateRunningCnt=0;
volatile uint16_t faultRegister1Value=0;
volatile uint16_t faultRegister2Value=0;
volatile struct CPU_clocks CPU_clocks_ins;

void set_PWM_A_DT(uint16_t a){

	pwm_set_a_m = (uint32_t)a;

	__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_4,pwm_set_a_m);

}
void set_PWM_B_DT(uint16_t a){

	pwm_set_b_m = (uint32_t)a;

	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,(uint32_t)pwm_set_b_m);

}
void set_PWM_C_DT(uint16_t a){

	pwm_set_c_m = (uint32_t)a;

	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,(uint32_t)pwm_set_c_m);

}

uint32_t rCpuClocks(void){

/*	 if (ARM_CM_DWT_CTRL != 0) {  // See if DWT is available

		  	 ARM_CM_DEMCR |= 1 << 24; // Set bit 24

		  	 ARM_CM_DWT_CYCCNT = 0;

		  	 ARM_CM_DWT_CTRL |= 1 << 0;  // Set bit 0

		  	}*/

	 return ARM_CM_DWT_CYCCNT;
}
