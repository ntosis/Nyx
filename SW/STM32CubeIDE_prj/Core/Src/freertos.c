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
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
typedef StaticTask_t osStaticThreadDef_t;
osThreadId_t defaultTaskHandle;
osThreadId_t ComputationINTHandle;
uint32_t ComputationINTBuffer[ 128 ];
osStaticThreadDef_t ComputationINTControlBlock;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void ComputationINTfunc(void *argument);

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
    .stack_mem = &ComputationINTBuffer[0],
    .stack_size = sizeof(ComputationINTBuffer),
    .cb_mem = &ComputationINTControlBlock,
    .cb_size = sizeof(ComputationINTControlBlock),
    .priority = (osPriority_t) osPriorityLow,
  };
  ComputationINTHandle = osThreadNew(ComputationINTfunc, NULL, &ComputationINT_attributes);

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
  /* Infinite loop */
  for(;;)
  {
	  /* Will be woken up by timer interrupt*/
	  ulTaskNotifyTake(pdTRUE,portMAX_DELAY);
	  HAL_GPIO_WritePin(TestPinC13_GPIO_Port, TestPinC13_Pin, GPIO_PIN_SET);
	  for(int i=0;i<10;i++) asm("nop");
	  HAL_GPIO_WritePin(TestPinC13_GPIO_Port, TestPinC13_Pin, GPIO_PIN_RESET);
  }
  /* USER CODE END ComputationINTfunc */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
