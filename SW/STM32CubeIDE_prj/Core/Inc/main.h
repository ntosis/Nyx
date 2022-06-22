/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <math.h>
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
volatile uint8_t switch_dca_input;
static uint16_t  linear_equation(int16_t rtu_In1);
extern osThreadId_t ComputationINTHandle;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
static uint16_t linear_equation(int16_t rtu_In1)
 {
   int32_t tmp;

   tmp = (int32_t)fmodf((float)(int32_t)floorf((float)rtu_In1 * 0.00390625F
     * 40.96F + 2048.0F), 65536.0F);
   return (uint16_t)(tmp < 0 ? (int32_t)(int16_t)-(int16_t)(uint16_t)-(float)
                    tmp : (int32_t)(int16_t)(uint16_t)(float)tmp);
 }
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define CAL_PIN_Pin GPIO_PIN_0
#define CAL_PIN_GPIO_Port GPIOC
#define TestINT_Pin GPIO_PIN_1
#define TestINT_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define DRV_CS_Pin GPIO_PIN_6
#define DRV_CS_GPIO_Port GPIOA
#define DRV_ENABLE_Pin GPIO_PIN_7
#define DRV_ENABLE_GPIO_Port GPIOA
#define SOB_AI_Pin GPIO_PIN_1
#define SOB_AI_GPIO_Port GPIOB
#define DRV_INLA_Pin GPIO_PIN_10
#define DRV_INLA_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define DRV_INLC_Pin GPIO_PIN_5
#define DRV_INLC_GPIO_Port GPIOB
#define PWM_INHC_Pin GPIO_PIN_6
#define PWM_INHC_GPIO_Port GPIOB
#define DRV_INLB_Pin GPIO_PIN_7
#define DRV_INLB_GPIO_Port GPIOB
#define PWM_INHA_Pin GPIO_PIN_8
#define PWM_INHA_GPIO_Port GPIOB
#define PWM_INHB_Pin GPIO_PIN_9
#define PWM_INHB_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
