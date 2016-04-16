################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mainApplication/LCD_main.c 

OBJS += \
./mainApplication/LCD_main.o 

C_DEPS += \
./mainApplication/LCD_main.d 


# Each subdirectory must supply rules for building sources it contributes
mainApplication/%.o: ../mainApplication/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


