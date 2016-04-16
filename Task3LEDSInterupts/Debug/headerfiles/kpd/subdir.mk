################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../headerfiles/kpd/KPD_prog.c 

OBJS += \
./headerfiles/kpd/KPD_prog.o 

C_DEPS += \
./headerfiles/kpd/KPD_prog.d 


# Each subdirectory must supply rules for building sources it contributes
headerfiles/kpd/%.o: ../headerfiles/kpd/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


