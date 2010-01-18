#-------------------------------------------------------------------
# This file is part of the CMake build system for GUCE
#     (Galaxy Unlimited Engine)
# For the latest info, see http://www.VanvelzenSoftware.com/
#
# The contents of this file are placed in the public domain. Feel
# free to make use of it in any way you like.
#-------------------------------------------------------------------

include( GUCEConfigTargets )


function(GUCEF_config_lib LIBNAME)
  GUCE_config_lib( ${LIBNAME} )
endfunction(GUCEF_config_lib)

function(GUCEF_config_plugin PLUGINNAME)
  GUCE_config_plugin( ${PLUGINNAME} )
endfunction(GUCEF_config_plugin)

function(GUCEF_config_tool TOOLNAME)
  GUCE_config_tool( ${TOOLNAME} )
endfunction(GUCEF_config_tool)