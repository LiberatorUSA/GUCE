!define TARGET_COMPILER_DESCRIPTION "C::B + MingW"
!define TARGET_COMPILER "CBMingW"
!define MINGW
!include ogresdk.nsh

Section -Samples
  ; We assume copysamples.sh has been run recently enough for these files to be available
  SetOutPath "$INSTDIR\samples\scripts"
  SetOverwrite try
  File ".\Samples\scripts\*.cbp"
  SetOutPath "$INSTDIR\samples\src"
  SetOverwrite try
  File ".\Samples\src\*.cpp"
  SetOutPath "$INSTDIR\samples\include"
  SetOverwrite try
  File ".\Samples\include\*.h"

  ; Refapp
  SetOutPath "$INSTDIR\samples\refapp\scripts"
  SetOverwrite try
  File ".\samples\refapp\scripts\*.cbp"
  SetOutPath "$INSTDIR\samples\refapp\src"
  SetOverwrite try
  File "..\..\ReferenceApplication\ReferenceAppLayer\src\*.cpp"
  SetOutPath "$INSTDIR\samples\refapp\include"
  SetOverwrite try
  File "..\..\ReferenceApplication\ReferenceAppLayer\include\*.h"
  
  
  SetOutPath "$INSTDIR\samples"
  SetOverwrite try
  File ".\Samples\Samples.workspace"


SectionEnd