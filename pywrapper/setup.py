r"""Setup."""
import platform
from setuptools import setup, Extension

libraries = None
library_dirs = None
runtime_library_dirs = None
extra_objects = None

if platform.system() == "Linux":
    libraries = ["ciaaw"]
    library_dirs = ["./src/pyciaaw"]
    runtime_library_dirs = ["$ORIGIN"]
if platform.system() == "Windows":
    extra_objects = ["./src/pyciaaw/libciaaw.dll.a"]
if platform.system() == "Darwin":
    libraries = ["ciaaw"]
    library_dirs = ["./src/pyciaaw"]
    runtime_library_dirs = ["@loader_path"]

if __name__ == "__main__":

    mod_version = Extension(name="pyciaaw.version",
                        sources=["./src/pyciaaw/cpy_ciaaw_version.c"],
                        libraries=libraries,
                        library_dirs=library_dirs,
                        runtime_library_dirs=runtime_library_dirs,
                        extra_objects=extra_objects)
    mod_saw_latest = Extension(name="pyciaaw.saw_latest",
                        sources=["./src/pyciaaw/cpy_ciaaw_saw_latest.c"],
                        libraries=libraries,
                        library_dirs=library_dirs,
                        runtime_library_dirs=runtime_library_dirs,
                        extra_objects=extra_objects)
    mod_saw_2021 = Extension(name="pyciaaw.saw_2021",
                        sources=["./src/pyciaaw/cpy_ciaaw_saw_2021.c"],
                        libraries=libraries,
                        library_dirs=library_dirs,
                        runtime_library_dirs=runtime_library_dirs,
                        extra_objects=extra_objects)
    setup(ext_modules=[mod_version, mod_saw_latest, mod_saw_2021])
