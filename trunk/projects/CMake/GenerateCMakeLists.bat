@echo off

SET GUCE_THEBATCHDIR=%CD%

IF NOT DEFINED GUCEF_HOME (
  ECHO WARNING: GUCEF_HOME not defined, falling back to relative path guesswork
  SET GUCEF_HOME=%CD%\..\..\..\..\GUCEF\trunk
)
ECHO GUCEF_HOME=%GUCEF_HOME%

IF NOT DEFINED GUCEF_HOME (
  ECHO Error: GUCEF_HOME is not defined
  GOTO END
)

GOTO FIND_GUCEF_OLD_SLN_DEBUG_CMAKELISTGENERATOR

REM -----------------------------------------------------

:FIND_GUCEF_OLD_SLN_DEBUG_CMAKELISTGENERATOR

SET GENERATORPATH=%GUCEF_HOME%\common\bin\Debug_MVC9
SET GENERATOREXE=CMakeListGenerator_d.exe
SET EXETEST=%GENERATORPATH%\%GENERATOREXE%

ECHO Test path = %EXETEST%
IF EXIST %EXETEST% (
  ECHO Warning: Using GUCEF Debug_MVC9 development version of the CMakeListGenerator
  GOTO RUN_CMAKELISTGENERATOR
)

IF NOT EXIST %EXETEST% (
  ECHO Cannot locate old GUCEF MVC9 debug development version of the CMakeListGenerator, trying CMake version
  GOTO FIND_GUCEF_CMAKE_SLN_DEBUG_CMAKELISTGENERATOR
)

cd %GUCE_THEBATCHDIR%
GOTO RUN_CMAKELISTGENERATOR

REM -----------------------------------------------------

:FIND_GUCEF_CMAKE_SLN_DEBUG_CMAKELISTGENERATOR

SET GENERATORPATH=%GUCEF_HOME%\common\bin\MVC9\bin\Debug
SET GENERATOREXE=CMakeListGenerator.exe
SET EXETEST=%GENERATORPATH%\%GENERATOREXE%

ECHO Test path = %EXETEST%
IF EXIST %EXETEST% (
  ECHO Warning: Using GUCEF CMake debug MVC9 development version of the CMakeListGenerator
  GOTO RUN_CMAKELISTGENERATOR
)

IF NOT EXIST %EXETEST% (
  ECHO Cannot locate GUCEF CMake MVC9 debug development version of the CMakeListGenerator, trying GUCE
  GOTO FIND_GUCE_CMAKE_SLN_DEBUG_CMAKELISTGENERATOR
)

cd %GUCE_THEBATCHDIR%
GOTO RUN_CMAKELISTGENERATOR

REM -----------------------------------------------------

:FIND_GUCE_CMAKE_SLN_DEBUG_CMAKELISTGENERATOR

SET GENERATORPATH=%GUCE_HOME%\common\bin\MVC9\bin\Debug
SET GENERATOREXE=CMakeListGenerator.exe
SET EXETEST=%GENERATORPATH%\%GENERATOREXE%

ECHO Test path = %EXETEST%
IF EXIST %EXETEST% (
  ECHO Warning: Using GUCE CMake debug MVC9 development version of the CMakeListGenerator
  GOTO RUN_CMAKELISTGENERATOR
)

IF NOT EXIST %EXETEST% (
  ECHO Cannot locate GUCE CMake MVC9 debug development version of the CMakeListGenerator, trying release version
  GOTO FIND_GUCEF_RELEASE_CMAKELISTGENERATOR
)

cd %GUCE_THEBATCHDIR%
GOTO RUN_CMAKELISTGENERATOR


REM -----------------------------------------------------

:FIND_GUCEF_RELEASE_CMAKELISTGENERATOR

SET GENERATORPATH=%GUCEF_HOME%\tools\CMakeListGenerator\bin\ReleasedBins\16April2010\CMakeListGenerator\
SET GENERATOREXE=CMakeListGenerator.exe
SET EXETEST=%GENERATORPATH%\%GENERATOREXE%

ECHO Test path = %EXETEST%
IF EXIST %EXETEST% (
  ECHO Using released version of CMakeListGenerator dated 16'th April 2010
  GOTO RUN_CMAKELISTGENERATOR
)

IF NOT EXIST %EXETEST% (
  ECHO Error: Unable to locate GUCEF's released CMakeListGenerator, trying GUCE release version
  GOTO FIND_GUCE_RELEASE_CMAKELISTGENERATOR
)
    
cd %GUCE_THEBATCHDIR%
GOTO RUN_CMAKELISTGENERATOR


REM -----------------------------------------------------

:FIND_GUCE_RELEASE_CMAKELISTGENERATOR

SET GENERATORPATH=%GUCE_THEBATCHDIR%\..\..\tools\CMakeListGenerator\bin\ReleasedBins\16April2010
SET GENERATOREXE=CMakeListGenerator.exe
SET EXETEST=%GENERATORPATH%\%GENERATOREXE%

ECHO Test path = %EXETEST%
IF NOT EXIST %EXETEST% (
  ECHO Error: Unable to locate GUCE's CMakeListGenerator, cannot locate any kind of generator
  GOTO END
)

cd %GUCE_THEBATCHDIR%
GOTO RUN_CMAKELISTGENERATOR


REM -----------------------------------------------------


:RUN_CMAKELISTGENERATOR

SET PATH=%GENERATORPATH%;%PATH%

cd %GUCE_THEBATCHDIR%
cd..
cd..

IF NOT DEFINED GUCE_HOME (
  ECHO GUCE environment variable not found, setting it
  SET GUCE_HOME=%CD%
  ECHO GUCE_HOME=%CD%
)

%GENERATOREXE% 'rootDir=%GUCEF_HOME%' 'rootDir=%GUCE_HOME%'
cd %GUCE_THEBATCHDIR%
GOTO END

REM -----------------------------------------------------

:END

IF NOT DEFINED NOPAUSE (
  PAUSE
)