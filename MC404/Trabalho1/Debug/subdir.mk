################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../definitions.c \
../label_table.c \
../main.c \
../opcodes.c \
../parser.c 

OBJS += \
./definitions.o \
./label_table.o \
./main.o \
./opcodes.o \
./parser.o 

C_DEPS += \
./definitions.d \
./label_table.d \
./main.d \
./opcodes.d \
./parser.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


