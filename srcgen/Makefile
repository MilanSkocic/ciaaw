CC=gcc
FC=gfortran
FFLAGS=-std=f2008 -Wall -Wextra -pedantic

.PHONY: generate

all: srcgen

srcgen: generator
	./generator

generator: core.o cpy_code.o fortran_code.o c_code.o parser.o main.o
	$(FC) $^ -o generator

%.o: %.f90
	$(FC) -c $(FFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f generator
	rm -f *.mod