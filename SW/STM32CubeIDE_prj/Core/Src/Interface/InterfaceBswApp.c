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
volatile uint32_t clocksNeededOfMAtlabFunc = 0;
volatile uint8_t NfaultState=0;
extern volatile uint8_t NfaultStateRunningCnt=0;
extern volatile uint16_t faultRegister1Value=0;
extern volatile uint16_t faultRegister2Value=0;

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
