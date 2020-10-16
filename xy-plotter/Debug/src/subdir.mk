################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DigitalIoPin.cpp \
../src/Fmutex.cpp \
../src/G1.cpp \
../src/G28.cpp \
../src/I2C.cpp \
../src/LpcUart.cpp \
../src/M1.cpp \
../src/M10.cpp \
../src/M11.cpp \
../src/M2.cpp \
../src/M4.cpp \
../src/M5.cpp \
../src/PWM_settings.cpp \
../src/Parser.cpp \
../src/SpeedSettings.cpp \
../src/XY-Plotter.cpp \
../src/cr_cpp_config.cpp \
../src/cr_startup_lpc15xx.cpp 

C_SRCS += \
../src/ITM_write.c \
../src/cdc_desc.c \
../src/cdc_main.c \
../src/cdc_vcom.c \
../src/crp.c \
../src/heap_lock_monitor.c \
../src/sysinit.c 

OBJS += \
./src/DigitalIoPin.o \
./src/Fmutex.o \
./src/G1.o \
./src/G28.o \
./src/I2C.o \
./src/ITM_write.o \
./src/LpcUart.o \
./src/M1.o \
./src/M10.o \
./src/M11.o \
./src/M2.o \
./src/M4.o \
./src/M5.o \
./src/PWM_settings.o \
./src/Parser.o \
./src/SpeedSettings.o \
./src/XY-Plotter.o \
./src/cdc_desc.o \
./src/cdc_main.o \
./src/cdc_vcom.o \
./src/cr_cpp_config.o \
./src/cr_startup_lpc15xx.o \
./src/crp.o \
./src/heap_lock_monitor.o \
./src/sysinit.o 

CPP_DEPS += \
./src/DigitalIoPin.d \
./src/Fmutex.d \
./src/G1.d \
./src/G28.d \
./src/I2C.d \
./src/LpcUart.d \
./src/M1.d \
./src/M10.d \
./src/M11.d \
./src/M2.d \
./src/M4.d \
./src/M5.d \
./src/PWM_settings.d \
./src/Parser.d \
./src/SpeedSettings.d \
./src/XY-Plotter.d \
./src/cr_cpp_config.d \
./src/cr_startup_lpc15xx.d 

C_DEPS += \
./src/ITM_write.d \
./src/cdc_desc.d \
./src/cdc_main.d \
./src/cdc_vcom.d \
./src/crp.d \
./src/heap_lock_monitor.d \
./src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -std=c++11 -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_LPCOPEN -DCPP_USE_HEAP -D__LPC15XX__ -I"C:\Users\johan\Documents\School\Platforms\MCUXpressoIDE_11.2.0_4120\XY-projektV2\XY-plotter\inc" -I"C:\Users\johan\Documents\School\Platforms\MCUXpressoIDE_11.2.0_4120\XY-projektV2\lpc_board_nxp_lpcxpresso_1549\inc" -I"C:\Users\johan\Documents\School\Platforms\MCUXpressoIDE_11.2.0_4120\XY-projektV2\lpc_chip_15xx\inc" -I"C:\Users\johan\Documents\School\Platforms\MCUXpressoIDE_11.2.0_4120\XY-projektV2\lpc_chip_15xx\inc\usbd" -I"C:\Users\johan\Documents\School\Platforms\MCUXpressoIDE_11.2.0_4120\XY-projektV2\FreeRTOS\inc" -I"C:\Users\johan\Documents\School\Platforms\MCUXpressoIDE_11.2.0_4120\XY-projektV2\FreeRTOS\src\include" -I"C:\Users\johan\Documents\School\Platforms\MCUXpressoIDE_11.2.0_4120\XY-projektV2\FreeRTOS\src\portable\GCC\ARM_CM3" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m3 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_LPCOPEN -DCPP_USE_HEAP -D__LPC15XX__ -I"C:\Users\johan\Documents\School\Platforms\MCUXpressoIDE_11.2.0_4120\XY-projektV2\XY-plotter\inc" -I"C:\Users\johan\Documents\School\Platforms\MCUXpressoIDE_11.2.0_4120\XY-projektV2\lpc_board_nxp_lpcxpresso_1549\inc" -I"C:\Users\johan\Documents\School\Platforms\MCUXpressoIDE_11.2.0_4120\XY-projektV2\lpc_chip_15xx\inc" -I"C:\Users\johan\Documents\School\Platforms\MCUXpressoIDE_11.2.0_4120\XY-projektV2\lpc_chip_15xx\inc\usbd" -I"C:\Users\johan\Documents\School\Platforms\MCUXpressoIDE_11.2.0_4120\XY-projektV2\FreeRTOS\inc" -I"C:\Users\johan\Documents\School\Platforms\MCUXpressoIDE_11.2.0_4120\XY-projektV2\FreeRTOS\src\include" -I"C:\Users\johan\Documents\School\Platforms\MCUXpressoIDE_11.2.0_4120\XY-projektV2\FreeRTOS\src\portable\GCC\ARM_CM3" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m3 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


