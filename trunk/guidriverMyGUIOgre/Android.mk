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
LOCAL_MODULE := guidriverMyGUIOgre
@echo Module name: $(LOCAL_MODULE)

LOCAL_SRC_FILES := \
  include/guceMyGUIOgre_CIOAccessToMyGuiDataStreamAdapter.cpp \
  src/guceMyGUIOgre.cpp \
  src/guceMyGUIOgre_CButtonImp.cpp \
  src/guceMyGUIOgre_CCheckboxImp.cpp \
  src/guceMyGUIOgre_CComboboxImp.cpp \
  src/guceMyGUIOgre_CDataManager.cpp \
  src/guceMyGUIOgre_CEditboxImp.cpp \
  src/guceMyGUIOgre_CFileOpenDialogImp.cpp \
  src/guceMyGUIOgre_CFileSaveDialogImp.cpp \
  src/guceMyGUIOgre_CFileSystemDialogImp.cpp \
  src/guceMyGUIOgre_CFormBackendImp.cpp \
  src/guceMyGUIOgre_CGridViewImp.cpp \
  src/guceMyGUIOgre_CGUIContext.cpp \
  src/guceMyGUIOgre_CGUIDriver.cpp \
  src/guceMyGUIOgre_CImageFrameImp.cpp \
  src/guceMyGUIOgre_CLabelImp.cpp \
  src/guceMyGUIOgre_CListboxImp.cpp \
  src/guceMyGUIOgre_CMemoboxImp.cpp \
  src/guceMyGUIOgre_CMenuBarImp.cpp \
  src/guceMyGUIOgre_CModule.cpp \
  src/guceMyGUIOgre_CMyGUIInputAdapter.cpp \
  src/guceMyGUIOgre_CPopupMenuImp.cpp \
  src/guceMyGUIOgre_CProgressBarImp.cpp \
  src/guceMyGUIOgre_CPushButtonImp.cpp \
  src/guceMyGUIOgre_CRenderContextImp.cpp \
  src/guceMyGUIOgre_CSpinnerImp.cpp \
  src/guceMyGUIOgre_CTabContentPaneImp.cpp \
  src/guceMyGUIOgre_CTabControlImp.cpp \
  src/guceMyGUIOgre_CTreeviewImp.cpp \
  src/guceMyGUIOgre_CVFSHandleToMyGuiDataStreamAdapter.cpp \
  src/guceMyGUIOgre_CVFSInfoProvider.cpp \
  src/guceMyGUIOgre_CWidgetImp.cpp \
  src/guceMyGUIOgre_CWindowImp.cpp \
  src/guceMyGUIOgre_pluginAPI.cpp \
  src/MyGUI_OgreRenderManager.cpp \
  src/MyGUI_OgreRTTexture.cpp \
  src/MyGUI_OgreTexture.cpp \
  src/MyGUI_OgreVertexBuffer.cpp

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
  $(MY_MODULE_PATH)/../dependencies/Ogre/OgreMain/src \
  $(MY_MODULE_PATH)/../dependencies/Ogre/OgreMain/src/nedmalloc \
  $(MY_MODULE_PATH)/../dependencies/freetype/include \
  $(MY_MODULE_PATH)/../dependencies/freetype/include/freetype \
  $(MY_MODULE_PATH)/../dependencies/freetype/include/freetype/config \
  $(MY_MODULE_PATH)/../dependencies/freetype/include/freetype/internal \
  $(MY_MODULE_PATH)/../dependencies/freetype/include/freetype/internal/services \
  $(MY_MODULE_PATH)/../dependencies/freetype/src/winfonts \
  $(MY_MODULE_PATH)/../guceCORE/include \
  $(MY_MODULE_PATH)/../guceGUI/include \
  $(MY_MODULE_PATH)/dependencies/MyGUI/MyGUIEngine/include


LOCAL_SHARED_LIBRARIES := \
  MyGUIEngine \
  guceCORE \
  guceGUI \
  gucefCORE \
  gucefMT

include $(BUILD_SHARED_LIBRARY)

