/*
This is for FLASH register address and some flash functions
*/
#ifndef FLASH_H
#define FLASH_H

#include <stdint.h>
#include "stm32h7xx_hal.h"

HAL_StatusTypeDef erase_app_memory(uint32_t bank, uint32_t sector, uint32_t NbSectors);
HAL_StatusTypeDef Flash_write32B(uint8_t const *src, uint32_t dst);

#endif
