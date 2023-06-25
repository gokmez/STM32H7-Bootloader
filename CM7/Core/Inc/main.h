/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32h7xx_hal.h"

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
#define QSPI_BK2_IO2_Pin GPIO_PIN_9
#define QSPI_BK2_IO2_GPIO_Port GPIOG
#define SDIO1_D2_Pin GPIO_PIN_10
#define SDIO1_D2_GPIO_Port GPIOC
#define OSC32_OUT_Pin GPIO_PIN_15
#define OSC32_OUT_GPIO_Port GPIOC
#define OSC32_IN_Pin GPIO_PIN_14
#define OSC32_IN_GPIO_Port GPIOC
#define SDIO1_CK_Pin GPIO_PIN_12
#define SDIO1_CK_GPIO_Port GPIOC
#define QSPI_BK2_IO3_Pin GPIO_PIN_14
#define QSPI_BK2_IO3_GPIO_Port GPIOG
#define SDIO1_CMD_Pin GPIO_PIN_2
#define SDIO1_CMD_GPIO_Port GPIOD
#define STLINK_TX_Pin GPIO_PIN_10
#define STLINK_TX_GPIO_Port GPIOA
#define STLINK_RX_Pin GPIO_PIN_9
#define STLINK_RX_GPIO_Port GPIOA
#define uSD_Detect_Pin GPIO_PIN_8
#define uSD_Detect_GPIO_Port GPIOI
#define SDIO1_D0_Pin GPIO_PIN_8
#define SDIO1_D0_GPIO_Port GPIOC
#define CEC_CK_MCO1_Pin GPIO_PIN_8
#define CEC_CK_MCO1_GPIO_Port GPIOA
#define QSPI_BK1_NCS_Pin GPIO_PIN_6
#define QSPI_BK1_NCS_GPIO_Port GPIOG
#define LED1_Pin GPIO_PIN_12
#define LED1_GPIO_Port GPIOI
#define LED2_Pin GPIO_PIN_13
#define LED2_GPIO_Port GPIOI
#define OSC_OUT_Pin GPIO_PIN_1
#define OSC_OUT_GPIO_Port GPIOH
#define OSC_IN_Pin GPIO_PIN_0
#define OSC_IN_GPIO_Port GPIOH
#define QSPI_BK1_IO3_Pin GPIO_PIN_6
#define QSPI_BK1_IO3_GPIO_Port GPIOF
#define QSPI_BK1_IO2_Pin GPIO_PIN_7
#define QSPI_BK1_IO2_GPIO_Port GPIOF
#define QSPI_BK1_IO1_Pin GPIO_PIN_9
#define QSPI_BK1_IO1_GPIO_Port GPIOF
#define QSPI_BK2_IO0_Pin GPIO_PIN_2
#define QSPI_BK2_IO0_GPIO_Port GPIOH
#define QSPI_BK2_IO1_Pin GPIO_PIN_3
#define QSPI_BK2_IO1_GPIO_Port GPIOH
#define QSPI_CLK_Pin GPIO_PIN_2
#define QSPI_CLK_GPIO_Port GPIOB
#define QSPI_BK1_IO0_Pin GPIO_PIN_11
#define QSPI_BK1_IO0_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
