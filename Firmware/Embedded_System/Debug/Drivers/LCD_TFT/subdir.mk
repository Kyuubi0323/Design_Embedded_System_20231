################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/LCD_TFT/font.c \
../Drivers/LCD_TFT/lcd.c \
../Drivers/LCD_TFT/touch.c 

OBJS += \
./Drivers/LCD_TFT/font.o \
./Drivers/LCD_TFT/lcd.o \
./Drivers/LCD_TFT/touch.o 

C_DEPS += \
./Drivers/LCD_TFT/font.d \
./Drivers/LCD_TFT/lcd.d \
./Drivers/LCD_TFT/touch.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/LCD_TFT/%.o Drivers/LCD_TFT/%.su Drivers/LCD_TFT/%.cyclo: ../Drivers/LCD_TFT/%.c Drivers/LCD_TFT/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I../Drivers/MAX30102 -I../Drivers/LCD_TFT -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-LCD_TFT

clean-Drivers-2f-LCD_TFT:
	-$(RM) ./Drivers/LCD_TFT/font.cyclo ./Drivers/LCD_TFT/font.d ./Drivers/LCD_TFT/font.o ./Drivers/LCD_TFT/font.su ./Drivers/LCD_TFT/lcd.cyclo ./Drivers/LCD_TFT/lcd.d ./Drivers/LCD_TFT/lcd.o ./Drivers/LCD_TFT/lcd.su ./Drivers/LCD_TFT/touch.cyclo ./Drivers/LCD_TFT/touch.d ./Drivers/LCD_TFT/touch.o ./Drivers/LCD_TFT/touch.su

.PHONY: clean-Drivers-2f-LCD_TFT

