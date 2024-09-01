PY=python
GEN_AST_SAW=../scripts/saw/gen_ast.py
GEN_AST_ICE=../scripts/ice/gen_ast.py

RAW_SAW_SRC=$(wildcard saw*.txt)
AST_SAW_SRC=$(patsubst %.txt, %.toml, $(RAW_SAW_SRC))

RAW_ICE_SRC=$(wildcard ice*.txt)
AST_ICE_SRC=$(patsubst %.txt, %.toml, $(RAW_ICE_SRC))

.PHONY: clean

all: $(AST_SAW_SRC) $(AST_ICE_SRC)

saw_2021.toml: saw_2021.txt
	$(PY) $(GEN_AST_SAW) $< $@

ice_2013.toml: ice_2013.txt
	$(PY) $(GEN_AST_ICE) $< $@

clean:
	rm -f *.toml

