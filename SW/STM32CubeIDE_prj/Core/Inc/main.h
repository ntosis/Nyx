/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern uint16_t adcBuffer[3];
extern osThreadId_t ComputationINTHandle;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TestPinC13_Pin GPIO_PIN_13
#define TestPinC13_GPIO_Port GPIOC
#define SOA_AI_Pin GPIO_PIN_0
#define SOA_AI_GPIO_Port GPIOA
#define SOB_AI_Pin GPIO_PIN_1
#define SOB_AI_GPIO_Port GPIOA
#define SOC_AI_Pin GPIO_PIN_2
#define SOC_AI_GPIO_Port GPIOA
#define DRV_CS_Pin GPIO_PIN_4
#define DRV_CS_GPIO_Port GPIOA
#define DRV_INHA_Pin GPIO_PIN_0
#define DRV_INHA_GPIO_Port GPIOB
#define DRV_INLA_Pin GPIO_PIN_1
#define DRV_INLA_GPIO_Port GPIOB
#define DRV_INHB_Pin GPIO_PIN_2
#define DRV_INHB_GPIO_Port GPIOB
#define DRV_ENABLE_Pin GPIO_PIN_9
#define DRV_ENABLE_GPIO_Port GPIOA
#define DRV_NFAULT_Pin GPIO_PIN_10
#define DRV_NFAULT_GPIO_Port GPIOA
#define DRV_INLB_Pin GPIO_PIN_3
#define DRV_INLB_GPIO_Port GPIOB
#define DRV_INHC_Pin GPIO_PIN_4
#define DRV_INHC_GPIO_Port GPIOB
#define DRV_INLC_Pin GPIO_PIN_5
#define DRV_INLC_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
