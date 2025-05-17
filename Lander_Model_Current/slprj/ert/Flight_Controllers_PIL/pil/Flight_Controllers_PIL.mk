###########################################################################
## Makefile generated for component 'Flight_Controllers_PIL'. 
## 
## Makefile     : Flight_Controllers_PIL.mk
## Generated on : Fri Sep 20 08:53:43 2024
## Final product: ./Flight_Controllers_PIL.pre.o
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = Flight_Controllers_PIL
MAKEFILE                  = Flight_Controllers_PIL.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2024b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2024b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/samue/OneDrive/DOCUME~1/MatLab/UTEP_I~1/UTEPLA~1/LANDER~4
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ../../../..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU Tools for PX4 Autopilots
# Supported Version(s):    
# ToolchainInfo Version:   2024b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# TARGET_LOAD_CMD_ARGS
# TARGET_LOAD_CMD
# PX4FIRMWAREROOTDIR
# CMAKEMAKECONFIG
# PYTHONROOTDIR

#-----------
# MACROS
#-----------

Q                    = $(if $(V),,@)
CPFLAGS              = -O binary
LIBGCC               = $(shell $(CC) $(ARCHCPUFLAGS) -print-libgcc-file-name)
LIBM                 = $(shell $(CC) $(ARCHCPUFLAGS) -print-file-name=libm.a)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm -lm

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU PX4 C Compiler
CC = echo gcc

# Linker: GNU PX4 Pre-Linker
LD = echo gcc

# C++ Compiler: GNU PX4 C++ Compiler
CPP = echo g++

# C++ Linker: GNU PX4 C++ Pre-Linker
CPP_LD = echo gcc

# Archiver: GNU PX4 Archiver
AR = echo

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
ENDGRP              = --end-group
OUTPUT_FLAG         = -o
STARTGRP            = --start-group
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
ENDGRP              = --end-group
OUTPUT_FLAG         = -o
STARTGRP            = --start-group
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /f/q
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
CFLAGS               =
CPPFLAGS             =
CPP_LDFLAGS          =
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./Flight_Controllers_PIL.pre.o
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/slprj/ert/Flight_Controllers_PIL -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(START_DIR)/slprj/ert/_sharedutils -IC:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/px4/core/include -I$(MATLAB_ROOT)/toolbox/rtw/targets/pil/c -I$(START_DIR)/slprj/ert/Flight_Controllers_PIL/pil -I$(MATLAB_ROOT)/extern/include/coder/connectivity/XILTgtAppSvc -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DMW_PX4_DISABLE_MAVLINK=1 -DPIL -DRTIOSTREAM_RX_BUFFER_BYTE_SIZE=128 -DRTIOSTREAM_TX_BUFFER_BYTE_SIZE=128 -DMW_PX4_EXTMODE_BAUD_RATE=3000000 -DMW_PX4_EXTMODE_HWPORT=\"/dev/ttyACM0\"
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0 -DCODER_ASSUMPTIONS_ENABLED=0 -DMEM_UNIT_BYTES=1 -DMemUnit_T=uint8_T
DEFINES_SKIPFORSIL = -DPX4 -DFMUv6x -DNULL=0 -DMW_PX4_NUTTX_BUILD -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -D__linux__ -DXCP_PLATFORM_LINUX_NO_PIE_SUPPORT -DSTACK_SIZE=64 -DRT
DEFINES_STANDARD = -DMODEL=Flight_Controllers_PIL -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_interface_lib.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_data_stream.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_services.c $(START_DIR)/slprj/ert/Flight_Controllers_PIL/pil/xil_interface.cpp $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xilcomms_rtiostream.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_rtiostream.c $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/px4/core/src/pil_main_px4.cpp C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/px4/core/src/MW_PX4_rtiostream_serial.cpp C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/px4/core/src/MW_PX4_TaskControl.cpp C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/px4/core/src/nuttxinitialize.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = xil_interface_lib.o xil_data_stream.o xil_services.o xil_interface.cpp.o xilcomms_rtiostream.o xil_rtiostream.o rtiostream_utils.o pil_main_px4.cpp.o MW_PX4_rtiostream_serial.cpp.o MW_PX4_TaskControl.cpp.o nuttxinitialize.cpp.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

MODELREF_LIBS = ../../../../slprj/ert/Flight_Controllers_PIL/Flight_Controllers_PIL_rtwlib.mk

LIBS = $(START_DIR)/slprj/ert/_sharedutils/rtwshared.mk

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(MODELREF_LIBS) $(LIBS)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(OBJS) --start-group ../../../../slprj/ert/Flight_Controllers_PIL/Flight_Controllers_PIL_rtwlib.mk $(LIBS) --end-group $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xil_interface_lib.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_interface_lib.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xil_data_stream.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_data_stream.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xil_services.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_services.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xil_interface.cpp.o : $(START_DIR)/slprj/ert/Flight_Controllers_PIL/pil/xil_interface.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xilcomms_rtiostream.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xilcomms_rtiostream.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xil_rtiostream.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_rtiostream.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtiostream_utils.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c
	$(CC) $(CFLAGS) -o "$@" "$<"


pil_main_px4.cpp.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/px4/core/src/pil_main_px4.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_PX4_rtiostream_serial.cpp.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/px4/core/src/MW_PX4_rtiostream_serial.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_PX4_TaskControl.cpp.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/px4/core/src/MW_PX4_TaskControl.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


nuttxinitialize.cpp.o : C:/ProgramData/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/px4/core/src/nuttxinitialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


