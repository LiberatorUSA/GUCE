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

# Configuration for module: GUCE_RefApp



if (LINUX)
  set( PLATFORM_HEADER_FILES 
    include/COgreDebugOverlay.h
    include/CRefAppSubSystem.h
  )

  set( PLATFORM_HEADER_INSTALL "LINUX" )
  source_group( "Platform Header Files" FILES ${PLATFORM_HEADER_FILES} )

  set( PLATFORM_SOURCE_FILES 
    src/COgreDebugOverlay.cpp
    src/CRefAppSubSystem.cpp
    src/RefAppMain.cpp
  )

  set( PLATFORM_SOURCE_INSTALL "LINUX" )
  source_group( "Platform Source Files" FILES ${PLATFORM_SOURCE_FILES} )

elseif (WIN32)
  set( PLATFORM_HEADER_FILES 
    include/COgreDebugOverlay.h
    include/CRefAppSubSystem.h
  )

  set( PLATFORM_HEADER_INSTALL "WIN32" )
  source_group( "Platform Header Files" FILES ${PLATFORM_HEADER_FILES} )

  set( PLATFORM_SOURCE_FILES 
    src/COgreDebugOverlay.cpp
    src/CRefAppSubSystem.cpp
    src/RefAppMain.cpp
  )

  set( PLATFORM_SOURCE_INSTALL "WIN32" )
  source_group( "Platform Source Files" FILES ${PLATFORM_SOURCE_FILES} )

elseif (WIN64)
  set( PLATFORM_HEADER_FILES 
    include/COgreDebugOverlay.h
    include/CRefAppSubSystem.h
  )

  set( PLATFORM_HEADER_INSTALL "WIN64" )
  source_group( "Platform Header Files" FILES ${PLATFORM_HEADER_FILES} )

  set( PLATFORM_SOURCE_FILES 
    src/COgreDebugOverlay.cpp
    src/CRefAppSubSystem.cpp
    src/RefAppMain.cpp
  )

  set( PLATFORM_SOURCE_INSTALL "WIN64" )
  source_group( "Platform Source Files" FILES ${PLATFORM_SOURCE_FILES} )

endif ()

# For ease of use make a variable that has all files for this module
set( ALL_FILES ${HEADER_FILES} ${SOURCE_FILES} ${PLATFORM_HEADER_FILES} ${PLATFORM_SOURCE_FILES} )


if( LINUX )
  set( MODULE_NAME "GUCE_RefApp" )
elseif( WIN32 )
  set( MODULE_NAME "GUCE_RefApp" )
elseif( WIN64 )
  set( MODULE_NAME "GUCE_RefApp" )
endif()
if( LINUX )
  add_library( ${MODULE_NAME} ${ALL_FILES} )
elseif( WIN32 )
  add_library( ${MODULE_NAME} ${ALL_FILES} )
elseif( WIN64 )
  add_library( ${MODULE_NAME} ${ALL_FILES} )
endif()

if ( LINUX )
  add_dependencies( ${MODULE_NAME} guceCORE guceGUI )
  target_link_libraries( ${MODULE_NAME} guceCORE guceGUI )
  set_target_properties( ${MODULE_NAME} PROPERTIES COMPILE_DEFINITIONS "GUCE_REFAPP_BUILD_MODULE" )
endif( LINUX )

if ( WIN32 )
  add_dependencies( ${MODULE_NAME} guceCORE guceGUI )
  target_link_libraries( ${MODULE_NAME} guceCORE guceGUI )
  set_target_properties( ${MODULE_NAME} PROPERTIES COMPILE_DEFINITIONS "GUCE_REFAPP_BUILD_MODULE" )
endif( WIN32 )

if ( WIN64 )
  add_dependencies( ${MODULE_NAME} guceCORE guceGUI )
  target_link_libraries( ${MODULE_NAME} guceCORE guceGUI )
  set_target_properties( ${MODULE_NAME} PROPERTIES COMPILE_DEFINITIONS "GUCE_REFAPP_BUILD_MODULE" )
endif( WIN64 )

include_directories( ../../../../GUCEF/trunk/common/include ../../../../GUCEF/trunk/gucefCOM/include ../../../../GUCEF/trunk/gucefCOMCORE/include ../../../../GUCEF/trunk/gucefCORE/include ../../../../GUCEF/trunk/gucefDRN/include ../../../../GUCEF/trunk/gucefGUI/include ../../../../GUCEF/trunk/gucefIMAGE/include ../../../../GUCEF/trunk/gucefINPUT/include ../../../../GUCEF/trunk/gucefMT/include ../../../../GUCEF/trunk/gucefPATCHER/include ../../../../GUCEF/trunk/gucefVFS/include ../../../../GUCEF/trunk/gucefVFS/plugins/vfspluginZIP/dependencies/zziplib ../../../../GUCEF/trunk/gucefVFS/plugins/vfspluginZIP/dependencies/zziplib/zzip ../../dependencies/Ogre/OgreMain/include ../../dependencies/Ogre/OgreMain/src ../../dependencies/Ogre/OgreMain/src/nedmalloc ../../dependencies/freetype/include ../../dependencies/freetype/include/freetype ../../dependencies/freetype/include/freetype/config ../../dependencies/freetype/include/freetype/internal ../../dependencies/freetype/include/freetype/internal/services ../../dependencies/freetype/src/winfonts ../../guceCORE/include ../../guceGUI/include )

if ( LINUX )
  include_directories( include )
endif( LINUX )

if ( WIN32 )
  include_directories( include )
endif( WIN32 )

if ( WIN64 )
  include_directories( include )
endif( WIN64 )



#******** START OF AUTOGENERATED TEMPLATED ADDITION CONTENT ********




if (LINUX)
GUCEF_config_lib( ${MODULE_NAME} )
elseif (WIN32)
GUCEF_config_lib( ${MODULE_NAME} )
elseif (WIN64)
GUCEF_config_lib( ${MODULE_NAME} )
endif()



#******** END OF AUTOGENERATED TEMPLATED ADDITION CONTENT ********


