
SET THEBATCHDIR=%CD%

IF DEFINED GUCEF_HOME (
  ECHO GUCEF environment variable found, using it's CMakeListGenerator
  SET GENERATORPATH=%GUCEF_HOME%\common\bin\Debug_MVC9
  SET GENERATOREXE=CMakeListGenerator_d.exe
  SET EXETEST=%GENERATORPATH%\%GENERATOREXE%
  cd %GENERATORPATH%

)

  IF NOT EXIST %EXETEST% (
    ECHO Development version of CMakeListGenerator not found, using released version
    SET GENERATORPATH=%GUCEF_HOME%\tools\CMakeListGenerator\bin\ReleasedBins\15Jan2010\CMakeListGenerator\
    SET GENERATOREXE=CMakeListGenerator.exe
  )

cd %THEBATCHDIR%

IF NOT DEFINED GENERATORPATH (

  ECHO GENERATORPATH not defined, using generator binary included with GUCE
  cd..
  cd..
  cd tools
  cd CMakeListGenerator
  cd bin
  cd ReleasedBins
  cd 15Jan2010
  SET GENERATORPATH=%CD%
  SET GENERATOREXE=CMakeListGenerator.exe
)

SET PATH=%GENERATORPATH%;%PATH%
cd %THEBATCHDIR%

cd..
cd..

%GENERATOREXE%

cd %THEBATCHDIR%

IF NOT DEFINED NOPAUSE (
  PAUSE
)