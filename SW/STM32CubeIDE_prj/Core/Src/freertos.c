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
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define __PWM1 0
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
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_4);
	__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_4,(uint16_t)0);
  /* Infinite loop */
  for(;;)
  {
	  /* Will be woken up by timer interrupt*/
	  ulTaskNotifyTake(pdTRUE,portMAX_DELAY);
	  /*HAL_GPIO_WritePin(TestPinC13_GPIO_Port, TestPinC13_Pin, GPIO_PIN_SET);
	  for(int i=0;i<10;i++) asm("nop");
	  volatile uint16_t a = adcBuffer[1];
	  HAL_GPIO_WritePin(TestPinC13_GPIO_Port, TestPinC13_Pin, GPIO_PIN_RESET);
	  volatile uint16_t intermediateVar[2]={0,0};
	  MX_DRV8304_Request_Status(intermediateVar,&hdrv8304);*/
	  HAL_GPIO_WritePin(GPIOB,DRV_INLC_Pin, GPIO_PIN_SET); //Remove Brake
	  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_4,(uint16_t)100);
	  MX_Change_Commutation_State();
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
	  MX_DRV8304_Request_Status(intermediateVar,&hdrv8304);
	  //HAL_GPIO_WritePin(GPIOB,DRV_INLB_Pin, GPIO_PIN_SET); //INLB connected

	 /* uint16_t intermediateVar[2]={0,0};
	  MX_DRV8304_Request_Status(intermediateVar,&hdrv8304);
#if __PWM1==0
	  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_4,(uint16_t)700);
	  HAL_GPIO_WritePin(GPIOB,DRV_INLC_Pin, GPIO_PIN_SET); //INLA connected
	  HAL_GPIO_WritePin(GPIOB,DRV_INLB_Pin, GPIO_PIN_RESET); //INLB connected
	  HAL_GPIO_TogglePin(GPIOB,DRV_INHC_Pin); //INHB Connected
#else
	  HAL_GPIO_WritePin(GPIOB,DRV_INLB_Pin, GPIO_PIN_SET); //INLB connected
	  HAL_GPIO_TogglePin(GPIOB,DRV_INHC_Pin); //INHB Connected
#endif
*/	  // Wait for the next cycle.
	  vTaskDelayUntil( &xLastWakeTime, xDelay );

  }
  /* USER CODE END testTask500msFunc */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
