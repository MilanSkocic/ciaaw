PY=python
GEN=../../../scripts/gen_cpython.py

AST_DIR=../../../data

AST_SRC=$(wildcard $(AST_DIR)/*.toml)
CPYTHON = cpy_ciaaw_saw_2021.c

.PHONY: clean

all: $(CPYTHON)

cpy_ciaaw_saw_2021.c: $(AST_DIR)/saw_2021.toml
	$(PY) $(GEN) $< $@

clean:
	rm -rf $(CPYTHON)

