#!/bin/bash

LIBNAME="libciaaw"
NAME="ciaaw"

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

cp -f VERSION ./py/VERSION
cp -f LICENSE ./py/LICENSE


echo "##### COMMON SETTINGS #####"
export LIBNAME NAME PLATFORM
echo "* LIBNAME=" $LIBNAME
echo "* NAME=" $NAME

echo "##### FPM SETTINGS #####"
export FPM_FFLAGS FPM_CFLAGS FPM_LDFLAGS
echo "* PLATFORM=" $PLATFORM
echo "* FPM_FFLAGS=" $FPM_FFLAGS
echo "* FPM_CFLAGS=" $FPM_CFLAGS
echo "* FPM_LDFLAGS=" $FPM_LDFLAGS

echo "##### INSTALLATION SETTINGS #####"
export DEFAULT_INSTALL_DIR BUILD_DIR INCLUDE_DIR EXT
echo "* DEFAULT INSTALL DIR=" $DEFAULT_INSTALL_DIR
echo "* BUILD DIR=" $BUILD_DIR
echo "* INCLUDE_DIR=" $INCLUDE_DIR

echo "##### COMPILERS #####"
export FC CC
echo "* FC=" $FC
echo "* CC=" $CC
