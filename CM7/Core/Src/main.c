/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "fatfs.h"
#include "quadspi.h"
#include "sdmmc.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "flash.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
static void gotoFirmware(uint32_t fwFlashStartAdd);
bool updateFirmware(const TCHAR* fwPath, uint32_t flashBank, uint32_t flashSector, uint32_t NbSectors, uint32_t fwFlashStartAdd);
bool updateExternalFlash(const TCHAR* fwPath);
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#ifndef HSEM_ID_0
#define HSEM_ID_0 (0U) /* HW semaphore 0*/
#endif

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* SD card parameters */
#define SD_CARD_PATH "/"
#define FILE_NAME "CM7.bin"
#define FILE_NAME_2 "CM4.bin"
#define FILE_NAME_3 "QSPI.bin"

/* Buffer size for reading data */
#define BUFFER_SIZE 512

#define FW_CM7_START_ADD 0x08020000
#define FW_CM4_START_ADD 0x08100000

typedef void (*pFunction)(void);


/**
  * @brief Jump to application from the Bootloader
  * @retval None
  */
static void gotoFirmware(uint32_t fwFlashStartAdd)
{
//  void (*app_reset_handler)(void) = (void*)(*((volatile uint32_t*) (0x08040000 + 4U)));
//
//  //__set_MSP(*(volatile uint32_t*) 0x08040000);
//  app_reset_handler();    //call the app reset handler

//	SCB_DisableDCache();
//
//	SCB_DisableICache();
//
//	HAL_MPU_Disable();
//
//	HAL_SuspendTick();
//
//	__disable_irq(); //disable interrupt
//
//	SysTick->CTRL = 0;  // Enabled in application
//	SysTick->LOAD = 0;
//	SysTick->VAL  = 0;
//
//	HAL_RCC_DeInit();
//
//	for(uint8_t i = 0; i < 8; i++) //clear all NVIC Enable and Pending registers
//	{
//	  NVIC->ICER[i]=0xFFFFFFFF;
//	  NVIC->ICPR[i]=0xFFFFFFFF;
//	}
//
//	__enable_irq();

//	void (*app_reset_handler)(void) = (void*)(*((volatile uint32_t*) (0x08040000 + 4U)));
//	__set_MSP(*(__IO uint32_t*) 0x08040000);
//
//	__set_CONTROL(0); //priviage mode
//	__set_PRIMASK(1);
//
//	SCB->VTOR = 0x08040000;
//
//	app_reset_handler();

	pFunction appEntry;
	uint32_t appStack;

	appStack = (uint32_t) *((__IO uint32_t*)fwFlashStartAdd);
	appEntry = (pFunction) *(__IO uint32_t*) (fwFlashStartAdd + 4);
//	__DMB();
	SCB->VTOR = fwFlashStartAdd;
//	__DSB();
//	SysTick->CTRL = 0x0;
//	HAL_DeInit();
	__set_MSP(appStack);
	appEntry();
}


bool updateFirmware(const TCHAR* fwPath, uint32_t flashBank, uint32_t flashSector, uint32_t NbSectors, uint32_t fwFlashStartAdd)
{
	uint8_t binFileRes[50], readBytes[BUFFER_SIZE];
	UINT bytesRead;
	FSIZE_t file_size;
	FIL file;
	uint32_t flashAdd, addCNTR;

	if (f_open(&file, fwPath, FA_READ) == FR_OK) {

		file_size = f_size(&file);

		sprintf(binFileRes, ".bin Size: %lu bytes \n\r", file_size);
		HAL_UART_Transmit(&huart1, binFileRes, 20, 100);

		erase_app_memory(flashBank, flashSector, NbSectors);

		flashAdd = fwFlashStartAdd;
		addCNTR  = 0;

		while (f_read(&file, readBytes, BUFFER_SIZE, &bytesRead) == FR_OK && bytesRead > 0) {
			// Process the read data here
			for(uint32_t i=0; i<16; i++){
				Flash_write32B(readBytes+(i*32), flashAdd+addCNTR);
				addCNTR += 32;
			}
			memset(readBytes, 0xFF, sizeof(readBytes));
		}
		f_close(&file);
	}

	return true;
}


bool updateExternalFlash(const TCHAR* fwPath)
{
	uint8_t binFileRes[50], readBytes[BUFFER_SIZE];
	UINT bytesRead;
	FSIZE_t file_size;
	FIL file;
	uint32_t addCNTR;

	if (f_open(&file, fwPath, FA_READ) == FR_OK) {

		file_size = f_size(&file);

		sprintf(binFileRes, ".bin Size: %lu bytes \n\r", file_size);
		HAL_UART_Transmit(&huart1, binFileRes, 20, 100);

		if (CSP_QSPI_Erase_Chip() != HAL_OK)
		{
			Error_Handler();
		}

		addCNTR  = 0;

		while (f_read(&file, readBytes, BUFFER_SIZE, &bytesRead) == FR_OK && bytesRead > 0) {
			// Process the read data here

			if (CSP_QSPI_WriteMemory(readBytes, addCNTR, sizeof(readBytes)) != HAL_OK)
			{
				Error_Handler();
			}

			addCNTR += BUFFER_SIZE;
			memset(readBytes, 0xFF, sizeof(readBytes));
		}
		f_close(&file);
	}

	return true;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int boot_main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
/* USER CODE BEGIN Boot_Mode_Sequence_0 */
  int32_t timeout;
/* USER CODE END Boot_Mode_Sequence_0 */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

/* USER CODE BEGIN Boot_Mode_Sequence_1 */
  /* Wait until CPU2 boots and enters in stop mode or timeout*/
  timeout = 0xFFFF;
  while((__HAL_RCC_GET_FLAG(RCC_FLAG_D2CKRDY) != RESET) && (timeout-- > 0));
  if ( timeout < 0 )
  {
  	Error_Handler();
  }
/* USER CODE END Boot_Mode_Sequence_1 */
  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();
/* USER CODE BEGIN Boot_Mode_Sequence_2 */
/* When system initialization is finished, Cortex-M7 will release Cortex-M4 by means of
HSEM notification */
/*HW semaphore Clock enable*/
__HAL_RCC_HSEM_CLK_ENABLE();
/*Take HSEM */
HAL_HSEM_FastTake(HSEM_ID_0);
/*Release HSEM in order to notify the CPU2(CM4)*/
HAL_HSEM_Release(HSEM_ID_0,0);
/* wait until CPU2 wakes up from stop mode */
timeout = 0xFFFF;
while((__HAL_RCC_GET_FLAG(RCC_FLAG_D2CKRDY) == RESET) && (timeout-- > 0));
if ( timeout < 0 )
{
	Error_Handler();
}
/* USER CODE END Boot_Mode_Sequence_2 */

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_QUADSPI_Init();
  MX_SDMMC1_SD_Init();
  MX_FATFS_Init();
  /* USER CODE BEGIN 2 */

//	HAL_Delay(5000);

	if (CSP_QUADSPI_Init() != HAL_OK)
	{
		Error_Handler();
	}

  // Mount the SD card
  FATFS fs;
  uint8_t mountRes;

  mountRes = f_mount(&fs, SD_CARD_PATH, 1);
  if (mountRes == FR_OK) {

  	// UPDATE CM7 FLASH REGION
	  updateFirmware(FILE_NAME, FLASH_BANK_1, FLASH_SECTOR_1, 7, FW_CM7_START_ADD);

	  // UPDATE CM4 FLASH REGION
	  updateFirmware(FILE_NAME_2, FLASH_BANK_2, FLASH_SECTOR_0, 8, FW_CM4_START_ADD);

	  // UPDATE QSPI
	  updateExternalFlash(FILE_NAME_3);
  }
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);

	// JUMP TO THE NEW APPLICATON
  gotoFirmware(FW_CM7_START_ADD);
  /* USER CODE END 2 */

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

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48|RCC_OSCILLATORTYPE_HSI
                              |RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 160;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSI, RCC_MCODIV_1);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

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
