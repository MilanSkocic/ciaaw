#!/bin/bash

NAME="ciaaw"
LIBNAME="lib$NAME"
PYNAME="py$NAME"
PY_SRC="./src/$PYNAME"

# environment variables
FC=gfortran
CC=gcc
PY=python
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
    PY="py -"
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

echo -n "Exporting env variables..."
export LIBNAME
export NAME
export PLATFORM
export FPM_FFLAGS
export FPM_CFLAGS
export FPM_LDFLAGS
export DEFAULT_INSTALL_DIR
export BUILD_DIR
export INCLUDE_DIR
export PY_SRC
export FC
export CC
export PY
export EXT
echo "OK"

echo "##### COMMON SETTINGS #####"
echo "* LIBNAME=" $LIBNAME
echo "* NAME=" $NAME
echo "* PLATFORM=" $PLATFORM

echo "##### FPM SETTINGS #####"
echo "* FPM_FFLAGS=" $FPM_FFLAGS
echo "* FPM_CFLAGS=" $FPM_CFLAGS
echo "* FPM_LDFLAGS=" $FPM_LDFLAGS

echo "##### INSTALLATION SETTINGS #####"
echo "* DEFAULT INSTALL DIR=" $DEFAULT_INSTALL_DIR
echo "* BUILD DIR=" $BUILD_DIR
echo "* INCLUDE_DIR=" $INCLUDE_DIR

echo "##### PYTHON SETTINGS #####"
echo "* PY_SRC=" $PY_SRC

echo "##### COMPILERS #####"
echo "* FC=" $FC
echo "* CC=" $CC
echo "* PY=" $PY


echo -n "Copying version and license for python..."
cp -f VERSION ./py/VERSION
cp -f LICENSE ./py/LICENSE
echo "OK"