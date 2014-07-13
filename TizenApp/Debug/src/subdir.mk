################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AppResourceId.cpp \
../src/Client.cpp \
../src/ClientThreadWork.cpp \
../src/ContentManager.cpp \
../src/Context.cpp \
../src/DateManager.cpp \
../src/PacketManager.cpp \
../src/PortNumManager.cpp \
../src/RTSPContextLogic.cpp \
../src/RTSPServer.cpp \
../src/RTSPSocket.cpp \
../src/ResponseDescribePacket.cpp \
../src/ResponseOptionPacket.cpp \
../src/ResponsePlayPacket.cpp \
../src/ResponseSetupPacket.cpp \
../src/ServerResource.cpp \
../src/SessionManager.cpp \
../src/StringConvertor.cpp \
../src/ThreadManager.cpp \
../src/TizenAppApp.cpp \
../src/TizenAppEntry.cpp \
../src/TizenAppForm.cpp \
../src/TizenAppFrame.cpp \
../src/TizenRTSPServer.cpp 

OBJS += \
./src/AppResourceId.o \
./src/Client.o \
./src/ClientThreadWork.o \
./src/ContentManager.o \
./src/Context.o \
./src/DateManager.o \
./src/PacketManager.o \
./src/PortNumManager.o \
./src/RTSPContextLogic.o \
./src/RTSPServer.o \
./src/RTSPSocket.o \
./src/ResponseDescribePacket.o \
./src/ResponseOptionPacket.o \
./src/ResponsePlayPacket.o \
./src/ResponseSetupPacket.o \
./src/ServerResource.o \
./src/SessionManager.o \
./src/StringConvertor.o \
./src/ThreadManager.o \
./src/TizenAppApp.o \
./src/TizenAppEntry.o \
./src/TizenAppForm.o \
./src/TizenAppFrame.o \
./src/TizenRTSPServer.o 

CPP_DEPS += \
./src/AppResourceId.d \
./src/Client.d \
./src/ClientThreadWork.d \
./src/ContentManager.d \
./src/Context.d \
./src/DateManager.d \
./src/PacketManager.d \
./src/PortNumManager.d \
./src/RTSPContextLogic.d \
./src/RTSPServer.d \
./src/RTSPSocket.d \
./src/ResponseDescribePacket.d \
./src/ResponseOptionPacket.d \
./src/ResponsePlayPacket.d \
./src/ResponseSetupPacket.d \
./src/ServerResource.d \
./src/SessionManager.d \
./src/StringConvertor.d \
./src/ThreadManager.d \
./src/TizenAppApp.d \
./src/TizenAppEntry.d \
./src/TizenAppForm.d \
./src/TizenAppFrame.d \
./src/TizenRTSPServer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: C++ Compiler'
	clang++.exe -I"pch" -D_DEBUG -I"C:\Users\Hoon\Desktop\TizenApp\inc" -O0 -g3 -Wall -c -fmessage-length=0 -target i386-tizen-linux-gnueabi -gcc-toolchain "C:/tizen-sdk/tools/smart-build-interface/../i386-linux-gnueabi-gcc-4.5/" -ccc-gcc-name i386-linux-gnueabi-g++ -march=i386 -Wno-gnu -fPIE --sysroot="C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/include/libxml2" -I"C:\tizen-sdk\library" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/include" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/include/osp" -D_APP_LOG -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


