MATLAB_ROOT = /Applications/MATLAB_R2011a.app
MAKEFILE = Calc_CrossCorr3D_8_mex.mk

include Calc_CrossCorr3D_8_mex.mki


SRC_FILES =  \
	Calc_CrossCorr3D_8_data.cpp \
	Calc_CrossCorr3D_8.cpp \
	permute.cpp \
	Calc_CrossCorr3D_8_initialize.cpp \
	Calc_CrossCorr3D_8_terminate.cpp \
	Calc_CrossCorr3D_8_api.cpp \
	Calc_CrossCorr3D_8_mex.cpp

MEX_FILE_NAME_WO_EXT = Calc_CrossCorr3D_8_mex
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexmaci64
TARGET = $(MEX_FILE_NAME)

SYS_LIBS = 


#
#====================================================================
# gmake makefile fragment for building MEX functions using Unix
# Copyright 2007-2010 The MathWorks, Inc.
#====================================================================
#
OBJEXT = o
.SUFFIXES: .$(OBJEXT)

OBJLISTC = $(SRC_FILES:.c=.$(OBJEXT))
OBJLIST  = $(OBJLISTC:.cpp=.$(OBJEXT))

target: $(TARGET)

ML_INCLUDES = -I "$(MATLAB_ROOT)/extern/include"
ML_INCLUDES+= -I "$(MATLAB_ROOT)/simulink/include"
ML_INCLUDES+= -I "$(MATLAB_ROOT)/toolbox/shared/simtargets"
ML_INCLUDES+= -I "$(MATLAB_ROOT)/rtw/ext_mode/common"
ML_INCLUDES+= -I "$(MATLAB_ROOT)/rtw/c/src/ext_mode/common"
SYS_INCLUDE = $(ML_INCLUDES)

# Additional includes

SYS_INCLUDE += -I "/Users/ccaiafa/Dropbox/Kronecker\ Inpainting/Test3D/codegen/mex/Calc_CrossCorr3D_8"
SYS_INCLUDE += -I "/Users/ccaiafa/Dropbox/Kronecker"
SYS_INCLUDE += -I "/Users/ccaiafa/Dropbox/Kronecker\ Inpainting/Test3D/Inpainting/Test3D"

EML_LIBS = -lemlrt -lut -lmwmathutil -lmwblascompat32
SYS_LIBS += $(CLIBS) $(EML_LIBS)


EXPORTFILE = $(MEX_FILE_NAME_WO_EXT)_mex.map
ifeq ($(Arch),maci)
  EXPORTOPT = -Wl,-exported_symbols_list,$(EXPORTFILE)
  COMP_FLAGS = -c $(CFLAGS) -DMX_COMPAT_32
  CXX_FLAGS = -c $(CXXFLAGS) -DMX_COMPAT_32
  LINK_FLAGS = $(filter-out %mexFunction.map, $(LDFLAGS))
else ifeq ($(Arch),maci64)
  EXPORTOPT = -Wl,-exported_symbols_list,$(EXPORTFILE)
  COMP_FLAGS = -c $(CFLAGS) -DMX_COMPAT_32
  CXX_FLAGS = -c $(CXXFLAGS) -DMX_COMPAT_32
  LINK_FLAGS = $(filter-out %mexFunction.map, $(LDFLAGS))
else
  EXPORTOPT = -Wl,--version-script,$(EXPORTFILE)
  COMP_FLAGS = -c $(CFLAGS) -DMX_COMPAT_32 $(OMPFLAGS)
  CXX_FLAGS = -c $(CXXFLAGS) -DMX_COMPAT_32 $(OMPFLAGS)
  LINK_FLAGS = $(filter-out %mexFunction.map, $(LDFLAGS)) $(OMPLINKFLAGS)
endif

ifeq ($(Arch),maci)
  LINK_FLAGS += -L$(MATLAB_ROOT)/sys/os/maci
endif
ifeq ($(EMC_CONFIG),optim)
  ifeq ($(Arch),mac)
    COMP_FLAGS += $(CDEBUGFLAGS)
    CXX_FLAGS += $(CXXDEBUGFLAGS)
  else
    COMP_FLAGS += $(COPTIMFLAGS)
    CXX_FLAGS += $(CXXOPTIMFLAGS)
  endif
  LINK_FLAGS += $(LDOPTIMFLAGS)
else
  COMP_FLAGS += $(CDEBUGFLAGS)
  CXX_FLAGS += $(CXXDEBUGFLAGS)
  LINK_FLAGS += $(LDDEBUGFLAGS)
endif
LINK_FLAGS += -o $(TARGET)
LINK_FLAGS += 

CCFLAGS =  $(COMP_FLAGS) $(USER_INCLUDE) $(SYS_INCLUDE)
CPPFLAGS =   $(CXX_FLAGS) $(USER_INCLUDE) $(SYS_INCLUDE)

%.$(OBJEXT) : %.c
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : %.cpp
	$(CXX) $(CPPFLAGS) "$<"

# Additional sources

%.$(OBJEXT) : /Users/ccaiafa/Dropbox/Kronecker\ Inpainting/Test3D/codegen/mex/Calc_CrossCorr3D_8/%.c
	$(CC) $(CCFLAGS) "$<"



%.$(OBJEXT) : /Users/ccaiafa/Dropbox/Kronecker\ Inpainting/Test3D/codegen/mex/Calc_CrossCorr3D_8/%.cpp
	$(CXX) $(CPPFLAGS) "$<"



$(TARGET): $(OBJLIST) $(MAKEFILE)
	$(LD) $(EXPORTOPT) $(LINK_FLAGS) $(OBJLIST) $(SYS_LIBS)

#====================================================================

