/*
 * InterfaceBswApp.h
 *
 *  Created on: Jan 15, 2021
 *      Author: unix
 */

#ifndef INC_INTERFACE_INTERFACEBSWAPP_H_
#define INC_INTERFACE_INTERFACEBSWAPP_H_

#include "stm32f4xx_hal.h"

void set_PWM_A_DT(uint16_t a);
void set_PWM_B_DT(uint16_t a);
void set_PWM_C_DT(uint16_t a);

#define  ARM_CM_DEMCR      (*(uint32_t *)0xE000EDFC)

#define  ARM_CM_DWT_CTRL   (*(uint32_t *)0xE0001000)

#define  ARM_CM_DWT_CYCCNT (*(uint32_t *)0xE0001004)

uint32_t rCpuClocks(void);
void emergency_disable_hardware(uint8_t in);

extern volatile uint32_t *DebugCntr;
extern uint16_t adcBuffer[3];
extern uint16_t DmaBuffer[3];
extern int16_t autoCalADCVal[2];

extern uint32_t pwm_set_a_m;
extern uint32_t pwm_set_b_m;
extern uint32_t pwm_set_c_m;

extern volatile uint8_t NfaultState;
extern volatile uint8_t NfaultStateRunningCnt;
extern volatile uint16_t faultRegister1Value;
extern volatile uint16_t faultRegister2Value;
extern volatile uint16_t DRVConRegisterValue;

extern uint8_t countInteruptsinOut;
extern uint8_t StepFunctionisStillRunning;
extern volatile uint32_t clocksNeededOfMAtlabFunc;
extern volatile uint32_t clocksNeededOfMAtlabFuncMAX;
extern volatile uint32_t clocksNeededOfMAtlabFuncMIN;



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
