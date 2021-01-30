/*
 * InterfaceBswApp.h
 *
 *  Created on: Jan 15, 2021
 *      Author: unix
 */

#ifndef INC_INTERFACE_INTERFACEBSWAPP_H_
#define INC_INTERFACE_INTERFACEBSWAPP_H_

#include "stm32f1xx_hal.h"

void set_PWM_A_DT(uint16_t a);
void set_PWM_B_DT(uint16_t a);
void set_PWM_C_DT(uint16_t a);

uint16_t adcBuffer[3];

uint32_t pwm_set_a_m;
uint32_t pwm_set_b_m;
uint32_t pwm_set_c_m;

extern volatile uint8_t NfaultState;
extern volatile uint8_t NfaultStateRunningCnt;
extern volatile uint16_t faultRegister1Value;
extern volatile uint16_t faultRegister2Value;

extern uint8_t countInteruptsinOut;
extern volatile uint32_t clocksNeededOfMAtlabFunc;

#endif /* INC_INTERFACE_INTERFACEBSWAPP_H_ */
