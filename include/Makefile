PY=python
GEN=../scripts/saw/gen_headers.py
CONC=../scripts/saw/gen_header.py

AST_DIR=../data

AST_SRC=$(wildcard $(AST_DIR)/*.toml)
C_HEADER = ciaaw_saw_2021.h 
MAIN_HEADER = ciaaw.h

.PHONY: clean

all: $(MAIN_HEADER)

ciaaw_saw_2021.h: $(AST_DIR)/saw_2021.toml
	$(PY) $(GEN) $< $@

$(MAIN_HEADER): $(C_HEADER)
	$(PY) $(CONC) $^ -o $@
	rm -f $(C_HEADER)

clean:
	rm -rf $(C_HEADER)
	rm -rf $(MAIN_HEADER)

