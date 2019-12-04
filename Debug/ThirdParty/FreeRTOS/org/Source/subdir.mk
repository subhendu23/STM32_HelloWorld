################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/FreeRTOS/org/Source/croutine.c \
../ThirdParty/FreeRTOS/org/Source/event_groups.c \
../ThirdParty/FreeRTOS/org/Source/list.c \
../ThirdParty/FreeRTOS/org/Source/queue.c \
../ThirdParty/FreeRTOS/org/Source/stream_buffer.c \
../ThirdParty/FreeRTOS/org/Source/tasks.c \
../ThirdParty/FreeRTOS/org/Source/timers.c 

OBJS += \
./ThirdParty/FreeRTOS/org/Source/croutine.o \
./ThirdParty/FreeRTOS/org/Source/event_groups.o \
./ThirdParty/FreeRTOS/org/Source/list.o \
./ThirdParty/FreeRTOS/org/Source/queue.o \
./ThirdParty/FreeRTOS/org/Source/stream_buffer.o \
./ThirdParty/FreeRTOS/org/Source/tasks.o \
./ThirdParty/FreeRTOS/org/Source/timers.o 

C_DEPS += \
./ThirdParty/FreeRTOS/org/Source/croutine.d \
./ThirdParty/FreeRTOS/org/Source/event_groups.d \
./ThirdParty/FreeRTOS/org/Source/list.d \
./ThirdParty/FreeRTOS/org/Source/queue.d \
./ThirdParty/FreeRTOS/org/Source/stream_buffer.d \
./ThirdParty/FreeRTOS/org/Source/tasks.d \
./ThirdParty/FreeRTOS/org/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/FreeRTOS/org/Source/%.o: ../ThirdParty/FreeRTOS/org/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -I"D:/FreeRTOS/FreeRTOS_WKSPACE/STM32_HelloWorld/StdPeriph_Driver/inc" -I"D:/FreeRTOS/FreeRTOS_WKSPACE/STM32_HelloWorld/ThirdParty/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"D:/FreeRTOS/FreeRTOS_WKSPACE/STM32_HelloWorld/ThirdParty/FreeRTOS/org/Source/portable" -I"D:/FreeRTOS/FreeRTOS_WKSPACE/STM32_HelloWorld/Config" -I"D:/FreeRTOS/FreeRTOS_WKSPACE/STM32_HelloWorld/ThirdParty/FreeRTOS/org/Source/portable/MemMang" -I"D:/FreeRTOS/FreeRTOS_WKSPACE/STM32_HelloWorld/ThirdParty/FreeRTOS/org/Source/include" -I"D:/FreeRTOS/FreeRTOS_WKSPACE/STM32_HelloWorld/inc" -I"D:/FreeRTOS/FreeRTOS_WKSPACE/STM32_HelloWorld/CMSIS/device" -I"D:/FreeRTOS/FreeRTOS_WKSPACE/STM32_HelloWorld/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


