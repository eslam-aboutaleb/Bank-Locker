################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../Alarm.c \
../BankLocker_Control.c \
../DIO_program.c \
../Door.c \
../EX_EEPROM.c \
../IN_EEPROM.c \
../main.c \
../MathFuncs.c \
../PaswordHandling_Control.c \
../ServoMotor.c \
../Timer1_PWM.c \
../TWI.c \
../UART_program.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
Alarm.o \
BankLocker_Control.o \
DIO_program.o \
Door.o \
EX_EEPROM.o \
IN_EEPROM.o \
main.o \
MathFuncs.o \
PaswordHandling_Control.o \
ServoMotor.o \
Timer1_PWM.o \
TWI.o \
UART_program.o

OBJS_AS_ARGS +=  \
Alarm.o \
BankLocker_Control.o \
DIO_program.o \
Door.o \
EX_EEPROM.o \
IN_EEPROM.o \
main.o \
MathFuncs.o \
PaswordHandling_Control.o \
ServoMotor.o \
Timer1_PWM.o \
TWI.o \
UART_program.o

C_DEPS +=  \
Alarm.d \
BankLocker_Control.d \
DIO_program.d \
Door.d \
EX_EEPROM.d \
IN_EEPROM.d \
main.d \
MathFuncs.d \
PaswordHandling_Control.d \
ServoMotor.d \
Timer1_PWM.d \
TWI.d \
UART_program.d

C_DEPS_AS_ARGS +=  \
Alarm.d \
BankLocker_Control.d \
DIO_program.d \
Door.d \
EX_EEPROM.d \
IN_EEPROM.d \
main.d \
MathFuncs.d \
PaswordHandling_Control.d \
ServoMotor.d \
Timer1_PWM.d \
TWI.d \
UART_program.d

OUTPUT_FILE_PATH +=Bank_Locker_Control.elf

OUTPUT_FILE_PATH_AS_ARGS +=Bank_Locker_Control.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler



























./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.150\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.150\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Bank_Locker_Control.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.150\gcc\dev\atmega32"  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Bank_Locker_Control.elf" "Bank_Locker_Control.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Bank_Locker_Control.elf" "Bank_Locker_Control.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Bank_Locker_Control.elf" > "Bank_Locker_Control.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Bank_Locker_Control.elf" "Bank_Locker_Control.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "Bank_Locker_Control.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Bank_Locker_Control.elf" "Bank_Locker_Control.a" "Bank_Locker_Control.hex" "Bank_Locker_Control.lss" "Bank_Locker_Control.eep" "Bank_Locker_Control.map" "Bank_Locker_Control.srec" "Bank_Locker_Control.usersignatures"
	