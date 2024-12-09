#!/bin/bash

NAME="ciaaw"
LIBNAME="libciaaw"

# environment variables
FC=gfortran
CC=gcc
BUILD_DIR="./build"
INCLUDE_DIR="./include"
FPM_FFLAGS="-std=f2008 -pedantic -Wall -Wextra"
FPM_CFLAGS="-std=c11 -pedantic -Wall -Wextra"
FPM_LDFLAGS=""
DEFAULT_INSTALL_DIR="$HOME/.local"
PLATFORM="linux"
EXT=".so"

echo -n "Detecting platform..."
if [[ "$OSTYPE" == "msys" ]]; then
    DEFAULT_INSTALL_DIR="${APPDATA//\\//}/local"
    PLATFORM="windows"
    ROOT=$ROOTWINDOWS
    EXT=".dll"
    LIBS=( "${LIBSWINDOWS[@]}" )
fi

if [[ "$OSTYPE" == "darwin"* ]];then
    PLATFORM="darwin"
    ROOT=$ROOTDARWIN
    EXT=".dylib"
    LIBS=( "${LIBSDARWIN[@]}" )
fi
echo "OK"


echo -n "Exporting the ENV variables..."
export LIBNAME NAME PLATFORM
export FPM_FFLAGS FPM_CFLAGS FPM_LDFLAGS
export DEFAULT_INSTALL_DIR BUILD_DIR INCLUDE_DIR EXT
export FC CC
echo "OK"

echo "##### COMMON SETTINGS #####"
echo "* LIBNAME=" $LIBNAME
echo "* NAME=" $NAME

echo "##### FPM SETTINGS #####"
echo "* PLATFORM=" $PLATFORM
echo "* FPM_FFLAGS=" $FPM_FFLAGS
echo "* FPM_CFLAGS=" $FPM_CFLAGS
echo "* FPM_LDFLAGS=" $FPM_LDFLAGS

echo "##### INSTALLATION SETTINGS #####"
echo "* DEFAULT INSTALL DIR=" $DEFAULT_INSTALL_DIR
echo "* BUILD DIR=" $BUILD_DIR
echo "* INCLUDE_DIR=" $INCLUDE_DIR

echo "##### COMPILERS #####"
echo "* FC=" $FC
echo "* CC=" $CC


echo -n "Copying VERSION and LICENSE to py..."
cp -f VERSION ./py/VERSION
cp -f LICENSE ./py/LICENSE
echo "OK"
