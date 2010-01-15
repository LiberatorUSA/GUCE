#-------------------------------------------------------------------
# This file is part of the CMake build system for GUCE
# For the latest info, see http://www.VanvelzenSoftware.com/
#
# The contents of this file are placed in the public domain. Feel
# free to make use of it in any way you like.
#-------------------------------------------------------------------

#######################################################################
# This file takes care of configuring GUCE to build with the settings
# given in CMake. It creates the necessary config.h file and will 
# also prepare package files for pkg-config and CMake.
#######################################################################

if (GUCE_BUILD_PLATFORM_IPHONE)
  set(GUCE_SET_BUILD_PLATFORM_IPHONE 1)
  set(GUCE_STATIC 1)
  set(GUCE_STATIC_LIB 1)
endif()

# should we build static libs?
if (GUCE_STATIC)
  set(GUCE_LIB_TYPE STATIC)
else ()
  set(GUCE_LIB_TYPE SHARED)
endif ()

# configure threading options
set(GUCE_THREAD_PROVIDER 0)
if (GUCE_CONFIG_THREADS)
	if (UNIX)
		add_definitions(-pthread)
	endif ()

	if (GUCE_CONFIG_THREAD_PROVIDER STREQUAL "boost")
		set(GUCE_THREAD_PROVIDER 1)
		include_directories(${Boost_INCLUDE_DIRS})
		# On MSVC Boost usually tries to autolink boost libraries. However since
		# this behaviour is not available on all compilers, we need to find the libraries
		# ourselves, anyway. Disable auto-linking to avoid mess-ups.
		add_definitions(-DBOOST_ALL_NO_LIB)
		set(GUCE_THREAD_LIBRARIES ${Boost_LIBRARIES})
	endif ()

	if (GUCE_CONFIG_THREAD_PROVIDER STREQUAL "poco")
		set(GUCE_THREAD_PROVIDER 2)
		include_directories(${POCO_INCLUDE_DIRS})
		set(GUCE_THREAD_LIBRARIES ${POCO_LIBRARIES})
	endif ()

	if (GUCE_CONFIG_THREAD_PROVIDER STREQUAL "tbb")
		set(GUCE_THREAD_PROVIDER 3)
		include_directories(${TBB_INCLUDE_DIRS})
		set(GUCE_THREAD_LIBRARIES ${TBB_LIBRARIES})
	endif ()
endif()


# determine config values depending on build options 
set(GUCE_SET_DOUBLE 0)
set(GUCE_SET_ALLOCATOR ${GUCE_CONFIG_ALLOCATOR})
set(GUCE_SET_CONTAINERS_USE_ALLOCATOR 0)
set(GUCE_SET_STRING_USE_ALLOCATOR 0)
set(GUCE_SET_MEMTRACK_DEBUG 0)
set(GUCE_SET_MEMTRACK_RELEASE 0)
set(GUCE_SET_THREADS ${GUCE_CONFIG_THREADS})
set(GUCE_SET_THREAD_PROVIDER ${GUCE_THREAD_PROVIDER})
set(GUCE_SET_DISABLE_FREEIMAGE 0)
set(GUCE_SET_DISABLE_DDS 0)
set(GUCE_SET_DISABLE_ZIP 0)
set(GUCE_SET_NEW_COMPILERS 0)
set(GUCE_STATIC_LIB 0)
set(GUCE_SET_USE_BOOST 0)
if (GUCE_CONFIG_DOUBLE)
  set(GUCE_SET_DOUBLE 1)
endif()
if (GUCE_CONFIG_CONTAINERS_USE_CUSTOM_ALLOCATOR)
  set(GUCE_SET_CONTAINERS_USE_ALLOCATOR 1)
endif ()
if (GUCE_CONFIG_STRING_USE_CUSTOM_ALLOCATOR)
  set(GUCE_SET_STRING_USE_ALLOCATOR 1)
endif ()
if (GUCE_CONFIG_MEMTRACK_DEBUG)
  set(GUCE_SET_MEMTRACK_DEBUG 1)
endif()
if (GUCE_CONFIG_MEMTRACK_RELEASE)
  set(GUCE_SET_MEMTRACK_RELEASE 1)
endif()
if (GUCE_CONFIG_DISABLE_FREEIMAGE)
  set(GUCE_SET_DISABLE_FREEIMAGE 1)
endif()
if (GUCE_CONFIG_DISABLE_DDS)
  set(GUCE_SET_DISABLE_DDS 1)
endif()
if (GUCE_CONFIG_DISABLE_ZIP)
  set(GUCE_SET_DISABLE_ZIP 1)
endif()
if(GUCE_CONFIG_NEW_COMPILERS)
  set(GUCE_SET_NEW_COMPILERS 1)
endif()
if (GUCE_STATIC)
  set(GUCE_STATIC_LIB 1)
endif()
if (GUCE_USE_BOOST)
  set(GUCE_SET_USE_BOOST 1)
endif()
add_definitions(-DHAVE_GUCE_BUILDSETTINGS_H)

if (GUCE_TEST_BIG_ENDIAN)
  set(GUCE_CONFIG_BIG_ENDIAN 1)
else ()
  set(GUCE_CONFIG_LITTLE_ENDIAN 1)
endif ()

# generate buildsettings.h 
configure_file(${GUCE_TEMPLATES_DIR}/GUCE_buildsettings.h.in ${GUCE_BINARY_DIR}/include/GUCE_buildsettings.h @ONLY)
install(FILES ${GUCE_BINARY_DIR}/include/GUCE_buildsettings.h DESTINATION include/GUCE)

# Read contents of the GUCE_Config.h file
file(READ "${GUCE_SOURCE_DIR}/common/include/GUCE_config.h" GUCE_CONFIG_H)
# add HAVE_GUCE_BUILDSETTINGS_H preprocessor define
file(WRITE ${GUCE_BINARY_DIR}/include/GUCE_config.h "#define HAVE_GUCE_BUILDSETTINGS_H\n${GUCE_CONFIG_H}")
install(FILES ${GUCE_BINARY_DIR}/include/GUCE_config.h DESTINATION include/GUCE)


# Create the pkg-config package files on Unix systems
if (UNIX)
  set(GUCE_LIB_SUFFIX "")
  set(GUCE_PLUGIN_PREFIX "")
  set(GUCE_PLUGIN_EXT ".so")
  if (GUCE_STATIC)
    set(GUCE_LIB_SUFFIX "${GUCE_LIB_SUFFIX}Static")
    set(GUCE_PLUGIN_PREFIX "lib")
    set(GUCE_PLUGIN_EXT ".a")
  endif ()
  string(TOLOWER "${CMAKE_BUILD_TYPE}" GUCE_BUILD_TYPE)
  if (GUCE_BUILD_TYPE STREQUAL "debug")
    set(GUCE_LIB_SUFFIX "${GUCE_LIB_SUFFIX}_d")
  endif ()

  set(GUCE_ADDITIONAL_LIBS "")
  set(GUCE_CFLAGS "")
  set(GUCE_PREFIX_PATH ${CMAKE_INSTALL_PREFIX})
  if (GUCE_CONFIG_THREADS GREATER 0)
    set(GUCE_CFLAGS "-pthread")
    set(GUCE_ADDITIONAL_LIBS "${GUCE_ADDITIONAL_LIBS} -lpthread")
  endif ()
  if (GUCE_STATIC)
    if (GUCE_CONFIG_THREADS)
      set(GUCE_ADDITIONAL_LIBS "${GUCE_ADDITIONAL_LIBS} -lboost-thread-mt")
    endif ()
    # there is no pkgconfig file for freeimage, so we need to add that lib manually
    set(GUCE_ADDITIONAL_LIBS "${GUCE_ADDITIONAL_LIBS} -lfreeimage")
    configure_file(${GUCE_TEMPLATES_DIR}/GUCEStatic.pc.in ${GUCE_BINARY_DIR}/pkgconfig/GUCE${GUCE_LIB_SUFFIX}.pc @ONLY)
  else ()
    configure_file(${GUCE_TEMPLATES_DIR}/GUCE.pc.in ${GUCE_BINARY_DIR}/pkgconfig/GUCE${GUCE_LIB_SUFFIX}.pc @ONLY)
  endif ()
  install(FILES ${GUCE_BINARY_DIR}/pkgconfig/GUCE${GUCE_LIB_SUFFIX}.pc DESTINATION lib/pkgconfig)

  # configure additional packages
  
endif ()

if (GUCE_STANDALONE_BUILD)
  set(CMAKE_USE_RELATIVE_PATHS true)
  set(CMAKE_SUPPRESS_REGENERATION true)
endif()

if (MSVC)
  # Enable intrinsics on MSVC in debug mode
  # Not actually necessary in release mode since /O2 implies /Oi but can't easily add this per build type?
  add_definitions(/Oi)
endif (MSVC)

### Commented because the FindGUCE script can currently fill this role better ###
# # Create the CMake package files
# if (WIN32)
#   set(GUCE_CMAKE_DIR CMake)
# elseif (UNIX)
#   set(GUCE_CMAKE_DIR lib/cmake)
# elseif (APPLE)
# endif ()
# configure_file(${GUCE_TEMPLATES_DIR}/GUCEConfig.cmake.in ${GUCE_BINARY_DIR}/cmake/GUCEConfig.cmake @ONLY)
# configure_file(${GUCE_TEMPLATES_DIR}/GUCEConfigVersion.cmake.in ${GUCE_BINARY_DIR}/cmake/GUCEConfigVersion.cmake @ONLY)
# install(FILES
#   ${GUCE_BINARY_DIR}/cmake/GUCEConfig.cmake
#   ${GUCE_BINARY_DIR}/cmake/GUCEConfigVersion.cmake
#   DESTINATION ${GUCE_CMAKE_DIR}
# )
# 
