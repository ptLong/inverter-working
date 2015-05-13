################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
ctrl.obj: ../ctrl.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"E:/ti/ccs6/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O2 --opt_for_speed=5 --include_path="E:/ti/ccs6/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/include" --include_path="E:/ti/controlSUITEMay08/device_support/F2837xD/v150/F2837xD_headers/include" --include_path="E:/ti/controlSUITEMay08/device_support/F2837xD/v150/F2837xD_common/include" -g --define=CPU1 --diag_warning=225 --display_error_number --diag_suppress=10063 --preproc_with_compile --preproc_dependency="ctrl.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"E:/ti/ccs6/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O2 --opt_for_speed=5 --include_path="E:/ti/ccs6/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/include" --include_path="E:/ti/controlSUITEMay08/device_support/F2837xD/v150/F2837xD_headers/include" --include_path="E:/ti/controlSUITEMay08/device_support/F2837xD/v150/F2837xD_common/include" -g --define=CPU1 --diag_warning=225 --display_error_number --diag_suppress=10063 --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

oit-pwm.obj: ../oit-pwm.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"E:/ti/ccs6/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O2 --opt_for_speed=5 --include_path="E:/ti/ccs6/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/include" --include_path="E:/ti/controlSUITEMay08/device_support/F2837xD/v150/F2837xD_headers/include" --include_path="E:/ti/controlSUITEMay08/device_support/F2837xD/v150/F2837xD_common/include" -g --define=CPU1 --diag_warning=225 --display_error_number --diag_suppress=10063 --preproc_with_compile --preproc_dependency="oit-pwm.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

system-init.obj: ../system-init.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"E:/ti/ccs6/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O2 --opt_for_speed=5 --include_path="E:/ti/ccs6/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/include" --include_path="E:/ti/controlSUITEMay08/device_support/F2837xD/v150/F2837xD_headers/include" --include_path="E:/ti/controlSUITEMay08/device_support/F2837xD/v150/F2837xD_common/include" -g --define=CPU1 --diag_warning=225 --display_error_number --diag_suppress=10063 --preproc_with_compile --preproc_dependency="system-init.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ti-sfo-v8.obj: ../ti-sfo-v8.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"E:/ti/ccs6/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O2 --opt_for_speed=5 --include_path="E:/ti/ccs6/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/include" --include_path="E:/ti/controlSUITEMay08/device_support/F2837xD/v150/F2837xD_headers/include" --include_path="E:/ti/controlSUITEMay08/device_support/F2837xD/v150/F2837xD_common/include" -g --define=CPU1 --diag_warning=225 --display_error_number --diag_suppress=10063 --preproc_with_compile --preproc_dependency="ti-sfo-v8.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


