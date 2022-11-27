/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "adc.h"
#include "InterfaceBswApp.h"
#include "MotorControlLib.h"
#include "dac.h"
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */


#define  ARM_CM_DEMCR      (*(uint32_t *)0xE000EDFC)

#define  ARM_CM_DWT_CTRL   (*(uint32_t *)0xE0001000)

#define  ARM_CM_DWT_CYCCNT (*(uint32_t *)0xE0001004)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
volatile uint8_t manualBreak=0;
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
uint32_t defaultTaskBuffer[ 128 ];
osStaticThreadDef_t defaultTaskControlBlock;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .cb_mem = &defaultTaskControlBlock,
  .cb_size = sizeof(defaultTaskControlBlock),
  .stack_mem = &defaultTaskBuffer[0],
  .stack_size = sizeof(defaultTaskBuffer),
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for ComputationINT */
osThreadId_t ComputationINTHandle;
uint32_t ComputationINTBuffer[ 128 ];
osStaticThreadDef_t ComputationINTControlBlock;
const osThreadAttr_t ComputationINT_attributes = {
  .name = "ComputationINT",
  .cb_mem = &ComputationINTControlBlock,
  .cb_size = sizeof(ComputationINTControlBlock),
  .stack_mem = &ComputationINTBuffer[0],
  .stack_size = sizeof(ComputationINTBuffer),
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for testTask500ms */
osThreadId_t testTask500msHandle;
uint32_t testTask500msBuffer[ 512 ];
osStaticThreadDef_t testTask500msControlBlock;
const osThreadAttr_t testTask500ms_attributes = {
  .name = "testTask500ms",
  .cb_mem = &testTask500msControlBlock,
  .cb_size = sizeof(testTask500msControlBlock),
  .stack_mem = &testTask500msBuffer[0],
  .stack_size = sizeof(testTask500msBuffer),
  .priority = (osPriority_t) osPriorityHigh,
};

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
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of ComputationINT */
  ComputationINTHandle = osThreadNew(ComputationINTfunc, NULL, &ComputationINT_attributes);

  /* creation of testTask500ms */
  testTask500msHandle = osThreadNew(testTask500msFunc, NULL, &testTask500ms_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

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

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(DRV_INLA_GPIO_Port, DRV_INLA_Pin, GPIO_PIN_SET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(DRV_INLB_GPIO_Port, DRV_INLC_Pin|DRV_INLB_Pin, GPIO_PIN_SET);

	HAL_TIM_IC_Start_IT(&htim8, TIM_CHANNEL_1);   // enable falling and rising edge int
	HAL_TIM_IC_Start_IT(&htim8, TIM_CHANNEL_2);
    __HAL_TIM_ENABLE_IT(&htim8,TIM_IT_UPDATE);    // enable timer overflow int.

    //Start PWM on CH1 and CH1N
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
    HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_1);

    //Start PWM on CH3 and CH3N
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
    HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_3);

	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);


	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,(uint16_t)250);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,(uint16_t)250);
	__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,(uint16_t)250);


	//HAL_ADCEx_InjectedStart(&hadc1);
	HAL_ADCEx_InjectedStart(&hadc2);
	HAL_ADC_Start_DMA(&hadc1,(uint32_t*) DmaBuffer, 1); // Start ADC in DMA mode and declare the buffer where store the results
	/*  Start DRV8304 Calibration always after ADC is working and will be triggered! */
	HAL_Delay(5); //wait 5ms to start DMA from ADC1 value transfer
	autoCalADCVal[1] = (int16_t)(2048 - DmaBuffer[0]);//HAL_ADCEx_InjectedGetValue(&hadc1,ADC_INJECTED_RANK_1);
	autoCalADCVal[0] = (int16_t)(2048 - HAL_ADCEx_InjectedGetValue(&hadc2,ADC_INJECTED_RANK_1)); //DMA measurment

	/*  Stop DRV8304 Calibration */

	/* Start DAC for Debugging */
	HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
	HAL_DAC_Start(&hdac, DAC_CHANNEL_2);

	HAL_TIM_Encoder_Start(&htim5,TIM_CHANNEL_ALL);
	HAL_TIM_Base_Start_IT(&htim10);

	//__HAL_TIM_ENABLE_IT(&htim8,TIM_IT_UPDATE);    // enable timer overflow int.

	/* Infinite loop */
	for(;;)
	  {
		  volatile uint32_t start=0,stop=0;
		  /* Will be woken up by timer interrupt*/
		  ulTaskNotifyTake(pdTRUE,portMAX_DELAY);
		  countInteruptsinOut++;

		  if(StepFunctionisStillRunning==0) {

			  portDISABLE_INTERRUPTS(); //cmsis Code
			  //HAL_GPIO_WritePin(TestINT_GPIO_Port, TestINT_Pin,GPIO_PIN_SET);
			  StepFunctionisStillRunning = 1;

			  	  disablePWMInputTimer();
				  adcBuffer[0] = (uint16_t)HAL_ADCEx_InjectedGetValue(&hadc2,ADC_INJECTED_RANK_1);
				  HAL_ADC_Stop_DMA(&hadc1);
				  adcBuffer[1] = DmaBuffer[0];// (int16_t)HAL_ADCEx_InjectedGetValue(&hadc1,ADC_INJECTED_RANK_1);

				  start = rCpuClocks();
				  d_q_Voltage_Limiter_sat_neg = -1 * d_q_Voltage_Limiter_sat_pos;
				  EncoderCounter = __HAL_TIM_GET_COUNTER(&htim5);
				  MotorControlLib_step();
				  HAL_ADC_Start_DMA(&hadc1,(uint32_t*) DmaBuffer, 1);
				  stop = rCpuClocks();

#ifdef EXTENDED_DEBUG
	  if ((MotorControlLib_M->Timing.TaskCounters.TID[2] == 0)&&(qSoll!=0)&&(dbg_obj.k<=(MAX_DBG_BUFFERSIZE-1))) {

				if(dbg_obj.k>(MAX_DBG_BUFFERSIZE-1)) {

					dbg_obj.k=0;

					}

				dbg_obj.dbgadcBuffer_0[dbg_obj.k] = adcBuffer[0];
				dbg_obj.dbgadcBuffer_1[dbg_obj.k] = adcBuffer[1];
				dbg_obj.dbgSig_Ia_m[dbg_obj.k]= Sig_Ia_m;
				dbg_obj.dbgSig_Ib_m[dbg_obj.k]=Sig_Ib_m;
				dbg_obj.dbgSig_Va_m[dbg_obj.k]=Sig_Va_m;
				dbg_obj.dbgSig_Vb_m[dbg_obj.k]=Sig_Vb_m;
				dbg_obj.dbgSig_Valpha_m[dbg_obj.k]=Sig_Valpha_m;
				dbg_obj.dbgSig_Vbeta_m[dbg_obj.k]=Sig_Vbeta_m;
				dbg_obj.dbgSig_Vgamma_m[dbg_obj.k]=Sig_Vgamma_m;
				dbg_obj.dbgSig_Vqsatu_m[dbg_obj.k]=Sig_Vqsatu_m;
				dbg_obj.dbgSig_Vdsatu_m[dbg_obj.k]=Sig_Vdsatu_m;
				dbg_obj.dbgSig_qAxis_m[dbg_obj.k]=Sig_qAxis_m;
				dbg_obj.dbgSig_dAxis_m[dbg_obj.k]=Sig_dAxis_m;
				dbg_obj.dbgSig_dAxis_PI_out[dbg_obj.k]= Sig_dAxis_PI_out;
				dbg_obj.dbgSig_qAxis_PI_out[dbg_obj.k]= Sig_qAxis_PI_out;
				dbg_obj.dbgSig_theta_el_m[dbg_obj.k]=Sig_theta_el_m;
				dbg_obj.dbgqSoll[dbg_obj.k]=qSoll;
				dbg_obj.dbgPI_d_Integrator[dbg_obj.k]=PI_d_Integrator;
				dbg_obj.dbgPI_q_Integrator[dbg_obj.k]=PI_q_Integrator;
				dbg_obj.dbgKpq[dbg_obj.k]=Kp_qAxis;
				dbg_obj.dbgKpd[dbg_obj.k]=Kp_dAxis;
				dbg_obj.dbgDuty[dbg_obj.k]=Duty;
				dbg_obj.dbgPWM_C[dbg_obj.k] = PWMdbg[0];
				dbg_obj.dbgPWM_A[dbg_obj.k] = PWMdbg[1];
				dbg_obj.dbgPWM_B[dbg_obj.k] = PWMdbg[2];
				dbg_obj.dbgEncoder[dbg_obj.k] = EncoderCounter;
				dbg_obj.dbgFlag_1[dbg_obj.k] = Flags[1];
				dbg_obj.dbgSig_Ic[dbg_obj.k] = Iabc[2];
				dbg_obj.dbgKiq[dbg_obj.k] = Ki_qAxis;
				dbg_obj.dbgKid[dbg_obj.k] = Ki_dAxis;
				dbg_obj.k++;
	      }
#endif


	  	if(manualBreak) {
	  		writeInFile();
	  	}

	  	clocksNeededOfMAtlabFunc = stop - start;
	  	countInteruptsinOut--;
	  	StepFunctionisStillRunning = 0;

	  	//HAL_GPIO_WritePin(TestINT_GPIO_Port, TestINT_Pin,GPIO_PIN_RESET);


	  	portENABLE_INTERRUPTS();

	  }

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
  const portTickType xDelay = 300 / portTICK_RATE_MS;
  // Initialise the xLastWakeTime variable with the current time.
  xLastWakeTime = xTaskGetTickCount ();
  CalcSpinSpeednDir_initialize();
  static uint8_t OneSecCnt=0;
  static uint8_t ChangeKpiCircle=0;
  /* Infinite loop */
  for(;;)
  {
	  if (!HAL_GPIO_ReadPin(GPIOC,Blue_Button_Pin)) {
		  ChangeKpiCircle++;
		  if(ChangeKpiCircle>3) { ChangeKpiCircle =0; }
	  }

	  if(!HAL_GPIO_ReadPin(GPIOC,UpSetBtn_Pin)) {
		  switch (ChangeKpiCircle) {
		  case 0: Kp_qAxis++; break;
		  case 1: Kp_dAxis++; break;
		  case 2: Ki_qAxis++; break;
		  case 3: Ki_dAxis++; break;
		  default: break;
		  }
	  }

	  if (OneSecCnt==1) { //1 sec period
		  //CalcSpinSpeednDir_step();
	  }
	  OneSecCnt++;
	  if(OneSecCnt>1) {OneSecCnt = 0; }
	  //uint16_t intermediateVar[2]={0,0};
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
	 // NfaultState = HAL_GPIO_ReadPin(DRV_NFAULT_GPIO_Port,DRV_NFAULT_Pin);
	 // NfaultStateRunningCnt++;
	  //MX_DRV8304_Report_Fault(&faultRegister1Value,&faultRegister2Value,&DRVConRegisterValue,&hdrv8304);
	  //HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14,GPIO_PIN_RESET);
	  // Wait for the next cycle.
	  vTaskDelayUntil( &xLastWakeTime, xDelay );

  }
  /* USER CODE END testTask500msFunc */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
#ifdef SEMIHOSTING // Log data in file
void writeInFile(void) {
		/*2500 old*/
#ifdef EXTENDED_DEBUG
			qSoll=0;
			set_PWM_A_DT(250U);
			set_PWM_B_DT(250U);
			set_PWM_C_DT(250U);

			FILE *fid;
			char* pFilename;
			float time = 0.0f;
			uint16_t index=0;
			pFilename = "NyxOutput_newProblem.csv";  // Set Filename
			//
			// Open file for writing at pPath and write pMessage into it
			// then close file.
			//
			fid = fopen(pFilename, "w+");
			//fwrite(pMessage, sizeof(char), strlen(pMessage), fid);
			fprintf(fid, "%s,%s,"
					"%s,%s,"
					"%s,%s,"
					"%s,%s,"
					"%s,%s,"
					"%s,%s,"
					"%s,%s,"
					"%s,%s,"
					"%s,%s,"
					"%s,%s,"
					"%s,%s,"
					"%s,%s,"
					"%s,%s,"
					"%s,%s\n",
					"time","qSoll",
					"Sig_Ic", "adcBuffer_0",
					"adcBuffer_1", "dbgPI_d_Integrator",
					"dbgPI_q_Integrator","Sig_Va_m",
					"Sig_Vb_m","KpQ",
					"KpD","Sig_Vgamma_m",
					"Sig_Vqsatu_m","Sig_Vdsatu_m",
					"Sig_qAxis_m","Sig_dAxis_m",
					"Sig_Valpha_m","Sig_Vbeta_m",
					"Sig_theta_el_m","Sig_qAxis_PI_out",
					"Sig_dAxis_PI_out","adcCalV0",
					"adcCalV1","Duty",
					"PWM_A","PWM_B",
					"PWM_C","EncoderCounter");

			for(int k=dbg_obj.k+1; k<=(MAX_DBG_BUFFERSIZE-1); k++) {
				  fprintf(fid, "%.4f,%i,"
						  "%f,%i,"
						  "%i,%f,"
						  "%f,%f,"
						  "%f,%i,"
						  "%i,%f,"
						  "%f,%f,"
						  "%f,%f,"
						  "%f,%f,"
						  "%f,%f,"
						  "%f,%i,"
						  "%i,%i,"
						  "%i,%i,"
						  "%i,%i\n",
						  time, dbg_obj.dbgqSoll[k],
						  dbg_obj.dbgSig_Ic[k], dbg_obj.dbgadcBuffer_0[k],
						  dbg_obj.dbgadcBuffer_1[k], dbg_obj.dbgPI_d_Integrator[k],
						  dbg_obj.dbgPI_q_Integrator[k],dbg_obj.dbgSig_Va_m[k],
						  dbg_obj.dbgSig_Vb_m[k],dbg_obj.dbgKpq[k],
						  dbg_obj.dbgKpd[k],dbg_obj.dbgSig_Vgamma_m[k],
						  dbg_obj.dbgSig_Vqsatu_m[k],dbg_obj.dbgSig_Vdsatu_m[k],
						  dbg_obj.dbgSig_qAxis_m[k],dbg_obj.dbgSig_dAxis_m[k],
						  dbg_obj.dbgSig_Valpha_m[k],dbg_obj.dbgSig_Vbeta_m[k],
						  dbg_obj.dbgSig_theta_el_m[k],dbg_obj.dbgSig_qAxis_PI_out[k],
						  dbg_obj.dbgSig_dAxis_PI_out[k],autoCalADCVal[0],
						  autoCalADCVal[1],dbg_obj.dbgDuty[k],
						  dbg_obj.dbgPWM_A[k],dbg_obj.dbgPWM_B[k],
						  dbg_obj.dbgPWM_C[k],dbg_obj.dbgEncoder[k]);
				  time+=0.0002f;
			  }

			for(int k=0;k<=dbg_obj.k; k++) {
			  				  fprintf(fid, "%.4f,%i,"
			  						  "%f,%i,"
			  						  "%i,%f,"
			  						  "%f,%f,"
			  						  "%f,%i,"
			  						  "%i,%f,"
			  						  "%f,%f,"
			  						  "%f,%f,"
			  						  "%f,%f,"
			  						  "%f,%f,"
			  						  "%f,%i,"
			  						  "%i,%i,"
			  						  "%i,%i,"
			  						  "%i,%i\n",
									  time, dbg_obj.dbgqSoll[k],
									  dbg_obj.dbgSig_Ic[k], dbg_obj.dbgadcBuffer_0[k],
									  dbg_obj.dbgadcBuffer_1[k], dbg_obj.dbgPI_d_Integrator[k],
									  dbg_obj.dbgPI_q_Integrator[k],dbg_obj.dbgSig_Va_m[k],
									  dbg_obj.dbgSig_Vb_m[k],dbg_obj.dbgKpq[k],
									  dbg_obj.dbgKpd[k],dbg_obj.dbgSig_Vgamma_m[k],
									  dbg_obj.dbgSig_Vqsatu_m[k],dbg_obj.dbgSig_Vdsatu_m[k],
									  dbg_obj.dbgSig_qAxis_m[k],dbg_obj.dbgSig_dAxis_m[k],
									  dbg_obj.dbgSig_Valpha_m[k],dbg_obj.dbgSig_Vbeta_m[k],
									  dbg_obj.dbgSig_theta_el_m[k],dbg_obj.dbgSig_qAxis_PI_out[k],
									  dbg_obj.dbgSig_dAxis_PI_out[k],0,
									  0,dbg_obj.dbgDuty[k],
									  dbg_obj.dbgPWM_A[k],dbg_obj.dbgPWM_B[k],
									  dbg_obj.dbgPWM_C[k],dbg_obj.dbgEncoder[k]);
			  	  time+=0.0002f;
			  }

			fclose(fid);

			while(1) { /* Trap software after logging data */ }

#endif
}
#endif
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
