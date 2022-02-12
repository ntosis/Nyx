
#include "main.h"

uint32_t CalculateTimerSpeedForPWMInput(TIM_HandleTypeDef *htim)
{
	uint32_t TIMxclock=0;

	if((htim->Instance == TIM8 ) ||(htim->Instance == TIM1)) {
		TIMxclock = 2 * HAL_RCC_GetPCLK2Freq(); // TIM8 & TIM1 is attached to APB2 and is mul 2 in STM32F446 TODO Check apb and factor when use an other CPU.
	}
	if(htim->Init.Prescaler !=0) {
		TIMxclock = TIMxclock / htim->Init.Prescaler;
	}
	else {
		//nothing to do
	}

   return TIMxclock;
}
