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
uint8_t EncoderCounterHasOverflowed=0;
uint8_t EncoderCounterHasOverflowedErrorFlag=0;
uint32_t EncoderCounter = 0;

volatile uint32_t clocksNeededOfMAtlabFunc = 0;
volatile uint32_t clocksNeededOfMAtlabFuncMAX = 0;
volatile uint32_t clocksNeededOfMAtlabFuncMIN = UINT32_MAX;
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
volatile uint32_t clocksNeededOfTestFunction = 0;
volatile uint8_t NfaultState=0;
volatile uint8_t NfaultStateRunningCnt=0;
volatile uint16_t faultRegister1Value=0;
volatile uint16_t faultRegister2Value=0;
volatile uint16_t DRVConRegisterValue=0;
volatile struct CPU_clocks CPU_clocks_ins;
#ifdef EXTENDED_DEBUG
volatile struct Debug_signals dbg_obj;
#endif
volatile uint32_t *DebugCntr;
volatile uint16_t PWMdbg[3];

uint8_t hasTimer8Overflowed=0;
uint8_t hasMathOverflowed_PWMin=0;
uint8_t NoSignal_PWMin=0;
uint32_t countWrongSignals=0;
char hasPWMSignalbeenread=0;

void set_PWM_A_DT(uint16_t a){

	if(qSoll==0) {
		pwm_set_a_m = 250U;
	}
	else {
		pwm_set_a_m = (uint32_t)500U - (uint32_t)a;
	}

		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,(uint32_t)pwm_set_a_m);
		//__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,(uint32_t)pwm_set_a_m);


	PWMdbg[0] = pwm_set_a_m;

}
void set_PWM_B_DT(uint16_t a){

	if(qSoll==0) {
		pwm_set_b_m = 250U;
	}
	else {
		pwm_set_b_m = (uint32_t)500U - (uint32_t)a;;
		}


	   __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,(uint32_t)pwm_set_b_m);
		//__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,(uint32_t)pwm_set_b_m);



	PWMdbg[1] = pwm_set_b_m;
}
void set_PWM_C_DT(uint16_t a){

	if(qSoll==0) {
		pwm_set_c_m = 250U;
	}
	else {
		pwm_set_c_m = (uint32_t)500U - (uint32_t)a;;
		}


	__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,(uint32_t)pwm_set_c_m);
	//__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,(uint32_t)pwm_set_c_m);

	PWMdbg[2] = pwm_set_c_m;

}

void emergency_disable_hardware(uint8_t in){

	/*After critical error detection you can call this function to disable all mosfet bridges.
	 * For DRV8304 is enough to set the ENABLE pin to low and the device suspends all Mosfets.
	*/

	if (in) {
	
		__disable_irq();
		HAL_GPIO_WritePin(DRV_ENABLE_GPIO_Port,DRV_ENABLE_Pin, GPIO_PIN_RESET);
#ifdef SEMIHOSTING
		writeInFile();
#endif
		while(1) { }

		    }
}

uint32_t rCpuClocks(void){

/*	 if (ARM_CM_DWT_CTRL != 0) {  // See if DWT is available

		  	 ARM_CM_DEMCR |= 1 << 24; // Set bit 24

		  	 ARM_CM_DWT_CYCCNT = 0;

		  	 ARM_CM_DWT_CTRL |= 1 << 0;  // Set bit 0

		  	}*/

	 return ARM_CM_DWT_CYCCNT;
}

void disablePWMInputTimer(void){

	static char isDisabled=0;

	if(qSoll!=0) {

		HAL_NVIC_DisableIRQ(TIM8_CC_IRQn);
		isDisabled=1;

	}
	else if((qSoll==0)&(isDisabled==1))
	{
		HAL_NVIC_EnableIRQ(TIM8_CC_IRQn);
		isDisabled=0;

	}

}
