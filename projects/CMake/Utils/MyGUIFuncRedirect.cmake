#-------------------------------------------------------------------
# This file is part of the CMake build system for GUCE
#     (Galaxy Unlimited Engine)
# For the latest info, see http://www.VanvelzenSoftware.com/
#
# The contents of this file are placed in the public domain. Feel
# free to make use of it in any way you like.
#-------------------------------------------------------------------

include( GUCEConfigTargets )


function(mygui_config_lib LIBNAME)
  GUCE_config_lib( ${LIBNAME} )
endfunction(mygui_config_lib)

function(mygui_config_plugin PLUGINNAME)
  GUCE_config_plugin( ${PLUGINNAME} )
endfunction(mygui_config_plugin)

function(mygui_config_tool TOOLNAME)
  GUCE_config_tool( ${TOOLNAME} )
endfunction(mygui_config_tool)

function(mygui_install_target TARGETNAME SUFFIX)
  GUCE_install_target( ${TARGETNAME} SUFFIX ${SUFFIX} )
endfunction(mygui_install_target)