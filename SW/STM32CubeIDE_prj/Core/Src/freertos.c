/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     
#include "portmacro.h"
#include "tim.h"
#include "drv8304.h"
#include "MotorControlLibNEWFixedP_FULL19b.h"
#include "adc.h"
#include "InterfaceBswApp.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define __PWM1 0


#define  ARM_CM_DEMCR      (*(uint32_t *)0xE000EDFC)

#define  ARM_CM_DWT_CTRL   (*(uint32_t *)0xE0001000)

#define  ARM_CM_DWT_CYCCNT (*(uint32_t *)0xE0001004)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId_t defaultTaskHandle;
osThreadId_t ComputationINTHandle;
osThreadId_t testTask500msHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void ComputationINTfunc(void *argument);
void testTask500msFunc(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */
osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  const osThreadAttr_t defaultTask_attributes = {
    .name = "defaultTask",
    .priority = (osPriority_t) osPriorityNormal,
    .stack_size = 128
  };
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* definition and creation of ComputationINT */
  const osThreadAttr_t ComputationINT_attributes = {
    .name = "ComputationINT",
    .priority = (osPriority_t) osPriorityNormal,
    .stack_size = 128
  };
  ComputationINTHandle = osThreadNew(ComputationINTfunc, NULL, &ComputationINT_attributes);

  /* definition and creation of testTask500ms */
  const osThreadAttr_t testTask500ms_attributes = {
    .name = "testTask500ms",
    .priority = (osPriority_t) osPriorityHigh,
    .stack_size = 512
  };
  testTask500msHandle = osThreadNew(testTask500msFunc, NULL, &testTask500ms_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_ComputationINTfunc */
/**
* @brief Function implementing the ComputationINT thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_ComputationINTfunc */
void ComputationINTfunc(void *argument)
{
  /* USER CODE BEGIN ComputationINTfunc */
 //Called in HAL_TIM_PeriodElapsedCallback
	  if (ARM_CM_DWT_CTRL != 0) {  // See if DWT is available

	  	 ARM_CM_DEMCR |= 1 << 24; // Set bit 24

	  	 ARM_CM_DWT_CYCCNT = 0;

	  	 ARM_CM_DWT_CTRL |= 1 << 0;  // Set bit 0

	  	}

	uint32_t tempGPIOB = GPIOB->ODR; /* Read the actual ODR Register values. */

	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_4);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);

	__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_4,(uint16_t)500);
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,(uint16_t)500);
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,(uint16_t)500);



	HAL_GPIO_WritePin(GPIOB,DRV_INLA_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,DRV_INLB_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,DRV_INLC_Pin, GPIO_PIN_SET);

	HAL_TIM_Base_Start_IT(&htim3);

  /* Infinite loop */
  for(;;)
  {
	  volatile uint32_t start=0,stop=0;
	  /* Will be woken up by timer interrupt*/
	  ulTaskNotifyTake(pdTRUE,portMAX_DELAY);


	  adcBuffer[1] = HAL_ADCEx_InjectedGetValue(&hadc1,ADC_INJECTED_RANK_1);

	  //MX_Change_Commutation_State();
	  	//__disable_irq(); //cmsis Code
	  	start = rCpuClocks();
	  	MotorControlLibNEWFixedP_FULL19b_step();
	  	//HAL_GPIO_TogglePin(GPIOB,DRV_INLC_Pin);
	  	stop = rCpuClocks();
	  	//__enable_irq();
	  	clocksNeededOfMAtlabFunc = stop - start;
	  	countInteruptsinOut--;



  }
  /* USER CODE END ComputationINTfunc */
}

/* USER CODE BEGIN Header_testTask500msFunc */
/**
* @brief Function implementing the testTask500ms thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_testTask500msFunc */
void testTask500msFunc(void *argument)
{
  /* USER CODE BEGIN testTask500msFunc */
  portTickType xLastWakeTime;
  const portTickType xDelay = 500 / portTICK_RATE_MS;
  // Initialise the xLastWakeTime variable with the current time.
  xLastWakeTime = xTaskGetTickCount ();
  /* Infinite loop */
  for(;;)
  {
	  uint16_t intermediateVar[2]={0,0};
	  //MX_DRV8304_Request_Status(intermediateVar,&hdrv8304);
	  //HAL_GPIO_WritePin(GPIOB,DRV_INLB_Pin, GPIO_PIN_SET); //INLB connected
	  //MX_DRV8304_CalculateIabc(&hdrv8304);
	 /* uint16_t intermediateVar[2]={0,0};

#if __PWM1==0
	  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_4,(uint16_t)700);
	  HAL_GPIO_WritePin(GPIOB,DRV_INLC_Pin, GPIO_PIN_SET); //INLA connected
	  HAL_GPIO_WritePin(GPIOB,DRV_INLB_Pin, GPIO_PIN_RESET); //INLB connected
	  HAL_GPIO_TogglePin(GPIOB,DRV_INHC_Pin); //INHB Connected
#else
	  HAL_GPIO_WritePin(GPIOB,DRV_INLB_Pin, GPIO_PIN_SET); //INLB connected
	  HAL_GPIO_TogglePin(GPIOB,DRV_INHC_Pin); //INHB Connected
#endif
*/
	  //HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14,GPIO_PIN_SET);
	  NfaultState = HAL_GPIO_ReadPin(DRV_NFAULT_GPIO_Port,DRV_NFAULT_Pin);
	  NfaultStateRunningCnt++;
	  MX_DRV8304_Report_Fault(&faultRegister1Value,&faultRegister2Value,&DRVConRegisterValue,&hdrv8304);
	  //HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14,GPIO_PIN_RESET);
	  // Wait for the next cycle.
	  vTaskDelayUntil( &xLastWakeTime, xDelay );

  }
  /* USER CODE END testTask500msFunc */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
