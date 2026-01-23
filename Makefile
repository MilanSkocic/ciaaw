include make.in
# ---------------------------------------------------------------------
# CONFIGURATION
install_dir=$(DESTDIR)/$(PREFIX)
ifneq ($(prefix), )
	PREFIX=$(prefix)
endif

ifneq ($(type), )
	btype=$(type)
else
	btype=release
endif

install_dir=$(DESTDIR)/$(PREFIX)

GEN=./scripts/saw/gen_src.py
GEN_ICE=./scripts/ice/gen_src.py
GEN_NAW=./scripts/naw/gen_src.py
GEN_PTE=./scripts/pte/gen_src.py

SRC_FYPP=$(wildcard *.fypp)
SRC_FYPP_F90=$(patsubst %.fypp, %.f90, $(SRC_FYPP))
F_MODULE = ./src/ciaaw_saw.f90  ./src/ciaaw_ice.f90 ./src/ciaaw_naw.f90 ./src/ciaaw_pte.f90
# ---------------------------------------------------------------------


# ---------------------------------------------------------------------
# TARGETS
.PHONY: build data sources references doc docs clean logo

all: $(FPM_LIBNAME)

$(FPM_LIBNAME): build copy_a shared
# ---------------------------------------------------------------------


# ---------------------------------------------------------------------
# SOURCES
sources: $(SRC_FYPP_F90) $(F_MODULE)
	
./src/ciaaw_saw.f90: ./data/saw_2021.toml
	$(FPM_PYGEN) $(GEN) $< $@

./src/ciaaw_ice.f90: ./data/ice_2013.toml
	$(FPM_PYGEN) $(GEN_ICE) $< $@

./src/ciaaw_naw.f90: ./data/naw_2020.toml
	$(FPM_PYGEN) $(GEN_NAW) $< $@

./src/ciaaw_pte.f90: ./data/saw_2021.toml ./data/ice_2013.toml
	$(FPM_PYGEN) $(GEN_PTE) $^ $@

./src/%.f90: ./src/%.fypp
	fypp -I ../include $< $@

prep:
	make -C srcprep
# ---------------------------------------------------------------------


# ---------------------------------------------------------------------
# COMPILATION
build: 
	fpm build --profile=$(btype)

test: build
	fpm test --profile=$(btype)

example: build
	fpm run --profile=$(btype) --example example_in_f
	fpm run --profile=$(btype) --example example_in_c
# ---------------------------------------------------------------------


# ---------------------------------------------------------------------
# LINKING - STATIC and DYNAMIC LIBS
copy_a: 
	cp -f $(shell find ./build/gfortran* -type f -name $(FPM_LIBNAME).a) $(FPM_BUILD_DIR)

shared: shared_$(FPM_PLATFORM)

shared_linux: 
	$(FPM_FC) -shared -o $(FPM_BUILD_DIR)/$(FPM_LIBNAME).so -Wl,--whole-archive $(FPM_BUILD_DIR)/$(FPM_LIBNAME).a -Wl,--no-whole-archive

shared_darwin: 
	$(FPM_FC) -dynamiclib -install_name @rpath/$(FPM_LIBNAME).dylib $(FPM_LDFLAGS) -o $(FPM_BUILD_DIR)/$(FPM_LIBNAME).dylib -Wl,-all_load $(FPM_BUILD_DIR)/$(FPM_LIBNAME).a

shared_windows: 
	$(FPM_FC) -shared $(FPM_LDFLAGS) -o $(FPM_BUILD_DIR)/$(FPM_LIBNAME).dll -Wl,--out-implib=$(FPM_BUILD_DIR)/$(FPM_LIBNAME).dll.a,--export-all-symbols,--enable-auto-import,--whole-archive $(FPM_BUILD_DIR)/$(FPM_LIBNAME).a -Wl,--no-whole-archive
# ---------------------------------------------------------------------


# ---------------------------------------------------------------------
# INSTALLATION 
install: install_dirs install_$(FPM_PLATFORM)

install_dirs: 
	mkdir -p $(install_dir)/bin
	mkdir -p $(install_dir)/include
	mkdir -p $(install_dir)/lib
	mkdir -p $(install_dir)/share/man/man3
	fpm install --prefix=$(install_dir) --profile=$(btype)
	cp -f $(FPM_INCLUDE_DIR)/$(FPM_NAME)*.h $(install_dir)/include
	cp -f doc/$(FPM_NAME)*.3 $(install_dir)/share/man/man3

install_linux: 
	cp -f $(FPM_BUILD_DIR)/$(FPM_LIBNAME).so $(install_dir)/lib

install_darwin: 
	cp -f $(FPM_BUILD_DIR)/$(FPM_LIBNAME).dylib $(install_dir)/lib

install_windows:
	cp -f $(FPM_BUILD_DIR)/$(FPM_LIBNAME).dll.a $(install_dir)/lib
	cp -f $(FPM_BUILD_DIR)/$(FPM_LIBNAME).dll $(install_dir)/lib
	cp -f $(FPM_BUILD_DIR)/$(FPM_LIBNAME).dll $(install_dir)/bin

uninstall:
	rm -f $(install_dir)/include/$(FPM_NAME)*.h
	rm -f $(install_dir)/include/$(FPM_NAME)*.mod
	rm -f $(install_dir)/lib/$(FPM_LIBNAME).a
	rm -f $(install_dir)/lib/$(FPM_LIBNAME).so
	rm -f $(install_dir)/lib/$(FPM_LIBNAME).dylib
	rm -f $(install_dir)/lib/$(FPM_LIBNAME).dll.a
	rm -f $(install_dir)/lib/$(FPM_LIBNAME).dll
	rm -f $(install_dir)/bin/$(FPM_LIBNAME).dll
# ---------------------------------------------------------------------


# ---------------------------------------------------------------------
# OTHERS
doc:
	fpm run --profile release --target $(FPM_APPNAME) -- --help > doc/$(FPM_APPNAME).1.prep
	make -C doc

docs:
	rm -rf docs/*
	cp -rf doc/sphinx/build/html/* docs/

logo:
	make -C media

clean:
	rm -rf $(F_MODULE) $(SRC_FYPP_F90)
	fpm clean --all
	make -C srcprep clean
	make -C doc clean
# ---------------------------------------------------------------------
