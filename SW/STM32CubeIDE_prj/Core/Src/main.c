/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "dac.h"
#include "dma.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */


#include "InterfaceBswApp.h"
#include "limits.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
volatile uint16_t ICValueFalling=0;
volatile uint16_t ICValueRising=0;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define  ARM_CM_DEMCR      (*(uint32_t *)0xE000EDFC)

#define  ARM_CM_DWT_CTRL   (*(uint32_t *)0xE0001000)

#define  ARM_CM_DWT_CYCCNT (*(uint32_t *)0xE0001004)
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
extern void initialise_monitor_handles(void);
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
static void MX_NVIC_Init(void);
/* USER CODE BEGIN PFP */
volatile uint16_t adcBuffer[3]; // Buffer for store the results of the ADC conversion
int16_t autoCalADCVal[2];
volatile uint16_t Duty;
uint32_t PWMICTimerSpeed;
volatile uint8_t switch_dca_input=0;
RCC_ClkInitTypeDef ClockInfos;
uint8_t zero=0;
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

  /* USER CODE BEGIN Init */
  DebugCntr = ((uint32_t*) 0xE0001004);
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  //MX_DMA_Init();
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_DMA_Init();
  MX_TIM8_Init();
  MX_ADC2_Init();
  MX_DAC_Init();
  MX_TIM4_Init();
  MX_SPI2_Init();

  /* Initialize interrupts */
  MX_NVIC_Init();
  /* USER CODE BEGIN 2 */
  SET_BIT(htim8.Instance->CR1,TIM_CR1_URS); //Set timer overflow as interrupt source.
  MotorControlLib_initialize();
  ConvertPWMtoAngle(&zero);
  //PWMICTimerSpeed = CalculateTimerSpeedForPWMInput(&htim8); /* Todo check the correct clock to be used for pwm IC*/
#ifdef SEMIHOSTING
  initialise_monitor_handles(); /* Semihosting specific*/
#endif
  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();  /* Call init function for freertos objects (in freertos.c) */
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 120;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief NVIC Configuration.
  * @retval None
  */
static void MX_NVIC_Init(void)
{
  /* TIM3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(TIM3_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(TIM3_IRQn);
  /* TIM8_CC_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(TIM8_CC_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(TIM8_CC_IRQn);
}

/* USER CODE BEGIN 4 */
 void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{

	 if (htim->Instance == TIM8) {

		 static uint8_t isTheFirstRisingEdgeAfterReset=1U;
		 float resDiv=0.0f;
		 uint16_t Dutytmp;

		 Dutytmp = Duty; //store old value for more security.

		 if ((htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)&(isTheFirstRisingEdgeAfterReset))  //rising edge after reset
		 	 {

			 isTheFirstRisingEdgeAfterReset = 0U; // Reset State


			 Duty = 0U;
		}
		else if ((htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)&(!(isTheFirstRisingEdgeAfterReset))) { // rising edge

			hasTimer8Overflowed = 0U;
			ICValueRising = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1); //measures all the pulse time on + off,add on for the first clock
			ICValueFalling = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2); //check if it is the first read

			if(ICValueRising < ICValueFalling) {

				// pwm input is not valid, set a pulse to see it in logic analyser.
			  	HAL_GPIO_WritePin(TestINT_GPIO_Port, TestINT_Pin,GPIO_PIN_SET);
				Duty = Dutytmp; //use the old value
				hasMathOverflowed_PWMin = 1U;
				countWrongSignals++;
				for (int i=0;i<50;i++){
					asm("nop");
				}
				HAL_GPIO_WritePin(TestINT_GPIO_Port, TestINT_Pin,GPIO_PIN_RESET);
				return;
			}
			else {
			//signal is valid

				if(ICValueRising != 0) {
				//avoid divion with zero
				   resDiv = ((float)ICValueFalling)/((float)ICValueRising);
				   Duty = (uint16_t)(resDiv * 4096.0f);

				}
				else {
					// division with zero could occurred

					hasMathOverflowed_PWMin = 1U;
					Duty = Dutytmp; //use the old value
					return;
				}

			}

		}

		else if ((htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)&(!(isTheFirstRisingEdgeAfterReset))) {// falling edge
			/* ICValueRising = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1); //measures all the pulse time on + off,add on for the first clock
			ICValueFalling = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2); //check if it is the first read

			 eq : Duty = ((ICValueRising - ICValueFalling) * 100)/4096;
			* uint32 is a long integer in this configuration.
			if (__builtin_usubl_overflow(ICValueRising,ICValueFalling,&resSub))  {
			    // overflowed
			    Duty = 0;
			    hasMathOverflowed_PWMin = 1;
			}
			else {

				if (__builtin_umull_overflow(resSub,4096,&resMul)) {
					// overflowed
					Duty = 0;
					hasMathOverflowed_PWMin = 1;
				}
				else {
					// if we reach this, we have the correct result.
					Duty = (uint16_t)(resMul/ICValueRising);
				}

			}
		*/}
		 // trap, should never occur
		 if(Duty>4096) {
			 qSoll=0;
			 set_PWM_A_DT(250U);
			 set_PWM_B_DT(250U);
			 set_PWM_C_DT(250U);
			 while(1){}
		 }
	 }
	 else { // not TIM8

		 //nothing to do
	 }
}

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
	  	  BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	  	  vTaskNotifyGiveFromISR(ComputationINTHandle,&xHigherPriorityTaskWoken);
	  	  portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
  }

  if(htim->Instance==TIM8) {

	  static uint32_t res=0U;
	  float resDiv=0.0f;

	  if (hasTimer8Overflowed < UINT8_MAX) {
		    hasTimer8Overflowed ++;
	  }

		ICValueRising = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1); //measures all the pulse time on + off,add on for the first clock
		ICValueFalling = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2); //check if it is the first read

		/* eq : Duty = ((ICValueRising - ICValueFalling) * 100)/4096;
		* uint32 is a long integer in this configuration. */
		if (__builtin_usubl_overflow(ICValueRising,ICValueFalling,&res))  {
			// overflowed

			Duty = 0;

			hasMathOverflowed_PWMin = 1;
		}
		else {

			if(ICValueRising != 0) {
				//avoid divion with zero
				resDiv = ((float)ICValueFalling)/((float)ICValueRising);
				Duty = (uint16_t)(resDiv * 4096.0f);
			}
			else {
				//do nothing
			}
		}

		if (hasTimer8Overflowed > 10) { // too many overflows, signal is not present.
			Duty = 0;
			NoSignal_PWMin = 1;
		}
		else if(hasTimer8Overflowed < 10) {
			NoSignal_PWMin = 0;
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
  __disable_irq();
  while (1)
  {
  }

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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
