################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/corem4.c \
../Src/gpio.c \
../Src/main.c \
../Src/rng.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/utility.c 

OBJS += \
./Src/corem4.o \
./Src/gpio.o \
./Src/main.o \
./Src/rng.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/utility.o 

C_DEPS += \
./Src/corem4.d \
./Src/gpio.d \
./Src/main.d \
./Src/rng.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/utility.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/corem4.cyclo ./Src/corem4.d ./Src/corem4.o ./Src/corem4.su ./Src/gpio.cyclo ./Src/gpio.d ./Src/gpio.o ./Src/gpio.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/rng.cyclo ./Src/rng.d ./Src/rng.o ./Src/rng.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/utility.cyclo ./Src/utility.d ./Src/utility.o ./Src/utility.su

.PHONY: clean-Src

