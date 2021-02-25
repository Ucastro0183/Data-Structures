################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../-\ stdUsingADT.cpp \
../Grid_Use.cpp \
../Map_Use.cpp \
../Queue_Use.cpp \
../Scanner_Use.cpp \
../Set_Use.cpp \
../Stack_Use.cpp \
../Vector_Use.cpp 

OBJS += \
./-\ stdUsingADT.o \
./Grid_Use.o \
./Map_Use.o \
./Queue_Use.o \
./Scanner_Use.o \
./Set_Use.o \
./Stack_Use.o \
./Vector_Use.o 

CPP_DEPS += \
./-\ stdUsingADT.d \
./Grid_Use.d \
./Map_Use.d \
./Queue_Use.d \
./Scanner_Use.d \
./Set_Use.d \
./Stack_Use.d \
./Vector_Use.d 


# Each subdirectory must supply rules for building sources it contributes
-\ stdUsingADT.o: ../-\ stdUsingADT.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"- stdUsingADT.d" -MT"-\ stdUsingADT.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


