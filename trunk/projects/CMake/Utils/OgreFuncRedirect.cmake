#-------------------------------------------------------------------
# This file is part of the CMake build system for GUCE
#     (Galaxy Unlimited Engine)
# For the latest info, see http://www.VanvelzenSoftware.com/
#
# The contents of this file are placed in the public domain. Feel
# free to make use of it in any way you like.
#-------------------------------------------------------------------

include( GUCEConfigTargets )


function(ogre_config_lib LIBNAME)
  GUCE_config_lib( ${LIBNAME} )
endfunction(ogre_config_lib)

function(ogre_config_plugin PLUGINNAME)
  GUCE_config_plugin( ${PLUGINNAME} )
endfunction(ogre_config_plugin)

function(ogre_config_tool TOOLNAME)
  GUCE_config_tool( ${TOOLNAME} )
endfunction(ogre_config_tool)