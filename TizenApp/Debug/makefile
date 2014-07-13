################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/MPAudio/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: TizenApp.exe secondary-outputs
# Tool invocations
TizenApp.exe: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: C++ Linker'
	-$(RM) .OBJ_LIST
	i386-linux-gnueabi-ld.exe -r -o xxxlib20.o  src/AppResourceId.o src/Client.o src/ClientThreadWork.o src/ContentManager.o src/Context.o src/DateManager.o src/PacketManager.o src/PortNumManager.o src/RTSPContextLogic.o src/RTSPServer.o src/RTSPSocket.o src/ResponseDescribePacket.o src/ResponseOptionPacket.o src/ResponsePlayPacket.o src/ResponseSetupPacket.o src/ServerResource.o src/SessionManager.o src/StringConvertor.o src/ThreadManager.o src/TizenAppApp.o
	i386-linux-gnueabi-ld.exe -r -o xxxlib40.o  src/TizenAppEntry.o src/TizenAppForm.o src/TizenAppFrame.o src/TizenRTSPServer.o src/MPAudio/APETag.o src/MPAudio/ID3V1Tag.o src/MPAudio/ID3V2Tag.o src/MPAudio/LameTag.o src/MPAudio/Lyrics3Tag.o src/MPAudio/MPAEndOfFileException.o src/MPAudio/MPAException.o src/MPAudio/MPAFile.o src/MPAudio/MPAFileStream.o src/MPAudio/MPAFrame.o src/MPAudio/MPAHeader.o src/MPAudio/MPAStream.o src/MPAudio/MusicMatchTag.o src/MPAudio/Tag.o src/MPAudio/Tags.o src/MPAudio/VBRHeader.o
	i386-linux-gnueabi-ld.exe -r -o xxxlib42.o  src/MPAudio/VBRIHeader.o src/MPAudio/XINGHeader.o
	clang++.exe -o"TizenApp.exe"  xxxlib20.o xxxlib40.o xxxlib42.o $(USER_OBJS) $(LIBS) -L"C:\Users\Hoon\Desktop\TizenApp\lib" -target i386-tizen-linux-gnueabi -gcc-toolchain "C:/tizen-sdk/tools/smart-build-interface/../i386-linux-gnueabi-gcc-4.5/" -ccc-gcc-name i386-linux-gnueabi-g++ -march=i386 -Xlinker --as-needed -pie -lpthread -Xlinker -rpath="/opt/usr/apps/SkDVaHBA0a/lib" -Xlinker -rpath="/home/developer/sdk_tools/lib" --sysroot="C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native" -L"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/lib" -L"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/lib/osp" -losp-uifw -losp-appfw -losp-image -losp-json -losp-ime -losp-net -lpthread -losp-content -losp-locations -losp-telephony -losp-uix -losp-media -losp-messaging -losp-web -losp-social -losp-wifi -losp-bluetooth -losp-nfc -losp-face -losp-secure-element -losp-speech-tts -losp-speech-stt -losp-shell -losp-shell-core -losp-vision -lxml2 -lalut -lopenal
	@echo 'Finished building target: $@'
	@echo ' '
# Other Targets
clean:
	@FOR %%i IN ( $(OBJS) ) DO ( $(RM) "%%i" )
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(MO_FILES)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(EDJ_FILES)$(CPP_DEPS)$(C_DEPS) TizenApp.exe
	-@echo ' '
secondary-outputs: $(MO_FILES) $(EDJ_FILES)
.PHONY: all clean dependents
.SECONDARY:
-include ../makefile.targets
