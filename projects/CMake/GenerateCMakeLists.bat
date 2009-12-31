
IF DEFINED GUCEF_HOME (
  ECHO GUCEF environment variable found, using it's CMake
  SET GENERATORPATH=%GUCEF_HOME%\common\bin\Debug_MVC9
)

IF NOT DEFINED GENERATORPATH (
  ECHO GENERATORPATH not defined, using generator binary included with GUCE
  cd..
  cd..
  cd tools
  cd CMakeListGenerator
  SET GENERATORPATH=%CD%
)


SET PATH=%GENERATORPATH%;%PATH%

cd..
cd..
cd..

CMakeListGenerator_d.exe

PAUSE