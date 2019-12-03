################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../src/Idle_WaitForInterrupts_ASM.asm \
../src/ReadCycles_ASM.asm 

CPP_SRCS += \
../src/LCD_Threads.cpp \
../src/Lab4_Core0_uTTCOSg2017_main.cpp \
../src/Temp_Functions.cpp \
../src/faultyLED1_Thread.cpp 

SRC_OBJS += \
./src/Idle_WaitForInterrupts_ASM.doj \
./src/LCD_Threads.doj \
./src/Lab4_Core0_uTTCOSg2017_main.doj \
./src/ReadCycles_ASM.doj \
./src/Temp_Functions.doj \
./src/faultyLED1_Thread.doj 

ASM_DEPS += \
./src/Idle_WaitForInterrupts_ASM.d \
./src/ReadCycles_ASM.d 

CPP_DEPS += \
./src/LCD_Threads.d \
./src/Lab4_Core0_uTTCOSg2017_main.d \
./src/Temp_Functions.d \
./src/faultyLED1_Thread.d 


# Each subdirectory must supply rules for building sources it contributes
src/Idle_WaitForInterrupts_ASM.doj: ../src/Idle_WaitForInterrupts_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="Lab4_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-63c465d30df61e512573ae87b0227b2b.txt -gnu-style-dependencies -MM -Mo "src/Idle_WaitForInterrupts_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/LCD_Threads.doj: ../src/LCD_Threads.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab4_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-335a5c745099bb93dd9da4a65502dd19.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/LCD_Threads.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Lab4_Core0_uTTCOSg2017_main.doj: ../src/Lab4_Core0_uTTCOSg2017_main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab4_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-335a5c745099bb93dd9da4a65502dd19.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Lab4_Core0_uTTCOSg2017_main.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/ReadCycles_ASM.doj: ../src/ReadCycles_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="Lab4_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-63c465d30df61e512573ae87b0227b2b.txt -gnu-style-dependencies -MM -Mo "src/ReadCycles_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Temp_Functions.doj: ../src/Temp_Functions.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab4_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-335a5c745099bb93dd9da4a65502dd19.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Temp_Functions.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/faultyLED1_Thread.doj: ../src/faultyLED1_Thread.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab4_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-335a5c745099bb93dd9da4a65502dd19.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/faultyLED1_Thread.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


