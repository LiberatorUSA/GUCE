#-------------------------------------------------------------------
# This file has been automatically generated by ProjectGenerator    
# which is part of a build system designed for GUCEF                
#     (Galaxy Unlimited Framework)                                  
# For the latest info, see http://www.VanvelzenSoftware.com/        
#                                                                   
# The contents of this file are placed in the public domain. Feel   
# free to make use of it in any way you like.                       
#-------------------------------------------------------------------


ifndef $(MY_MODULE_PATH)
  MY_MODULE_PATH := $(call my-dir)
endif
LOCAL_PATH := $(MY_MODULE_PATH)

include $(CLEAR_VARS)

@echo Module path: $(MY_MODULE_PATH)
LOCAL_MODULE := guceCORE
@echo Module name: $(LOCAL_MODULE)

LOCAL_SRC_FILES := \
  src/CGUCEApplication.cpp \
  src/CGUCECOREModule.cpp \
  src/CGUCEFVFSArchive.cpp \
  src/CGUCEFVFSArchiveFactory.cpp \
  src/CIOAccessArchive.cpp \
  src/CIOAccessArchiveFactory.cpp \
  src/CIOAccessToDataStream.cpp \
  src/CIWindowContextHandler.cpp \
  src/COgreDataStreamToIOAccess.cpp \
  src/COgreImageCodecAdapter.cpp \
  src/COgreLogToGUCEFLogAdapter.cpp \
  src/CStaticDataStreamPtr.cpp \
  src/CStaticResourcePtr.cpp \
  src/CVFSHandleToDataStream.cpp \
  src/CWindowContext.cpp \
  src/CWindowManager.cpp \
  src/guceCORE.cpp \
  src/guceCORE_CIMeshCodec.cpp \
  src/guceCORE_CMeshManager.cpp \
  src/guceCORE_COgreMeshCodecAdapter.cpp \
  src/guceCORE_CVideoOptions.cpp \
  src/guceCORE_CVideoSettings.cpp \
  src/miscutils.cpp

LOCAL_C_INCLUDES := \
  $(MY_MODULE_PATH)/include \
  $(MY_MODULE_PATH)/../../../GUCEF/trunk/common/include \
  $(MY_MODULE_PATH)/../../../GUCEF/trunk/gucefCOM/include \
  $(MY_MODULE_PATH)/../../../GUCEF/trunk/gucefCOMCORE/include \
  $(MY_MODULE_PATH)/../../../GUCEF/trunk/gucefCORE/include \
  $(MY_MODULE_PATH)/../../../GUCEF/trunk/gucefCORE/include/android \
  $(MY_MODULE_PATH)/../../../GUCEF/trunk/gucefDRN/include \
  $(MY_MODULE_PATH)/../../../GUCEF/trunk/gucefGUI/include \
  $(MY_MODULE_PATH)/../../../GUCEF/trunk/gucefIMAGE/include \
  $(MY_MODULE_PATH)/../../../GUCEF/trunk/gucefINPUT/include \
  $(MY_MODULE_PATH)/../../../GUCEF/trunk/gucefMT/include \
  $(MY_MODULE_PATH)/../../../GUCEF/trunk/gucefPATCHER/include \
  $(MY_MODULE_PATH)/../../../GUCEF/trunk/gucefVFS/include \
  $(MY_MODULE_PATH)/../../../GUCEF/trunk/gucefVFS/plugins/vfspluginZIP/dependencies/zziplib \
  $(MY_MODULE_PATH)/../../../GUCEF/trunk/gucefVFS/plugins/vfspluginZIP/dependencies/zziplib/zzip \
  $(MY_MODULE_PATH)/../dependencies/Ogre/OgreMain/include \
  $(MY_MODULE_PATH)/../dependencies/Ogre/OgreMain/include/Android \
  $(MY_MODULE_PATH)/../dependencies/Ogre/OgreMain/src \
  $(MY_MODULE_PATH)/../dependencies/Ogre/OgreMain/src/nedmalloc \
  $(MY_MODULE_PATH)/../dependencies/freetype/include \
  $(MY_MODULE_PATH)/../dependencies/freetype/include/freetype \
  $(MY_MODULE_PATH)/../dependencies/freetype/include/freetype/config \
  $(MY_MODULE_PATH)/../dependencies/freetype/include/freetype/internal \
  $(MY_MODULE_PATH)/../dependencies/freetype/include/freetype/internal/services \
  $(MY_MODULE_PATH)/../dependencies/freetype/src/winfonts


LOCAL_SHARED_LIBRARIES := \
  OgreMain \
  gucefCOM \
  gucefCOMCORE \
  gucefCORE \
  gucefDRN \
  gucefGUI \
  gucefIMAGE \
  gucefINPUT \
  gucefMT \
  gucefPATCHER \
  gucefVFS

include $(BUILD_SHARED_LIBRARY)
