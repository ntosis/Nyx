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

#define  ARM_CM_DEMCR      (*(uint32_t *)0xE000EDFC)

#define  ARM_CM_DWT_CTRL   (*(uint32_t *)0xE0001000)

#define  ARM_CM_DWT_CYCCNT (*(uint32_t *)0xE0001004)

uint32_t rCpuClocks(void);
volatile uint32_t *DebugCntr;
uint16_t adcBuffer[3];

uint32_t pwm_set_a_m;
uint32_t pwm_set_b_m;
uint32_t pwm_set_c_m;

extern volatile uint8_t NfaultState;
extern volatile uint8_t NfaultStateRunningCnt;
extern volatile uint16_t faultRegister1Value;
extern volatile uint16_t faultRegister2Value;
extern volatile uint16_t DRVConRegisterValue;

extern uint8_t countInteruptsinOut;
extern uint8_t StepFunctionisStillRunning;
extern volatile uint32_t clocksNeededOfMAtlabFunc;
volatile uint32_t clocksNeededOfMAtlabFuncMAX;
volatile uint32_t clocksNeededOfMAtlabFuncMIN;
volatile uint32_t clocksNeededOfMAtlabFunc_1;
volatile uint32_t clocksNeededOfMAtlabFunc_2;
volatile uint32_t clocksNeededOfMAtlabFunc_3;
volatile uint32_t clocksNeededOfMAtlabFunc_4;
volatile uint32_t clocksNeededOfMAtlabFunc_5;
volatile uint32_t clocksNeededOfMAtlabFunc_6;
volatile uint32_t clocksNeededOfMAtlabFunc_7;
volatile uint32_t clocksNeededOfMAtlabFunc_8;
volatile uint32_t clocksNeededOfMAtlabFunc_9;
volatile uint32_t clocksNeededOfMAtlabFunc_10;
volatile uint32_t clocksNeededOfMAtlabFunc_11;
volatile uint32_t clocksNeededOfMAtlabFunc_12;
volatile uint32_t clocksNeededOfMAtlabFunc_13;


struct CPU_clocks {
  uint32_t StepFunctionClocks;
  uint32_t FluxObserverClocks;
  uint32_t Step1;
  uint32_t Step2;
  uint32_t Step3;
  uint32_t Step4;
  uint32_t Step5;
  uint32_t Step6;
  uint32_t Step7;
  uint32_t Step8;
  uint32_t Step9;
};
extern volatile struct CPU_clocks CPU_clocks_ins;
#endif /* INC_INTERFACE_INTERFACEBSWAPP_H_ */
