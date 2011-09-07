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

GOTO FIND_GUCE_CMAKE_SLN_DEBUG_PROJECTGENERATOR

REM -----------------------------------------------------

:FIND_GUCE_CMAKE_SLN_DEBUG_PROJECTGENERATOR

SET GENERATORPATH=%GUCE_THEBATCHDIR%\..\..\common\bin\MVC10\bin\Debug
SET GENERATOREXE=ProjectGenerator.exe
SET EXETEST="%GENERATORPATH%\%GENERATOREXE%"

ECHO Test path = %EXETEST%
IF EXIST %EXETEST% (
  ECHO Warning: Using GUCE CMake debug MVC10 development version of the ProjectGenerator
  GOTO RUN_PROJECTGENERATOR
)

IF NOT EXIST %EXETEST% (
  ECHO Cannot locate GUCE CMake MVC10 debug development version of the ProjectGenerator, trying GUCEF
  GOTO FIND_GUCEF_CMAKE_SLN_DEBUG_PROJECTGENERATOR
)

cd %GUCE_THEBATCHDIR%
GOTO RUN_PROJECTGENERATOR

REM -----------------------------------------------------

:FIND_GUCEF_CMAKE_SLN_DEBUG_PROJECTGENERATOR

SET GENERATORPATH=%GUCEF_HOME%\common\bin\MVC10\bin\Debug
SET GENERATOREXE=ProjectGenerator.exe
SET EXETEST=%GENERATORPATH%\%GENERATOREXE%

ECHO Test path = %EXETEST%
IF EXIST %EXETEST% (
  ECHO Warning: Using GUCEF CMake debug MVC10 development version of the ProjectGenerator
  GOTO RUN_PROJECTGENERATOR
)

IF NOT EXIST %EXETEST% (
  ECHO Cannot locate GUCEF CMake MVC10 debug development version of the ProjectGenerator, trying GUCE
  GOTO FIND_GUCE_CMAKE_SLN_DEBUG_PROJECTGENERATOR
)

cd %GUCE_THEBATCHDIR%
GOTO RUN_PROJECTGENERATOR

REM -----------------------------------------------------

:FIND_GUCE_CMAKE_SLN_DEBUG_PROJECTGENERATOR

SET GENERATORPATH=%GUCE_HOME%\common\bin\MVC10\bin\Debug
SET GENERATOREXE=ProjectGenerator.exe
SET EXETEST=%GENERATORPATH%\%GENERATOREXE%

ECHO Test path = %EXETEST%
IF EXIST %EXETEST% (
  ECHO Warning: Using GUCE CMake debug MVC10 development version of the ProjectGenerator
  GOTO RUN_PROJECTGENERATOR
)

IF NOT EXIST %EXETEST% (
  ECHO Cannot locate GUCE CMake MVC10 debug development version of the ProjectGenerator, trying release version
  GOTO FIND_GUCEF_RELEASE_PROJECTGENERATOR
)

cd %GUCE_THEBATCHDIR%
GOTO RUN_PROJECTGENERATOR


REM -----------------------------------------------------

:FIND_GUCEF_RELEASE_PROJECTGENERATOR

SET GENERATORPATH=%GUCEF_HOME%\tools\ProjectGenerator\bin\ReleasedBins\Win32\6September2011
SET GENERATOREXE=ProjectGenerator.exe
SET EXETEST=%GENERATORPATH%\%GENERATOREXE%

ECHO Test path = %EXETEST%
IF EXIST %EXETEST% (
  ECHO Using released version of ProjectGenerator dated 6'th September 2011
  GOTO RUN_PROJECTGENERATOR
)

IF NOT EXIST %EXETEST% (
  ECHO Error: Unable to locate GUCEF's released ProjectGenerator, trying GUCE release version
  GOTO FIND_GUCE_RELEASE_PROJECTGENERATOR
)
    
cd %GUCE_THEBATCHDIR%
GOTO RUN_PROJECTGENERATOR


REM -----------------------------------------------------

:FIND_GUCE_RELEASE_PROJECTGENERATOR

SET GENERATORPATH=%GUCE_THEBATCHDIR%\..\..\tools\ProjectGenerator\bin\ReleasedBins\Win32\6September2011
SET GENERATOREXE=ProjectGenerator.exe
SET EXETEST=%GENERATORPATH%\%GENERATOREXE%

ECHO Test path = %EXETEST%
IF NOT EXIST %EXETEST% (
  ECHO Error: Unable to locate GUCE's ProjectGenerator, cannot locate any kind of generator
  GOTO END
)

cd %GUCE_THEBATCHDIR%
GOTO RUN_PROJECTGENERATOR


REM -----------------------------------------------------


:RUN_PROJECTGENERATOR

SET PATH=%GENERATORPATH%;%PATH%

cd %GUCE_THEBATCHDIR%
cd..
cd..

IF NOT DEFINED GUCE_HOME (
  ECHO GUCE environment variable not found, setting it
  SET GUCE_HOME=%CD%
  ECHO GUCE_HOME=%CD%
)

%GENERATOREXE% *rootDir=%GUCEF_HOME%* *rootDir=%GUCE_HOME%* *dirsToIgnore=.svn;_svn* *projectName=GUCEF* *generators=cmake* *outputDir=%GUCE_HOME%* *cmakgen:TemplateDir=%GUCEF_HOME%\projects\CMake\ProjectGenTemplates*
cd %GUCE_THEBATCHDIR%
GOTO END

REM -----------------------------------------------------

:END

IF NOT DEFINED NOPAUSE (
  PAUSE
)