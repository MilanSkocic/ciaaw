r"""Setup."""
import platform
import shutil
import pathlib
import subprocess
from setuptools import setup, Extension

name = "ciaaw"
libraries = None
library_dirs = None
runtime_library_dirs = None
extra_objects = None
ext = [".so"]


if platform.system() == "Linux":
    libraries = [name]
    library_dirs = [f"./src/py{name:s}"]
    runtime_library_dirs = ["$ORIGIN"]
    ext = [".so"]
if platform.system() == "Windows":
    extra_objects = [f"./src/py{name:s}/lib{name:s}.dll.a"]
    ext = [".dll", ".dll.a"]
if platform.system() == "Darwin":
    libraries = [name]
    library_dirs = [f"./src/py{name:s}"]
    runtime_library_dirs = ["@loader_path"]
    ext = [".dylib"]


version = None
with open("./VERSION", "r") as f:
    version = f.read().strip()


if __name__ == "__main__":

    mod_ciaaw = Extension(name="pyciaaw._ciaaw",
                        sources=["./src/pyciaaw/_ciaaw.c"],
                        libraries=libraries,
                        library_dirs=library_dirs,
                        runtime_library_dirs=runtime_library_dirs,
                        extra_objects=extra_objects)
    setup(version=version,
            ext_modules=[mod_ciaaw])
