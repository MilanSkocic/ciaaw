PY=python
GEN=../scripts/gen_headers.py

AST_DIR=../data

AST_SRC=$(wildcard $(AST_DIR)/*.toml)
C_HEADER = cciaaw_saw_2021.h 

.PHONY: clean

all: $(C_HEADER)

cciaaw_saw_2021.h: $(AST_DIR)/saw_2021.toml
	$(PY) $(GEN) $< $@

clean:
	rm -rf $(C_HEADER)

