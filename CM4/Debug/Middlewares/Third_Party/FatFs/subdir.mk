################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/UPWORK/WORKS/19.\ Custom\ Bootloader\ for\ STM32H7/2.\ Src/stm32h747i-bootloader/Middlewares/Third_Party/FatFs/src/diskio.c \
D:/UPWORK/WORKS/19.\ Custom\ Bootloader\ for\ STM32H7/2.\ Src/stm32h747i-bootloader/Middlewares/Third_Party/FatFs/src/ff.c \
D:/UPWORK/WORKS/19.\ Custom\ Bootloader\ for\ STM32H7/2.\ Src/stm32h747i-bootloader/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c \
D:/UPWORK/WORKS/19.\ Custom\ Bootloader\ for\ STM32H7/2.\ Src/stm32h747i-bootloader/Middlewares/Third_Party/FatFs/src/option/syscall.c 

OBJS += \
./Middlewares/Third_Party/FatFs/diskio.o \
./Middlewares/Third_Party/FatFs/ff.o \
./Middlewares/Third_Party/FatFs/ff_gen_drv.o \
./Middlewares/Third_Party/FatFs/syscall.o 

C_DEPS += \
./Middlewares/Third_Party/FatFs/diskio.d \
./Middlewares/Third_Party/FatFs/ff.d \
./Middlewares/Third_Party/FatFs/ff_gen_drv.d \
./Middlewares/Third_Party/FatFs/syscall.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FatFs/diskio.o: D:/UPWORK/WORKS/19.\ Custom\ Bootloader\ for\ STM32H7/2.\ Src/stm32h747i-bootloader/Middlewares/Third_Party/FatFs/src/diskio.c Middlewares/Third_Party/FatFs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32H747xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/Third_Party/FatFs/diskio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/Third_Party/FatFs/ff.o: D:/UPWORK/WORKS/19.\ Custom\ Bootloader\ for\ STM32H7/2.\ Src/stm32h747i-bootloader/Middlewares/Third_Party/FatFs/src/ff.c Middlewares/Third_Party/FatFs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32H747xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/Third_Party/FatFs/ff.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/Third_Party/FatFs/ff_gen_drv.o: D:/UPWORK/WORKS/19.\ Custom\ Bootloader\ for\ STM32H7/2.\ Src/stm32h747i-bootloader/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c Middlewares/Third_Party/FatFs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32H747xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/Third_Party/FatFs/ff_gen_drv.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/Third_Party/FatFs/syscall.o: D:/UPWORK/WORKS/19.\ Custom\ Bootloader\ for\ STM32H7/2.\ Src/stm32h747i-bootloader/Middlewares/Third_Party/FatFs/src/option/syscall.c Middlewares/Third_Party/FatFs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32H747xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/Third_Party/FatFs/syscall.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-FatFs

clean-Middlewares-2f-Third_Party-2f-FatFs:
	-$(RM) ./Middlewares/Third_Party/FatFs/diskio.cyclo ./Middlewares/Third_Party/FatFs/diskio.d ./Middlewares/Third_Party/FatFs/diskio.o ./Middlewares/Third_Party/FatFs/diskio.su ./Middlewares/Third_Party/FatFs/ff.cyclo ./Middlewares/Third_Party/FatFs/ff.d ./Middlewares/Third_Party/FatFs/ff.o ./Middlewares/Third_Party/FatFs/ff.su ./Middlewares/Third_Party/FatFs/ff_gen_drv.cyclo ./Middlewares/Third_Party/FatFs/ff_gen_drv.d ./Middlewares/Third_Party/FatFs/ff_gen_drv.o ./Middlewares/Third_Party/FatFs/ff_gen_drv.su ./Middlewares/Third_Party/FatFs/syscall.cyclo ./Middlewares/Third_Party/FatFs/syscall.d ./Middlewares/Third_Party/FatFs/syscall.o ./Middlewares/Third_Party/FatFs/syscall.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-FatFs

