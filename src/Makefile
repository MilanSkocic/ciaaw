PY=python
GEN=../scripts/saw/gen_src.py
GEN_ICE=../scripts/ice/gen_src.py
GEN_CAPI=../scripts/saw/gen_capi.py

AST_DIR=../data
SRC_DIR=.

AST_SRC=$(wildcard $(AST_DIR)/*.toml)
F_MODULE = ciaaw_saw.f90  ciaaw_ice.f90
SRC_FYPP=$(wildcard *.fypp)
SRC_FYPP_F90=$(patsubst %.fypp, %.f90, $(SRC_FYPP))

.PHONY: clean

all: $(F_MODULE) $(SRC_FYPP_F90)

ciaaw_saw.f90: $(AST_DIR)/saw_2021.toml
	$(PY) $(GEN) $< $@

ciaaw_ice.f90: $(AST_DIR)/ice_2013.toml
	$(PY) $(GEN_ICE) $< $@

#capi_saw_2021.f90: $(AST_DIR)/saw_2021.toml
#	$(PY) $(GEN_CAPI) $< $@

%.f90: %.fypp
	fypp -I ../include $< $@

clean:
	rm -rf $(F_MODULE) $(SRC_FYPP_F90)

