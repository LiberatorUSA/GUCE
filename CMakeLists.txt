#-------------------------------------------------------------------
# This file is part of the CMake build system for GUCE
#     (Galaxy Unlimited Framework)
# For the latest info, see http://www.VanvelzenSoftware.com/
#
# The contents of this file are placed in the public domain. Feel
# free to make use of it in any way you like.
#-------------------------------------------------------------------

######################################################################
# GUCE BUILD SYSTEM
# Welcome to the CMake build system for GUCE.
# This is the main file where we prepare the general build environment
# and provide build configuration options.
######################################################################

cmake_minimum_required(VERSION 2.6)
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS TRUE)
cmake_policy(SET CMP0003 NEW)

project(GUCE)

# Include necessary submodules
set(CMAKE_MODULE_PATH 
  "${GUCE_SOURCE_DIR}/projects/CMake"
  "${GUCE_SOURCE_DIR}/projects/CMake/Utils" 
  "${GUCE_SOURCE_DIR}/projects/CMake/Packages"
)

include(CMakeDependentOption)
include(MacroLogFeature)
include(GUCEConfigTargets)
include(PreprocessorUtils)
include(GUCEFFuncRedirect)

set(GUCE_TEMPLATES_DIR "${GUCE_SOURCE_DIR}/projects/CMake/Templates")
set(GUCE_WORK_DIR ${GUCE_BINARY_DIR})


#####################################################################
# Set up the basic build environment
#####################################################################

if (CMAKE_BUILD_TYPE STREQUAL "")
  # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
  # differentiation between debug and release builds.
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()

# determine GUCE version numbers
include(GUCEGetVersion)
GUCE_get_version(${GUCE_SOURCE_DIR}/common/include/GUCE_prerequisites.h)
message(STATUS "Configuring GUCE ${GUCE_VERSION}")

if (NOT APPLE)
  # Create debug libraries with _d postfix
  set(CMAKE_DEBUG_POSTFIX "_d")
endif ()

# Set compiler specific build flags
if (CMAKE_COMPILER_IS_GNUCXX)
  add_definitions(-msse)
endif ()
if (MSVC)
  add_definitions(/fp:fast)
endif ()

if (CMAKE_COMPILER_IS_GNUCXX)
  # Test for GCC visibility
  include(CheckCXXCompilerFlag)
  check_cxx_compiler_flag(-fvisibility=hidden GUCE_GCC_VISIBILITY)
  if (GUCE_GCC_VISIBILITY)
    # determine gcc version
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion 
      OUTPUT_VARIABLE GUCE_GCC_VERSION)
    message(STATUS "Detected g++ ${GUCE_GCC_VERSION}")
    message(STATUS "Enabling GCC visibility flags")
    set(GUCE_GCC_VISIBILITY_FLAGS "-DGUCE_GCC_VISIBILITY -fvisibility=hidden")
  
    # check if we can safely add -fvisibility-inlines-hidden
    string(TOLOWER "${CMAKE_BUILD_TYPE}" GUCE_BUILD_TYPE)
    if (GUCE_BUILD_TYPE STREQUAL "debug" AND GUCE_GCC_VERSION VERSION_LESS "4.2")
      message(STATUS "Skipping -fvisibility-inlines-hidden due to possible bug in g++ < 4.2")
    else ()
      set(GUCE_GCC_VISIBILITY_FLAGS "${GUCE_GCC_VISIBILITY_FLAGS} -fvisibility-inlines-hidden")
    endif ()
  endif (GUCE_GCC_VISIBILITY)
endif (CMAKE_COMPILER_IS_GNUCXX)

# determine system endianess
include(TestBigEndian)
test_big_endian(GUCE_TEST_BIG_ENDIAN)

# Add common include path
include_directories("${GUCE_SOURCE_DIR}/common/include")
#include_directories("${GUCE_BINARY_DIR}/include")
if (APPLE)
  include_directories("${CMAKE_SOURCE_DIR}/GUCEMain/include/OSX")
endif (APPLE)

# Find dependencies
include(Dependencies)
# definitions for samples
set(GUCE_LIBRARIES GUCECORE ) 

# Specify build paths
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${GUCE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${GUCE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${GUCE_BINARY_DIR}/bin")
if (WIN32 OR APPLE)
  if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    # We don't want to install in default system location, install is really for the SDK, so call it that
    set(CMAKE_INSTALL_PREFIX
	  "${GUCE_BINARY_DIR}/sdk" CACHE PATH "GUCE install prefix" FORCE
    )
  endif (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
endif(WIN32 OR APPLE)

# Set up iPhone overrides.
if (GUCE_BUILD_PLATFORM_IPHONE)
  # Force gcc <= 4.2 on iPhone
  include(CMakeForceCompiler)
  CMAKE_FORCE_C_COMPILER(gcc-4.2 GNU)
  CMAKE_FORCE_CXX_COMPILER(gcc-4.2 GNU)

  include_directories("${CMAKE_SOURCE_DIR}/GUCEMain/include/iPhone")

  # Set build variables
  set(CMAKE_OSX_SYSROOT iphoneos3.0)
  set(CMAKE_OSX_ARCHITECTURES "$(ARCHS_UNIVERSAL_IPHONE_OS)")
  set(CMAKE_EXE_LINKER_FLAGS "-framework Foundation -framework CoreGraphics -framework QuartzCore -framework UIKit ${GUCE_SOURCE_DIR}/iPhoneDependencies/lib/release/libboost_date_time.a ${GUCE_SOURCE_DIR}/iPhoneDependencies/lib/release/libboost_thread.a")
  set(XCODE_ATTRIBUTE_SDKROOT iphoneos3.0)
  set(GUCE_BUILD_RENDERSYSTEM_GLES TRUE CACHE BOOL "Forcing OpenGL ES RenderSystem for iPhone" FORCE)
  set(GUCE_STATIC TRUE CACHE BOOL "Forcing static build for iPhone" FORCE)
  set(GUCE_SET_USE_BOOST TRUE CACHE BOOL "Forcing use of Boost libraries for iPhone" FORCE)
  set(GUCE_USE_BOOST TRUE CACHE BOOL "Forcing use of Boost libraries for iPhone" FORCE)
  set(Boost_FOUND TRUE CACHE BOOL "Forcing use of Boost libraries for iPhone" FORCE)
  set(MACOSX_BUNDLE_GUI_IDENTIFIER "com.yourcompany.\${PRODUCT_NAME:rfc1034identifier}")

  add_definitions(-fno-regmove)
  remove_definitions(-msse)
elseif (APPLE AND NOT GUCE_BUILD_PLATFORM_IPHONE)
  # Force gcc <= 4.0 on Mac OS X because 4.2 is not supported prior to Mac OS X 10.5
  include(CMakeForceCompiler)
  CMAKE_FORCE_C_COMPILER(gcc-4.0 GNU)
  CMAKE_FORCE_CXX_COMPILER(gcc-4.0 GNU)

  # Set 10.4 as the base SDK by default
  set(XCODE_ATTRIBUTE_SDKROOT macosx10.4)

  # Make sure that the OpenGL render system is selected for non-iPhone Apple builds
  set(GUCE_BUILD_RENDERSYSTEM_GL TRUE)
  set(GUCE_BUILD_RENDERSYSTEM_GLES FALSE)
endif ()

######################################################################
# Provide user options to customise the build process
######################################################################

# Customise what to build
option(GUCE_STATIC "Static build" FALSE)

set(GUCE_CONFIG_ALLOCATOR 2 CACHE STRING
"Specify the memory allocator to use. Possible values:
  1 - Standard allocator
  2 - nedmalloc
  3 - User-provided allocator"
)
option(GUCE_CONFIG_MEMTRACK_DEBUG "Enable GUCE's memory tracker in debug mode" FALSE)
option(GUCE_CONFIG_MEMTRACK_RELEASE "Enable GUCE's memory tracker in release mode" FALSE)

# determine threading options

# Customise what to install


###################################################################
# configure global build settings based on selected build options
###################################################################

include(ConfigureBuild)

##################################################################
# Now setup targets
##################################################################

getenv_path( GUCEF_HOME )
message( STATUS "GUCEF_HOME=${ENV_GUCEF_HOME}" )

# Add GUCEF's common include path
include_directories("${ENV_GUCEF_HOME}/common/include")

# Setup GUCEF modules
add_subdirectory( ${ENV_GUCEF_HOME}/gucefMT ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefCORE ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefVFS ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefCOMCORE ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefGUI ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefIMAGE ${GUCE_BINARY_DIR} )
#add_subdirectory( ${ENV_GUCEF_HOME}/gucefMATH ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefINPUT ${GUCE_BINARY_DIR} )
#add_subdirectory( ${ENV_GUCEF_HOME}/gucefAUDIO ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefCOM ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefMULTIPLAY ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefDRN ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefPATCHER ${GUCE_BINARY_DIR} )

# Setup GUCEF plugin dependencies
add_subdirectory( ${ENV_GUCEF_HOME}/gucefCORE/plugins/dstorepluginPARSIFALXML/dependancy/libparsifal ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefINPUT/plugins/inputdriverOIS/dependency/OIS ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefIMAGE/plugins/imgpluginFreeImage/dependencies/FreeImage ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefVFS/plugins/vfspluginZIP/dependencies/zlib ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefVFS/plugins/vfspluginZIP/dependencies/zziplib/zzip ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefVFS/plugins/vfspluginDVP/dependencies/DVPACKSYS ${GUCE_BINARY_DIR} )

# Setup GUCEF Plugin modules
add_subdirectory( ${ENV_GUCEF_HOME}/gucefCORE/plugins/dstorepluginPARSIFALXML ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefVFS/plugins/vfspluginDVP ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefVFS/plugins/vfspluginVP ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefVFS/plugins/vfspluginZIP ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefIMAGE/plugins/imgpluginFreeImage ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefIMAGE/plugins/imgpluginDEVIL ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefINPUT/plugins/inputdriverOIS ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefINPUT/plugins/inputdriverMSWINMSG ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefINPUT/plugins/inputdriverDIRECTINPUT8 ${GUCE_BINARY_DIR} )

# Setup GUCEF Test applications
add_subdirectory( ${ENV_GUCEF_HOME}/gucefVFS_TestApp ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefCOM_TestApp ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefCOMCORE_TestApp ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefMT_TestApp ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefCORE_TestApp ${GUCE_BINARY_DIR} )
#add_subdirectory( ${ENV_GUCEF_HOME}/gucefGUI_TestApp ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefIMAGE_TestApp ${GUCE_BINARY_DIR} )
#add_subdirectory( ${ENV_GUCEF_HOME}/gucefMULTIPLAY_TestApp ${GUCE_BINARY_DIR} )
#add_subdirectory( ${ENV_GUCEF_HOME}/gucefMATH_TestApp ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefINPUT_TestApp ${GUCE_BINARY_DIR} )
#add_subdirectory( ${ENV_GUCEF_HOME}/gucefAUDIO_TestApp ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/gucefDRN_TestApp ${GUCE_BINARY_DIR} )

# Setup GUCEF Tools
add_subdirectory( ${ENV_GUCEF_HOME}/tools/DuplicateFileFinder ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/tools/DVPPackTool ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/tools/FileReplacer ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/tools/HDFiller ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/tools/PatcherGUI ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/tools/PatchSetGenerator ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/tools/ServerPortExtender ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/tools/CMakeListGenerator ${GUCE_BINARY_DIR} )
add_subdirectory( ${ENV_GUCEF_HOME}/tools/CallstackLogAnalyzer ${GUCE_BINARY_DIR} )

# Setup GUCE modules
add_subdirectory( guceCORE )
add_subdirectory( guceGUI )

# Setup GUCE Plugin modules
add_subdirectory( guidriverCEGUIOgre )
add_subdirectory( guidriverMyGUIOgre )

# Setup GUCE Sample applications
add_subdirectory( samples/refapp )

# Install documentation
add_subdirectory(docs)

# Install CMake modules
#add_subdirectory( CMake )

# Provide CPack packaging target
#include( Packaging )

# Show feature summary
include( FeatureSummary )

