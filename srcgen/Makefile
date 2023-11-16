CC=gcc
FC=gfortran
FFLAGS=-std=f2008 -Wall -Wextra -pedantic

.PHONY: generate

all: srcgen

srcgen: generator
	./generator

generator: main.o
	$(FC) $^ -o generator

%.o: %.f90
	$(FC) -c $(FFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f generator
	rm -f *.mod