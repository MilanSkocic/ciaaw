r"""Setup."""
import platform
from setuptools import setup, Extension

libraries = None
library_dirs = None
runtime_library_dirs = None
extra_objects = None

if platform.system() == "Linux":
    libraries = ["ciaaw"]
    library_dirs = ["./pyciaaw"]
    runtime_library_dirs = ["$ORIGIN"]
if platform.system() == "Windows":
    extra_objects = ["./pyciaaw/libciaaw.dll.a"]
if platform.system() == "Darwin":
    libraries = ["ciaaw"]
    library_dirs = ["./pyciaaw"]
    runtime_library_dirs = ["@loader_path"]

if __name__ == "__main__":

    mod_version = Extension(name="pyciaaw.version",
                        sources=["./pyciaaw/cpy_ciaaw_version.c"],
                        libraries=libraries,
                        library_dirs=library_dirs,
                        runtime_library_dirs=runtime_library_dirs,
                        extra_objects=extra_objects)
    mod_ext = Extension(name="pyciaaw.saw",
                        sources=["./pyciaaw/cpy_ciaaw_saw.c"],
                        libraries=libraries,
                        library_dirs=library_dirs,
                        runtime_library_dirs=runtime_library_dirs,
                        extra_objects=extra_objects)
    setup(ext_modules=[mod_version, mod_ext])
