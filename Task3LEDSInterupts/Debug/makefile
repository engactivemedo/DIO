################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include mainApplication/subdir.mk
-include lcd_files/subdir.mk
-include headerfiles/tetris/subdir.mk
-include headerfiles/kpd/subdir.mk
-include headerfiles/keypadsFiles/subdir.mk
-include headerfiles/DelayFiles/subdir.mk
-include headerfiles/DIOFiles/subdir.mk
-include TIMER0/subdir.mk
-include ADC_files/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Task3LEDSInterupts.lss \

FLASH_IMAGE += \
Task3LEDSInterupts.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Task3LEDSInterupts.elf secondary-outputs

# Tool invocations
Task3LEDSInterupts.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Task3LEDSInterupts.map -mmcu=atmega32 -o "Task3LEDSInterupts.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Task3LEDSInterupts.lss: Task3LEDSInterupts.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Task3LEDSInterupts.elf  >"Task3LEDSInterupts.lss"
	@echo 'Finished building: $@'
	@echo ' '

Task3LEDSInterupts.hex: Task3LEDSInterupts.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Task3LEDSInterupts.elf  "Task3LEDSInterupts.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Task3LEDSInterupts.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Task3LEDSInterupts.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Task3LEDSInterupts.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
