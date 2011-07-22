#-------------------------------------------------------------------
# This file has been automatically generated by ProjectGenerator    
# which is part of a build system designed for GUCEF                
#     (Galaxy Unlimited Framework)                                  
# For the latest info, see http://www.VanvelzenSoftware.com/        
#                                                                   
# The contents of this file are placed in the public domain. Feel   
# free to make use of it in any way you like.                       
#-------------------------------------------------------------------


#
# This is the project makefile which includes all modules which are part of this project
#
# PROJECT: "GUCE"
#

ifndef $(PROJECT_ROOT_PATH)
  PROJECT_ROOT_PATH := $(call my-dir)
endif

include $(CLEAR_VARS)

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/dependencies/miniupnpc
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefCORE/plugins/dstorepluginPARSIFALXML/dependancy/libparsifal
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefVFS/plugins/vfspluginZIP/dependencies/zziplib
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/dependencies/freetype
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/dependencies/pcre
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefCORE
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefMT
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefMT_TestApp
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/dependencies/Ogre/RenderSystems/GLES2
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/guidriverMyGUIOgre/dependencies/MyGUI/MyGUIEngine
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefCOMCORE
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefCORE_TestApp
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefIMAGE
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefINPUT
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefMATH
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefVFS
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefVFS/plugins/vfspluginDVP/dependencies/DVPACKSYS
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/tools/DuplicateFileFinder
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/tools/FileReplacer
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/tools/HDFiller
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/tools/ProjectGenerator
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/tools/ReferenceUpdater
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/guidriverCEGUIOgre/dependency/CEGUI
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefCOM
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefCOMCORE_TestApp
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefCORE/plugins/dstorepluginPARSIFALXML
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefDRN
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefIMAGE_TestApp
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefINPUT_TestApp
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefLOADER
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefLOADER_TestApp
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefANDROIDGLUE/Gingerbread/jni
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefVFS/plugins/vfspluginVP
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/tools/DVPPackTool
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/tools/FileDiff
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/tools/ServerPortExtender
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefCOM_TestApp
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefDRN_TestApp
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefGUI
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefMULTIPLAY
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefPATCHER
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/tools/ArchiveDiffLib
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefVFS/plugins/vfspluginDVP
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefVFS/plugins/vfspluginZIP
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/tools/GucefLogServiceLib
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/tools/SVNMagicMerge
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/dependencies/Ogre/OgreMain
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/dependencies/Ogre/Samples/Common
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/dependencies/Ogre/Samples/SkyBox
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/dependencies/Ogre/Tools/XMLConverter
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/dependencies/Ogre/RenderSystems/GLES
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/dependencies/Ogre/RenderSystems/GL
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/dependencies/Ogre/RenderSystems/Direct3D9
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/dependencies/Ogre/RenderSystems/Direct3D11
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/dependencies/Ogre/RenderSystems/Direct3D10
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/dependencies/Ogre/PlugIns/OctreeSceneManager
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/dependencies/Ogre/Samples/Browser
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/guidriverMyGUIOgre/dependencies/MyGUI/Common
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/guidriverMyGUIOgre/dependencies/MyGUI/Tools/LayoutEditor
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/guidriverMyGUIOgre/dependencies/MyGUI/Tools/ImageSetViewer
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/guidriverMyGUIOgre/dependencies/MyGUI/Tools/FontViewer
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefSMDRN
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/tools/GucefLogServiceApp
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/tools/GucefLogServiceClientPlugin
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/../../GUCEF/trunk/gucefPRODMAN
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/guceCORE
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/guceGUI
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/guidriverMyGUIOgre
include $(MY_MODULE_PATH)/Android.mk

MY_MODULE_PATH := $(PROJECT_ROOT_PATH)/guidriverCEGUIOgre
include $(MY_MODULE_PATH)/Android.mk

