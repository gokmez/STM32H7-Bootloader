#include "flash.h"

HAL_StatusTypeDef erase_app_memory(uint32_t bank, uint32_t sector, uint32_t NbSectors){
	
	HAL_StatusTypeDef ret;
	FLASH_EraseInitTypeDef EraseInitStruct;
	uint32_t SectorError;
	
	HAL_FLASH_Unlock();
	
	EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;
	EraseInitStruct.Banks = bank;
	EraseInitStruct.Sector = sector;
	EraseInitStruct.NbSectors = NbSectors;
	EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;

	ret = HAL_FLASHEx_Erase( &EraseInitStruct, &SectorError );

	HAL_FLASH_Lock();
	return ret;
}


HAL_StatusTypeDef Flash_write32B(uint8_t const *src, uint32_t dst){
    uint32_t FlashAddress = dst;

    if (FlashAddress & (32-1)) {
        return HAL_ERROR; // bad alignment
    }
	
	HAL_StatusTypeDef ret;
	
	HAL_FLASH_Unlock();
	
	ret = HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, FlashAddress, (uint32_t)src);

	HAL_FLASH_Lock();

	return ret;
	
}

