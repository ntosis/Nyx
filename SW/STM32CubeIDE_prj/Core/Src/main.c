/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "adc.h"
#include "dma.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "drv8304.h"
#include "MotorControlLibNEWFixedP_FULL19b.h"
#include "InterfaceBswApp.h"
#include "limits.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* Exported block signals */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define  ARM_CM_DEMCR      (*(uint32_t *)0xE000EDFC)

#define  ARM_CM_DWT_CTRL   (*(uint32_t *)0xE0001000)

#define  ARM_CM_DWT_CYCCNT (*(uint32_t *)0xE0001004)
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */
uint16_t adcBuffer[3]; // Buffer for store the results of the ADC conversion
volatile uint16_t MAXadcBuffer[3];
volatile uint16_t MINadcBuffer[3]={ UINT_MAX, UINT_MAX, UINT_MAX};

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  DebugCntr = ((uint32_t*) 0xE0001004);
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  MX_DMA_Init(); /*ToDo Bug! Cube mx is generating the adc init function before dma init and the register are configured false. Bug!  */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM3_Init();
  MX_ADC1_Init();
  MX_DMA_Init();
  MX_SPI1_Init();
  MX_TIM4_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_ADCEx_Calibration_Start(&hadc1);
  HAL_ADC_Start_DMA(&hadc1,(uint32_t*) adcBuffer, 1); // Start ADC in DMA mode and declare the buffer where store the results
  HAL_ADCEx_InjectedStart(&hadc1);
  MX_DRV8304_Init();
  /* HAL_TIM_Base_Start_IT(&htim3); Moved to FreeRTOS Task*/
  MotorControlLibNEWFixedP_FULL19b_initialize();
  /* USER CODE END 2 */

  /* Call init function for freertos objects (in freertos.c) */
  MX_FREERTOS_Init(); 

  /* Start scheduler */
  osKernelStart();
  
  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL8;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV4;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enables the Clock Security System 
  */
  HAL_RCC_EnableCSS();
}

/* USER CODE BEGIN 4 */
 /*void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
   Prevent unused argument(s) compilation warning
  UNUSED(hadc);
  DMA_Counter[0]++;
   NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_ConvCpltCallback must be implemented in the user file.

}

*
  * @brief  Conversion DMA half-transfer callback in non blocking mode
  * @param  hadc: ADC handle
  * @retval None

 void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef* hadc)
 {
    Prevent unused argument(s) compilation warning
   UNUSED(hadc);
   static uint16_t i=0;
   DMA_Counter[3]++;
   if(i>999) i=0;
   ADCConversion[0][i++] = HAL_ADCEx_InjectedGetValue(&hadc1,ADC_INJECTED_RANK_1);
    NOTE : This function Should not be modified, when the callback is needed,
             the HAL_ADCEx_InjectedConvCpltCallback could be implemented in the user file

 }
 void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
   Prevent unused argument(s) compilation warning
  UNUSED(hadc);
  DMA_Counter[1]++;
   NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_ConvHalfCpltCallback must be implemented in the user file.

}

 void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc)
 {
    Prevent unused argument(s) compilation warning
   UNUSED(hadc);
   DMA_Counter[2]++;
    NOTE : This function should not be modified. When the callback is needed,
             function HAL_ADC_ErrorCallback must be implemented in the user file.

 }*/
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */
  if(htim->Instance==TIM3)
  {
	  volatile uint32_t start=0,stop=0;
	  countInteruptsinOut++;
/*	  BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	  vTaskNotifyGiveFromISR(ComputationINTHandle,&xHigherPriorityTaskWoken);
	  portYIELD_FROM_ISR(xHigherPriorityTaskWoken);*/
	  if(StepFunctionisStillRunning==0) {
		  portDISABLE_INTERRUPTS(); //cmsis Code
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13,GPIO_PIN_SET);
		  StepFunctionisStillRunning = 1;
	      adcBuffer[1] = HAL_ADCEx_InjectedGetValue(&hadc1,ADC_INJECTED_RANK_1);
	      if( adcBuffer[1]>MAXadcBuffer[1])   MAXadcBuffer[1]=adcBuffer[1];
	      if( adcBuffer[0]>MAXadcBuffer[0])   MAXadcBuffer[0]=adcBuffer[0];
	      if( adcBuffer[1]<MINadcBuffer[1])   MINadcBuffer[1]=adcBuffer[1];
	      if( adcBuffer[0]<MINadcBuffer[0])   MINadcBuffer[0]=adcBuffer[0];

	  //MX_Change_Commutation_State();

	  	start = rCpuClocks();
	  	MotorControlLibNEWFixedP_FULL19b_step();
	  	//HAL_GPIO_TogglePin(GPIOB,DRV_INLC_Pin);
	  	stop = rCpuClocks();
	  	//
	  	clocksNeededOfMAtlabFunc = stop - start;
	  	countInteruptsinOut--;
	  	StepFunctionisStillRunning = 0;
	  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13,GPIO_PIN_RESET);
	  	if(clocksNeededOfMAtlabFunc > clocksNeededOfMAtlabFuncMAX) clocksNeededOfMAtlabFuncMAX = clocksNeededOfMAtlabFunc;
	  	if(clocksNeededOfMAtlabFunc < clocksNeededOfMAtlabFuncMIN) clocksNeededOfMAtlabFuncMIN = clocksNeededOfMAtlabFunc;
	  	portENABLE_INTERRUPTS();
	  }
  }
  /* USER CODE END Callback 1 */
}
/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
