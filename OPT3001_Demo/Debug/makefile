################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32L4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
opt3001_test.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
opt3001_test.list \

OBJCOPY_BIN += \
opt3001_test.bin \


# All Target
all: opt3001_test.elf secondary-outputs

# Tool invocations
opt3001_test.elf: $(OBJS) $(USER_OBJS) C:\Users\shashikant\STM32CubeIDE\workspace_1.0.1\opt3001_test\STM32L476RGTX_FLASH.ld
	arm-none-eabi-gcc -o "opt3001_test.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\shashikant\STM32CubeIDE\workspace_1.0.1\opt3001_test\STM32L476RGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="opt3001_test.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

opt3001_test.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "opt3001_test.list"
	@echo 'Finished building: $@'
	@echo ' '

opt3001_test.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "opt3001_test.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
