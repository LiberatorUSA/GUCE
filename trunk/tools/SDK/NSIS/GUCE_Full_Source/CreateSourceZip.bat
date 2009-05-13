
:: *** Set some environment variables ***

SET ZIPOUTPUTDIR=%CD%
cd..
cd..
cd..
cd InfoZip
cd MSWIN
cd WIN32
SET ZIPTOOLDIR=%CD%
cd..
cd..
cd..
cd..
SET ARCHIVEROOTDIR=%CD%

:: *** Get rid of data we dont need in the GUCE dirs ***

:: - Disabled in favor of a removal after zip creation
::   it is a better idea to mess with the zip then with the archive ;)
::cd docs
::rd /s /q API
::mkdir docs
::cd %ARCHIVEROOTDIR%\guceCORE
::rd /s /q bin
::mkdir bin
::cd %ARCHIVEROOTDIR%\guceGUI
::rd /s /q bin
::mkdir bin
::cd %ARCHIVEROOTDIR%\guceMULTIPLAY
::rd /s /q bin
::mkdir bin

:: *** Create the zip file using GUCE + dependencies ***

%ZIPTOOLDIR%\zip.exe -v -r %ZIPOUTPUTDIR%\GUCE_FULL_SOURCE.zip %ARCHIVEROOTDIR% -x@%ZIPOUTPUTDIR%\ExcludeFromZip.txt

:: *** Get rid of data we dont need in the GUCE dirs ***

%ZIPTOOLDIR%\zip.exe -d %ZIPOUTPUTDIR%\GUCE_FULL_SOURCE.zip "GUALL/GUCE/dependency/Ogre/api\*" "GUALL/GUCE/dependency/Ogre/OgreMain/lib\*" "GUALL/GUCE/dependency/Ogre/OgreMain/obj\*" "GUALL/GUCE/dependency/Ogre/Samples\*" "GUALL/GUCE/dependency/Ogre/Tools\*" "GUALL/GUCE/dependency/CEGUI/bin\*" "GUALL/GUCE/dependency/CEGUI/lib\*" "GUALL/GUCE/dependency/CEGUI/dependencies/bin\*" "GUALL/GUCE/guceCORE/bin\*" "GUALL/GUCE/guceGUI/bin\*" "GUALL/GUCE/guceMULTIPLAY/bin\*" "GUALL/GUCE/common/bin/Debug*" "GUALL/GUCE/common/bin/Release*" "GUALL/GUCE/common/docs/API\*"

:: *** Expand the zip file using GUCEF + dependencies

SET ARCHIVEROOTDIR=%GUCEF_HOME%
%ZIPTOOLDIR%\zip.exe -v -r %ZIPOUTPUTDIR%\GUCE_FULL_SOURCE.zip %ARCHIVEROOTDIR% -x@%ZIPOUTPUTDIR%\ExcludeFromZip.txt

:: *** Get rid of data we dont need in the GUCEF dirs ***

%ZIPTOOLDIR%\zip.exe -d %ZIPOUTPUTDIR%\GUCE_FULL_SOURCE.zip "GUALL/GUCEF/docs/API*" "*/bin*"

REM *** FINISHED!!! ***
PAUSE