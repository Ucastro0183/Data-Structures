################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ConnectionsGraph.cpp \
../Grid.cpp \
../Hash.cpp \
../Lexicon.cpp \
../Map.cpp \
../MyError.cpp \
../MyTree.cpp \
../Queue.cpp \
../Scanner.cpp \
../Set.cpp \
../Stack.cpp \
../TreeMap.cpp \
../Vector.cpp 

OBJS += \
./ConnectionsGraph.o \
./Grid.o \
./Hash.o \
./Lexicon.o \
./Map.o \
./MyError.o \
./MyTree.o \
./Queue.o \
./Scanner.o \
./Set.o \
./Stack.o \
./TreeMap.o \
./Vector.o 

CPP_DEPS += \
./ConnectionsGraph.d \
./Grid.d \
./Hash.d \
./Lexicon.d \
./Map.d \
./MyError.d \
./MyTree.d \
./Queue.d \
./Scanner.d \
./Set.d \
./Stack.d \
./TreeMap.d \
./Vector.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


