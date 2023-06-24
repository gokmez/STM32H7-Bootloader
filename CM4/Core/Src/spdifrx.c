/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    spdifrx.c
  * @brief   This file provides code for the configuration
  *          of the SPDIFRX instances.
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
/* Includes ------------------------------------------------------------------*/
#include "spdifrx.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

SPDIFRX_HandleTypeDef hspdif1;

/* SPDIFRX1 init function */
void MX_SPDIFRX1_Init(void)
{

  /* USER CODE BEGIN SPDIFRX1_Init 0 */

  /* USER CODE END SPDIFRX1_Init 0 */

  /* USER CODE BEGIN SPDIFRX1_Init 1 */

  /* USER CODE END SPDIFRX1_Init 1 */
  hspdif1.Instance = SPDIFRX;
  hspdif1.Init.InputSelection = SPDIFRX_INPUT_IN0;
  hspdif1.Init.Retries = SPDIFRX_MAXRETRIES_NONE;
  hspdif1.Init.WaitForActivity = SPDIFRX_WAITFORACTIVITY_OFF;
  hspdif1.Init.ChannelSelection = SPDIFRX_CHANNEL_A;
  hspdif1.Init.DataFormat = SPDIFRX_DATAFORMAT_LSB;
  hspdif1.Init.StereoMode = SPDIFRX_STEREOMODE_DISABLE;
  hspdif1.Init.PreambleTypeMask = SPDIFRX_PREAMBLETYPEMASK_OFF;
  hspdif1.Init.ChannelStatusMask = SPDIFRX_CHANNELSTATUS_OFF;
  hspdif1.Init.ValidityBitMask = SPDIFRX_VALIDITYMASK_OFF;
  hspdif1.Init.ParityErrorMask = SPDIFRX_PARITYERRORMASK_OFF;
  hspdif1.Init.SymbolClockGen = DISABLE;
  hspdif1.Init.BackupSymbolClockGen = DISABLE;
  if (HAL_SPDIFRX_Init(&hspdif1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPDIFRX1_Init 2 */

  /* USER CODE END SPDIFRX1_Init 2 */

}

void HAL_SPDIFRX_MspInit(SPDIFRX_HandleTypeDef* spdifrxHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(spdifrxHandle->Instance==SPDIFRX)
  {
  /* USER CODE BEGIN SPDIFRX_MspInit 0 */

  /* USER CODE END SPDIFRX_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SPDIFRX;
    PeriphClkInitStruct.SpdifrxClockSelection = RCC_SPDIFRXCLKSOURCE_PLL;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* SPDIFRX clock enable */
    __HAL_RCC_SPDIFRX_CLK_ENABLE();

    __HAL_RCC_GPIOD_CLK_ENABLE();
    /**SPDIFRX1 GPIO Configuration
    PD7     ------> SPDIFRX1_IN0
    */
    GPIO_InitStruct.Pin = SPDIF_RX0_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF9_SPDIF;
    HAL_GPIO_Init(SPDIF_RX0_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN SPDIFRX_MspInit 1 */

  /* USER CODE END SPDIFRX_MspInit 1 */
  }
}

void HAL_SPDIFRX_MspDeInit(SPDIFRX_HandleTypeDef* spdifrxHandle)
{

  if(spdifrxHandle->Instance==SPDIFRX)
  {
  /* USER CODE BEGIN SPDIFRX_MspDeInit 0 */

  /* USER CODE END SPDIFRX_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_SPDIFRX_CLK_DISABLE();

    /**SPDIFRX1 GPIO Configuration
    PD7     ------> SPDIFRX1_IN0
    */
    HAL_GPIO_DeInit(SPDIF_RX0_GPIO_Port, SPDIF_RX0_Pin);

  /* USER CODE BEGIN SPDIFRX_MspDeInit 1 */

  /* USER CODE END SPDIFRX_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
