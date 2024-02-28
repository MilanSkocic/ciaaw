PYW_SRC="./src/py$HEADER_PREFIX"
LIB_INCLUDE_DIR="../include"
LIB_BUILD_DIR="../build"

EXT=".so"

LIBS=("libgfortran.5" "libquadmath.0" "libgcc_s.1.1")
LIBSWINDOWS=("libwinpthread")

ROOTLINUX=/usr/lib/
ROOTDARWIN=/usr/local/opt/gcc/lib/gcc/current
ROOTWINDOWS=/C/msys64/mingw64/bin
ROOT=$ROOTLINUX

export PYW_SRC
echo "PYW_SRC=" $PYW_SRC

export LIB_INCLUDE_DIR
echo "LIB_INCLUDE_DIR=" $LIB_INCLUDE_DIR

export LIB_BUILD_DIR
echo "LIB_BUILD_DIR=" $LIB_BUILD_DIR


if [ "$PLATFORM" = "darwin" ]; then
    ROOT=$ROOTDARWIN
    EXT=".dylib"
fi

if [ "$PLATFORM" = "windows" ]; then
    ROOT=$ROOTWINDOWS
    EXT=".dll"
    LIBS+=$LIBSWINDOWS
fi

if ! [ -z $1 ]; then
    ROOT=$1
fi

echo "GCC folder: $ROOT"

for lib in ${LIBS[@]}; do
    fpath=$ROOT/$lib$EXT
    if [ -f "$fpath" ]; then
        echo -n "   $fpath exists."
        cp "$fpath" $PYW_SRC
        echo " Copied."
    else
        echo "   $fpath does not exist."
    fi
done

echo "$LIBNAME folder: $LIB_BUILD_DIR"
fpath=$LIB_BUILD_DIR/$LIBNAME$EXT 
if [ -f $fpath ]; then
    echo -n "    $fpath exists."
    cp $fpath $PYW_SRC
    echo " Copied."
    if [ "$PLATFORM" = "windows" ]; then
        cp $fpath.a $PYW_SRC
    fi
else
    echo "    $fpath does not exist."
fi

echo "Include folder: $LIB_INCLUDE_DIR"
echo -n "    Copying headers..."
cp $LIB_INCLUDE_DIR/$HEADER_PREFIX*.h $PYW_SRC
echo "OK"
