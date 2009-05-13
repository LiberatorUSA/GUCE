SET DOXFILEDIR=%CD%
cd..
mkdir API
SET APIDOCSDIR=%CD%\API
cd..
cd tools
cd Doxygen
cd MSWIN
cd WIN32
SET DOXYGEN_HOME=%CD%
doxygen.exe "%DOXFILEDIR%\GUCE_API.dox"
PAUSE