IF "%GUCEF_HOME%" != "" GOTO USEENVVAR

:USERELPATH
SET %OUTPUTDIR% = %~dp0
SET %GUCEF_HOME% = %OUTPUTDIR%\..\..\..\..\GUCEF\

copy %GUCEF_HOME%\common\bin\Debug_MVC9\*.dll %~dp0
mkdir %~dp0\plugins
copy %GUCEF_HOME%\common\bin\Debug_MVC9\plugins\*.dll %~dp0\plugins
GOTO END


:USEENVVAR
copy %GUCEF_HOME%\common\bin\Debug_MVC9\*.dll %~dp0
mkdir %~dp0\plugins
copy %GUCEF_HOME%\common\bin\Debug_MVC9\plugins\*.dll %~dp0\plugins


:END
pause