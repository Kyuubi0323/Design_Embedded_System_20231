################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Startup/ringbuf/UartRingbuffer.c 

OBJS += \
./Core/Startup/ringbuf/UartRingbuffer.o 

C_DEPS += \
./Core/Startup/ringbuf/UartRingbuffer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/ringbuf/%.o Core/Startup/ringbuf/%.su Core/Startup/ringbuf/%.cyclo: ../Core/Startup/ringbuf/%.c Core/Startup/ringbuf/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Admin/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I../Drivers/ili9341 -I"D:/Advance_Kyuubi_Main_1S/MANDEVICES/Git_clone/Design_Embedded_System_20231/Firmware/Embedded_System/Core/Startup/ili9341" -I"D:/Advance_Kyuubi_Main_1S/MANDEVICES/Git_clone/Design_Embedded_System_20231/Firmware/Embedded_System/Core/Startup/max30102" -I"D:/Advance_Kyuubi_Main_1S/MANDEVICES/Git_clone/Design_Embedded_System_20231/Firmware/Embedded_System/Core/Startup/ringbuf" -I"D:/Advance_Kyuubi_Main_1S/MANDEVICES/Git_clone/Design_Embedded_System_20231/Firmware/Embedded_System/Core/Startup/delay_timer" -I"D:/Advance_Kyuubi_Main_1S/MANDEVICES/Git_clone/Design_Embedded_System_20231/Firmware/Embedded_System/Core/Startup/dht11" -I"D:/Advance_Kyuubi_Main_1S/MANDEVICES/Git_clone/Design_Embedded_System_20231/Firmware/Embedded_System/Core/Startup/common" -I"D:/Advance_Kyuubi_Main_1S/MANDEVICES/Git_clone/Design_Embedded_System_20231/Firmware/Embedded_System/Core/Startup/ds18b20" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Startup-2f-ringbuf

clean-Core-2f-Startup-2f-ringbuf:
	-$(RM) ./Core/Startup/ringbuf/UartRingbuffer.cyclo ./Core/Startup/ringbuf/UartRingbuffer.d ./Core/Startup/ringbuf/UartRingbuffer.o ./Core/Startup/ringbuf/UartRingbuffer.su

.PHONY: clean-Core-2f-Startup-2f-ringbuf

