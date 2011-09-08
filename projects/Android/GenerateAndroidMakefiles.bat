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

GOTO FIND_GUCEF_CMAKE_SLN_DEBUG_MVC10_PROJECTGENERATOR


REM -----------------------------------------------------

:FIND_GUCEF_RELEASE_PROJECTGENERATOR

SET GENERATORPATH=%GUCEF_HOME%\tools\ProjectGenerator\bin\ReleasedBins\Win32\6September2011\
SET GENERATOREXE=ProjectGenerator.exe
SET EXETEST=%GENERATORPATH%\%GENERATOREXE%

ECHO Test path = "%EXETEST%"
IF EXIST "%EXETEST%" (
  ECHO Using released version of ProjectGenerator dated 6th September 2011
  GOTO RUN_PROJECTGENERATOR
)

IF NOT EXIST "%EXETEST%" (
  ECHO Error: Unable to locate GUCEF released ProjectGenerator
  GOTO END
)
    
cd "%GUCEF_THEBATCHDIR%"
GOTO RUN_PROJECTGENERATOR

REM -----------------------------------------------------

:FIND_GUCEF_CMAKE_SLN_DEBUG_MVC10_PROJECTGENERATOR

SET GENERATORPATH=%GUCEF_HOME%\common\bin\MVC10\bin\Debug
SET GENERATOREXE=ProjectGenerator.exe
SET EXETEST=%GENERATORPATH%\%GENERATOREXE%

ECHO Test path = "%EXETEST%"
IF EXIST "%EXETEST%" (
  ECHO Warning: Using CMake debug development version of the ProjectGenerator
  GOTO RUN_PROJECTGENERATOR
)

IF NOT EXIST "%EXETEST%" (
  ECHO Cannot locate CMake debug development version of the ProjectGenerator
  GOTO FIND_GUCEF_RELEASE_PROJECTGENERATOR
)

cd "%GUCEF_THEBATCHDIR%"
GOTO RUN_PROJECTGENERATOR


REM -----------------------------------------------------

:RUN_PROJECTGENERATOR

SET PATH="%GENERATORPATH%";%PATH%

cd %GUCE_THEBATCHDIR%\..\..\

IF NOT DEFINED GUCE_HOME (
  ECHO WARNING: GUCE_HOME not defined, falling back to relative path
  SET GUCE_HOME=%GUCE_THEBATCHDIR%\..\..\
)

%GENERATOREXE% *rootDir=%GUCEF_HOME%* *rootDir=%GUCE_HOME%* *outputDir=%GUCE_HOME%* *generators=androidmake* *dirsToIgnore=.svn;_svn* *projectName=GUCE*
cd "%GUCE_THEBATCHDIR%"
GOTO END


REM -----------------------------------------------------

:END

IF NOT DEFINED NOPAUSE (
  PAUSE
)