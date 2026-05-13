export PREP_DOCUMENT_DIR=../

f90prep=$(wildcard *.f90)
f90=$(patsubst %.f90, ../src/%.f90, $(f90prep))


all: example.txt fapi.txt capi.txt pyapi.txt $(f90)

../src/%.f90: %.f90
	prep $< -o $@

example.txt: ../example/example.f90 ../example/example.c ../example/example.py
	./concatex.sh

fapi.txt: ciaaw.f90
	./code2txt $< $@

capi.txt: ../include/ciaaw.h
	./code2txt $< $@

pyapi.txt: ../py/src/pyciaaw/__init__.py
	./code2txt $< $@

clean:
	rm -f $(f90)
	rm -f *api.txt example*.txt
