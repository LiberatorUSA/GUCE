@echo off

SET GUCE_THEBATCHDIR=%CD%

IF NOT DEFINED GUCEF_HOME (
  ECHO Error: GUCEF_HOME is not defined
  GOTO END
)

ECHO GUCEF_HOME=%GUCEF_HOME%

IF NOT DEFINED DEBUG_CMAKELISTGENERATOR (
  GOTO FIND_GUCEF_RELEASE_CMAKELISTGENERATOR
)

IF DEFINED DEBUG_CMAKELISTGENERATOR (
  GOTO FIND_GUCEF_DEBUG_CMAKELISTGENERATOR
)

GOTO FIND_GUCEF_RELEASE_CMAKELISTGENERATOR

REM -----------------------------------------------------

:FIND_GUCEF_DEBUG_CMAKELISTGENERATOR

SET GENERATORPATH=%GUCEF_HOME%\common\bin\Debug_MVC9
SET GENERATOREXE=CMakeListGenerator_d.exe
SET EXETEST=%GENERATORPATH%\%GENERATOREXE%

IF EXIST %EXETEST% (
  ECHO Warning: Using debug development version of the CMakeListGenerator
  GOTO RUN_CMAKELISTGENERATOR
)

IF NOT EXIST %EXETEST% (
  ECHO Error: Cannot locate debug development version of the CMakeListGenerator
  GOTO END
)

cd %GUCE_THEBATCHDIR%
GOTO RUN_CMAKELISTGENERATOR


REM -----------------------------------------------------

:FIND_GUCEF_RELEASE_CMAKELISTGENERATOR

SET GENERATORPATH=%GUCEF_HOME%\tools\CMakeListGenerator\bin\ReleasedBins\18Jan2010\CMakeListGenerator\
SET GENERATOREXE=CMakeListGenerator.exe
SET EXETEST=%GENERATORPATH%\%GENERATOREXE%

IF EXIST %EXETEST% (
  ECHO Using released version of CMakeListGenerator dated 18'th Jan 2010
  GOTO RUN_CMAKELISTGENERATOR
)

IF NOT EXIST %EXETEST% (
  ECHO Error: Unable to locate GUCEF's released CMakeListGenerator, trying GUCE version
  GOTO FIND_GUCE_CMAKELISTGENERATOR
)
    
cd %GUCE_THEBATCHDIR%
GOTO RUN_CMAKELISTGENERATOR


REM -----------------------------------------------------


:FIND_GUCE_CMAKELISTGENERATOR

cd %GUCE_THEBATCHDIR%
cd..
cd..
cd tools
cd CMakeListGenerator
cd bin
cd ReleasedBins
cd 15Jan2010
SET GENERATORPATH=%CD%
SET GENERATOREXE=CMakeListGenerator.exe
SET EXETEST=%GENERATORPATH%\%GENERATOREXE%

IF NOT EXIST %EXETEST% (
  ECHO Error: Unable to locate GUCE's CMakeListGenerator
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
)

%GENERATOREXE% 'rootDir=%GUCEF_HOME%' 'rootDir=%GUCE_HOME%'
cd %GUCE_THEBATCHDIR%

REM -----------------------------------------------------

:END

IF NOT DEFINED NOPAUSE (
  PAUSE
)