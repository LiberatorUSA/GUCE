#-------------------------------------------------------------------
# This file is part of the CMake build system for GUCE
#     (Galaxy Unlimited Engine)
# For the latest info, see http://www.VanvelzenSoftware.com/
#
# The contents of this file are placed in the public domain. Feel
# free to make use of it in any way you like.
#-------------------------------------------------------------------

# Configure settings and install targets

if (WIN32)
  set(GUCE_RELEASE_PATH "/Release")
  set(GUCE_RELWDBG_PATH "/RelWithDebInfo")
  set(GUCE_MINSIZE_PATH "/MinSizeRel")
  set(GUCE_DEBUG_PATH "/Debug")
  set(GUCE_LIB_RELEASE_PATH "/Release")
  set(GUCE_LIB_RELWDBG_PATH "/RelWithDebInfo")
  set(GUCE_LIB_MINSIZE_PATH "/MinSizeRel")
  set(GUCE_LIB_DEBUG_PATH "/Debug")
  set(GUCE_PLUGIN_PATH "/opt")
elseif (UNIX)
  set(GUCE_RELEASE_PATH "")
  set(GUCE_RELWDBG_PATH "")
  set(GUCE_MINSIZE_PATH "")
  set(GUCE_DEBUG_PATH "/debug")
  set(GUCE_LIB_RELEASE_PATH "")
  set(GUCE_LIB_RELWDBG_PATH "")
  set(GUCE_LIB_MINSIZE_PATH "")
  set(GUCE_LIB_DEBUG_PATH "")
  set(GUCE_PLUGIN_PATH "/GUCE")
endif ()

# create vcproj.user file for Visual Studio to set debug working directory
function(GUCE_create_vcproj_userfile TARGETNAME)
  if (MSVC)
    configure_file(
	  ${GUCE_TEMPLATES_DIR}/VisualStudioUserFile.vcproj.user.in
	  ${CMAKE_CURRENT_BINARY_DIR}/${TARGETNAME}.vcproj.user
	  @ONLY
	)
  endif ()
endfunction(GUCE_create_vcproj_userfile)

# install targets according to current build type
function(GUCE_install_target TARGETNAME SUFFIX)
  install(TARGETS ${TARGETNAME}
    RUNTIME DESTINATION "bin${GUCE_RELEASE_PATH}" CONFIGURATIONS Release None ""
    LIBRARY DESTINATION "lib${GUCE_LIB_RELEASE_PATH}${SUFFIX}" CONFIGURATIONS Release None ""
    ARCHIVE DESTINATION "lib${GUCE_LIB_RELEASE_PATH}${SUFFIX}" CONFIGURATIONS Release None ""
    FRAMEWORK DESTINATION "bin${GUCE_RELEASE_PATH}" CONFIGURATIONS Release None ""
  )
  install(TARGETS ${TARGETNAME}
    RUNTIME DESTINATION "bin${GUCE_RELWDBG_PATH}" CONFIGURATIONS RelWithDebInfo
    LIBRARY DESTINATION "lib${GUCE_LIB_RELWDBG_PATH}${SUFFIX}" CONFIGURATIONS RelWithDebInfo
    ARCHIVE DESTINATION "lib${GUCE_LIB_RELWDBG_PATH}${SUFFIX}" CONFIGURATIONS RelWithDebInfo
    FRAMEWORK DESTINATION "bin${GUCE_RELWDBG_PATH}" CONFIGURATIONS RelWithDebInfo
  )
  install(TARGETS ${TARGETNAME}
    RUNTIME DESTINATION "bin${GUCE_MINSIZE_PATH}" CONFIGURATIONS MinSizeRel
    LIBRARY DESTINATION "lib${GUCE_LIB_MINSIZE_PATH}${SUFFIX}" CONFIGURATIONS MinSizeRel
    ARCHIVE DESTINATION "lib${GUCE_LIB_MINSIZE_PATH}${SUFFIX}" CONFIGURATIONS MinSizeRel
    FRAMEWORK DESTINATION "bin${GUCE_MINSIZE_PATH}" CONFIGURATIONS MinSizeRel
  )
  install(TARGETS ${TARGETNAME}
    RUNTIME DESTINATION "bin${GUCE_DEBUG_PATH}" CONFIGURATIONS Debug
    LIBRARY DESTINATION "lib${GUCE_LIB_DEBUG_PATH}${SUFFIX}" CONFIGURATIONS Debug
    ARCHIVE DESTINATION "lib${GUCE_LIB_DEBUG_PATH}${SUFFIX}" CONFIGURATIONS Debug
    FRAMEWORK DESTINATION "bin${GUCE_DEBUG_PATH}" CONFIGURATIONS Debug
  )
endfunction(GUCE_install_target)

# setup common target settings
function(GUCE_config_common TARGETNAME)
  set_target_properties(${TARGETNAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${GUCE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${GUCE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${GUCE_BINARY_DIR}/bin
  )
  if(GUCE_BUILD_PLATFORM_IPHONE)
    set_target_properties(${TARGETNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_THUMB_SUPPORT "NO")
    set_target_properties(${TARGETNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_UNROLL_LOOPS "YES")
    set_target_properties(${TARGETNAME} PROPERTIES XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "iPhone Developer")
    set_target_properties(${TARGETNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_PRECOMPILE_PREFIX_HEADER "YES")
    set_target_properties(${TARGETNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_PREFIX_HEADER "${GUCE_SOURCE_DIR}/GUCEMain/include/GUCEStableHeaders.h")
  endif(GUCE_BUILD_PLATFORM_IPHONE)

  GUCE_create_vcproj_userfile(${TARGETNAME})

  if (MSVC) 
    add_definitions( "/D_CRT_SECURE_NO_WARNINGS /wd4251 /nologo" )
  endif()

endfunction(GUCE_config_common)

# setup library build
function(GUCE_config_lib LIBNAME)
  GUCE_config_common(${LIBNAME})
  if (GUCE_STATIC)
    # add static prefix, if compiling static version
    set_target_properties(${LIBNAME} PROPERTIES OUTPUT_NAME ${LIBNAME}Static)

    if(GUCE_BUILD_PLATFORM_IPHONE)
      set_target_properties(${LIBNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_UNROLL_LOOPS "YES")
      set_target_properties(${LIBNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_THUMB_SUPPORT "NO")
      set_target_properties(${LIBNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_PRECOMPILE_PREFIX_HEADER "YES")
      set_target_properties(${LIBNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_PREFIX_HEADER "${GUCE_SOURCE_DIR}/GUCEMain/include/GUCEStableHeaders.h")
    endif(GUCE_BUILD_PLATFORM_IPHONE)
  else (GUCE_STATIC)
    if (CMAKE_COMPILER_IS_GNUCXX)
      # add GCC visibility flags to shared library build
      set_target_properties(${LIBNAME} PROPERTIES COMPILE_FLAGS "${GUCE_GCC_VISIBILITY_FLAGS}")
	endif (CMAKE_COMPILER_IS_GNUCXX)
	
	# Set some Mac OS X specific framework settings, including installing the headers in subdirs
	if (APPLE AND NOT GUCE_BUILD_PLATFORM_IPHONE)
      set_target_properties(${LIBNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_PRECOMPILE_PREFIX_HEADER "YES")
      set_target_properties(${LIBNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_PREFIX_HEADER "${GUCE_SOURCE_DIR}/GUCEMain/include/GUCEStableHeaders.h")
      set_target_properties(${LIBNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_UNROLL_LOOPS "YES")
      add_custom_command(TARGET ${LIBNAME} POST_BUILD
        COMMAND mkdir ARGS -p ${CMAKE_BINARY_DIR}/lib/$(CONFIGURATION)/GUCE.framework/Headers/Threading
	    COMMAND /Developer/Library/PrivateFrameworks/DevToolsCore.framework/Resources/pbxcp ARGS -exclude .DS_Store -exclude CVS -exclude .svn -exclude 'CMakeLists.txt' -resolve-src-symlinks ${GUCE_SOURCE_DIR}/GUCEMain/include/Threading/* ${CMAKE_BINARY_DIR}/lib/$(CONFIGURATION)/GUCE.framework/Headers/Threading/
        COMMAND mkdir ARGS -p ${CMAKE_BINARY_DIR}/lib/$(CONFIGURATION)/GUCE.framework/Headers/OSX
	    COMMAND /Developer/Library/PrivateFrameworks/DevToolsCore.framework/Resources/pbxcp ARGS -exclude .DS_Store -exclude CVS -exclude .svn -exclude 'CMakeLists.txt' -resolve-src-symlinks ${GUCE_SOURCE_DIR}/GUCEMain/include/OSX/*.h ${CMAKE_BINARY_DIR}/lib/$(CONFIGURATION)/GUCE.framework/Headers/OSX/
    )
	endif (APPLE AND NOT GUCE_BUILD_PLATFORM_IPHONE)
  endif (GUCE_STATIC)
  GUCE_install_target(${LIBNAME} "")
  
  if (GUCE_INSTALL_PDB)
    # install debug pdb files
    if (GUCE_STATIC)
	  install(FILES ${GUCE_BINARY_DIR}/lib${GUCE_LIB_DEBUG_PATH}/${LIBNAME}Static_d.pdb
	    DESTINATION lib${GUCE_LIB_DEBUG_PATH}
		CONFIGURATIONS Debug
	  )
	  install(FILES ${GUCE_BINARY_DIR}/lib${GUCE_LIB_RELWDBG_PATH}/${LIBNAME}Static.pdb
	    DESTINATION lib${GUCE_LIB_RELWDBG_PATH}
		CONFIGURATIONS RelWithDebInfo
	  )
	else ()
	  install(FILES ${GUCE_BINARY_DIR}/bin${GUCE_DEBUG_PATH}/${LIBNAME}_d.pdb
	    DESTINATION bin${GUCE_DEBUG_PATH}
		CONFIGURATIONS Debug
	  )
	  install(FILES ${GUCE_BINARY_DIR}/bin${GUCE_RELWDBG_PATH}/${LIBNAME}.pdb
	    DESTINATION bin${GUCE_RELWDBG_PATH}
		CONFIGURATIONS RelWithDebInfo
	  )
	endif ()
  endif ()
endfunction(GUCE_config_lib)

# setup plugin build
function(GUCE_config_plugin PLUGINNAME)
  GUCE_config_common(${PLUGINNAME})
  if (GUCE_STATIC)
    # add static prefix, if compiling static version
    set_target_properties(${PLUGINNAME} PROPERTIES OUTPUT_NAME ${PLUGINNAME}Static)

    if(GUCE_BUILD_PLATFORM_IPHONE)
      set_target_properties(${PLUGINNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_THUMB_SUPPORT "NO")
      set_target_properties(${PLUGINNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_UNROLL_LOOPS "YES")
      set_target_properties(${PLUGINNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_PRECOMPILE_PREFIX_HEADER "YES")
      set_target_properties(${PLUGINNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_PREFIX_HEADER "${GUCE_SOURCE_DIR}/GUCEMain/include/GUCEStableHeaders.h")
    endif(GUCE_BUILD_PLATFORM_IPHONE)
  else (GUCE_STATIC)
    if (CMAKE_COMPILER_IS_GNUCXX)
      # add GCC visibility flags to shared library build
      set_target_properties(${PLUGINNAME} PROPERTIES COMPILE_FLAGS "${GUCE_GCC_VISIBILITY_FLAGS}")
      # disable "lib" prefix on Unix
      set_target_properties(${PLUGINNAME} PROPERTIES PREFIX "")
	endif (CMAKE_COMPILER_IS_GNUCXX)	
  endif (GUCE_STATIC)
  GUCE_install_target(${PLUGINNAME} ${GUCE_PLUGIN_PATH})

  if (GUCE_INSTALL_PDB)
    # install debug pdb files
    if (GUCE_STATIC)
	  install(FILES ${GUCE_BINARY_DIR}/lib${GUCE_LIB_DEBUG_PATH}/${PLUGINNAME}Static_d.pdb
	    DESTINATION lib${GUCE_LIB_DEBUG_PATH}/opt
		CONFIGURATIONS Debug
	  )
	  install(FILES ${GUCE_BINARY_DIR}/lib${GUCE_LIB_RELWDBG_PATH}/${PLUGINNAME}Static.pdb
	    DESTINATION lib${GUCE_LIB_RELWDBG_PATH}/opt
		CONFIGURATIONS RelWithDebInfo
	  )
	else ()
	  install(FILES ${GUCE_BINARY_DIR}/bin${GUCE_DEBUG_PATH}/${PLUGINNAME}_d.pdb
	    DESTINATION bin${GUCE_DEBUG_PATH}
		CONFIGURATIONS Debug
	  )
	  install(FILES ${GUCE_BINARY_DIR}/bin${GUCE_RELWDBG_PATH}/${PLUGINNAME}.pdb
	    DESTINATION bin${GUCE_RELWDBG_PATH}
		CONFIGURATIONS RelWithDebInfo
	  )
	endif ()
  endif ()
endfunction(GUCE_config_plugin)

# setup GUCE demo build
function(GUCE_config_sample SAMPLENAME)
  # The PRODUCT_NAME target setting cannot contain underscores.  Just remove them
  # Known bug in Xcode CFBundleIdentifier processing rdar://6187020
  # Can cause an instant App Store rejection. Also, code signing will fail. 
  #if (GUCE_BUILD_PLATFORM_IPHONE)
#    string (REPLACE "_" "" SAMPLENAME ${SAMPLENAME})
  #endif()
  GUCE_config_common(${SAMPLENAME})

  # set install RPATH for Unix systems
  if (UNIX AND GUCE_FULL_RPATH)
    set_property(TARGET ${SAMPLENAME} APPEND PROPERTY
      INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
    set_property(TARGET ${SAMPLENAME} PROPERTY INSTALL_RPATH_USE_LINK_PATH TRUE)
  endif ()
  
  if (APPLE)
    # On OS X, create .app bundle
    set_property(TARGET ${SAMPLENAME} PROPERTY MACOSX_BUNDLE TRUE)

	if (GUCE_BUILD_PLATFORM_IPHONE)
      set (GUCE_SAMPLE_CONTENTS_PATH 
        ${CMAKE_BINARY_DIR}/bin/$(CONFIGURATION)$(EFFECTIVE_PLATFORM_NAME)/$(PRODUCT_NAME).app)
      add_custom_command(TARGET ${SAMPLENAME} POST_BUILD
        COMMAND cp ARGS ${CMAKE_BINARY_DIR}/bin/*.cfg ${GUCE_SAMPLE_CONTENTS_PATH}/
	    COMMAND /Developer/Library/PrivateFrameworks/DevToolsCore.framework/Resources/pbxcp -exclude .DS_Store -exclude CVS -exclude .svn -exclude 'CMakeLists.txt' -resolve-src-symlinks ${GUCE_SOURCE_DIR}/Samples/Media ${GUCE_SAMPLE_CONTENTS_PATH}/
	    COMMAND /Developer/Library/PrivateFrameworks/DevToolsCore.framework/Resources/pbxcp -exclude .DS_Store -exclude CVS -exclude .svn -exclude 'CMakeLists.txt' -resolve-src-symlinks ${GUCE_SOURCE_DIR}/Samples/Common/misc/Icon.png ${GUCE_SAMPLE_CONTENTS_PATH}/
	    COMMAND /Developer/Library/PrivateFrameworks/DevToolsCore.framework/Resources/pbxcp -exclude .DS_Store -exclude CVS -exclude .svn -exclude 'CMakeLists.txt' -resolve-src-symlinks ${GUCE_SOURCE_DIR}/Samples/Common/misc/Default.png ${GUCE_SAMPLE_CONTENTS_PATH}/
      )
	else ()
      # also, symlink frameworks so .app is standalone
      # NOTE: $(CONFIGURATION) is not resolvable at CMake run time, it's only 
      # valid at build time (hence parenthesis rather than braces)
      set (GUCE_SAMPLE_CONTENTS_PATH 
        ${CMAKE_BINARY_DIR}/bin/$(CONFIGURATION)/${SAMPLENAME}.app/Contents)
      add_custom_command(TARGET ${SAMPLENAME} POST_BUILD
        COMMAND mkdir ARGS -p ${GUCE_SAMPLE_CONTENTS_PATH}/Frameworks
        COMMAND ln ARGS -s -f ${CMAKE_BINARY_DIR}/lib/$(CONFIGURATION)/GUCE.framework 
          ${GUCE_SAMPLE_CONTENTS_PATH}/Frameworks/
        COMMAND ln ARGS -s -f ${CMAKE_SOURCE_DIR}/Dependencies/Cg.framework 
          ${GUCE_SAMPLE_CONTENTS_PATH}/Frameworks/
        COMMAND ln ARGS -s -f ${CMAKE_SOURCE_DIR}/Dependencies/CEGUI.framework 
          ${GUCE_SAMPLE_CONTENTS_PATH}/Frameworks/
      )
      # now cfg files
      add_custom_command(TARGET ${SAMPLENAME} POST_BUILD
        COMMAND mkdir ARGS -p ${GUCE_SAMPLE_CONTENTS_PATH}/Resources
        COMMAND ln ARGS -s -f ${CMAKE_BINARY_DIR}/bin/plugins.cfg 
          ${GUCE_SAMPLE_CONTENTS_PATH}/Resources/
        COMMAND ln ARGS -s -f ${CMAKE_BINARY_DIR}/bin/resources.cfg 
          ${GUCE_SAMPLE_CONTENTS_PATH}/Resources/
        COMMAND ln ARGS -s -f ${CMAKE_BINARY_DIR}/bin/media.cfg 
          ${GUCE_SAMPLE_CONTENTS_PATH}/Resources/
        COMMAND ln ARGS -s -f ${CMAKE_BINARY_DIR}/bin/quake3settings.cfg 
          ${GUCE_SAMPLE_CONTENTS_PATH}/Resources/
      )
      # now plugins
      add_custom_command(TARGET ${SAMPLENAME} POST_BUILD
        COMMAND mkdir ARGS -p ${GUCE_SAMPLE_CONTENTS_PATH}/Plugins)
      if (GUCE_BUILD_RENDERSYSTEM_GL)
        add_custom_command(TARGET ${SAMPLENAME} POST_BUILD
          COMMAND ln ARGS -s -f ${CMAKE_BINARY_DIR}/lib/$(CONFIGURATION)/RenderSystem_GL.dylib 
            ${GUCE_SAMPLE_CONTENTS_PATH}/Plugins/
        )
      endif ()
      if (GUCE_BUILD_RENDERSYSTEM_GLES)
        add_custom_command(TARGET ${SAMPLENAME} POST_BUILD
          COMMAND ln ARGS -s -f ${CMAKE_BINARY_DIR}/lib/$(CONFIGURATION)/RenderSystem_GLES.a
            ${GUCE_SAMPLE_CONTENTS_PATH}/Plugins/
        )
      endif ()
      if (GUCE_BUILD_PLUGIN_BSP)    
        add_custom_command(TARGET ${SAMPLENAME} POST_BUILD
        COMMAND ln ARGS -s -f ${CMAKE_BINARY_DIR}/lib/$(CONFIGURATION)/Plugin_BSPSceneManager.dylib 
          ${GUCE_SAMPLE_CONTENTS_PATH}/Plugins/
        )
      endif()
      if (GUCE_BUILD_PLUGIN_CG)    
        add_custom_command(TARGET ${SAMPLENAME} POST_BUILD
        COMMAND ln ARGS -s -f ${CMAKE_BINARY_DIR}/lib/$(CONFIGURATION)/Plugin_CgProgramManager.dylib 
          ${GUCE_SAMPLE_CONTENTS_PATH}/Plugins/
        )
      endif()
      if (GUCE_BUILD_PLUGIN_OCTREE)    
        add_custom_command(TARGET ${SAMPLENAME} POST_BUILD
        COMMAND ln ARGS -s -f ${CMAKE_BINARY_DIR}/lib/$(CONFIGURATION)/Plugin_OctreeSceneManager.dylib 
          ${GUCE_SAMPLE_CONTENTS_PATH}/Plugins/
       )
      endif()
      if (GUCE_BUILD_PLUGIN_PCZ)    
        add_custom_command(TARGET ${SAMPLENAME} POST_BUILD
          COMMAND ln ARGS -s -f ${CMAKE_BINARY_DIR}/lib/$(CONFIGURATION)/Plugin_PCZSceneManager.dylib 
            ${GUCE_SAMPLE_CONTENTS_PATH}/Plugins/    
        )
        add_custom_command(TARGET ${SAMPLENAME} POST_BUILD
        COMMAND ln ARGS -s -f ${CMAKE_BINARY_DIR}/lib/$(CONFIGURATION)/Plugin_OctreeZone.dylib 
          ${GUCE_SAMPLE_CONTENTS_PATH}/Plugins/
      )
      endif()
      if (GUCE_BUILD_PLUGIN_PFX)    
        add_custom_command(TARGET ${SAMPLENAME} POST_BUILD
        COMMAND ln ARGS -s -f ${CMAKE_BINARY_DIR}/lib/$(CONFIGURATION)/Plugin_ParticleFX.dylib 
          ${GUCE_SAMPLE_CONTENTS_PATH}/Plugins/
        )
      endif()
      if (GUCE_BUILD_CEGUIRENDERER)    
        add_custom_command(TARGET ${SAMPLENAME} POST_BUILD
        COMMAND ln ARGS -s -f ${CMAKE_BINARY_DIR}/lib/$(CONFIGURATION)/libCEGUIGUCERenderer.dylib 
          ${GUCE_SAMPLE_CONTENTS_PATH}/Plugins/
        )
      endif()
    endif()
  endif (APPLE)

  if (GUCE_INSTALL_SAMPLES)
    GUCE_install_target(${SAMPLENAME} "")
    if (GUCE_INSTALL_PDB)
      # install debug pdb files
      install(FILES ${GUCE_BINARY_DIR}/bin${GUCE_DEBUG_PATH}/${SAMPLENAME}.pdb
        DESTINATION bin${GUCE_DEBUG_PATH} CONFIGURATIONS Debug
        )
      install(FILES ${GUCE_BINARY_DIR}/bin${GUCE_RELWDBG_PATH}/${SAMPLENAME}.pdb
        DESTINATION bin${GUCE_RELWDBG_PATH} CONFIGURATIONS RelWithDebInfo
        )
    endif ()
  endif ()	

endfunction(GUCE_config_sample)

# setup GUCE tool build
function(GUCE_config_tool TOOLNAME)
  GUCE_config_common(${TOOLNAME})

  # set install RPATH for Unix systems
  if (UNIX AND GUCE_FULL_RPATH)
    set_property(TARGET ${TOOLNAME} APPEND PROPERTY
      INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
    set_property(TARGET ${TOOLNAME} PROPERTY INSTALL_RPATH_USE_LINK_PATH TRUE)
  endif ()

  if (GUCE_INSTALL_TOOLS)
    GUCE_install_target(${TOOLNAME} "")
    if (GUCE_INSTALL_PDB)
      # install debug pdb files
      install(FILES ${GUCE_BINARY_DIR}/bin${GUCE_DEBUG_PATH}/${TOOLNAME}.pdb
        DESTINATION bin${GUCE_DEBUG_PATH}
        CONFIGURATIONS Debug
        )
      install(FILES ${GUCE_BINARY_DIR}/bin${GUCE_RELWDBG_PATH}/${TOOLNAME}.pdb
        DESTINATION bin${GUCE_RELWDBG_PATH}
        CONFIGURATIONS RelWithDebInfo
        )
    endif ()
  endif ()	

endfunction(GUCE_config_tool)
