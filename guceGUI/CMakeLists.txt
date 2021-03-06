#-------------------------------------------------------------------
# This file was automatically generated by ProjectGenerator
# which is tooling part the build system designed for GUCEF
#     (Galaxy Unlimited Framework)
# For the latest info, see http://www.VanvelzenSoftware.com/
#
# The contents of this file are placed in the public domain. Feel
# free to make use of it in any way you like.
#-------------------------------------------------------------------
#

# Configuration for module: guceGUI

set( HEADER_FILES 
  include/CGUCEGUIModule.h
  include/CGUIManager.h
  include/guceGUI.h
  include/guceGUIDLLInit.h
  include/guceGUI_CConsole.h
  include/guceGUI_CConsoleForm.h
  include/guceGUI_CGUIEditor.h
  include/guceGUI_CIGUIDriver.h
  include/guceGUI_CMeshViewer.h
  include/guceGUI_CMeshViewerForm.h
  include/guceGUI_COgreGUIRenderContext.h
  include/guceGUI_config.h
  include/guceGUI_CSettingsMenuForm.h
  include/guceGUI_CVideoSettingsForm.h
  include/guceGUI_macros.h
  include/guceGUI_Types.h
)

set( SOURCE_FILES 
  src/CGUCEGUIModule.cpp
  src/CGUIManager.cpp
  src/guceGUI.cpp
  src/guceGUI_CConsole.cpp
  src/guceGUI_CConsoleForm.cpp
  src/guceGUI_CGUIEditor.cpp
  src/guceGUI_CIGUIDriver.cpp
  src/guceGUI_CMeshViewer.cpp
  src/guceGUI_CMeshViewerForm.cpp
  src/guceGUI_COgreGUIRenderContext.cpp
  src/guceGUI_CSettingsMenuForm.cpp
  src/guceGUI_CVideoSettingsForm.cpp
)

# Make sure the PLATFORM_HEADER_FILES variable is always defined
 set( PLATFORM_HEADER_FILES "" )

# Make sure the PLATFORM_SOURCE_FILES variable is always defined
 set( PLATFORM_SOURCE_FILES "" )

# For ease of use make a variable that has all files for this module
set( ALL_FILES ${HEADER_FILES} ${SOURCE_FILES} ${PLATFORM_HEADER_FILES} ${PLATFORM_SOURCE_FILES} )




#******** END OF AUTOGENERATED CONTENT ********



add_library( guceGUI ${ALL_FILES} )
add_dependencies( guceGUI guceCORE gucefCORE gucefMT gucefGUI gucefIMAGE gucefVFS gucefINPUT )
target_link_libraries( guceGUI guceCORE gucefCORE gucefMT gucefGUI gucefIMAGE gucefVFS gucefINPUT )
set_target_properties( guceGUI PROPERTIES COMPILE_DEFINITIONS GUCE_GUI_BUILD_MODULE )
GUCE_config_lib( guceGUI )


#******** START OF AUTOGENERATED CONTENT ********



include_directories( ../../../GUCEF/trunk/common/include ../../../GUCEF/trunk/gucefCOM/include ../../../GUCEF/trunk/gucefCOMCORE/include ../../../GUCEF/trunk/gucefCORE/include ../../../GUCEF/trunk/gucefDRN/include ../../../GUCEF/trunk/gucefGUI/include ../../../GUCEF/trunk/gucefIMAGE/include ../../../GUCEF/trunk/gucefINPUT/include ../../../GUCEF/trunk/gucefMT/include ../../../GUCEF/trunk/gucefPATCHER/include ../../../GUCEF/trunk/gucefVFS/include ../../../GUCEF/trunk/gucefVFS/plugins/vfspluginZIP/dependencies/zziplib ../../../GUCEF/trunk/gucefVFS/plugins/vfspluginZIP/dependencies/zziplib/zzip ../dependencies/Ogre/OgreMain/include ../dependencies/Ogre/OgreMain/src ../dependencies/Ogre/OgreMain/src/nedmalloc ../dependencies/freetype/include ../dependencies/freetype/include/freetype ../dependencies/freetype/include/freetype/config ../dependencies/freetype/include/freetype/internal ../dependencies/freetype/include/freetype/internal/services ../dependencies/freetype/src/winfonts ../guceCORE/include include )

if ( ANDROID )
  include_directories( ../../../GUCEF/trunk/gucefCORE/include/android )
endif( ANDROID )

if ( LINUX )
  include_directories( ../../../GUCEF/trunk/gucefCORE/include/linux )
endif( LINUX )

if ( WIN32 )
  include_directories( ../../../GUCEF/trunk/gucefCORE/include/mswin )
endif( WIN32 )

if ( WIN64 )
  include_directories( ../../../GUCEF/trunk/gucefCORE/include/mswin )
endif( WIN64 )
