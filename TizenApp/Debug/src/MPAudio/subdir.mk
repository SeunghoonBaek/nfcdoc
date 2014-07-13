################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MPAudio/APETag.cpp \
../src/MPAudio/ID3V1Tag.cpp \
../src/MPAudio/ID3V2Tag.cpp \
../src/MPAudio/LameTag.cpp \
../src/MPAudio/Lyrics3Tag.cpp \
../src/MPAudio/MPAEndOfFileException.cpp \
../src/MPAudio/MPAException.cpp \
../src/MPAudio/MPAFile.cpp \
../src/MPAudio/MPAFileStream.cpp \
../src/MPAudio/MPAFrame.cpp \
../src/MPAudio/MPAHeader.cpp \
../src/MPAudio/MPAStream.cpp \
../src/MPAudio/MusicMatchTag.cpp \
../src/MPAudio/Tag.cpp \
../src/MPAudio/Tags.cpp \
../src/MPAudio/VBRHeader.cpp \
../src/MPAudio/VBRIHeader.cpp \
../src/MPAudio/XINGHeader.cpp 

OBJS += \
./src/MPAudio/APETag.o \
./src/MPAudio/ID3V1Tag.o \
./src/MPAudio/ID3V2Tag.o \
./src/MPAudio/LameTag.o \
./src/MPAudio/Lyrics3Tag.o \
./src/MPAudio/MPAEndOfFileException.o \
./src/MPAudio/MPAException.o \
./src/MPAudio/MPAFile.o \
./src/MPAudio/MPAFileStream.o \
./src/MPAudio/MPAFrame.o \
./src/MPAudio/MPAHeader.o \
./src/MPAudio/MPAStream.o \
./src/MPAudio/MusicMatchTag.o \
./src/MPAudio/Tag.o \
./src/MPAudio/Tags.o \
./src/MPAudio/VBRHeader.o \
./src/MPAudio/VBRIHeader.o \
./src/MPAudio/XINGHeader.o 

CPP_DEPS += \
./src/MPAudio/APETag.d \
./src/MPAudio/ID3V1Tag.d \
./src/MPAudio/ID3V2Tag.d \
./src/MPAudio/LameTag.d \
./src/MPAudio/Lyrics3Tag.d \
./src/MPAudio/MPAEndOfFileException.d \
./src/MPAudio/MPAException.d \
./src/MPAudio/MPAFile.d \
./src/MPAudio/MPAFileStream.d \
./src/MPAudio/MPAFrame.d \
./src/MPAudio/MPAHeader.d \
./src/MPAudio/MPAStream.d \
./src/MPAudio/MusicMatchTag.d \
./src/MPAudio/Tag.d \
./src/MPAudio/Tags.d \
./src/MPAudio/VBRHeader.d \
./src/MPAudio/VBRIHeader.d \
./src/MPAudio/XINGHeader.d 


# Each subdirectory must supply rules for building sources it contributes
src/MPAudio/%.o: ../src/MPAudio/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: C++ Compiler'
	clang++.exe -I"pch" -D_DEBUG -I"C:\Users\Hoon\Desktop\TizenApp\inc" -O0 -g3 -Wall -c -fmessage-length=0 -target i386-tizen-linux-gnueabi -gcc-toolchain "C:/tizen-sdk/tools/smart-build-interface/../i386-linux-gnueabi-gcc-4.5/" -ccc-gcc-name i386-linux-gnueabi-g++ -march=i386 -Wno-gnu -fPIE --sysroot="C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/include/libxml2" -I"C:\tizen-sdk\library" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/include" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/include/osp" -D_APP_LOG -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


