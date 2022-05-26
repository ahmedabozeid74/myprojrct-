################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DIO_prg.c \
../KPD_prg.c \
../LCD_prg.c \
../LDR.c \
../LM35.c \
../main.c \
../servo.c 

OBJS += \
./ADC.o \
./DIO_prg.o \
./KPD_prg.o \
./LCD_prg.o \
./LDR.o \
./LM35.o \
./main.o \
./servo.o 

C_DEPS += \
./ADC.d \
./DIO_prg.d \
./KPD_prg.d \
./LCD_prg.d \
./LDR.d \
./LM35.d \
./main.d \
./servo.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


