# =============================================================================
#  FILE:
#    rti1006.tmf
#
#  DESCRIPTION:
#    RTI/RTI-MP Template Makefile:
#      Board   : DS1006
#      Version : bus/net
#      Make    : dsmake (OPUS MAKE 6.12)
#
#  AUTHOR(S):
#    J. Hagendorf
#
#  Copyright 2015, dSPACE GmbH. All rights reserved.
#
#  $RCSfile: rti1006.tmf $ $Revision: 2.112 $ $Date: 2019/06/21 11:04:20CEST $
#  $ProjectName: e:/ARC/Products/ImplSW/RTISW/RTI/Components/Build/Makefile/project.pj $
# =============================================================================
# NEVER CHANGE THIS LINE:
# RTI_TEMPLATE_MAKEFILE_VERSION = 260
# =============================================================================

# -----------------------------------------------------------------------------
# Make configuration for whitespace support
# -----------------------------------------------------------------------------

# NO_WARN_LEGACY_TOKENS

.OPTIONS : MacroQuoted
.OPTIONS : TargetQuoted

WS_APPEND_SEMIKOLON   = W|_WS_OUTER_|, =|_WS_INNER_|,|_WS_OUTER_|= ,Q-,>;,|_WS_INNER_|= ,Q+

WS_PACK_TARGET_ARGS   = "=|_WS_DBL_QUOTE_|
WS_UNPACK_TARGET_ARGS = |_WS_DBL_QUOTE_|="

# -----------------------------------------------------------------------------
# Support for parentheses in path names
# -----------------------------------------------------------------------------
.NOLIBRARY :

# Command to execute shell
EXEC_SHELL = -- call

# -----------------------------------------------------------------------------
# Evaluate VERBOSE mode
# -----------------------------------------------------------------------------

%ifdef VERBOSEFLAG
  .DEBUG_PRINT
  .DEBUG_RUN
% echo Windows: $(OS) Version: $(OSVERSION) Release: $(OSRELEASE)
% echo Windows: $(OS) Version: $(OSVERSION) Release: $(OSRELEASE) > CON
% exec "$(MAKE)" -V
% exec "$(MAKE)" -V >CON
% echo Running in VERBOSE mode for $(MAKEFILE) >CON
% echo Please wait ... >CON
% echo >CON
%endif

# -----------------------------------------------------------------------------
# NOTE:
#
# The user customization macros
#
#    SFCN_DIR, USER_SRCS, USER_SRCS_DIR, USER_INCLUDES_PATH, and USER_LIBS
#
# are now available from within the model-specific file model_usr.mk.
# RTI creates a template model_usr.mk file the first time a model is built.
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# RTW section: Host Environment Specifications and Customization Macros
# -----------------------------------------------------------------------------

# RTW specific environment specifications
# SECTION_DEFAULTS_RTW_BEGIN
MAKECMD                        = "%DSPACE_ROOT%\Exe\dsmake.exe"
HOST                           = PC
BUILD                          = yes
BUILD_SUCCESS                  = MAKE PROCESS SUCCEEDED
FILES_UP_TO_DATE               = FILES ARE UP TO DATE
BUILD_ERROR                    = [sprintf('*** Errors occurred during make process.\n*** Inspect MATLAB Command Window for details.\n*** Aborting RTI build procedure for model hilTest.')]
SYS_TARGET_FILE                = rti1006.tlc
PROJ_MARKER_FILE               = no
VERBOSE_BUILD_OFF_TREATMENT    = PRINT_OUTPUT_ALWAYS
# SECTION_DEFAULTS_RTW_END

# RTW specific customization macros
# SECTION_CUSTOMIZATION_RTW_BEGIN
MAKEFILE                       = hilTest.mk
BUILDARGS                      =  EXTMODE_STATIC_ALLOC=0 TMW_EXTMODE_TESTING=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 EXTMODE_TRANSPORT=0 MAT_FILE=0 COMBINE_OUTPUT_UPDATE_FCNS=0 INCLUDE_MDL_TERMINATE_FCN=1 MULTI_INSTANCE_CODE=0 ISPROTECTINGMODEL=NOTPROTECTING
MATLAB_ROOT                    = C:\Program Files\MATLAB\R2019b
MATLAB_BIN                     = C:\Program Files\MATLAB\R2019b\bin
MATLAB_ROOT_ALT                = C:\PROGRA~1\MATLAB\R2019b
MATLAB_BIN_ALT                 = C:\PROGRA~1\MATLAB\R2019b\bin
RELEASE_VERSION                = R2019b
RELEASE_VERSION               := $(RELEASE_VERSION,S'\.'_',W_,LC,S'^r'')
COMPUTER                       = PCWIN64
MODEL                          = hilTest
MODULES                        = rt_matrx.c rt_printf.c hilTest_data.c hilTest_rticanmm.c hilTest_trc_ptr.c rtGetInf.c rtGetNaN.c rt_nonfinite.c RTICANMMGetSimTime.c RTICANMM_MAIN_CAN.c RTICANMM_SETUP_CAVPCM.c
S_FUNCTIONS                    = 
S_FUNCTIONS_LIB                = "C:\Program Files\dSPACE RCPHIL 2019-B\Compiler\X86Tools\lib\libsupc++.a" "C:\Program Files\dSPACE RCPHIL 2019-B\Compiler\X86Tools\lib\libstlport.a"
SOLVER                         = 
NUMST                          = 2
TID01EQ                        = 1
NCSTATES                       = 0
EXT_MODE                       = 0
MULTITASKING                   = 0
# Support for parallel computing
MASTER_ANCHOR_DIR              = 
START_DIR                      = C:\Users\UWECOCAR3\Desktop\aiiiiiiiidan\Git\ArudinoCANDisplay\HIL
# Shared library for utility code
RTW_SHARED_LIB_SRCS_WILD       = 
RTW_SHARED_LIB_SRCS_DIR        = 
RTW_SHARED_LIB_OBJS_DIR        = 
RTW_SHARED_LIB                 = 
RTW_MODELLIB                   = 
RTW_MODELREF_LINK_LIBS         = 
RTW_MODELREF_TARGET_TYPE       = NONE
RTW_MODELREFS                  = 
RTW_MODELREF_INC_PATH          = 
RTW_RELATIVE_PATH_TO_ANCHOR    = ..
# SECTION_CUSTOMIZATION_RTW_END

# Deal with alternative MATLAB directory.
%if '$(MATLAB_ROOT)' != '$(MATLAB_ROOT_ALT)'
% set MATLAB_ROOT     = $(MATLAB_ROOT_ALT)
%endif
%if  '$(MATLAB_BIN)' != '$(MATLAB_BIN_ALT)'
% set MATLAB_BIN      = $(MATLAB_BIN_ALT)
%endif

# RTI specific customization macros.
# Avoid quote characters (', ") in macro value.
# SECTION_CUSTOMIZATION_RTI_BEGIN

_TMP_OPTION_NAME                 =   SSCALE
$(_TMP_OPTION_NAME)              = OPTION_DISABLED
$(_TMP_OPTION_NAME)             := $($(_TMP_OPTION_NAME),'=,"=)
%if    '$($(_TMP_OPTION_NAME))' != ''
% if   '$($(_TMP_OPTION_NAME))' == 'OPTION_DISABLED'
%   undef $(_TMP_OPTION_NAME)
% endif
%endif
%undef _TMP_OPTION_NAME


CC_OPTS                          = 
CC_OPTS                         := $(CC_OPTS,'=,"=)

CC_OPT_OPTS                      = USE_DEFAULT
CC_OPT_OPTS                     := $(CC_OPT_OPTS,'=,"=)

ENABLE_REAL_TIME_TESTING         = ON
ENABLE_REAL_TIME_TESTING        := $(ENABLE_REAL_TIME_TESTING,'=,"=)

RTI_ASSERTION_MODE               = OFF
RTI_ASSERTION_MODE              := $(RTI_ASSERTION_MODE,'=,"=)

SSTATE                           = RUN
SSTATE                          := $(SSTATE,'=,"=)

SMODE                            = RTSIM
SMODE                           := $(SMODE,'=,"=)

# SECTION_CUSTOMIZATION_RTI_END

# Define options which are not used for referenced models.
OPTS_UNUSED_FOR_REF_MODELS = \
	SMODE \
	SSTATE \
	ENABLE_REAL_TIME_TESTING \
	SSCALE

# Define options which are not used for MP build.
OPTS_UNUSED_FOR_MP_BUILD = \
	SMODE \
	SSTATE \
	SSCALE

#------------------------------------------------------------------------------
# REMOVE DUPLICATE MODULES
#------------------------------------------------------------------------------
%set KEEP_MODULES =
%foreach MOD_ITEM in $(MODULES)
#Check if module is already contained in current modules list.
%if !member($(MOD_ITEM),$(KEEP_MODULES))
%set KEEP_MODULES += $(MOD_ITEM)
%endif
%endfor
%set MODULES = $(KEEP_MODULES)
%undef KEEP_MODULES

# -----------------------------------------------------------------------------
# RTI section: Macros referenced by RTI API functions.
# -----------------------------------------------------------------------------

# Evaluate Target Type for Model Referencing.
%if '$(RTW_MODELREF_TARGET_TYPE)' == 'NONE'
   # Root Model or no Model Referencing
%  set _IS_ROOT_MODEL = 1
%else
   # Referenced Model for Model Referencing
%  undef _IS_ROOT_MODEL
%  foreach ITEM in $(OPTS_UNUSED_FOR_REF_MODELS)
%    undef $(ITEM)
%  endfor
%  undef OPTS_UNUSED_FOR_REF_MODELS
%endif

# SECTION_DEFAULTS_RTI_BEGIN
DEFAULT_CC_OPT_OPTS = -O2 -finline-functions -D_INLINE
# SECTION_DEFAULTS_RTI_END

# CC debug option indicating optional linking of RT debug libraries
# NOTE: the DS1006 does not support debug information in a format more recent than DWARF-2
CC_DBG_OPT = -g

# -----------------------------------------------------------------------------
# Specification of the dSPACE hardware and software
# -----------------------------------------------------------------------------

BOARD_TYPE     = 1006
RTI_BASE_DIR   = "$(DSPACE_ROOT)\MATLAB\RTI\RTI"
RTI_C_DIR      = $(RTI_BASE_DIR,>\C)
RTI_SFCN_DIR   = $(RTI_BASE_DIR,>\SFcn)

RTI_PLATFORM_DIR        = "$(DSPACE_ROOT)\MATLAB\RTI\RTI$(BOARD_TYPE)\RTI"
RTI_PLATFORM_SFCN_DIR   = "$(DSPACE_ROOT)\MATLAB\RTI\RTI$(BOARD_TYPE)\SFcn"
RTI_PLATFORM_C_DIR      = "$(DSPACE_ROOT)\MATLAB\RTI\RTI$(BOARD_TYPE)\C"

RTLIB_DIR      = "$(DSPACE_ROOT)\DS$(BOARD_TYPE)\RTLib"
RTLIB_ASM_PATH =
RTK_DIR        = "$(DSPACE_ROOT)\DS$(BOARD_TYPE)\RTKernel"

# -----------------------------------------------------------------------------
# Specify processor type, object and program extensions
# -----------------------------------------------------------------------------

PROCESSOR_FAMILY    = x86
PROCESSOR_TYPE      = 86

PRG_EXT             = x86

CC_SRC_EXT          = c
CXX_SRC_EXT         = cpp
ASM_SRC_EXT         = asm

%if $(MULTITASKING) == 1
% set CC_OBJ_EXT    = m$(PROCESSOR_TYPE)
% set ASM_OBJ_EXT   = am$(PROCESSOR_TYPE)
% set CXX_OBJ_EXT   = cppm$(PROCESSOR_TYPE)
%else
% set CC_OBJ_EXT    = o$(PROCESSOR_TYPE)
% set CXX_OBJ_EXT   = cppo$(PROCESSOR_TYPE)
% set ASM_OBJ_EXT   = ao$(PROCESSOR_TYPE)
%endif
LIBOBJ_EXT          = lo$(PROCESSOR_TYPE)

# For backwards compatibility with blockset and user makefiles
OBJ_EXT             = $(CC_OBJ_EXT)

# -----------------------------------------------------------------------------
# Define macro NEWLINE which expands to a newline character
# -----------------------------------------------------------------------------

NEWLINE =^

# DO NOT DELETE THE PRECEDING EMPTY LINE !

# -----------------------------------------------------------------------------
# Set RTW build directory
# -----------------------------------------------------------------------------

WORKDIR_ABS := "$(MAKEDIR,"=)"
WORKDIR_ABS :=  $(WORKDIR_ABS,>\$(RTW_RELATIVE_PATH_TO_ANCHOR),A,S'\\$$'')
WORKDIR      = $(RTW_RELATIVE_PATH_TO_ANCHOR)\\
WORKDIR_PATH = $(RTW_RELATIVE_PATH_TO_ANCHOR)

# -----------------------------------------------------------------------------
# Define temporary files
# -----------------------------------------------------------------------------

TMP_AR_OUT = _tmp_$(MODEL)_ar.txt
TMP_CC_OUT = _tmp_$(MODEL)_cc.txt
TMP_CC_MSG = _tmp_$(MODEL)_cc_msg.txt
TMP_LK_OUT = _tmp_$(MODEL)_lk.txt
TMP_MG_OUT = _tmp_$(MODEL)_mg.txt

TMP_FILE_LIST = $(TMP_AR_OUT) $(TMP_CC_OUT) $(TMP_CC_MSG) $(TMP_LK_OUT) $(TMP_MG_OUT)

# -----------------------------------------------------------------------------
# Define the start rule of the makefile
# -----------------------------------------------------------------------------

start : make_main

# -----------------------------------------------------------------------------
# Include RTI configuration makefile and user-specific makefile extension.
# -----------------------------------------------------------------------------

# Search path for makefiles to be included
%setenv INIT = .;$(WORKDIR_PATH);

# Path setting extended by RTI blockset makefiles
BLOCKSET_INCLUDES =
BLOCKSET_SRCS_DIR =
BLOCKSET_SRCS     =
BLOCKSET_ASM_SRCS =
BLOCKSET_OBJS     =
BLOCKSET_LIBS     =

# Required for protected model build, since _usr.mk file is not generated for PM
%if exists($(WORKDIR)$(MODEL)_usr.mk)
%  include $(WORKDIR)$(MODEL)_usr.mk
%endif

%ifdef _IS_ROOT_MODEL
%  include         $(MODEL)_rti.mk
%else
   # Predefine macros set by $(MODEL)_rti.mk.
%  set MDL_CUSTOM_C_SRCS        =
%  set MDL_CUSTOM_ASM_SRCS      =
%  set MDL_CUSTOM_LIBS          =
%  set MDL_CUSTOM_OBJS          =
%  set MDL_CUSTOM_SRCS_DIR      =
%  set MDL_CUSTOM_INCLUDES_PATH =

   # Empty targets defined by $(MODEL)_rti.mk.
blockset_init          :
blockset_clean         :
blockset_deps          :
blockset_after_linkage :

%endif

%ifndef USER_MAKEFILE_VERSION
%  set  USER_MAKEFILE_VERSION = 0
%endif

# Define list of all user makefile macros
%set USER_MACROS_LIST = \
	SFCN_DIR \
	USER_SRCS \
	USER_ASM_SRCS \
	USER_SRCS_DIR \
	USER_INCLUDES_PATH \
	USER_OBJS USER_LIBS

# -----------------------------------------------------------------------------
# MP-specific settings
# -----------------------------------------------------------------------------

# Check Build type: Are we building a RTI-MP model? Then undefine options
# unsupported for MP-Builds
%undef _IS_MP_BUILD
%ifdef BUILDTYPE
%  if $(BUILDTYPE,"=) == RTI_MP
%    set _IS_MP_BUILD = 1
%    foreach ITEM in $(OPTS_UNUSED_FOR_MP_BUILD)
%      undef $(ITEM)
%    endfor
%    undef OPTS_UNUSED_FOR_MP_BUILD
%  endif
%endif

# set path to MP C directory
%ifdef _IS_MP_BUILD
%  set RTIMP_C_DIR = "$(DSPACE_ROOT)\MATLAB\RTIMP\C"
%endif

# -----------------------------------------------------------------------------
# Application type definition.
# -----------------------------------------------------------------------------

%undef  _IS_CXX_APPL
%ifdef  USER_BUILD_CPP_APPL
% if "$(USER_BUILD_CPP_APPL, UC)" == "ON"
%   set _IS_CXX_APPL = 1
% endif
%endif

# -----------------------------------------------------------------------------
# Treat User Makefile macros allowing paths.
# Need to prepend "..\" to relative paths, if build directory is used.
# -----------------------------------------------------------------------------

%set USER_MACROS_ALLOWING_PATHS = \
	SFCN_DIR \
	USER_SRCS_DIR \
	USER_INCLUDES_PATH \
	USER_OBJS \
	USER_LIBS

%foreach USER_MACRO_IN in $(USER_MACROS_ALLOWING_PATHS)
%  set USER_MACRO_OUT
%  if '$($(USER_MACRO_IN))' != ''
%    foreach ITEM in $($(USER_MACRO_IN))
%      set TMP_RELPATH_ITEM = $(ITEM,<$(WORKDIR))
%      if exists("$(TMP_RELPATH_ITEM,"=)") # ... existing item with relative path
%        set USER_MACRO_OUT += $(TMP_RELPATH_ITEM)
%      elseif exists("$(ITEM,"=)") # ... existing item with absolute path
%        set USER_MACRO_OUT += $(ITEM)
%      else # ... missing item, do not add to output list
%        ifndef USER_MACRO_WARN
%          set USER_MACRO_WARN_MESSAGE =
%          set USER_MACRO_WARN_MESSAGE +=WARNING: One or more files/directories from the User Makefile do not exist:
%          set USER_MACRO_WARN
%        endif
%        set USER_MACRO_WARN_MESSAGE +=$(NEWLINE)  -\> $(ITEM)
%      endif # if exists()
%      undef TMP_RELPATH_ITEM
%    endfor
%  endif
%  set $(USER_MACRO_IN) = $(USER_MACRO_OUT)
%endfor

# -----------------------------------------------------------------------------
# Process command option
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# Tool Definitions
# -----------------------------------------------------------------------------

COMP_ROOT = "$(DSPACE_ROOT)\Compiler\X86Tools"

# x86 compiler version is stored in a makefile include (compiler_version.mk).
# This include file sets the macro COMP_VERSION
COMP_VER_INFO_FILE = $(COMP_ROOT,>\LIB\compiler_version.mk)
%if exists("$(COMP_VER_INFO_FILE,"=)")
%  include $(COMP_VER_INFO_FILE)
%endif

%ifndef DS$(BOARD_TYPE)_COMPILER_VER
  COMP_VS_DISP = (GCC Vs $(COMP_VERSION))
%else
  COMP_VS_DISP = (DS$(BOARD_TYPE) Compiler Vs $(DS$(BOARD_TYPE)_COMPILER_VER), GCC Vs $(COMP_VERSION))
%endif
COMP_BIN = $(COMP_ROOT,>\BIN)
COMP_LIB = $(COMP_ROOT,>\LIB)
COMP_INC = $(COMP_ROOT,>\INCLUDE\NEWLIB)

%undef _IS_CXX_STL
%ifdef _IS_CXX_APPL
% set COMP_STL_LIBFILE = $(COMP_LIB,>\libsupc++.a) $(COMP_LIB,>\libstlport.a)
% set COMP_INC = $(COMP_ROOT,>\INCLUDE\STLPORT) $(COMP_ROOT,>\INCLUDE\C++) $(COMP_INC)
% set _IS_CXX_STL = 1
%endif

CC  = $(COMP_BIN,>\i686-elf-gcc.exe)
CXX = $(COMP_BIN,>\i686-elf-g++.exe)
AS  = $(COMP_BIN,>\i686-elf-as.exe)
AR  = $(COMP_BIN,>\i686-elf-ar.exe)
LD  = $(COMP_BIN,>\i686-elf-ld.exe)

MG  = "$(DSPACE_ROOT)\exe\x86-insmod.exe"

INCPATH_OPT     = -I
ASM_INCPATH_OPT = -I

# -----------------------------------------------------------------------------
# Shared library for utility code
# -----------------------------------------------------------------------------

%undef HAS_RTW_SHARED_LIB
RTW_SHARED_INCLUDES =
RTW_SHARED_LIB_SRCS =
RTW_SHARED_LIB_OBJS =

%ifdef _IS_ROOT_MODEL
%  if '$(RTW_SHARED_LIB)' != ''
%    set HAS_RTW_SHARED_LIB       = 1
%    set RTW_SHARED_INCLUDES      = $(RTW_SHARED_LIB_SRCS_DIR)
%    set RTW_SHARED_LIB_SRCS      = $(RTW_SHARED_LIB_SRCS_WILD,*F)
%    set RTW_SHARED_LIB_OBJS      = $(RTW_SHARED_LIB_SRCS,S'\.$(CC_SRC_EXT)$$'.$(LIBOBJ_EXT)')
%    set RTW_SHARED_LIB_OBJS_DIR := $(RTW_SHARED_LIB_OBJS_DIR,A,"=, =|_WS_INNER_|)
%    set RTW_SHARED_LIB_OBJS     := $(RTW_SHARED_LIB_OBJS,F,<$(RTW_SHARED_LIB_OBJS_DIR,>\))
%    set RTW_SHARED_LIB_OBJS     := $(RTW_SHARED_LIB_OBJS,<",Q-,>",|_WS_INNER_|= ,Q+)
%  endif
%endif # _IS_ROOT_MODEL

%if '$(RTW_SHARED_LIB_SRCS_DIR)' != ''
%  set RTW_SHARED_INCLUDES      = $(RTW_SHARED_LIB_SRCS_DIR)
%endif

# -----------------------------------------------------------------------------
# Source files and objects
# -----------------------------------------------------------------------------

# Standard Source Files -------------------------------------------------------

%ifdef _IS_MP_BUILD
%  set SIMENGINE = $(MODEL,"=)_simeng
%else
%  set SIMENGINE = rti_sim_engine
%endif

%ifndef _IS_CXX_APPL
% set RTI_INIT_SRC = rti_init_c.c
%else
% set RTI_INIT_SRC = rti_init_cpp.c
%endif # _IS_CXX_APPL

%ifdef _IS_ROOT_MODEL
   # Standard Sources for Root Model
STD_SRCS = \
	 $(MODEL).c \
	 $(MODULES) \
	 $(SIMENGINE).c \
	 $(RTI_INIT_SRC) \
	 rt_sim.c

%else
   # Standard Sources for Referenced Model
STD_SRCS = \
	 $(MODULES)

%endif

# standard dependencies for model and simengine
SIMENG_DEP_FILES = \
	               $(SIMENGINE).c \
	               $(MODEL).h \
	               rtModel.h \
	               $(MODEL)_usr.c \
	               $(MODEL)_rti.c \
	               $(MODEL)_th.c \
	               $(MAKEFILE)

%ifdef _IS_MP_BUILD
%  set SIMENG_DEP_FILES += $(MODEL)_ipc.h 
%endif


MODEL_DEP_FILES = \
	               $(MODEL).c \
	               $(MODEL).h \
	               rtModel.h \
	               $(MAKEFILE)

%ifdef _IS_MP_BUILD
%  set MODEL_DEP_FILES += $(MODEL)_ipc.h 
%endif

# Sources which dependent on compiler defines from the makefile ---------------

%ifdef _IS_ROOT_MODEL
%  set MAKEFILE_DEP_SRCS = rt_sim.c
%  set MAKEFILE_DEP_OBJS = $(MAKEFILE_DEP_SRCS,S'\.$(CC_SRC_EXT)$$'.$(CC_OBJ_EXT)')
%else
%  set MAKEFILE_DEP_OBJS =
%endif

# Sources and objects for RTW Custom Run-Time libraries -------------------

# List of RTW Custom Run-Time Libraries and related sources.

RTWCUST_LIBS             =
RTWCUST_LIB_SRCS         =
RTWCUST_LIB_OBJS         =
RTWCUST_PRECOMP_LIBS     =

RTWCUST_LIB_PLATFORM_EXT = _r$(RELEASE_VERSION)_ds$(BOARD_TYPE)

# RTW Custom Run-Time Libraries from rtwmakecfg.m (to be built).


# RTW Custom Run-Time Libraries from rtwmakecfg.m (pre-compiled).

# Assembler sources -----------------------------------------------------------

ASM_SRCS = $(BLOCKSET_ASM_SRCS) $(MDL_CUSTOM_ASM_SRCS) $(USER_ASM_SRCS)

# Define objects --------------------------------------------------------------

STD_OBJS           = $(STD_SRCS,         S'\.$(CC_SRC_EXT)$$'.$(CC_OBJ_EXT)',S'\.$(CXX_SRC_EXT)$$'.$(CXX_OBJ_EXT)')
MODULE_OBJS        = $(MODULES,          S'\.$(CC_SRC_EXT)$$'.$(CC_OBJ_EXT)',S'\.$(CXX_SRC_EXT)$$'.$(CXX_OBJ_EXT)')
BLOCKSET_C_OBJS    = $(BLOCKSET_SRCS,    S'\.$(CC_SRC_EXT)$$'.$(CC_OBJ_EXT)',S'\.$(CXX_SRC_EXT)$$'.$(CXX_OBJ_EXT)')
SFCN_OBJS          = $(S_FUNCTIONS,      S'\.$(CC_SRC_EXT)$$'.$(CC_OBJ_EXT)',S'\.$(CXX_SRC_EXT)$$'.$(CXX_OBJ_EXT)')
USER_SRCS_OBJS     = $(USER_SRCS,        S'\.$(CC_SRC_EXT)$$'.$(CC_OBJ_EXT)',S'\.$(CXX_SRC_EXT)$$'.$(CXX_OBJ_EXT)')
MDL_CUSTOM_C_OBJS  = $(MDL_CUSTOM_C_SRCS,S'\.$(CC_SRC_EXT)$$'.$(CC_OBJ_EXT)',S'\.$(CXX_SRC_EXT)$$'.$(CXX_OBJ_EXT)')
# RTWCUST_LIB_OBJS defined above
ASM_OBJS           = $(ASM_SRCS,         S'\.$(ASM_SRC_EXT)$$'.$(ASM_OBJ_EXT)')

# All objects to be built.
ALL_OBJS  = $(STD_OBJS) $(BLOCKSET_C_OBJS) $(BLOCKSET_OBJS) $(SFCN_OBJS) \
	    $(USER_SRCS_OBJS) $(RTWCUST_LIB_OBJS) \
	    $(MDL_CUSTOM_C_OBJS) $(MDL_CUSTOM_OBJS) $(ASM_OBJS)

# Define output files ---------------------------------------------------------

%ifdef _IS_ROOT_MODEL
%  set PROGRAM = $(WORKDIR)$(MODEL).$(PRG_EXT)
%  set MAPFILE = $(WORKDIR)$(MODEL).map
%else
%  set PRODUCT = $(RTW_MODELLIB)
%endif

# -----------------------------------------------------------------------------
# Libraries
# -----------------------------------------------------------------------------

# RTWCUST_LIBS and RTWCUST_PRECOMP_LIBS defined above

COMPILER_LIBS =

# Additional add-on/hotfix/feature extension files
# - extension of patched relocatable object files is .opj
# - extension of patched relocatable debug object files is .opjdbg
# - extension of additional library files is .lib

%ifdef _IS_ROOT_MODEL
%  set CC_OPT_TMP = $(CC_OPT_OPTS) $(CC_OPTS)
#  if compiler options contain the debug option, define the according debug library to be linked against
%  if '$(CC_OPT_TMP,M^$(CC_DBG_OPT)$$)' == ''
%    set DSPACE_RTLIBS = $(RTLIB_DIR,>\ds$(BOARD_TYPE).lib)
%    set DSPACE_RTLIB_OPJS_SPEC = $(RTLIB_DIR,>\*.opj)
%    set DSPACE_RTLIB_OPJS := $(DSPACE_RTLIB_OPJS_SPEC,*F,M\.opj$$)
%  else
%    set DSPACE_RTLIBS = $(RTLIB_DIR,>\ds$(BOARD_TYPE)dbg.lib)
%    set DSPACE_RTLIB_OPJS_SPEC = $(RTLIB_DIR,>\*.opjdbg)
%    set DSPACE_RTLIB_OPJS := $(DSPACE_RTLIB_OPJS_SPEC,*F,M\.opjdbg$$)
%  endif
%  set DSPACE_RTLIB_ADDLIBS_SPEC = $(RTLIB_DIR,>\*.lib)
%  set DSPACE_RTLIB_ADDLIBS := $(DSPACE_RTLIB_ADDLIBS_SPEC,*F,M\.lib$$,Nds$(BOARD_TYPE)dbg.lib$$,N[dD][sS]$(BOARD_TYPE).lib$$)
%  set DSPACE_EXT_LINK_FILES = $(DSPACE_RTLIB_OPJS) $(DSPACE_RTLIB_ADDLIBS)
%  foreach ITEM IN $(DSPACE_EXT_LINK_FILES)
%    echo USING RTLIB ADD-ON OR HOTFIX: $(ITEM)
%  endfor
%  set DSPACE_LIBS = \
	$(BLOCKSET_LIBS) \
	$(MDL_CUSTOM_LIBS) \
	$(RTK_DIR,>\rtk$(BOARD_TYPE).lib) \
	$(DSPACE_RTLIBS)
	
%  undef DSPACE_RTLIBS
%  undef CC_OPT_TMP
%else  # _IS_ROOT_MODEL
%  set DSPACE_LIBS = \
	$(MDL_CUSTOM_LIBS)
%endif #_IS_ROOT_MODEL

%ifdef _IS_ROOT_MODEL
%  set COMPILER_LIBS = 
%  set CC_LIBS = $(COMP_LIB,>\libgcc.a) $(COMP_LIB,>\libc.a) $(COMP_LIB,>\libm.a)
%  set CXX_LIBS = $(COMP_LIB,>\libgcc.a) $(COMP_STL_LIBFILE) $(COMP_LIB,>\libc.a) $(COMP_LIB,>\libm.a)

%  ifndef _IS_CXX_APPL
%    set COMPILER_LIBS = $(CC_LIBS)
%  else
%    set COMPILER_LIBS = $(CXX_LIBS)
%  endif # _IS_CXX_APPL

# Define input files for application.
% set PROGRAM_LINK_OBJS_BEGIN = $(COMP_LIB,>\crti.o) $(COMP_LIB,>\crtbegin.o)

PROGRAM_LINK_OBJS_END   = $(COMP_LIB,>\crtend.o) $(COMP_LIB,>\crtn.o)

PROGRAM_LINK_OBJS  = \
	                $(USER_SRCS_OBJS) \
	                $(USER_OBJS) \
	                $(SFCN_OBJS) \
	                $(STD_OBJS) \
	                $(BLOCKSET_OBJS) \
	                $(BLOCKSET_C_OBJS) \
	                $(MDL_CUSTOM_OBJS) \
	                $(MDL_CUSTOM_C_OBJS) \
	                $(ASM_OBJS)

PROGRAM_LINK_LIBS  = \
	                $(USER_LIBS) \
	                $(DSPACE_EXT_LINK_FILES) # before RTLib in DSPACE_LIBS \
	                $(DSPACE_LIBS) \
	                $(S_FUNCTIONS_LIB) \
	                $(RTW_SHARED_LIB) \
	                $(RTWCUST_LIBS) \
	                $(RTWCUST_PRECOMP_LIBS) \
	                $(RTW_MODELREF_LINK_LIBS) \
	                $(COMPILER_LIBS)

%else  # _IS_ROOT_MODEL
  # Define contents of RTW model library.
PRODUCT_LIB_OBJS  = \
	                $(USER_SRCS_OBJS) \
	                $(USER_OBJS) \
	                $(SFCN_OBJS) \
	                $(STD_OBJS) \
	                $(BLOCKSET_OBJS) \
	                $(BLOCKSET_C_OBJS) \
	                $(MDL_CUSTOM_OBJS) \
	                $(MDL_CUSTOM_C_OBJS) \
	                $(ASM_OBJS)

PRODUCT_LIB_LIBS  = \
	                $(USER_LIBS) \
	                $(S_FUNCTIONS_LIB)
%endif # _IS_ROOT_MODEL

# -----------------------------------------------------------------------------
# Tool options
# -----------------------------------------------------------------------------

# Compiler options ------------------------------------------------------------

# C compiler options always required
CC_REQ_OPTS  = \
	-B$(COMP_BIN) \
	-pipe \
	-mpreferred-stack-boundary=3 \
	-march=opteron \
	-mtune=opteron \
	-msse2 \
	-mfpmath=sse \
	-fno-strict-aliasing \
	-fno-common \
	-fomit-frame-pointer \
	-ffast-math \
	-Werror-implicit-function-declaration \
	-o $(.TARGET)

CXX_REQ_OPTS = \
	-B$(COMP_BIN) \
	-pipe \
	-mpreferred-stack-boundary=3 \
	-march=opteron \
	-mtune=opteron \
	-msse2 \
	-mfpmath=sse \
	-fno-strict-aliasing \
	-fno-common \
	-fomit-frame-pointer \
	-ffast-math \
	-fno-non-call-exceptions \
	-o $(.TARGET)

# C compiler options
%ifndef CC_OPTS
%  set  CC_OPTS =
%endif

# C compiler optimization options
OPT_OPTS = $(DEFAULT_CC_OPT_OPTS)
%ifdef CC_OPT_OPTS
%  if '$(CC_OPT_OPTS)' == 'USE_NONE'
%    set OPT_OPTS = -O0
%  elseif '$(CC_OPT_OPTS)' != 'USE_DEFAULT' 
%    set OPT_OPTS = $(CC_OPT_OPTS)
%  endif
%endif

# Compiler message options (command line option precedes)
MSG_OPTS =

# Debugging options (command line option precedes)
DBG_OPTS =

# Simulation mode options
# These are only necessary for RTI builds, in RTI-MP these options are generated in simengine
%if !defined(_IS_MP_BUILD)
%  ifdef SSTATE
%    set SSTATE_OPT = -DSSTATE=$(SSTATE)
%  else
%    set SSTATE_OPT =
%  endif
%  ifdef SMODE  
%    set SMODE_OPT = -DSMODE=$(SMODE)
%  else
%    set SMODE_OPT =
%  endif
%  ifdef SSCALE
%    set SSCALE_OPT = -DRTI_TIMER_TASK_TIME_SCALE=$(SSCALE)
%  else
%    set SSCALE_OPT =
%  endif
%endif

# RTI assertion mode options
ASSERTION_DEFINE_VALUE = RTI_ASSERTION_MODE_OFF
%ifdef RTI_ASSERTION_MODE
% if member($(RTI_ASSERTION_MODE,UC), OFF WARN STOP)
%   set ASSERTION_DEFINE_VALUE = RTI_ASSERTION_MODE_$(RTI_ASSERTION_MODE,UC)
% endif
%endif
ASSERTION_DEFINE = -DRTI_ASSERTION_MODE=$(ASSERTION_DEFINE_VALUE)

DEFINE_OPTS = \
	# For model-wide information use rtModel data-structure instead of simStruct. \
	-DUSE_RTMODEL \
	-DMODEL=$(MODEL) \
	-DMT=$(MULTITASKING) \
	-DRT \
	-DNUMST=$(NUMST) \
	-DNCSTATES=$(NCSTATES) \
	-DTID01EQ=$(TID01EQ) \
	-DNO_PRINTF \
	-D_DS$(BOARD_TYPE) \
	-DRTI_BUILD \
	$(ASSERTION_DEFINE)

DEFINE_CXX_OPTS = -U_INLINE

%if !defined(_IS_MP_BUILD)
%  set DEFINE_OPTS += $(SSTATE_OPT)  
%  set DEFINE_OPTS += $(SMODE_OPT)
%  set DEFINE_OPTS += $(SSCALE_OPT)
%endif

%ifdef _IS_MP_BUILD
%  set DEFINE_OPTS += -DRTIMP_BUILD
%endif

%ifndef _IS_ROOT_MODEL 
%  ifdef _IS_CXX_APPL
%    set DEFINE_OPTS += -DRTI_CXX_ENABLED
%  endif
%endif

%ifdef _IS_ROOT_MODEL
%  if "$(ENABLE_REAL_TIME_TESTING,UC)" == "ON"
%    set DEFINE_OPTS += -DRTT_ENABLE
%  endif
%endif

# RTW Custom Include paths from rtwmakecfg.m.
RTWCUST_INCLUDES = \
	"$(START_DIR)" \
	"$(START_DIR)\hilTest_rti1006" \
	"$(MATLAB_ROOT)\extern\include" \
	"$(MATLAB_ROOT)\simulink\include" \
	"$(MATLAB_ROOT)\rtw\c\src" \
	"$(MATLAB_ROOT)\rtw\c\src\ext_mode\common" \
	"$(START_DIR)\RTICANMM_FILES" \
	"C:\PROGRA~1\DSPACE~4\MATLAB\RTICANMM\C"
# End: Custom Include paths.

MATLAB_INCLUDES = \
	$(MATLAB_ROOT,>\simulink\include) \
	$(MATLAB_ROOT,>\extern\include) \
	$(MATLAB_ROOT,>\rtw\c\src) \
	$(MATLAB_ROOT,>\rtw\c\src\ext_mode\common) \
	$(RTWCUST_INCLUDES) \
	$(RTW_SHARED_INCLUDES) \
	$(RTW_RELATIVE_PATH_TO_ANCHOR) \
	$(RTW_MODELREF_INC_PATH)

DSPACE_INCLUDES = \
	$(RTK_DIR) \
	$(RTLIB_DIR) \
	$(RTI_C_DIR) \
	$(RTI_SFCN_DIR) \
	$(RTI_PLATFORM_C_DIR) \
	$(RTI_PLATFORM_SFCN_DIR)

%ifdef _IS_MP_BUILD
%  set DSPACE_INCLUDES += $(RTIMP_C_DIR)
%endif

INCLUDES = \
	. \
	$(WORKDIR_PATH) \
	$(MDL_CUSTOM_INCLUDES_PATH) \
	$(SFCN_DIR) \
	$(USER_INCLUDES_PATH) \
	$(COMP_INC) \
	$(DSPACE_INCLUDES) \
	$(BLOCKSET_INCLUDES) \
	$(MATLAB_INCLUDES)
	
INCLUDES := $(INCLUDES,S'\\$$'')

%set KEEP_INC_PATHS =
%foreach INC_ITEM in $(INCLUDES)
# Check if path exists
% if dir("$(INC_ITEM,"=)")
    # Check if path is already contained in current include path list.
%   if !member("$(INC_ITEM,"=)",$(KEEP_INC_PATHS))
%     set KEEP_INC_PATHS += "$(INC_ITEM,"=)"
%   endif
% endif
%endfor

%set INCLUDES := $(KEEP_INC_PATHS)
%undef KEEP_INC_PATHS

%foreach INCPATH in $(INCLUDES)
%  set INCLUDE_PATH += $(INCPATH_OPT)$(INCPATH)
%end

CC_FLAGS  = $(CC_REQ_OPTS)  $(MSG_OPTS) $(OPT_OPTS) $(CC_OPTS) $(DBG_OPTS) $(DEFINE_OPTS) $(INCLUDE_PATH)
CXX_FLAGS = $(CXX_REQ_OPTS)  $(MSG_OPTS) $(OPT_OPTS) $(CC_OPTS) $(DBG_OPTS) $(DEFINE_OPTS) $(DEFINE_CXX_OPTS) $(INCLUDE_PATH)

# Sources needing divergent compiler options (mostly platform specific) -------

CC_FLAGS_EXTRA1      = $(CC_FLAGS) -fno-unsafe-math-optimizations -fno-finite-math-only
CC_FLAGS_EXTRA1_SRCS = rt_nonfinite.c

# Assembler options -----------------------------------------------------------

# Assembler options (command line option precedes)
ASM_OPTS        =
ASM_INCLUDES = \
	. \
	$(WORKDIR_PATH) \
	$(RTLIB_ASM_PATH) \
	$(USER_INCLUDES_PATH)

%foreach ASMINCPATH in $(ASM_INCLUDES)
%  set ASM_INCLUDE_PATH += $(ASM_INCPATH_OPT)$(ASMINCPATH)
%end

ASM_REQ_OPTS    =
ASM_DEFINE_OPTS = --defsym DS_BOARD_TYPE=$(BOARD_TYPE)
AS_OPTS         = $(ASM_REQ_OPTS) $(ASM_OPTS) $(ASM_DEFINE_OPTS) \
                  $(ASM_INCLUDE_PATH)
ASM_CMD_LINE    = $(AS_OPTS) -o $(.TARGET) $(.SOURCE)

# Linker options --------------------------------------------------------------
# -r : generate relocateable output
LNK_OPTS = -r

# Debugging option for linker
LNK_DBG_OPTS =

# Archiver options ------------------------------------------------------------
# -M : control archiver with command language
AR_OPTS = -M

# generate table of contents
# -t : Display a table listing the contents of archive
AR_TBL_OPTS = -t


# -----------------------------------------------------------------------------
# Search path for make utility
# -----------------------------------------------------------------------------

.PATH.h     := $(INCLUDES,$(WS_APPEND_SEMIKOLON))

TMP_PATH_CC  = .
TMP_PATH_CC += $(WORKDIR_PATH)
TMP_PATH_CC += $(MDL_CUSTOM_SRCS_DIR)
TMP_PATH_CC += $(SFCN_DIR)
TMP_PATH_CC += $(USER_SRCS_DIR)
TMP_PATH_CC += $(RTI_C_DIR)
TMP_PATH_CC += $(RTI_SFCN_DIR)
TMP_PATH_CC += $(RTI_PLATFORM_C_DIR)
TMP_PATH_CC += $(RTI_PLATFORM_SFCN_DIR)
TMP_PATH_CC += $(BLOCKSET_SRCS_DIR)
TMP_PATH_CC += $(RTLIB_DIR)
TMP_PATH_CC += $(MATLAB_ROOT,>\rtw\c\src)
%ifdef _IS_MP_BUILD
%  set TMP_PATH_CC += $(RTIMP_C_DIR)
%endif
# RTW Custom Source paths from rtwmakecfg.m.
TMP_PATH_CC += "C:\PROGRA~1\DSPACE~4\MATLAB\RTICANMM\C"
TMP_PATH_CC += "$(START_DIR)\RTICANMM_FILES"
TMP_PATH_CC += "C:\PROGRA~1\DSPACE~4\MATLAB\RTICANMM\TLC"
TMP_PATH_CC += "$(MATLAB_ROOT)\rtw\c\src"
TMP_PATH_CC += "$(MATLAB_ROOT)\simulink\src"
# End: Custom Source paths.
TMP_PATH_CC += $(MATLAB_ROOT,>\simulink\src)

.PATH.$(CC_SRC_EXT) := $(TMP_PATH_CC,$(WS_APPEND_SEMIKOLON))
%undef TMP_PATH_CC

%ifdef _IS_CXX_APPL
.PATH.$(CXX_SRC_EXT) := $(.PATH.$(CC_SRC_EXT))
%endif # _IS_CXX_APPL

TMP_PATH_ASM = .
TMP_PATH_ASM += $(WORKDIR_PATH)
TMP_PATH_ASM += $(BLOCKSET_SRCS_DIR)
TMP_PATH_ASM += $(MDL_CUSTOM_SRCS_DIR)
TMP_PATH_ASM += $(RTLIB_ASM_PATH)
TMP_PATH_ASM += $(USER_SRCS_DIR)

.PATH.$(ASM_SRC_EXT) := $(TMP_PATH_ASM,$(WS_APPEND_SEMIKOLON))
%undef TMP_PATH_ASM

# =============================================================================
# Rules
# =============================================================================

# -----------------------------------------------------------------------------
# First rule of the makefile
# -----------------------------------------------------------------------------

%if defined(_IS_MP_BUILD)
make_main : start_check init compile_deps link             cleanup          make_success
%else     # _IS_MP_BUILD
%  if defined(_IS_ROOT_MODEL)
make_main : start_check init compile_deps link             cleanup          make_success
%  else     # _IS_ROOT_MODEL
make_main : start_check init compile_deps      mdl_ref_lib cleanup          make_success
%  endif    # _IS_ROOT_MODEL
%endif   # _IS_MP_BUILD

# -----------------------------------------------------------------------------
# Standard message rules
# -----------------------------------------------------------------------------

make_success_quiet :
	%abort 0

make_abort_quiet :
	%abort

make_success :
    %echo	
	%if   '$(MODEL)' != 'rtwshared'
		%echo $(BUILD_SUCCESS)
		%ifdef VERBOSEFLAG
			%echo $(BUILD_SUCCESS) > CON
		%endif
	%else
		%ifdef HAS_COMPILED
			%echo $(BUILD_SUCCESS)
			%ifdef VERBOSEFLAG
				%echo $(BUILD_SUCCESS) > CON
			%endif
		%else
			%echo $(FILES_UP_TO_DATE)
		%endif    
	%endif
    %echo

make_abort :
	%echo
	%echo MAKE PROCESS ABORTED
	%ifdef VERBOSEFLAG
	  %echo MAKE PROCESS ABORTED  > CON
	%endif
	%echo
	%abort

# -----------------------------------------------------------------------------
# Start rule (messages and checks)
# -----------------------------------------------------------------------------

start_check :
	%echo
	%ifdef _IS_ROOT_MODEL
	  %if $(MULTITASKING) == 1
	    %echo BUILDING APPLICATION "$(MODEL)" (Multiple Timer Task Mode)
	  %else
	    %echo BUILDING APPLICATION "$(MODEL)" (Single Timer Task Mode)
	  %endif # MULTITASKING
	%elseif '$(MODEL)' == 'rtwshared'
	  %echo BUILDING SHARED UTILITIES
	%else
	  %echo BUILDING REFERENCED MODEL "$(MODEL)"
	%endif # _IS_ROOT_MODEL
	%echo
	%echo WORK  DIRECTORY "$(WORKDIR_ABS,"=)"
	%echo BUILD DIRECTORY "$(MAKEDIR,"=)"
	%ifdef HAS_RTW_SHARED_LIB
	  %echo SHARED LOCATION "$(RTW_SHARED_LIB_SRCS_DIR,A,"=)"
	%endif
	%echo TARGET COMPILER "$(COMP_ROOT,"=)" $(COMP_VS_DISP)
	%echo
	%if !(exists("$(CC,"=)") && exists("$(AS,"=)") && exists("$(LD,"=)") && exists("$(AR,"=)"))
	  %echo ERROR: Cannot find target compiler. Possible reasons are:
	  %echo        - Compiler not installed.
	  %echo        - Environment variable DSPACE_ROOT points to wrong directory.
	  %do make_abort
	%endif
	%if !(exists("$(MG,"=)"))
	  %echo ERROR: Cannot find $(MG,F) tool. Possible reasons are:
	  %echo        - RTLib$(BOARD_TYPE) not installed.
	  %echo        - Environment variable DSPACE_ROOT points to wrong directory.
	  %do make_abort
	%endif
	#       Compiler version deteceted via makefile include
	%if !exists("$(COMP_VER_INFO_FILE,"=)")
	  %echo ERROR: Unable to determine x86 compiler version.
	  %echo        File $(COMP_VER_INFO_FILE) is missing.
	  %echo
	  %echo        COMP_ROOT = "$(COMP_ROOT,"=)"
	  %do make_abort
	%endif
	#       Include file exists, but macro COMP_VERSION not set.
	%ifndef COMP_VERSION
	  %echo ERROR: Failed to determine x86 compiler version.
	  %echo        Macro COMP_VERSION not set in file
	  %echo        $(COMP_VER_INFO_FILE).
	  %echo
	  %echo        COMP_ROOT = "$(COMP_ROOT,"=)"
	  %do make_abort
	%endif
	%if !(dir("$(MATLAB_BIN,"=)"))
	  %echo ERROR: MATLAB root directory not found.
	  %echo        The MATLAB root directory was supposed to be at
	  %echo          $(MATLAB_ROOT)
	  %echo        but no longer is available there. If this model was
	  %echo        generated on another environment rebuild the model.
	  %do make_abort
	%endif
	#the macros returns the value NULL, when USR Makefile does not exist, e.g. for protected model
	%if !null($(USER_MAKEFILE_VERSION))
	  %if ($(USER_MAKEFILE_VERSION) != 1) && ($(USER_MAKEFILE_VERSION) != 2)
	    %echo ERROR: User makefile $(MODEL)_usr.mk has a version
	    %echo        incompatible to this makefile: $(USER_MAKEFILE_VERSION)
	    %echo        Please use a new template.
	    %do make_abort
	  %endif
	  %if $(USER_MAKEFILE_VERSION) < 2
	    %echo INFO: User makefile $(MODEL)_usr.mk comes from an older RTI version.
	    %echo       - Use a new template to get access to all available options.
	    %echo       - If you do not make use of the options of the user makefile,
	    %echo         you can delete $(MODEL)_usr.mk and rebuild the model to
	    %echo         suppress this message.
	    %echo
	  %endif
	%endif
	%ifdef LOAD
	  %echo ERROR: LOAD option is no longer supported.
	  %echo        Please use the official RTI API command rti_build instead.
	  %do make_abort
	%endif
	%ifdef SSTATE
	  %if !member($(SSTATE), STOP PAUSE RUN)
	    %echo ERROR: Invalid SSTATE option '$(SSTATE)' specified.
	    %echo        Select one of STOP, PAUSE or RUN.
	    %do make_abort
	  %endif
	%endif
	%ifdef SMODE
	  %if !member($(SMODE), RTSIM NRTSIM NRTSIM_SCALED)
	    %echo ERROR: Invalid SMODE option '$(SMODE)' specified.
	    %echo        Select one of RTSIM, NRTSIM or NRTSIM_SCALED.
	    %do make_abort
	  %endif
	%endif
	%ifdef SSCALE
	  %if (!defined(SMODE)) || ("$(SMODE)" != "NRTSIM_SCALED")
	    %echo ERROR: Missing or incorrect SMODE option. To use the SSCALE
	    %echo        option, you must set the option SMODE=NRTSIM_SCALED.
	    %do make_abort
	    %endif
	%endif
	%set USER_MK_MSG = DEFINITIONS FROM USER MAKEFILE "$(MODEL)_usr.mk" ...
	%foreach USER_MACRO in $(USER_MACROS_LIST)
	  %if '$($(USER_MACRO))' != ''
	    %set USER_MK_MSG_PRINT = 1
	    %set USER_MK_MSG +=$(NEWLINE)  $(USER_MACRO) = $($(USER_MACRO))
	  %endif
	%endfor
	%if defined(USER_MK_MSG_PRINT)
	  %echo $(USER_MK_MSG)
	  %echo
	%endif
	%if defined(USER_MACRO_WARN_MESSAGE)
	  %echo $(USER_MACRO_WARN_MESSAGE)
	  %echo
	%endif
	%ifdef _IS_ROOT_MODEL
	  %ifndef BUILDTYPE
	    %echo RTI-ASSERT: Internal make macro BUILDTYPE is not set.
	    %do make_abort
	  %endif  
	%endif

# -----------------------------------------------------------------------------
# Initialization rules
# -----------------------------------------------------------------------------

init : make_init blockset_init

make_init :
	%ifdef COMPALL
	  %if '$(COMPALL, UC)' == 'ON'
	    %do delete_file FILE_LIST="$(ALL_OBJS,$(WS_PACK_TARGET_ARGS)) $(RTWCUST_LIBS,$(WS_PACK_TARGET_ARGS))"
	  %endif
	%endif

# -----------------------------------------------------------------------------
# Rules to build the program
# -----------------------------------------------------------------------------

compile_deps : \
	model_deps \
	simengine_deps \
	$(STD_OBJS) \
	blockset_deps \
	$(BLOCKSET_C_OBJS)  \
	$(SFCN_OBJS) \
	$(USER_SRCS_OBJS) \
	$(MDL_CUSTOM_C_OBJS) \
	$(ASM_OBJS) \
	$(RTW_SHARED_LIB_OBJS) \
	$(RTWCUST_LIB_OBJS) \
	$(RTW_SHARED_LIB) \
	$(RTWCUST_LIBS) \
	$(RTWCUST_PRECOMP_LIBS)

# -----------------------------------------------------------------------------
# Link rules
# -----------------------------------------------------------------------------

link : link_main blockset_after_linkage

link_main :
	%echo
	%echo LINKING APPLICATION ...
	%set APL_LK     = $(WORKDIR)$(MODEL).lk
	%set TMP_LK     = _tmp_$(APL_LK,F)
	%set TMP_LK_MRI = _tmp_$(APL_LK,B)_mri.txt
	%do link_build_objectlist
	%if exists($(APL_LK))
	  %echo Using local linker command file "$(APL_LK,F)"
	  copy >NUL $(APL_LK) $(TMP_LK)
	%else
	  copy >NUL $(RTLIB_DIR,>\ds$(BOARD_TYPE).lk) $(TMP_LK)
	%endif
	%do link_program
	%echo LINKING FINISHED

link_build_objectlist :
	# Build list of objects in specific order
	%set OBJ_PRE = LOAD
	%set LIB_PRE = LOAD
	%foreach OBJ in $(PROGRAM_LINK_OBJS_BEGIN)
	  %set LK_OBJS +=$(OBJ_PRE) $(OBJ)$(NEWLINE)
	%endfor
	%foreach OBJ in $(PROGRAM_LINK_OBJS)
	  %set LK_OBJS +=$(OBJ_PRE) "$(OBJ,"=)"$(NEWLINE)
	%endfor
	%foreach LIB in $(PROGRAM_LINK_LIBS)
	  %set LK_OBJS +=$(LIB_PRE) "$(LIB,"=)"$(NEWLINE)
	%endfor
	%foreach OBJ in $(PROGRAM_LINK_OBJS_END)
	  %set LK_OBJS +=$(OBJ_PRE) $(OBJ)$(NEWLINE)
	%endfor

link_program :
	%echo $(LK_OBJS) > $(TMP_LK_MRI)
	# Linking application executable.
	%set LINKPRG_MSG = (1)
	# PR 41391: Added flags --start-group, --end-group for cyclic linkage
	%set LD_CMD := \
	   $(EXEC_SHELL) "$(LD,"=)" $(LNK_DBG_OPTS) $(LNK_OPTS) -T $(TMP_LK) -o $(PROGRAM) --start-group -c $(TMP_LK_MRI) --end-group
	%echo $(LD_CMD) > $(TMP_LK_OUT)
	$(LD_CMD)
	%if $(status)
	  %set _STATUS = $(status)
	  type $(TMP_LK_OUT)
	  %echo LINKING FAILED $(LINKPRG_MSG)($(_STATUS))
	  %do make_abort
	%endif
	# Trial link agains unresolved symbols.
	%set LINKPRG_MSG = (2)
	%set LDTEST_CMD := \
	  $(EXEC_SHELL) "$(LD,"=)" $(LNK_DBG_OPTS) -T $(RTLIB_DIR,>\extsym1006.lk) -o NUL --start-group -c $(TMP_LK_MRI) --end-group
	%echo $(LDTEST_CMD) > $(TMP_LK_OUT)
	$(LDTEST_CMD)
	%if $(status)
	  %set _STATUS = $(status)
	  type $(TMP_LK_OUT)
	  %echo LINKING FAILED $(LINKPRG_MSG)($(_STATUS))
	  %do delete_file FILE_LIST="$(PROGRAM,$(WS_PACK_TARGET_ARGS))"
	  %do make_abort
	%endif
	# Generating MAP file.
	%set  MG_CMD = $(EXEC_SHELL) $(MG) -m -f $(PROGRAM) > $(MAPFILE)
	%echo $(MG_CMD,S'>'\\>') > $(TMP_MG_OUT)
	$(MG_CMD)
	%if $(status)
	  %set _STATUS = $(status)
	  type $(TMP_MG_OUT)
	  %echo LINKING FAILED (MAPFILE GENERATOR)($(_STATUS))
	  %do make_abort
	%endif

# -----------------------------------------------------------------------------
# Clean up rules
# -----------------------------------------------------------------------------

cleanup : make_clean blockset_clean

make_clean :
	%undef CLEANUP_ON
	%ifdef CLEANUP
	  %if '$(CLEANUP)' == 'ON'
	    %set CLEANUP_ON
	  %endif
	%endif
	%ifdef CLEANUP_ON
	  %do delete_file FILE_LIST="$(TMP_LK,$(WS_PACK_TARGET_ARGS)) $(TMP_FILE_LIST,$(WS_PACK_TARGET_ARGS))"
	%endif

delete_file :
	%set FILE_LIST = $(FILE_LIST,$(WS_UNPACK_TARGET_ARGS))
	%foreach ITEM in $(FILE_LIST)
	  %if exists($(ITEM))
	    del $(ITEM) >NUL
	  %endif
	%endfor

# -----------------------------------------------------------------------------
# Rules for the simulation engine
# -----------------------------------------------------------------------------

%ifdef _IS_ROOT_MODEL

  # Root model.
simengine_deps : simengine_init $(SIMENGINE).$(CC_OBJ_EXT)

simengine_init :
	%ifndef _IS_MP_BUILD
	  # Prepare options list.
	  %set SIMENGINE_OPTS_MARKER_CURRENT = Simulation options of $(SIMENGINE).c:
	  %if defined(SMODE)
	    %set SIMENGINE_OPTS_MARKER_CURRENT += SMODE = "$(SMODE)";
	  %endif
	  %if defined(SSTATE)
	    %set SIMENGINE_OPTS_MARKER_CURRENT += SSTATE = "$(SSTATE)";
	  %endif
	  %if defined(SSCALE)
	    %set SIMENGINE_OPTS_MARKER_CURRENT += SSCALE = "$(SSCALE)";
	  %endif
	  %set SIMENGINE_OPTS_MARKER_FILE = $(SIMENGINE).sopts
	  %if exists($(SIMENGINE_OPTS_MARKER_FILE))
	    %set SIMENGINE_OPTS_MARKER_FILE_CONTENS := $(SIMENGINE_OPTS_MARKER_FILE,@)
	    %if "$(SIMENGINE_OPTS_MARKER_FILE_CONTENS)" != "$(SIMENGINE_OPTS_MARKER_CURRENT)"
	      # Options changed compared to previous build.
	      %do delete_file FILE_LIST="$(SIMENGINE).$(CC_OBJ_EXT) $(SIMENGINE_OPTS_MARKER_FILE)"
	      %set UPDATE_SIMENGINE_OPTS_MARKER_FILE = 1
	    %endif
	    %undef SIMENGINE_OPTS_MARKER_FILE_CONTENS
	  %else
	    # Options file does not exist. Delete sim engine object if it exists.
	    %do delete_file FILE_LIST=$(SIMENGINE).$(CC_OBJ_EXT)
	    %set UPDATE_SIMENGINE_OPTS_MARKER_FILE = 1
	  %endif
	  # Write options file with current option setting.
	  %ifdef UPDATE_SIMENGINE_OPTS_MARKER_FILE
	    %echo $(SIMENGINE_OPTS_MARKER_CURRENT) > $(SIMENGINE_OPTS_MARKER_FILE)
	    %undef UPDATE_SIMENGINE_OPTS_MARKER_FILE
	  %endif
	%endif

%if exists($(WORKDIR)$(MODEL).ddc)
$(SIMENGINE).$(CC_OBJ_EXT) : $(WORKDIR)$(MODEL).ddc
%endif

$(SIMENGINE).$(CC_OBJ_EXT) : $(SIMENG_DEP_FILES)

%else # _IS_ROOT_MODEL

  # Referenced model.
simengine_deps :

%endif # _IS_ROOT_MODEL

# -----------------------------------------------------------------------------
# Rules for the model
# -----------------------------------------------------------------------------

%ifdef _IS_ROOT_MODEL

  # Root model.
model_deps : $(MODEL).$(CC_OBJ_EXT) $(MODULE_OBJS)

$(MODEL).$(CC_OBJ_EXT) : $(MODEL_DEP_FILES)

%else # _IS_ROOT_MODEL

  # Referenced model.
model_deps :

%endif # _IS_ROOT_MODEL

# -----------------------------------------------------------------------------
# Rules for referenced models (ref. model library)
# -----------------------------------------------------------------------------

%ifdef _IS_ROOT_MODEL
%else # _IS_ROOT_MODEL
mdl_ref_lib : pre_build_library $(PRODUCT)

# this pre_build_library step workarounds the problem of dsmake utility - for FAT compatibility
# reasons the file timestamps are compared with just merely one-second resolution
pre_build_library :
    %ifdef HAS_COMPILED
      %if exists($(PRODUCT))
        # delete library file if it already exists and any source file it depends on has been compiled
        %do delete_file FILE_LIST="$(PRODUCT,$(WS_PACK_TARGET_ARGS))"
      %endif
    %endif

$(PRODUCT) : $(PRODUCT_LIB_OBJS) $(PRODUCT_LIB_LIBS)
  %do build_library  _LIB_NAME="$(.TARGET,$(WS_PACK_TARGET_ARGS))" _LIB_FILES="$(PRODUCT_LIB_LIBS,$(WS_PACK_TARGET_ARGS))"

%endif # _IS_ROOT_MODEL
# -----------------------------------------------------------------------------
# Rules for the model library
# -----------------------------------------------------------------------------

# Common library archiving rule
build_library :
	%set _LIB_NAME = $(_LIB_NAME,$(WS_UNPACK_TARGET_ARGS))
	%if defined(_LIB_FILES)
	  # Library files to be added to the output library.
	  %set _LIB_FILES = $(_LIB_FILES,$(WS_UNPACK_TARGET_ARGS))
	%else
	  %set _LIB_FILES =
	%endif
	%ifndef BUILD_MSG_SEP_SPACE
	  # Additional newline to separate from COMPILING messages
	  %echo
	  %set BUILD_MSG_SEP_SPACE
	%endif

	# Create librarian/archiver command file
	%set LIB_CMD_LIST_FILE   = $(_LIB_NAME,B)_cmd.lst
	# Create library
	%if exists($(_LIB_NAME))
	  # make sure that the libs are always created
	  %do delete_file FILE_LIST="$(_LIB_NAME,$(WS_PACK_TARGET_ARGS))"
	%endif
	%echo CREATE $(_LIB_NAME)      >  $(LIB_CMD_LIST_FILE)
	%foreach ITEM in $(.SOURCES)
	  %if $(ITEM,E) == .cc_opt
	  # Just Skipping
	  %elif member($(ITEM),$(_LIB_FILES))
	    # Add a library file.
	    %echo ADDLIB $(ITEM)       >> $(LIB_CMD_LIST_FILE)
	  %else
	    # Add an object file.
	    %echo ADDMOD $(ITEM)       >> $(LIB_CMD_LIST_FILE)
	  %endif
	%endfor
	%echo SAVE                     >> $(LIB_CMD_LIST_FILE)
	%echo END                      >> $(LIB_CMD_LIST_FILE)

	%echo
	%echo BUILDING LIBRARY "$(_LIB_NAME,F)" ...
	%set AR_CMD := "$(AR,"=)" $(AR_OPTS) < $(LIB_CMD_LIST_FILE)
	%echo $(AR_CMD,S'<'\\<')  >  $(TMP_AR_OUT)
	    $(EXEC_SHELL) $(AR_CMD)  >> $(TMP_AR_OUT) 2>>&1
	%if $(status)
	  %set _STATUS = $(status)
	  type $(TMP_AR_OUT)
	  %echo ARCHIVER FAILED ($(_STATUS))
	  %do delete_file FILE_LIST=$(_LIB_NAME)
	  %do make_abort
	%endif
	# Generate a table of contents.
	$(EXEC_SHELL) "$(AR,"=)" $(AR_TBL_OPTS) $(_LIB_NAME) > $(_LIB_NAME,B)_lib_tbl.txt 2>>&1
	%echo BUILDING LIBRARY FINISHED



# -----------------------------------------------------------------------------
# Rules for shared library for utility code
# -----------------------------------------------------------------------------

%ifdef HAS_RTW_SHARED_LIB
$(RTW_SHARED_LIB_OBJS) : $(RTW_SHARED_LIB_SRCS_DIR,>\$(%,B).$(CC_SRC_EXT))
	%undef COMP_LIB_MSG_OUTPUT
	%do comp_lib_sources _LIB_NAME=$(RTW_SHARED_LIB)

$(RTW_SHARED_LIB) : $(RTW_SHARED_LIB_OBJS)
	%do build_library    _LIB_NAME=$(.TARGET)
%endif


# -----------------------------------------------------------------------------
# Rules for the additional RTW run-time libraries (dynamically expanded)
# -----------------------------------------------------------------------------

# RTW Custom Run-Time Libraries from rtwmakecfg.m (to be built).


# RTW Custom Run-Time Libraries from rtwmakecfg.m (pre-compiled).


# -----------------------------------------------------------------------------
# General compile rules
# -----------------------------------------------------------------------------

%.$(CC_OBJ_EXT) : %.$(CC_SRC_EXT)
	%do comp_rule

comp_rule :
	%if     member($(.SOURCE,F),    $(CC_FLAGS_EXTRA1_SRCS))
	  %do comp_source  TMP_CC_FLAGS="$(CC_FLAGS_EXTRA1,$(WS_PACK_TARGET_ARGS))"
	%else
	  %do comp_source  TMP_CC_FLAGS="$(CC_FLAGS,$(WS_PACK_TARGET_ARGS))"
	%endif

comp_source :
	%set TMP_CC_FLAGS = $(TMP_CC_FLAGS,$(WS_UNPACK_TARGET_ARGS))
	%echo > $(TMP_CC_MSG)
	%echo -n > $(TMP_CC_OUT)
	%ifndef CC_MSG
	  %set CC_MSG =
	%endif
	%set CC_OPT_FILE = $(.SOURCE,B,>.cc_opt)
	%echo -c $(TMP_CC_FLAGS,W\n,\\=/) > $(CC_OPT_FILE)
	%set CC_CMD = "$(CC,"=)" @$(CC_OPT_FILE) $(.SOURCE)
	%ifndef CC_MSG_QUIET
	  %echo COMPILING  "$(.SOURCE,"=)" $(CC_MSG)
	  $(EXEC_SHELL) $(CC_CMD)
	%else
	  %echo COMPILING  "$(.SOURCE,"=)" $(CC_MSG) >> $(TMP_CC_MSG)
	  %echo -n .
	  $(EXEC_SHELL) $(CC_CMD) > $(TMP_CC_OUT) 2>>&1
	%endif
	%if $(status)
	  %set _STATUS = $(status)
	  type $(TMP_CC_MSG)
	  type $(TMP_CC_OUT)
	  %echo COMPILING FAILED ($(_STATUS))
	  %do make_abort
	%elseif !empty($(TMP_CC_OUT))
	  type $(TMP_CC_MSG)
	  type $(TMP_CC_OUT)
	%endif
	%set HAS_COMPILED = 1

%ifdef _IS_CXX_APPL
%.$(CXX_OBJ_EXT) : %.$(CXX_SRC_EXT)
	%set CXX_OPT_FILE = $(.SOURCE,B,>.cxx_opt)
	%echo -c $(CXX_FLAGS,W\n,\\=/) > $(CXX_OPT_FILE)
	%set CXX_CMD = "$(CXX,"=)" @$(CXX_OPT_FILE) $(.SOURCE)
	%echo COMPILING  "$(.SOURCE,"=)"
	$(EXEC_SHELL) $(CXX_CMD)
	%if $(status)
	  %set _STATUS = $(status)
	  %echo COMPILING FAILED ($(_STATUS))
	  %do make_abort
	%endif
	%set HAS_COMPILED = 1
%endif # _IS_CXX_APPL

# rule for preprocessing only (for macro debugging)
%.i : %.$(CC_SRC_EXT)
	%set TMP_PP_OUT = _tmp_$(MODEL)_pp.txt
	%if member($(.SOURCE,F),    $(CC_FLAGS_EXTRA1_SRCS))
	  %set TMP_CC_FLAGS = $(CC_FLAGS_EXTRA1)
	%else
	  %set TMP_CC_FLAGS = $(CC_FLAGS)
	%endif
	%set PP_OPT_FILE = $(.SOURCE,B,>.pp_opt)
	%echo -E $(TMP_CC_FLAGS,W\n,\\=/) > $(PP_OPT_FILE)
	%set PP_CMD = "$(CC,"=)" @$(PP_OPT_FILE) $(.SOURCE)
	%echo $(EXEC_SHELL) $(PP_CMD) > $(TMP_PP_OUT)
	%echo
	%echo PREPROCESSING "$(.SOURCE,"=)" $(CC_MSG)
	$(EXEC_SHELL) $(PP_CMD)
	%if $(status)
	  %set _STATUS = $(status)
	  type $(TMP_PP_OUT)
	  %echo PREPROCESSING FAILED ($(_STATUS))
	%endif

# -----------------------------------------------------------------------------
# Assembly rule
# -----------------------------------------------------------------------------

%.$(ASM_OBJ_EXT) : %.$(ASM_SRC_EXT)
	%echo ASSEMBLING "$(.SOURCE,"=)"
	$(EXEC_SHELL) "$(AS,"=)" $(ASM_CMD_LINE)
	%if $(status)
	  %echo ASSEMBLING FAILED ($(status))
	  %do make_abort
	%endif

# -----------------------------------------------------------------------------
# Special dependencies
# -----------------------------------------------------------------------------

# Common rules to compile library sources
comp_lib_sources :
	%do comp_lib_sources_msg
	%do comp_rule CC_MSG_QUIET=1 CC_OBJ_EXT=$(LIBOBJ_EXT)

comp_lib_sources_msg :
	%if '$(_LIB_NAME)' != '$(_LIB_NAME_MSG)'
	  %set _LIB_NAME_MSG = $(_LIB_NAME)
	  %set _COMP_DOT_COUNT =
	  %echo
	  %echo COMPILING  "$(_LIB_NAME,F)" library sources
	  %echo -n            .
	%endif
	%if %length(_COMP_DOT_COUNT) > 68
	  %set _COMP_DOT_COUNT =
	  %echo
	  %echo -n            .
	%endif
	%set _COMP_DOT_COUNT +=.


% if   '$(MODEL)' != 'rtwshared'
$(ALL_OBJS) : $(MODEL)_rti.prj
% endif


%ifdef _IS_ROOT_MODEL
$(MAKEFILE_DEP_OBJS) : $(MAKEFILE)
%endif

# EOF -------------------------------------------------------------------------
