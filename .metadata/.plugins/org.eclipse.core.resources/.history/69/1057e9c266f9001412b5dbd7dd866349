################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := E:/ti/ccs6/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4

ORDERED_OBJS += \
"./ctrl.obj" \
"./main.obj" \
"./oit-pwm.obj" \
"./system-init.obj" \
"./ti-sfo-v8.obj" \
"./TI/F2837xD_Adc.obj" \
"./TI/F2837xD_CodeStartBranch.obj" \
"./TI/F2837xD_CpuTimers.obj" \
"./TI/F2837xD_DBGIER.obj" \
"./TI/F2837xD_DefaultISR.obj" \
"./TI/F2837xD_Dma.obj" \
"./TI/F2837xD_ECap.obj" \
"./TI/F2837xD_EPwm.obj" \
"./TI/F2837xD_EQep.obj" \
"./TI/F2837xD_Emif.obj" \
"./TI/F2837xD_GlobalVariableDefs.obj" \
"./TI/F2837xD_Gpio.obj" \
"./TI/F2837xD_I2C.obj" \
"./TI/F2837xD_Ipc.obj" \
"./TI/F2837xD_Ipc_Driver.obj" \
"./TI/F2837xD_Ipc_Driver_Lite.obj" \
"./TI/F2837xD_Ipc_Driver_Util.obj" \
"./TI/F2837xD_Mcbsp.obj" \
"./TI/F2837xD_PieCtrl.obj" \
"./TI/F2837xD_PieVect.obj" \
"./TI/F2837xD_Sci.obj" \
"./TI/F2837xD_Spi.obj" \
"./TI/F2837xD_SysCtrl.obj" \
"./TI/F2837xD_Upp.obj" \
"./TI/F2837xD_sci_io.obj" \
"./TI/F2837xD_sdfm_drivers.obj" \
"./TI/F2837xD_struct.obj" \
"./TI/F2837xD_usDelay.obj" \
"../TI/SFO_v8_fpu_lib_build_c28.lib" \
$(GEN_CMDS__FLAG) \
-l"rts2800_fpu32.lib" \
-l"2837xD_RAM_lnk_cpu1.cmd" \
-l"F2837xD_Headers_nonBIOS_cpu1.cmd" \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include TI/subdir_vars.mk
-include subdir_rules.mk
-include TI/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
oit-inverter-final.out \

EXE_OUTPUTS__QUOTED += \
"oit-inverter-final.out" \

BIN_OUTPUTS += \
oit-inverter-final.hex \

BIN_OUTPUTS__QUOTED += \
"oit-inverter-final.hex" \


# All Target
all: oit-inverter-final.out

# Tool invocations
oit-inverter-final.out: $(OBJS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"E:/ti/ccs6/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O2 --opt_for_speed=5 -g --define=CPU1 --diag_warning=225 --display_error_number --diag_suppress=10063 -z -m"oit-inverter-final.map" --stack_size=0x100 --warn_sections -i"E:/ti/ccs6/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/lib" -i"E:/ti/ccs6/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/include" -i"E:/ti/controlSUITEMay08/device_support/F2837xD/v150/F2837xD_common/cmd" -i"E:/ti/controlSUITEMay08/device_support/F2837xD/v150/F2837xD_headers/cmd" --reread_libs --display_error_number --xml_link_info="oit-inverter-final_linkInfo.xml" --entry_point=code_start --rom_model -o "oit-inverter-final.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

oit-inverter-final.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C2000 Hex Utility'
	"E:/ti/ccs6/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/hex2000"  -o "oit-inverter-final.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "ctrl.pp" "main.pp" "oit-pwm.pp" "system-init.pp" "ti-sfo-v8.pp" "TI\F2837xD_Adc.pp" "TI\F2837xD_CpuTimers.pp" "TI\F2837xD_DefaultISR.pp" "TI\F2837xD_Dma.pp" "TI\F2837xD_ECap.pp" "TI\F2837xD_EPwm.pp" "TI\F2837xD_EQep.pp" "TI\F2837xD_Emif.pp" "TI\F2837xD_GlobalVariableDefs.pp" "TI\F2837xD_Gpio.pp" "TI\F2837xD_I2C.pp" "TI\F2837xD_Ipc.pp" "TI\F2837xD_Ipc_Driver.pp" "TI\F2837xD_Ipc_Driver_Lite.pp" "TI\F2837xD_Ipc_Driver_Util.pp" "TI\F2837xD_Mcbsp.pp" "TI\F2837xD_PieCtrl.pp" "TI\F2837xD_PieVect.pp" "TI\F2837xD_Sci.pp" "TI\F2837xD_Spi.pp" "TI\F2837xD_SysCtrl.pp" "TI\F2837xD_Upp.pp" "TI\F2837xD_sci_io.pp" "TI\F2837xD_sdfm_drivers.pp" "TI\F2837xD_struct.pp" 
	-$(RM) "ctrl.obj" "main.obj" "oit-pwm.obj" "system-init.obj" "ti-sfo-v8.obj" "TI\F2837xD_Adc.obj" "TI\F2837xD_CodeStartBranch.obj" "TI\F2837xD_CpuTimers.obj" "TI\F2837xD_DBGIER.obj" "TI\F2837xD_DefaultISR.obj" "TI\F2837xD_Dma.obj" "TI\F2837xD_ECap.obj" "TI\F2837xD_EPwm.obj" "TI\F2837xD_EQep.obj" "TI\F2837xD_Emif.obj" "TI\F2837xD_GlobalVariableDefs.obj" "TI\F2837xD_Gpio.obj" "TI\F2837xD_I2C.obj" "TI\F2837xD_Ipc.obj" "TI\F2837xD_Ipc_Driver.obj" "TI\F2837xD_Ipc_Driver_Lite.obj" "TI\F2837xD_Ipc_Driver_Util.obj" "TI\F2837xD_Mcbsp.obj" "TI\F2837xD_PieCtrl.obj" "TI\F2837xD_PieVect.obj" "TI\F2837xD_Sci.obj" "TI\F2837xD_Spi.obj" "TI\F2837xD_SysCtrl.obj" "TI\F2837xD_Upp.obj" "TI\F2837xD_sci_io.obj" "TI\F2837xD_sdfm_drivers.obj" "TI\F2837xD_struct.obj" "TI\F2837xD_usDelay.obj" 
	-$(RM) "TI\F2837xD_CodeStartBranch.pp" "TI\F2837xD_DBGIER.pp" "TI\F2837xD_usDelay.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

