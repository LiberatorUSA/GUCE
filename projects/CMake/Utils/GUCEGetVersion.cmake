#-------------------------------------------------------------------
# This file is part of the CMake build system for GUCE
#     (Galaxy Unlimited Engine)
# For the latest info, see http://www.VanvelzenSoftware.com/
#
# The contents of this file are placed in the public domain. Feel
# free to make use of it in any way you like.
#-------------------------------------------------------------------

include(PreprocessorUtils)

macro(GUCE_get_version HEADER)
  file(READ ${HEADER} TEMP_VAR_CONTENTS)
  get_preprocessor_entry(TEMP_VAR_CONTENTS GUCE_VERSION_MAJOR GUCE_VERSION_MAJOR)
  get_preprocessor_entry(TEMP_VAR_CONTENTS GUCE_VERSION_MINOR GUCE_VERSION_MINOR)
  get_preprocessor_entry(TEMP_VAR_CONTENTS GUCE_VERSION_PATCH GUCE_VERSION_PATCH)
  get_preprocessor_entry(TEMP_VAR_CONTENTS GUCE_VERSION_NAME GUCE_VERSION_NAME)
  get_preprocessor_entry(TEMP_VAR_CONTENTS GUCE_VERSION_SUFFIX GUCE_VERSION_SUFFIX)
  set(GUCE_VERSION "${GUCE_VERSION_MAJOR}.${GUCE_VERSION_MINOR}.${GUCE_VERSION_PATCH}")
endmacro()
