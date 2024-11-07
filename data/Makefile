PY=python
GEN_AST_SAW=../scripts/saw/gen_ast.py
GEN_AST_ICE=../scripts/ice/gen_ast.py
FORMAT_NAW = ../scripts/naw/format_iupac.py

RAW_SAW_SRC=$(wildcard saw*.txt)
AST_SAW_SRC=$(patsubst %.txt, %.toml, $(RAW_SAW_SRC))

RAW_ICE_SRC=$(wildcard ice*.txt)
AST_ICE_SRC=$(patsubst %.txt, %.toml, $(RAW_ICE_SRC))

IUPAC_CLEAN_SRC = naw_2020.csv

.PHONY: clean

all: $(AST_SAW_SRC) $(AST_ICE_SRC) $(IUPAC_CLEAN_SRC)

saw_2021.toml: saw_2021.txt
	$(PY) $(GEN_AST_SAW) $< $@

ice_2013.toml: ice_2013.txt
	$(PY) $(GEN_AST_ICE) $< $@

naw_2020.csv: IUPAC-atomic-masses.csv
	$(PY) $(FORMAT_NAW) $< $@

clean:
	rm -f *.toml

