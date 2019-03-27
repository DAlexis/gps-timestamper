/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

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
#define Signal_Pin GPIO_PIN_0
#define Signal_GPIO_Port GPIOA
#define PPS_Pin GPIO_PIN_1
#define PPS_GPIO_Port GPIOA
#define TAG_USART2_TX_Pin GPIO_PIN_2
#define TAG_USART2_TX_GPIO_Port GPIOA
#define TAG_USART2_RX_Pin GPIO_PIN_3
#define TAG_USART2_RX_GPIO_Port GPIOA
#define DAC_treshold_03_Pin GPIO_PIN_4
#define DAC_treshold_03_GPIO_Port GPIOA
#define DAC_treshold_47_Pin GPIO_PIN_5
#define DAC_treshold_47_GPIO_Port GPIOA
#define LED_ch7_Pin GPIO_PIN_7
#define LED_ch7_GPIO_Port GPIOE
#define LED_2_Pin GPIO_PIN_12
#define LED_2_GPIO_Port GPIOD
#define LED_3_Pin GPIO_PIN_13
#define LED_3_GPIO_Port GPIOD
#define LED_4_Pin GPIO_PIN_14
#define LED_4_GPIO_Port GPIOD
#define Sound_pin_Pin GPIO_PIN_15
#define Sound_pin_GPIO_Port GPIOD
#define JSON_OUTPUT_USART1_TX_Pin GPIO_PIN_9
#define JSON_OUTPUT_USART1_TX_GPIO_Port GPIOA
#define JSON_OUTPUT_USART1_RX_Pin GPIO_PIN_10
#define JSON_OUTPUT_USART1_RX_GPIO_Port GPIOA
#define Sig_ch0_Pin GPIO_PIN_0
#define Sig_ch0_GPIO_Port GPIOD
#define Sig_ch1_Pin GPIO_PIN_1
#define Sig_ch1_GPIO_Port GPIOD
#define Sig_ch2_Pin GPIO_PIN_2
#define Sig_ch2_GPIO_Port GPIOD
#define SIg_ch3_Pin GPIO_PIN_3
#define SIg_ch3_GPIO_Port GPIOD
#define Sig_ch4_Pin GPIO_PIN_4
#define Sig_ch4_GPIO_Port GPIOD
#define Sig_ch5_Pin GPIO_PIN_5
#define Sig_ch5_GPIO_Port GPIOD
#define Sig_ch6_Pin GPIO_PIN_6
#define Sig_ch6_GPIO_Port GPIOD
#define Sig_ch7_Pin GPIO_PIN_7
#define Sig_ch7_GPIO_Port GPIOD
#define LED_0_Pin GPIO_PIN_0
#define LED_0_GPIO_Port GPIOE
#define LED_1_Pin GPIO_PIN_1
#define LED_1_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
