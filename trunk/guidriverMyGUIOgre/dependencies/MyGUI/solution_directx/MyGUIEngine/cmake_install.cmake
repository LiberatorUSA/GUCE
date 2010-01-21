# Install script for directory: D:/MyGUI/MyGUI_300/MyGUIEngine

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "D:/MyGUI/MyGUI_300/solution_directx/sdk")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Release" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/MyGUI/MyGUI_300/solution_directx/lib/Release/MyGUIEngine.lib")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/Release" TYPE SHARED_LIBRARY FILES "D:/MyGUI/MyGUI_300/solution_directx/bin/Release/MyGUIEngine.dll")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/RelWithDebInfo" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/MyGUI/MyGUI_300/solution_directx/lib/RelWithDebInfo/MyGUIEngine.lib")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/RelWithDebInfo" TYPE SHARED_LIBRARY FILES "D:/MyGUI/MyGUI_300/solution_directx/bin/RelWithDebInfo/MyGUIEngine.dll")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/MinSizeRel" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/MyGUI/MyGUI_300/solution_directx/lib/MinSizeRel/MyGUIEngine.lib")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/MinSizeRel" TYPE SHARED_LIBRARY FILES "D:/MyGUI/MyGUI_300/solution_directx/bin/MinSizeRel/MyGUIEngine.dll")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Debug" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/MyGUI/MyGUI_300/solution_directx/lib/Debug/MyGUIEngine_d.lib")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/Debug" TYPE SHARED_LIBRARY FILES "D:/MyGUI/MyGUI_300/solution_directx/bin/Debug/MyGUIEngine_d.dll")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/MYGUI" TYPE FILE FILES
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Allocator.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_CustomAllocator.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_DDItemInfo.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_IBItemInfo.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_MenuItemType.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_MessageStyle.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_WidgetToolTip.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Button.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Canvas.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ComboBox.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_DDContainer.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Edit.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_HScroll.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ItemBox.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_List.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ListBox.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ListCtrl.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_MenuBar.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_MenuCtrl.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_MenuItem.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Message.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_MultiList.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_PopupMenu.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Progress.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ScrollView.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_StaticImage.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_StaticText.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Tab.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_TabItem.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_VScroll.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Widget.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Window.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_IWidgetFactory.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Bitwise.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_CoordConverter.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_DataFileStream.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_DataStream.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Delegate.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_DelegateImplement.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_DynLib.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Enumerator.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_EventPair.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Guid.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_RenderOut.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_TextChangeHistory.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_TextIterator.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_TextureUtility.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_TextView.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Timer.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_UString.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Utility.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_WidgetTranslate.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_XmlDocument.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_LogManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_LogStream.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_CastWidget.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Common.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Diagnostic.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Exception.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_GenericFactory.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Macros.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Platform.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Precompiled.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Prerequest.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_RenderFormat.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ResourceHolder.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_WidgetDefines.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ICroppedRectangle.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_IDataStream.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Instance.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_IObject.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ISerializable.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ITexture.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_IUnlinkWidget.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_IVertexBuffer.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_IWidgetCreator.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Plugin.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_RTTI.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_BiIndexBase.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ScrollViewBase.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_WidgetEvent.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_WidgetUserData.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_EditText.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_MainSkin.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_RawRect.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_RotatingSkin.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_SimpleText.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_SubSkin.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_TileRect.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_IStateInfo.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ISubWidget.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ISubWidgetRect.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ISubWidgetText.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_LayerItem.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_LayerNode.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_OverlappedLayer.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_RenderItem.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_SharedLayer.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_SharedLayerNode.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ILayer.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ILayerItem.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ILayerNode.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_IRenderTarget.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ActionController.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ControllerEdgeHide.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ControllerFadeAlpha.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ControllerItem.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ControllerPosition.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ResourceImageSet.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ResourceImageSetPointer.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ResourceManualFont.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ResourceManualPointer.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ResourceSkin.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ResourceTrueTypeFont.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_IFont.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_IPointer.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_IResource.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ChildSkinInfo.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_FontData.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_MaskPickInfo.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_SubWidgetBinding.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_SubWidgetInfo.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Align.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Any.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Colour.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_CommonStateInfo.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ImageInfo.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_InputDefine.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_RenderTargetInfo.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_TCoord.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_TPoint.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_TRect.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_TSize.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Types.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Version.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_VertexData.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_WidgetStyle.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ClipboardManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ControllerManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_DataManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_DynLibManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_FactoryManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_FontManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_Gui.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_InputManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_LanguageManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_LayerManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_LayoutManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_PluginManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_PointerManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_RenderManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_ResourceManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_SkinManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_SubWidgetManager.h"
    "D:/MyGUI/MyGUI_300/MyGUIEngine/include/MyGUI_WidgetManager.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

