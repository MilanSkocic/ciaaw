# ---------------------------------------------------------------------
# CONFIGURATION
ifneq ($(prefix), )
	install_dir=$(prefix)
else
	install_dir=$(DEFAULT_INSTALL_DIR)
endif

ifneq ($(type), )
	btype=$(type)
else
	btype=release
endif

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

all: $(LIBNAME)

$(LIBNAME): build copy_a shared
# ---------------------------------------------------------------------


# ---------------------------------------------------------------------
# SOURCES
sources: $(SRC_FYPP_F90) $(F_MODULE)
	
./src/ciaaw_saw.f90: ./data/saw_2021.toml
	$(PYGEN) $(GEN) $< $@

./src/ciaaw_ice.f90: ./data/ice_2013.toml
	$(PYGEN) $(GEN_ICE) $< $@

./src/ciaaw_naw.f90: ./data/naw_2020.toml
	$(PYGEN) $(GEN_NAW) $< $@

./src/ciaaw_pte.f90: ./data/saw_2021.toml ./data/ice_2013.toml
	$(PYGEN) $(GEN_PTE) $^ $@

./src/%.f90: ./src/%.fypp
	fypp -I ../include $< $@
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
	cp -f $(shell find ./build/gfortran* -type f -name $(LIBNAME).a) $(BUILD_DIR)

shared: shared_$(PLATFORM)

shared_linux: 
	$(FC) -shared -o $(BUILD_DIR)/$(LIBNAME).so -Wl,--whole-archive $(BUILD_DIR)/$(LIBNAME).a -Wl,--no-whole-archive

shared_darwin: 
	$(FC) -dynamiclib -install_name @rpath/$(LIBNAME).dylib $(FPM_LDFLAGS) -o $(BUILD_DIR)/$(LIBNAME).dylib -Wl,-all_load $(BUILD_DIR)/$(LIBNAME).a

shared_windows: 
	$(FC) -shared $(FPM_LDFLAGS) -o $(BUILD_DIR)/$(LIBNAME).dll -Wl,--out-implib=$(BUILD_DIR)/$(LIBNAME).dll.a,--export-all-symbols,--enable-auto-import,--whole-archive $(BUILD_DIR)/$(LIBNAME).a -Wl,--no-whole-archive
# ---------------------------------------------------------------------


# ---------------------------------------------------------------------
# INSTALLATION 
install: install_dirs install_$(PLATFORM)

install_dirs: 
	mkdir -p $(install_dir)/bin
	mkdir -p $(install_dir)/include
	mkdir -p $(install_dir)/lib
	fpm install --prefix=$(install_dir) --profile=$(btype)
	cp -f $(INCLUDE_DIR)/$(NAME)*.h $(install_dir)/include

install_linux: 
	cp -f $(BUILD_DIR)/$(LIBNAME).so $(install_dir)/lib

install_darwin: 
	cp -f $(BUILD_DIR)/$(LIBNAME).dylib $(install_dir)/lib

install_windows:
	cp -f $(BUILD_DIR)/$(LIBNAME).dll.a $(install_dir)/lib
	cp -f $(BUILD_DIR)/$(LIBNAME).dll $(install_dir)/lib
	cp -f $(BUILD_DIR)/$(LIBNAME).dll $(install_dir)/bin

uninstall:
	rm -f $(install_dir)/include/$(NAME)*.h
	rm -f $(install_dir)/include/$(NAME)*.mod
	rm -f $(install_dir)/lib/$(LIBNAME).a
	rm -f $(install_dir)/lib/$(LIBNAME).so
	rm -f $(install_dir)/lib/$(LIBNAME).dylib
	rm -f $(install_dir)/lib/$(LIBNAME).dll.a
	rm -f $(install_dir)/lib/$(LIBNAME).dll
	rm -f $(install_dir)/bin/$(LIBNAME).dll
# ---------------------------------------------------------------------


# ---------------------------------------------------------------------
# OTHERS
references:
	pandoc -t markdown_strict --citeproc --csl ase.csl _REFERENCES.md -o REFERENCES.md

doc: references
	ford API-doc-FORD-file.md

docs:
	rm -rf docs/*
	cp -rf API-doc/* docs/

clean:
	rm -rf $(F_MODULE) $(SRC_FYPP_F90)
	fpm clean --all
	rm -rf API-doc/*
# ---------------------------------------------------------------------
