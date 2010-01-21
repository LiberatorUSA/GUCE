# Install script for directory: D:/MyGUI/MyGUI_300/Demos

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

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("D:/MyGUI/MyGUI_300/solution_directx/Demos/Demo_Colour/cmake_install.cmake")
  INCLUDE("D:/MyGUI/MyGUI_300/solution_directx/Demos/Demo_Console/cmake_install.cmake")
  INCLUDE("D:/MyGUI/MyGUI_300/solution_directx/Demos/Demo_Controllers/cmake_install.cmake")
  INCLUDE("D:/MyGUI/MyGUI_300/solution_directx/Demos/Demo_Gui/cmake_install.cmake")
  INCLUDE("D:/MyGUI/MyGUI_300/solution_directx/Demos/Demo_ItemBox/cmake_install.cmake")
  INCLUDE("D:/MyGUI/MyGUI_300/solution_directx/Demos/Demo_PanelView/cmake_install.cmake")
  INCLUDE("D:/MyGUI/MyGUI_300/solution_directx/Demos/Demo_Picking/cmake_install.cmake")
  INCLUDE("D:/MyGUI/MyGUI_300/solution_directx/Demos/Demo_PluginStrangeButton/cmake_install.cmake")
  INCLUDE("D:/MyGUI/MyGUI_300/solution_directx/Demos/Demo_RenderBox/cmake_install.cmake")
  INCLUDE("D:/MyGUI/MyGUI_300/solution_directx/Demos/Demo_ScrollView/cmake_install.cmake")
  INCLUDE("D:/MyGUI/MyGUI_300/solution_directx/Demos/Demo_Themes/cmake_install.cmake")
  INCLUDE("D:/MyGUI/MyGUI_300/solution_directx/Demos/Demo_Pointers/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

