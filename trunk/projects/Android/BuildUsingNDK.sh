#!/bin/bash
#


# Turn on tracing, we want to see what's going on
#set -x

#------------------------------------------------------------------------------

function SetGucefHome {

  # Set GUCEF_HOME if it is not set yet
  GUCEF_HOME=${GUCEF_HOME:=undefined}
  if [ "$GUCEF_HOME" = "undefined" ]; then
    echo "GUCEF_HOME environment variable not found, setting it"
    GUCEF_HOME="$GUCEANDROIDBUILD_SCRIPTSTARTDIR/../../../../GUCEF/trunk"
  fi
  echo "GUCEF_HOME = $GUCEF_HOME"

}

#------------------------------------------------------------------------------

function SetGuceHome {

  # Set GUCE_HOME if it is not set yet
  GUCE_HOME=${GUCE_HOME:=undefined}
  if [ "$GUCE_HOME" = "undefined" ]; then
    echo "GUCE_HOME environment variable not found, setting it"
    GUCE_HOME="$GUCEANDROIDBUILD_SCRIPTSTARTDIR/../.."
  fi
  echo "GUCE_HOME = $GUCE_HOME"

}

#------------------------------------------------------------------------------

echo " "
echo "*** Setting up basic variables ***"
echo " "

# Remember the dir where we started out since we use relative paths
scriptPath="$(cd "${0%/*}" 2>/dev/null; echo "$PWD"/"${0##*/}")"
GUCEANDROIDBUILD_SCRIPTSTARTDIR=${scriptPath%/*}
echo "GUCEANDROIDBUILD_SCRIPTSTARTDIR = $GUCEANDROIDBUILD_SCRIPTSTARTDIR"

# Make sure the GUCEF_HOME variable is set
SetGucefHome

# Make sure the GUCE_HOME variable is set
SetGuceHome

if [ "$GUCEF_HOME" = "undefined" ]; then
  echo "GUCEF_HOME environment variable not found, fatal error"
  exit
fi

if [ "$GUCE_HOME" = "undefined" ]; then
  echo "GUCE_HOME environment variable not found, fatal error"
  exit
fi

echo " "
echo "*** Locating NDK ***"
echo " "

. $GUCEF_HOME/projects/Android/FindNDK.sh

echo " "
echo "Changing current directory to Android project dir relative to GUCE_HOME"

cd $GUCE_HOME/projects/Android/jni

echo "Project dir = $PWD"
echo " "

echo " "
echo "*** Invoking build ***"
echo " "

$ANDROIDNDK/ndk-build

#echo "Press enter to continue..."
#line=""
#read line
