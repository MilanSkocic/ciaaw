GEN_AST_SAW=../scripts/saw/gen_ast.py
GEN_AST_ICE=../scripts/ice/gen_ast.py
GEN_AST_NAW=../scripts/naw/gen_ast.py
FORMAT_NAW = ../scripts/naw/format_iupac.py

GEN=../scripts/saw/gen_src.py
GEN_ICE=../scripts/ice/gen_src.py
GEN_NAW=../scripts/naw/gen_src.py
GEN_PTE=../scripts/pte/gen_src.py

RAW_SAW_SRC=$(wildcard ./src/saw*.txt)
AST_SAW_SRC=$(patsubst ./src/%.txt, ./build/%.toml, $(RAW_SAW_SRC))

RAW_ICE_SRC=$(wildcard ./src/ice*.txt)
AST_ICE_SRC=$(patsubst ./src/%.txt, ./build/%.toml, $(RAW_ICE_SRC))

RAW_NAW_SRC=$(wildcard ./src/naw*.txt)
AST_NAW_SRC=$(patsubst ./src/%.txt, ./build/%.toml, $(RAW_NAW_SRC))

IUPAC_CLEAN_SRC = ./src/naw_2020.txt

.PHONY: clean

all: dirs $(AST_SAW_SRC) $(AST_ICE_SRC) $(IUPAC_CLEAN_SRC) $(AST_NAW_SRC) \
	 build/ciaaw_saw.f90 build/ciaaw_ice.f90 build/ciaaw_naw.f90 build/ciaaw_pte.f90 \
	 ../src/ciaaw_saw.f90 ../src/ciaaw_ice.f90 ../src/ciaaw_naw.f90 ../src/ciaaw_pte.f90

.PHONY: dirs
dirs:
	mkdir -p build

build/saw_2021.toml: src/saw_2021.txt
	$(PYGEN) $(GEN_AST_SAW) $< $@

build/ice_2013.toml: src/ice_2013.txt
	$(PYGEN) $(GEN_AST_ICE) $< $@

build/naw_2020.toml: src/naw_2020.txt
	$(PYGEN) $(GEN_AST_NAW) $< $@

build/naw_2020.txt: src/IUPAC-atomic-masses.csv build/saw_2021.toml
	$(PYGEN) $(FORMAT_NAW) $^ $@

build/ciaaw_saw.f90: ./build/saw_2021.toml
	$(FPM_PYGEN) $(GEN) $< $@

build/ciaaw_ice.f90: ./build/ice_2013.toml
	$(FPM_PYGEN) $(GEN_ICE) $< $@

build/ciaaw_naw.f90: ./build/naw_2020.toml
	$(FPM_PYGEN) $(GEN_NAW) $< $@

build/ciaaw_pte.f90: ./build/saw_2021.toml ./build/ice_2013.toml
	$(FPM_PYGEN) $(GEN_PTE) $^ $@

../src/%.f90: build/%.f90
	cp -fv $^ $@

clean:
	rm -rf build/*
	rm -rf ../src/ciaaw_saw.f90
	rm -rf ../src/ciaaw_ice.f90
	rm -rf ../src/ciaaw_naw.f90
	rm -rf ../src/ciaaw_pte.f90

