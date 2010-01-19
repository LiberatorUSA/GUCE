@echo off

SET GUCE_BATCHSTARTDIR=%CD%

ECHO *** Enable command extensions ***

VERIFY OTHER 2>nul
SETLOCAL ENABLEEXTENSIONS
IF ERRORLEVEL 1 (
  REM ERROR: Unable to enable extensions
  PAUSE
)
ENDLOCAL

ECHO *** Locating GUCEF ***

IF NOT DEFINED GUCEF_HOME (
  ECHO GUCEF_HOME not defined, defaulting to local trunk copy
  SET GUCEF_HOME=%CD%\..\..\..\..\GUCEF\trunk
  cd "%GUCE_BATCHSTARTDIR%"
)

ECHO GUCEF_HOME="%GUCEF_HOME%"

ECHO *** Perform GUCE common CMake environment variable setup ***

cd %GUCE_BATCHSTARTDIR%
cd..
cd..
SET GUCE_HOME=%CD%

IF NOT DEFINED FREETYPE_HOME (
  ECHO FREETYPE_HOME environment variable not found, setting it
  SET FREETYPE_HOME=%GUCE_HOME%\dependencies\freetype
)

IF NOT DEFINED OGRE_HOME (
  ECHO OGRE_HOME environment variable not found, setting it
  SET OGRE_HOME=%GUCE_HOME%\dependencies\Ogre
)

IF NOT DEFINED ZLIB_HOME (
  ECHO ZLIB_HOME environment variable not found, setting it
  SET ZLIB_HOME=%GUCE_HOME%\dependencies\zlib
)

IF NOT DEFINED ZZZIP_HOME (
  ECHO ZZZIP_HOME environment variable not found, setting it
  SET ZZZIP_HOME=%GUCE_HOME%\dependencies\zziplib
)

IF NOT DEFINED CEGUI_HOME (
  ECHO CEGUI_HOME environment variable not found, setting it
  SET CEGUI_HOME=%GUCE_HOME%\guidriverCEGUIOgre\dependency\CEGUI
)

IF NOT DEFINED MYGUI_HOME (
  ECHO MYGUI_HOME environment variable not found, setting it
  SET MYGUI_HOME=%MYGUI_HOME%\guidriverMyGUIOgre\dependencies\MyGUI
)

cd "%GUCE_BATCHSTARTDIR%"

ECHO *** Invoking GUCEF's CMakeCommon ***

SET SKIP_GUCEF_CMAKELISTSFILEGENERATION=TRUE
cd %GUCEF_HOME%\projects\CMake\
CALL %GUCEF_HOME%\projects\CMake\CMakeCommon.bat

cd "%GUCE_BATCHSTARTDIR%"

ECHO *** Generate CMakeLists.txt files ***

SET NOPAUSE=TRUE
CALL GenerateCMakeLists.bat

SET OUTPUTDIR=%GUCE_HOME%\common\bin
SET SRCROOTDIR=%GUCE_HOME%

ECHO CMake source dir = %SRCROOTDIR%
ECHO CMake output root is = %OUTPUTDIR%

cd "%GUCE_BATCHSTARTDIR%"



































