# =============================================================================
#  Make include file hilTest_rti.mk:
#
#   RTI1006 7.14 (02-May-2020)
#   Mon May  2 10:16:49 2022
#
#   Copyright 2020, dSPACE GmbH. All rights reserved.
# =============================================================================

# Initialize variables used in blockset makefiles -----------------------------

BLOCKSET_LIBS     :=
BLOCKSET_SRCS     :=
BLOCKSET_INCLUDES :=

# Default rules for additional blocksets --------------------------------------

blockset_init          :
blockset_clean         :
blockset_deps          :
blockset_after_linkage :

# Includes for additional blocksets -------------------------------------------



# Model-specific options ------------------------------------------------------

# Additional C source files declared by the model
MDL_CUSTOM_C_SRCS = rti_assert.c DsBusCustomCode.c DsBusCustomCode_SecOC.c

# Additional assembler source files declared by the model
MDL_CUSTOM_ASM_SRCS =

# Additional libraries declared by the model
MDL_CUSTOM_LIBS = \
  "$(DSPACE_ROOT)\DS1006\RTPython\dsrtt1006.lib"

# Additional objects declared by the model
MDL_CUSTOM_OBJS =

# Directories where additional C and assembler source files are stored
MDL_CUSTOM_SRCS_DIR = \
  "$(DSPACE_ROOT)\BusImplementationSoftware\BusCustomCode"

# Directories where additional header files are stored
MDL_CUSTOM_INCLUDES_PATH = \
  "$(DSPACE_ROOT)\DS1006\RTPython" \
  "$(DSPACE_ROOT)\BusImplementationSoftware\BusCustomCode"


# Define build type information
BUILDTYPE = RTI

# EOF -------------------------------------------------------------------------
